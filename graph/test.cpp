#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <vector>

using namespace std;

#define LOCAL 0
#define LMAX 110005
#define ALPHA 26
#define MAXDPMEM 1230000000
#define TIME_LIMIT 1.94
#define QMOD 65535
#define INF 1000000000

namespace XOR128 {

unsigned int xx, yy, zz, uu;

void reset(unsigned int seed) {
	xx = seed;
	yy = 362436069;
	zz = 521288629;
	uu = 786232308;
}

inline unsigned int rand() {
	unsigned int t = (xx ^ (xx << 11));
	xx = yy; yy = zz; zz = uu;
	return (uu = (uu ^ (uu >> 19)) ^ (t ^ (t >> 8)));
}
}

unsigned int fast_rand_seed;
#define fast_rand (fast_rand_seed = (214013U * fast_rand_seed + 2531011U))

namespace MCMF {

int cost[2 * ALPHA + 3][2 * ALPHA + 3];
int smin[2 * ALPHA + 3];
int q[QMOD + 1], p[2 * ALPHA + 3];
int flow[2 * ALPHA + 3][2 * ALPHA + 3], cap[2 * ALPHA + 3][2 * ALPHA + 3], t[2 * ALPHA + 3], inq[2 * ALPHA + 3];
vector<pair<int, int> > dest;

int MinCostMaxFlow() {
	int i, j, li, ls, min_cost = 0, max_flow = 0;

	memset(flow, 0, sizeof(flow));
	memset(p, 0, sizeof(p));

	int M = 2 * ALPHA + 2;

	// Do the flow.
	while (1) {
		li = ls = 0;
		for (i = 2; i <= ALPHA + 1; i++) {
			if (flow[1][i] == cap[1][i]) {
				smin[i] = INF;
				inq[i] = 0;
				p[i] = 0;
			} else {
				smin[i] = 0;
				inq[i] = 1;
				q[ls] = i;
				ls = (ls + 1) & QMOD;
				t[i] = 1;
				p[i] = 1;
			}
		}

		for (i = ALPHA + 2; i <= 2 * ALPHA + 2; i++) {
			smin[i] = INF;
			inq[i] = 0;
			p[i] = 0;
		}

		while (li != ls) {
			i = q[li];
			inq[i] = 0;
			li = (li + 1) & QMOD;
			if (p[i] > 0 && inq[p[i]]) continue;
			if (p[p[i]] > 0 && inq[p[p[i]]]) continue;
			if (p[p[p[i]]] > 0 && inq[p[p[p[i]]]]) continue;
			if (p[p[p[p[i]]]] > 0 && inq[p[p[p[p[i]]]]]) continue;

			if (i <= ALPHA + 1) {
				for (j = ALPHA + 2; j <= 2 * ALPHA + 1; j++) {
					if (flow[i][j] < cap[i][j]) {
						if (smin[i] + cost[i][j] < smin[j]) {
							smin[j] = smin[i] + cost[i][j];
							p[j] = i;
							t[j] = 1;
							if (!inq[j]) {
								inq[j] = 1;
								q[ls] = j;
								ls = (ls + 1) & QMOD;
							}
						}
					}
				}
			} else {
				for (j = 1; j <= ALPHA + 1; j++)
					if (flow[j][i] > 0) {
						if (smin[i] - cost[j][i] < smin[j]) {
							smin[j] = smin[i] - cost[j][i];
							p[j] = i;
							t[j] = 2;
							if (!inq[j]) {
								inq[j] = 1;
								q[ls] = j;
								ls = (ls + 1) & QMOD;
							}
						}
					}
				}
			}

		dest.clear();
		for (j = ALPHA + 2; j <= 2 * ALPHA + 1; j++)
			if (smin[j] < INF && flow[j][2 * ALPHA + 2] < cap[j][2 * ALPHA + 2])
				dest.push_back(make_pair(smin[j], j));

		if (dest.empty()) break;

		sort(dest.begin(), dest.end());

		memset(inq, 0, sizeof(inq));
		for (int did = 0; did < dest.size(); did++) {
			int node = dest[did].second;

			// Retrace the path back from node to 1.
			int max_flow_inc = cap[node][2 * ALPHA + 2] - flow[node][2 * ALPHA + 2];

			while (node != 1) {
				if (inq[node]) break;
				inq[node] = 1;
				int dif;
				if (t[node] == 1) dif = cap[p[node]][node] - flow[p[node]][node];
				else dif = flow[node][p[node]];
				if (dif < max_flow_inc) max_flow_inc = dif;
				node = p[node];
			}

			if (node == 1) {
				node = dest[did].second;
				max_flow += max_flow_inc;
				min_cost += smin[node] * max_flow_inc;
				flow[node][2 * ALPHA + 2] += max_flow_inc;

				while (node != 1) {
					if (t[node] == 1) {
                        flow[p[node]][node] += max_flow_inc;
						//fprintf(stderr, "inc flow %d->%d\n", p[node], node);
                    } else {
                        flow[node][p[node]] -= max_flow_inc;
						//fprintf(stderr, "dec flow %d->%d\n", node, p[node]);
                    }
                    node = p[node];
                }

				break;
			} else break;
		}
	}

	if (LOCAL) fprintf(stderr, "[MCMF] maxf=%d minc=%d\n", max_flow, min_cost);
	return min_cost;
}

}

char S[LMAX], T[LMAX], Scopy[LMAX];
int R[ALPHA][ALPHA], I, D, W, LS, LT;
clock_t TEND;

void GenerateTest(int t) {
	XOR128::reset(11997 * t + 9991);
	int lmin, lmax;
	if (t < 20) {
		lmin = 900;
		lmax = 1000;
	} else if (t < 40) {
		lmin = 9000;
		lmax = 10000;
	} else if (t < 60) {
		lmin = 45000;
		lmax = 50000;
	} else {
		lmin = 99000;
		lmax = 100000;
	}
	int ls = lmin + (XOR128::rand() % (lmax - lmin + 1));
	int lt = lmin + (XOR128::rand() % (lmax - lmin + 1));
	S[ls + 1] = T[lt + 1] = 0;
	for (int i = 1; i <= ls; i++) S[i] = 'A' + (XOR128::rand() % ALPHA);
	for (int i = 1; i <= lt; i++) T[i] = 'A' + (XOR128::rand() % ALPHA);
	for (int i = 0; i < ALPHA; i++)
		for (int j = 0; j < ALPHA; j++)
			if (i == j) R[i][j] = 0;
			else R[i][j] = 1000 + (XOR128::rand() % 9001);
	for (int k = 0; k < ALPHA; k++)
		for (int i = 0; i < ALPHA; i++)
			for (int j = 0; j < ALPHA; j++)
				if (R[i][k] + R[k][j] < R[i][j]) R[i][j] = R[i][k] + R[k][j];
	int Rmin = 10000, Rmax = 0;
	for (int i = 0; i < ALPHA; i++)
		for (int j = 0; j < ALPHA; j++) {
			if (i == j) continue;
			if (R[i][j] < Rmin) Rmin = R[i][j];
			if (R[i][j] > Rmax) Rmax = R[i][j];
		}
	Rmin *= 1.5;
	assert(Rmin <= Rmax);
	I = Rmin + (XOR128::rand() % (Rmax - Rmin + 1));
	D = Rmin + (XOR128::rand() % (Rmax - Rmin + 1));
	W = Rmin + (XOR128::rand() % (Rmax - Rmin + 1));
}

void ReadInput() {
	scanf("%s %s %d %d %d", S + 1, T + 1, &I, &D, &W);
	for (int i = 0; i < ALPHA; i++)
		for (int j = 0; j < ALPHA; j++)
			scanf("%d", &R[i][j]);
}

struct Op {
	char op, ch;
	int poz, poz2;
} ops[2 * LMAX], bops[2 * LMAX];

int nops, nbops, smin, bsmin;

void Init() {
	LS = strlen(S + 1); LT = strlen(T + 1);
	for (int i = 1; i <= LS; i++) S[i] -= 'A';
	for (int i = 1; i <= LT; i++) T[i] -= 'A';
	bsmin = -1;
	nbops = 0;
}

int minoffset, maxoffset;
char dpmem[MAXDPMEM];
int *dp[LMAX], nalloc, zero;
char *dpcase[LMAX];
int smpoz[LMAX], tmpoz[LMAX], nmpoz;
char smatched[LMAX], tmatched[LMAX];

void DP1(int MINOFFSET, int R_upper_bound) {
	nalloc = 0;
	minoffset = maxoffset = LT - LS;
	if (maxoffset < MINOFFSET) maxoffset = MINOFFSET;
	if (minoffset > -MINOFFSET) minoffset = -MINOFFSET;
	zero = -minoffset;
	for (int l = 0; l <= LS; l++) {
		dp[l] = (int*) &dpmem[nalloc];
		nalloc += 4 * (maxoffset - minoffset + 1);
	}
	for (int l = 0; l <= LS; l++) {
		dpcase[l] = &dpmem[nalloc];
		nalloc += (maxoffset - minoffset + 1);
	}
	//if (LOCAL) fprintf(stderr, "nalloc=%d\n", nalloc);
	for (int offset = minoffset; offset <= maxoffset; offset++)
		dp[0][zero + offset] = -1;
	dp[0][zero] = 0;
	for (int l = 1; l <= LS; l++) {
		//fprintf(stderr, "l=%d/%d\n", l, LS);
		const auto& dp_l_minus_1 = dp[l - 1];
		auto& dp_l = dp[l];
		auto& dpcase_l = dpcase[l];
		const auto& R_l = R[S[l]];
		for (int offset = minoffset; offset <= maxoffset; offset++) {
			dp_l[zero + offset] = -1;
			int j = l + offset; // offset = j - l
			if (j < 0 || j > LT) continue;
			// Case 0: dp(l,j) = dp(l-1,j-1) + change(S[l] into T[j])
			int rsc = min(I + D, R_l[T[j]]);
			if (j >= 1 && dp_l_minus_1[zero + offset] >= 0 && rsc <= R_upper_bound) {
				dp_l[zero + offset] = dp_l_minus_1[zero + offset] + rsc;
				dpcase_l[zero + offset] = 0;
			}
			// Case 1: dp(l,j) = dp(l-1,j) + delete S[l]
			if (/*LS > LT &&*/ offset + 1 <= maxoffset && dp_l_minus_1[zero + offset + 1] >= 0) {
				int v = dp_l_minus_1[zero + offset + 1] + D;
				if (dp_l[zero + offset] < 0 || v < dp_l[zero + offset]) {
					dp_l[zero + offset] = v;
					dpcase_l[zero + offset] = 1;
				}
			}
			// Case 2: dp(l,j) = dp(l,j-1) + insert T[j]
			if (/*LS < LT &&*/ offset - 1 >= minoffset && dp_l[zero + offset - 1] >= 0) {
				int v = dp_l[zero + offset - 1] + I;
				if (dp_l[zero + offset] < 0 || v < dp_l[zero + offset]) {
					dp_l[zero + offset] = v;
					dpcase_l[zero + offset] = 2;
				}
			}
		}
	}

	smin = dp[LS][zero + LT - LS];
	//if (LOCAL) fprintf(stderr, "DP: LS=%d LT=%d smin=%d/%d => %.6lf\n", LS, LT, smin, LS * D + LT * I, (double) smin / (LS + LT));
	if (smin < 0) return;

	nmpoz = 0;
	memset(smatched, 0, (LS + 1) * sizeof(char));
	memset(tmatched, 0, (LT + 1) * sizeof(char));

	nops = 0;
	int i = LS, j = LT;
	while (i > 0) {
		int offset = zero + j - i;
		if (dpcase[i][offset] == 0) {
			if (R[S[i]][T[j]] > I + D) {
				ops[nops].op = 'D';
				ops[nops].poz = i;
				nops++;
				ops[nops].op = 'I';
				ops[nops].poz = i - 1;
				ops[nops].ch = T[j];
				nops++;
			} else {
				ops[nops].op = 'R';
				ops[nops].poz = i;
				ops[nops].ch = T[j];
				nops++;
			}
			if (R[S[i]][T[j]] <= R_upper_bound) {
				smpoz[nmpoz] = i;
				tmpoz[nmpoz++] = j;
				smatched[i] = 1;
				tmatched[j] = 1;
			}
			i--;
			j--;
		} else if (dpcase[i][offset] == 1) {
			ops[nops].op = 'D';
			ops[nops].poz = i;
			nops++;
			i--;
		} else { // dpcase[i][offset] == 2
			ops[nops].op = 'I';
			ops[nops].poz = i;
			ops[nops].ch = T[j];
			nops++;
			j--;
		}
	}

	reverse(&smpoz[0], &smpoz[nmpoz]);
	reverse(&tmpoz[0], &tmpoz[nmpoz]);
	smpoz[nmpoz] = LS + 1;
	tmpoz[nmpoz++] = LT + 1;

	if (bsmin < 0 || smin < bsmin) {
		bsmin = smin;
		nbops = nops;
		memcpy(&bops[0], &ops[0], nbops * sizeof(bops[0]));
	}
	if (LOCAL) fprintf(stderr, "nmpoz=%d\n", nmpoz);
}

void DP2(int MINOFFSET, int R_upper_bound) {
	nalloc = 0;
	minoffset = maxoffset = LT - LS;
	if (maxoffset < MINOFFSET) maxoffset = MINOFFSET;
	if (minoffset > -MINOFFSET) minoffset = -MINOFFSET;
	zero = -minoffset;
	for (int l = 0; l <= LS; l++) {
		dp[l] = (int*) &dpmem[nalloc];
		nalloc += 4 * (maxoffset - minoffset + 1);
	}
	for (int l = 0; l <= LS; l++) {
		dpcase[l] = &dpmem[nalloc];
		nalloc += (maxoffset - minoffset + 1);
	}
	//fprintf(stderr, "nalloc=%d\n", nalloc);
	for (int offset = minoffset; offset <= maxoffset; offset++)
		dp[0][zero + offset] = -1;
	dp[0][zero] = 0;
	for (int l = 1; l <= LS; l++) {
		const auto& dp_l_minus_1 = dp[l - 1];
		auto& dp_l = dp[l];
		auto& dpcase_l = dpcase[l];
		const auto& R_l = R[S[l]];
		for (int offset = minoffset; offset <= maxoffset; offset++) {
			dp_l[zero + offset] = -1;
			int j = l + offset; // offset = j - l
			if (j < 0 || j > LT) continue;
			// Case 0: dp(l,j) = dp(l-1,j-1) + change(S[l] into T[j])
			if (j >= 1 && dp_l_minus_1[zero + offset] >= 0) {
				dp_l[zero + offset] = dp_l_minus_1[zero + offset] + (R_l[T[j]] <= R_upper_bound);
				dpcase_l[zero + offset] = 0;
			}
			// Case 1: dp(l,j) = dp(l-1,j) + delete S[l]
			if (LS > LT && offset + 1 <= maxoffset && dp_l_minus_1[zero + offset + 1] >= 0) {
				int v = dp_l_minus_1[zero + offset + 1];
				if (dp_l[zero + offset] < 0 || v > dp_l[zero + offset]) {
					dp_l[zero + offset] = v;
					dpcase_l[zero + offset] = 1;
				}
			}
			// Case 2: dp(l,j) = dp(l,j-1) + insert T[j]
			if (LS < LT && offset - 1 >= minoffset && dp_l[zero + offset - 1] >= 0) {
				int v = dp_l[zero + offset - 1];
				if (dp_l[zero + offset] < 0 || v > dp_l[zero + offset]) {
					dp_l[zero + offset] = v;
					dpcase_l[zero + offset] = 2;
				}
			}
		}
	}

	int fpoz = dp[LS][zero + LT - LS];
	if (LOCAL) fprintf(stderr, "DP: LS=%d LT=%d fpoz=%d\n", LS, LT, fpoz);
	//assert(fpoz > 0);

	nmpoz = 0;
	memset(smatched, 0, (LS + 1) * sizeof(char));
	memset(tmatched, 0, (LT + 1) * sizeof(char));

	// Generate the matched positions.
	int i = LS, j = LT;
	while (i > 0) {
		int offset = zero + j - i;
		if (dpcase[i][offset] == 0) {
			if (R[S[i]][T[j]] <= R_upper_bound) {
				smpoz[nmpoz] = i;
				tmpoz[nmpoz++] = j;
				smatched[i] = 1;
				tmatched[j] = 1;
			}
			i--;
			j--;
		} else if (dpcase[i][offset] == 1) {
			i--;
		} else { // dpcase[i][offset] == 2
			j--;
		}
	}
	reverse(&smpoz[0], &smpoz[nmpoz]);
	reverse(&tmpoz[0], &tmpoz[nmpoz]);
	smpoz[nmpoz] = LS + 1;
	tmpoz[nmpoz++] = LT + 1;
}

void DP3(int MINOFFSET, int R_upper_bound) {
	nalloc = 0;
	minoffset = maxoffset = LT - LS;
	if (maxoffset < MINOFFSET) maxoffset = MINOFFSET;
	if (minoffset > -MINOFFSET) minoffset = -MINOFFSET;
	zero = -minoffset;
	for (int l = 0; l <= LS; l++) {
		dp[l] = (int*) &dpmem[nalloc];
		nalloc += 4 * (maxoffset - minoffset + 1);
	}
	for (int l = 0; l <= LS; l++) {
		dpcase[l] = &dpmem[nalloc];
		nalloc += (maxoffset - minoffset + 1);
	}
	//fprintf(stderr, "nalloc=%d\n", nalloc);
	for (int offset = minoffset; offset <= maxoffset; offset++)
		dp[0][zero + offset] = -1;
	dp[0][zero] = 0;
	for (int l = 1; l <= LS; l++) {
		const auto& dp_l_minus_1 = dp[l - 1];
		auto& dp_l = dp[l];
		auto& dpcase_l = dpcase[l];
		const auto& R_l = R[S[l]];
		for (int offset = minoffset; offset <= maxoffset; offset++) {
			dp_l[zero + offset] = -1;
			int j = l + offset; // offset = j - l
			if (j < 0 || j > LT) continue;
			// Case 0: dp(l,j) = dp(l-1,j-1) + change(S[l] into T[j])
			if (j >= 1 && dp_l_minus_1[zero + offset] >= 0) {
				dp_l[zero + offset] = dp_l_minus_1[zero + offset] + (R_l[T[j]] <= R_upper_bound) * (1000000 - R_l[T[j]]);
				dpcase_l[zero + offset] = 0;
			}
			// Case 1: dp(l,j) = dp(l-1,j) + delete S[l]
			if (/*LS > LT &&*/ offset + 1 <= maxoffset && dp_l_minus_1[zero + offset + 1] >= 0) {
				int v = dp_l_minus_1[zero + offset + 1];// - (R_l[T[j]] <= R_upper_bound) * 10000;
				if (dp_l[zero + offset] < 0 || v > dp_l[zero + offset]) {
					dp_l[zero + offset] = v;
					dpcase_l[zero + offset] = 1;
				}
			}
			// Case 2: dp(l,j) = dp(l,j-1) + insert T[j]
			if (/*LS < LT &&*/ offset - 1 >= minoffset && dp_l[zero + offset - 1] >= 0) {
				int v = dp_l[zero + offset - 1];// - (R_l[T[j]] <= R_upper_bound) * 10000;
				if (dp_l[zero + offset] < 0 || v > dp_l[zero + offset]) {
					dp_l[zero + offset] = v;
					dpcase_l[zero + offset] = 2;
				}
			}
		}
	}

	int fpoz = dp[LS][zero + LT - LS];
	if (LOCAL) fprintf(stderr, "DP: LS=%d LT=%d fpoz=%d\n", LS, LT, fpoz);
	//assert(fpoz > 0);

	nmpoz = 0;
	memset(smatched, 0, (LS + 1) * sizeof(char));
	memset(tmatched, 0, (LT + 1) * sizeof(char));

	// Generate the matched positions.
	int i = LS, j = LT;
	while (i > 0) {
		int offset = zero + j - i;
		if (dpcase[i][offset] == 0) {
			if (R[S[i]][T[j]] <= R_upper_bound) {
				smpoz[nmpoz] = i;
				tmpoz[nmpoz++] = j;
				smatched[i] = 1;
				tmatched[j] = 1;
			}
			i--;
			j--;
		} else if (dpcase[i][offset] == 1) {
			i--;
		} else { // dpcase[i][offset] == 2
			j--;
		}
	}
	reverse(&smpoz[0], &smpoz[nmpoz]);
	reverse(&tmpoz[0], &tmpoz[nmpoz]);
	smpoz[nmpoz] = LS + 1;
	tmpoz[nmpoz++] = LT + 1;
}

int chave[2][ALPHA][LMAX], nchave[2][ALPHA];
int nspoz[LMAX], ntpoz[LMAX], sallpoz[LMAX], nsallpoz, tallpoz[LMAX], ntallpoz;
int need[ALPHA][ALPHA];
int have[ALPHA][ALPHA][LMAX], nhave[ALPHA][ALPHA];
int q[QMOD + 1][2], qli, qls, p[ALPHA][2], dist[ALPHA][2], dscore[ALPHA][2];
int anc[ALPHA][2][2];

#define MAXLPATH 100000
unsigned char lpath[MAXLPATH];
int lprev[MAXLPATH], llast[ALPHA][2], nlpath;

//unsigned char path[ALPHA][2][2 * ALPHA], npath[ALPHA][2];

char inq[ALPHA][2];
int nswaps;

bool Fix(int x, int y) {
	memset(inq, 0, sizeof(inq));
	q[qli = qls = 0][0] = x;
	q[0][1] = 0;
	inq[x][0] = 1;
	dist[x][0] = dscore[x][0] = 0;
	int z;

	while (qli <= qls) {
		z = q[qli][0];
		int t = q[qli][1];
		if (t == 0) {
			int d = dist[z][0];
			if ((d - 1) * W >= d * (I + D)) return false;
			if (nhave[z][y] < need[z][y]) break;
			for (int w = 0; w < ALPHA; w++)
				if (nhave[z][w] < need[z][w] &&
					(!inq[w][1] ||
					(dist[w][1] == dist[z][0] + 1 && dscore[z][0] + R[z][w] < dscore[w][1]))
					&& w != y) {
					if (!inq[w][1]) {
						qls++;
						q[qls][0] = w;
						q[qls][1] = 1;
						inq[w][1] = 1;
					}
					p[w][1] = z;
					dist[w][1] = dist[z][0] + 1;
					dscore[w][1] = dscore[z][0] + R[z][w];
				}
		} else {
			for (int w = 0; w < ALPHA; w++)
				if (nhave[w][z] > need[w][z] &&
					(!inq[w][0] ||
					(dist[w][0] == dist[z][1] + 1 && dscore[z][1] - R[w][z] < dscore[w][0]))
					) {
					if (!inq[w][0]) {
						qls++;
						q[qls][0] = w;
						q[qls][1] = 0;
						inq[w][0] = 1;
					}
					p[w][0] = z;
					dist[w][0] = dist[z][1] + 1;
					dscore[w][0] = dscore[z][1] - R[w][z];
				}
		}
		qli++;
	}

	if (qli > qls) return false;

	while (z != x) {
		int w = p[z][0];
		int pz = have[z][w][nhave[z][w] - 1];
		nhave[z][w]--;

		//assert(Scopy[sallpoz[pz]] == z);
		//assert(T[tallpoz[pz]] == w);

		int px = have[x][y][nhave[x][y] - 1];
		nhave[x][y]--;
		//assert(Scopy[sallpoz[px]] == x);
		//assert(T[tallpoz[px]] == y);

		ops[nops].op = 'S';
		ops[nops].poz = sallpoz[px];
		ops[nops++].poz2 = sallpoz[pz];
		nswaps++;
		smin += W;
		//assert(Scopy[sallpoz[px]] == x && Scopy[sallpoz[pz]] == z);
		Scopy[sallpoz[px]] = z;
		Scopy[sallpoz[pz]] = x;

		have[x][w][nhave[x][w]++] = pz;
		have[z][y][nhave[z][y]++] = px;

		y = w;
		z = p[w][1];
		px = pz;
	}

	return true;
}

#define MAXNUPD 10000
int bit[ALPHA], nupd[ALPHA][2];

void ComputeBits() {
	for (int i = 0; i < ALPHA; i++) bit[i] = 1 << i;
}

bool Fix2(int x, int y) {
	memset(inq, 0, sizeof(inq));
	memset(anc, 0, sizeof(anc));
	memset(nupd, 0, sizeof(nupd));

	for (int i = 0; i < ALPHA; i++) dscore[i][0] = dscore[i][1] = INF;

	nlpath = 0;
	llast[x][0] = 0;

	q[qli = 0][0] = x;
	q[0][1] = 0;
	inq[x][0] = 1;
	dscore[x][0] = -R[x][y];
	p[x][0] = -1;
	qli = 1;

	int z, zbest = -1, dbest = min(0, I + D - R[x][y]);

//	fprintf(stderr, "---\n");

	while (qli != qls) {
		z = q[qli][0];
		int t = q[qli][1];
		if (t == 0) {
			if (dscore[z][0] + R[z][y] < dbest) {
				dbest = dscore[z][0] + R[z][y];
				zbest = z;
				if (dbest < -1000) break;
			}
			const auto& dscore_z_0 = dscore[z][0];
			const auto& anc_z_0_0 = anc[z][0][0];
			const auto& anc_z_0_1 = anc[z][0][1];
			for (int w = 0; w < ALPHA; w++) {
				//if (nupd[w][1] >= MAXNUPD) continue;
				if (inq[w][1] != 2 &&
					dscore_z_0 + R[z][w] + W < dscore[w][1]
					&& !(anc_z_0_1 & bit[w])
					) {
					if (!inq[w][1]) {
						q[qls][0] = w;
						q[qls][1] = 1;
						inq[w][1] = 1;
						qls = (qls + 1) & QMOD;
					}
					p[w][1] = z;
					dscore[w][1] = dscore[z][0] + R[z][w] + W;
					anc[w][1][0] = anc_z_0_0 | bit[z];
					anc[w][1][1] = anc_z_0_1;
					nlpath++;
					//assert(nlpath < MAXLPATH);
					lpath[nlpath] = z;
					lprev[nlpath] = llast[z][0];
					llast[w][1] = nlpath;
					nupd[w][1]++;
				}
			}
		} else {
			const auto& dscore_z_1 = dscore[z][1];
			const auto& anc_z_1_0 = anc[z][1][0];
			const auto& anc_z_1_1 = anc[z][1][1];
			for (int w = 0; w < ALPHA; w++) {
				//if (nupd[w][0] >= MAXNUPD) continue;
				if (inq[w][0] != 2 &&
					nhave[w][z] > 0 &&
					dscore_z_1 - R[w][z] < dscore[w][0]
					&& !(anc_z_1_0 & bit[w])
					) {
					if (!inq[w][0]) {
						q[qls][0] = w;
						q[qls][1] = 0;
						inq[w][0] = 1;
						qls = (qls + 1) & QMOD;
					}
					p[w][0] = z;
					dist[w][0] = dist[z][1] + 1;
					dscore[w][0] = dscore[z][1] - R[w][z];
					anc[w][0][1] = anc_z_1_1 | bit[z];
					anc[w][0][0] = anc_z_1_0;
					nlpath++;
					//assert(nlpath < MAXLPATH);
					lpath[nlpath] = z;
					lprev[nlpath] = llast[z][1];
					llast[w][0] = nlpath;
					nupd[w][0]++;
				}
			}
		}
		//inq[z][t] = 2;
		qli = (qli + 1) & QMOD;
	}

	//if (zbest >= 0) fprintf(stderr, "zbest=%d dbest=%d\n", zbest, dbest);

	if (zbest < 0) return false;

	z = zbest; int t = 0, lidx = llast[zbest][0];

	for (; lidx > 0; lidx = lprev[lidx]) {
		int w = lpath[lidx];
		p[z][t] = w;
		z = w;
		t ^= 1;
	}

	//return Fix(x, y);

	/*
	for (int pidx = npath[zbest][0] - 1; pidx >= 0; pidx--) {
		p[z][t] = path[zbest][0][pidx];
		z = p[z][t];
		t ^= 1;
	}*/

	int nsw = 1;
	/*
	int nsw = nhave[x][y];
	z = zbest;
	while (z != x) {
		int w = p[z][0];
		if (nhave[z][w] < nsw) nsw = nhave[z][w];
		z = p[w][1];
	}*/

	return Fix(x, y);

	for (int k = 0; k < nsw; k++) {
		z = zbest;
		while (z != x) {
			int w = p[z][0];

			//assert(nhave[z][w] > 0);
			int pz = have[z][w][nhave[z][w] - 1];
			nhave[z][w]--;

			//assert(Scopy[sallpoz[pz]] == z);
			//assert(T[tallpoz[pz]] == w);

			int px = have[x][y][nhave[x][y] - 1];
			nhave[x][y]--;
			//assert(Scopy[sallpoz[px]] == x);
			//assert(T[tallpoz[px]] == y);

			ops[nops].op = 'S';
			ops[nops].poz = sallpoz[px];
			ops[nops++].poz2 = sallpoz[pz];
			nswaps++;
			smin += W;
			//assert(Scopy[sallpoz[px]] == x && Scopy[sallpoz[pz]] == z);
			Scopy[sallpoz[px]] = z;
			Scopy[sallpoz[pz]] = x;

			have[x][w][nhave[x][w]++] = pz;
			have[z][y][nhave[z][y]++] = px;

			y = w;
			z = p[w][1];
			px = pz;
		}
	}

	return true;
}

vector<pair<int, pair<int, int>>> rv;
int scap[LMAX], tcap[LMAX], sgid[LMAX], tgid[LMAX];
char pbad[ALPHA][ALPHA];

void PerformSwaps(bool use_fix2) {
	memcpy(Scopy + 1, S + 1, LS * sizeof(char));
	nswaps = 0;
	bool updated = true;
	memset(pbad, 0, sizeof(pbad));
	while (updated) {
		updated = false;
		for (int i = rv.size() - 1; i >= 0; i--) {
			int x = rv[i].second.first, y = rv[i].second.second;
			if (pbad[x][y] || nhave[x][y] <= need[x][y]) continue;
			bool result = use_fix2 ? Fix2(x, y) : Fix(x, y);
			if (!result) {
				pbad[x][y] = 1;
				continue;
			}
			updated = true;
			//i++;
		}
	}
	for (int x = 0; x < ALPHA; x++)
		for (int y = 0; y < ALPHA; y++) {
			if (!pbad[x][y] || R[x][y] < I + D) continue;
			while (nhave[x][y] > need[x][y]) {
				int px = have[x][y][--nhave[x][y]];
				smatched[sallpoz[px]] = tmatched[tallpoz[px]] = 0;
			}
		}
}

void DoSwaps(bool use_fix2) {
	smin = nops = 0;

	memset(smatched + 1, 0, LS * sizeof(char));
	memset(tmatched + 1, 0, LT * sizeof(char));
	memset(nchave, 0, sizeof(nchave));
	int finc = 0, fdel = 0;

	for (int midx = 0; midx < nmpoz; midx++) {
		int si = smpoz[midx], ti = tmpoz[midx];
		if (si <= LS && ti <= LT) {
			smatched[si] = tmatched[ti] = 2;
			if (S[si] != T[ti]) {
				smin += R[S[si]][T[ti]];
				ops[nops].op = 'R';
				ops[nops].poz = si;
				ops[nops++].ch = T[ti];
			}
		}
		int s1 = midx == 0 ? 1 : smpoz[midx - 1] + 1, s2 = smpoz[midx] - 1;
		int t1 = midx == 0 ? 1 : tmpoz[midx - 1] + 1, t2 = tmpoz[midx] - 1;

		//if (s2 > LS) s2 = LS; //
		//if (t2 > LT) t2 = LT; //

		int ls = s2 - s1 + 1, lt = t2 - t1 + 1;
		if (LS <= LT) {
			if (ls > lt) {
				fprintf(stderr, "LS=%d LT=%d midx=%d: ls=%d lt=%d\n", LS, LT, midx, ls, lt);
				exit(1);
			}
		} else {
			if (ls < lt) {
				fprintf(stderr, "LS=%d LT=%d midx=%d: ls=%d lt=%d\n", LS, LT, midx, ls, lt);
				exit(2);
			}
		}
		scap[midx] = tcap[midx] = min(s2 - s1 + 1, t2 - t1 + 1);
		for (int i = s1; i <= s2; i++) {
			sgid[i] = midx;
			chave[0][S[i]][nchave[0][S[i]]++] = i;
		}
		for (int i = t1; i <= t2; i++) {
			tgid[i] = midx;
			chave[1][T[i]][nchave[1][T[i]]++] = i;
		}
		if (ls > scap[midx]) fdel += ls - scap[midx];
		else finc += lt - scap[midx];
	}
	if (LOCAL) fprintf(stderr, "fdel=%d finc=%d : %d\n", fdel, finc, I * finc + D * fdel);

	for (int i = 0; i < ALPHA; i++) {
		random_shuffle(&chave[0][i][0], &chave[0][i][nchave[0][i]]);
		random_shuffle(&chave[1][i][0], &chave[1][i][nchave[1][i]]);
	}

	rv.clear();
	for (int i = 0; i < ALPHA; i++)
		for (int j = 0; j < ALPHA; j++)
			rv.push_back(make_pair(R[i][j], make_pair(i, j)));
	sort(rv.begin(), rv.end());

	memset(need, 0, sizeof(need));

	for (const auto& rp : rv) {
		int x = rp.second.first, y = rp.second.second;
		//if (W / 2 + R[x][y] >= I + D) break;
		while (1) {
			int py = -1;
			while (nchave[1][y]) {
				py = chave[1][y][nchave[1][y] - 1];
				if (!tcap[tgid[py]]) {
					nchave[1][y]--;
					continue;
				}
				break;
			}
			if (!nchave[1][y]) break;
			py = chave[1][y][nchave[1][y] - 1];

			int px = -1;
			while (nchave[0][x]) {
				px = chave[0][x][nchave[0][x] - 1];
				if (!scap[sgid[px]]) {
					nchave[0][x]--;
					continue;
				}
				break;
			}
			if (!nchave[0][x]) break;
			px = chave[0][x][nchave[0][x] - 1];

			nchave[0][x]--;
			nchave[1][y]--;

			tcap[tgid[py]]--;
			scap[sgid[px]]--;
			smatched[px] = tmatched[py] = 1;
			if (W / 2 + R[x][y] < I + D) need[x][y]++;
		}
	}

	for (int midx = 0; midx < nmpoz; midx++)
		if (scap[midx] != 0 || tcap[midx] != 0) {
			fprintf(stderr, "midx=%d scap=%d tcap=%d\n", midx, scap[midx], tcap[midx]);
			exit(11);
		}

	nsallpoz = 0;
	for (int i = 1; i <= LS; i++) {
		if (smatched[i] != 1) continue;
		sallpoz[nsallpoz++] = i;
	}
	ntallpoz = 0;
	for (int i = 1; i <= LT; i++) {
		if (tmatched[i] != 1) continue;
		tallpoz[ntallpoz++] = i;
	}
	//assert(nsallpoz == ntallpoz);

	memset(nhave, 0, sizeof(nhave));
	for (int i = 0; i < nsallpoz; i++) {
		int x = S[sallpoz[i]], y = T[tallpoz[i]];
		have[x][y][nhave[x][y]++] = i;
	}

	PerformSwaps(use_fix2);

	for (int i = 0; i < nsallpoz; i++) {
		int si = sallpoz[i], ti = tallpoz[i];
		if (smatched[si] != 1) continue;
		smin += R[Scopy[si]][T[ti]];
		if (Scopy[si] == T[ti]) continue;
		ops[nops].op = 'R';
		ops[nops].poz = si;
		ops[nops++].ch = T[ti];
	}

	int ndel = 0, nins = 0;
	for (int i = LS; i >= 1; i--)
		if (!smatched[i]) {
			ops[nops].op = 'D';
			ops[nops++].poz = i;
			smin += D;
			ndel++;
		}

	for (int i = 1; i <= LT; i++)
		if (!tmatched[i]) {
			ops[nops].op = 'I';
			ops[nops].ch = T[i];
			ops[nops++].poz = i - 1;
			smin += I;
			nins++;
		}

	if (LOCAL) fprintf(stderr, "DoSwaps: smin=%d ndel=%d nins=%d nswaps=%d (%d)\n", smin, ndel, nins, nswaps, ndel * D + nins * I + nswaps * W);
	if (bsmin < 0 || smin < bsmin) {
		//if (LOCAL) fprintf(stderr, "smin=%d ndel=%d nins=%d nswaps=%d (%d)\n", smin, ndel, nins, nswaps, ndel * D + nins * I + nswaps * W);
		bsmin = smin;
		nbops = nops;
		memcpy(&bops[0], &ops[0], nbops * sizeof(bops[0]));
	}
}

void DoSwaps2(bool use_fix2) {
	smin = nops = 0;

	memset(smatched + 1, 0, LS * sizeof(char));
	memset(tmatched + 1, 0, LT * sizeof(char));
	memset(nchave, 0, sizeof(nchave));
	int finc = 0, fdel = 0;

	for (int midx = 0; midx < nmpoz; midx++) {
		int si = smpoz[midx], ti = tmpoz[midx];
		if (si <= LS && ti <= LT) {
			smatched[si] = tmatched[ti] = 1;
			chave[0][S[si]][nchave[0][S[si]]++] = si;
			chave[1][T[ti]][nchave[1][T[ti]]++] = ti;
		}
	}

	for (int i = 0; i < ALPHA; i++) {
		random_shuffle(&chave[0][i][0], &chave[0][i][nchave[0][i]]);
		random_shuffle(&chave[1][i][0], &chave[1][i][nchave[1][i]]);
	}

	rv.clear();
	for (int i = 0; i < ALPHA; i++)
		for (int j = 0; j < ALPHA; j++)
			rv.push_back(make_pair(R[i][j], make_pair(i, j)));
	sort(rv.begin(), rv.end());

	memset(need, 0, sizeof(need));

	for (const auto& rp : rv) {
		int x = rp.second.first, y = rp.second.second;
		if (W / 2 + R[x][y] >= I + D) break;
		while (nchave[0][x] && nchave[1][y]) {
			int px = chave[0][x][nchave[0][x] - 1];
			int py = chave[1][y][nchave[1][y] - 1];
			nchave[0][x]--;
			nchave[1][y]--;
			if (W / 2 + R[x][y] < I + D) need[x][y]++;
		}
	}

	nsallpoz = 0;
	for (int i = 1; i <= LS; i++) {
		if (smatched[i] != 1) continue;
		sallpoz[nsallpoz++] = i;
	}
	ntallpoz = 0;
	for (int i = 1; i <= LT; i++) {
		if (tmatched[i] != 1) continue;
		tallpoz[ntallpoz++] = i;
	}
	//assert(nsallpoz == ntallpoz);

	memset(nhave, 0, sizeof(nhave));
	for (int i = 0; i < nsallpoz; i++) {
		int x = S[sallpoz[i]], y = T[tallpoz[i]];
		have[x][y][nhave[x][y]++] = i;
	}

	PerformSwaps(use_fix2);

	for (int i = 0; i < nsallpoz; i++) {
		int si = sallpoz[i], ti = tallpoz[i];
		if (smatched[si] != 1) continue;
		smin += R[Scopy[si]][T[ti]];
		if (Scopy[si] == T[ti]) continue;
		ops[nops].op = 'R';
		ops[nops].poz = si;
		ops[nops++].ch = T[ti];
	}

	int ndel = 0, nins = 0;
	for (int i = LS; i >= 1; i--)
		if (!smatched[i]) {
			ops[nops].op = 'D';
			ops[nops++].poz = i;
			smin += D;
			ndel++;
		}

	for (int i = 1; i <= LT; i++)
		if (!tmatched[i]) {
			ops[nops].op = 'I';
			ops[nops].ch = T[i];
			ops[nops++].poz = i - 1;
			smin += I;
			nins++;
		}

	if (LOCAL) fprintf(stderr, "DoSwaps2: smin=%d ndel=%d nins=%d nswaps=%d (%d)\n", smin, ndel, nins, nswaps, ndel * D + nins * I + nswaps * W);
	if (bsmin < 0 || smin < bsmin) {
		//if (LOCAL) fprintf(stderr, "* smin=%d ndel=%d nins=%d nswaps=%d (%d)\n", smin, ndel, nins, nswaps, ndel * D + nins * I + nswaps * W);
		bsmin = smin;
		nbops = nops;
		memcpy(&bops[0], &ops[0], nbops * sizeof(bops[0]));
	}
}

int Rf[ALPHA][ALPHA], spozperm[LMAX], tpozperm[LMAX];

void MinCostMaxFlow(bool use_fix2) {
	memset(MCMF::cap, 0, sizeof(MCMF::cap));
	memset(MCMF::cost, 0, sizeof(MCMF::cost));
	for (int i = 1; i <= LS; i++) MCMF::cap[1][2 + S[i]]++;
	for (int i = 1; i <= LT; i++) MCMF::cap[2 + ALPHA + T[i]][2 * ALPHA + 2]++;
	int sbase = LS <= LT ? I * (LT - LS) : D * (LS - LT);

	for (int i = 0; i < ALPHA; i++)
		for (int j = 0; j < ALPHA; j++) {
			Rf[i][j] = R[i][j] + 0.5 * W;
			MCMF::cap[2 + i][2 + ALPHA + j] = LS;
			MCMF::cost[2 + i][2 + ALPHA + j] = min(Rf[i][j], 10000+I + D);
		}

	int cmin = MCMF::MinCostMaxFlow();
	unsigned int niter = 0;

	for (int i = 1; i <= LS; i++) spozperm[i] = i;
	for (int i = 1; i <= LT; i++) tpozperm[i] = i;

	rv.clear();
	for (int i = 0; i < ALPHA; i++)
		for (int j = 0; j < ALPHA; j++)
			rv.push_back(make_pair(R[i][j], make_pair(i, j)));
	sort(rv.begin(), rv.end());

	while (clock() < TEND) {
		niter++;
		memset(nspoz, 0, sizeof(nspoz));
		memset(ntpoz, 0, sizeof(ntpoz));
		memset(need, 0, sizeof(need));

		for (int i = 0; i < ALPHA; i++)
			for (int j = 0; j < ALPHA; j++) {
				if (Rf[i][j] >= I + D) continue;
				nspoz[i] += MCMF::flow[2 + i][2 + ALPHA + j];
				ntpoz[j] += MCMF::flow[2 + i][2 + ALPHA + j];
				need[i][j] = MCMF::flow[2 + i][2 + ALPHA + j];
			}

		nsallpoz = 0;
		for (int i = 1; i <= LS; i++) {
			int pi = spozperm[i];
			nspoz[S[pi]]--;
			if (nspoz[S[pi]] >= 0) sallpoz[nsallpoz++] = pi;
		}
		sort(&sallpoz[0], &sallpoz[nsallpoz]);

		ntallpoz = 0;
		for (int i = 1; i <= LT; i++) {
			int pi = tpozperm[i];
			ntpoz[T[pi]]--;
			if (ntpoz[T[pi]] >= 0) tallpoz[ntallpoz++] = pi;
		}
		sort(&tallpoz[0], &tallpoz[ntallpoz]);

		//if (LOCAL) fprintf(stderr, "nsallpoz=%d ntallpoz=%d\n", nsallpoz, ntallpoz);
		//assert(nsallpoz == ntallpoz);

		memset(nhave, 0, sizeof(nhave));
		for (int i = 0; i < nsallpoz; i++) {
			char x = S[sallpoz[i]], y = T[tallpoz[i]];
			have[x][y][nhave[x][y]++] = i;
		}

		smin = nops = 0;
		memset(smatched, 0, (LS + 1) * sizeof(char));
		memset(tmatched, 0, (LT + 1) * sizeof(char));
		for (int i = 0; i < nsallpoz; i++) smatched[sallpoz[i]] = tmatched[tallpoz[i]] = 1;

		PerformSwaps(use_fix2);

		int cchange = 0;
		for (int i = 0; i < nsallpoz; i++) {
			if (!smatched[sallpoz[i]]) continue;
			cchange += R[Scopy[sallpoz[i]]][T[tallpoz[i]]];
			ops[nops].op = 'R';
			ops[nops].poz = sallpoz[i];
			ops[nops++].ch = T[tallpoz[i]];
		}

		//if (LOCAL) fprintf(stderr, "cchange=%d cmin=%d\n", cchange, cmin);
		smin += cchange;

		int ndel = 0, nins = 0;

		for (int i = LS; i >= 1; i--)
			if (!smatched[i]) {
				ops[nops].op = 'D';
				ops[nops++].poz = i;
				smin += D;
				ndel++;
			}

		for (int i = 1; i <= LT; i++)
			if (!tmatched[i]) {
				ops[nops].op = 'I';
				ops[nops].ch = T[i];
				ops[nops++].poz = i - 1;
				smin += I;
				nins++;
			}

		//if (LOCAL) fprintf(stderr, "smin=%d ndel=%d nins=%d\n", smin, ndel, nins);
		if (bsmin < 0 || smin < bsmin) {
			bsmin = smin;
			nbops = nops;
			memcpy(&bops[0], &ops[0], nbops * sizeof(bops[0]));
		}

		random_shuffle(&spozperm[1], &spozperm[LS + 1]);
		random_shuffle(&tpozperm[1], &tpozperm[LT + 1]);
		//break;
	}

	if (LOCAL) fprintf(stderr, "niter=%u\n", niter);
}

int t_in_file;

void Solve() {
	Init();

	if (0&&LS >= 45000 && LS <= 50000 && W > 5000 && abs(LS - LT) <= 1000) {
		DP1(10, 10000);
		DoSwaps2(true);
		return;
	}

	if (LS <= 1000) {
		DP1(10, 10000);
		DoSwaps2(true);//1 <= t_in_file && t_in_file <= 40);
		DP2(20, 0);
		DoSwaps(false);
		MinCostMaxFlow(false);
		return;
	}

	if ((LS >= 9000 && LS <= 10000) || LS >= 90000 /*|| abs(LS - LT) <= 2000*/) DP1(50, 10000);
	DP2(LS <= 1000 ? 20 : 50/*0*/, 0);
	DoSwaps(false);
	MinCostMaxFlow(false);
}

void WriteOutput() {
	printf("%d\n", nbops);
	for (int i = 0; i < nbops; i++)
		if (bops[i].op == 'I') printf("I %d %c\n", bops[i].poz, 'A' + bops[i].ch);
		else if (bops[i].op == 'R') printf("R %d %c\n", bops[i].poz, 'A' + bops[i].ch);
		else if (bops[i].op == 'D') printf("D %d\n", bops[i].poz);
		else if (bops[i].op == 'S') printf("S %d %d\n", bops[i].poz, bops[i].poz2);
}

void CheckSolution() {
	assert(nbops <= LS + LT);
	int rscore = 0;
	for (int i = 0; i < nbops; i++) {
		if (bops[i].op == 'I') {
			rscore += I;
			int ipoz = bops[i].poz;
			char ich = bops[i].ch;
			for (int j = LS; j > ipoz; j--) S[j + 1] = S[j];
			S[ipoz + 1] = ich;
			LS++;
		} else if (bops[i].op == 'R') {
			int rpoz = bops[i].poz;
			char rch = bops[i].ch;
			//assert(R[S[rpoz]][rch] <= I + D);
			rscore += R[S[rpoz]][rch];
			S[rpoz] = rch;
		} else if (bops[i].op == 'D') {
			rscore += D;
			int dpoz = bops[i].poz;
			for (int i = dpoz + 1; i <= LS; i++) S[i - 1] = S[i];
			LS--;
		} else {
			rscore += W;
			int spoz1 = bops[i].poz, spoz2 = bops[i].poz2;
			char tmp = S[spoz1]; S[spoz1] = S[spoz2]; S[spoz2] = tmp;
		}
	}

	assert(LS == LT);
	if (rscore != bsmin) {
		fprintf(stderr, "rscore=%d bsmin=%d\n", rscore, bsmin);
		exit(2);
	}

	for (int i = 1; i <= LS; i++)
		if (S[i] != T[i]) {
			fprintf(stderr, "i=%d Si=%c Ti=%c\n", i, S[i] + 'A', T[i] + 'A');
			exit(1);
		}
}

#define TMAX 80
double base_score[TMAX];

bool ShouldRunTest(int t, int ttype) {
	return ttype == 0;
	return true;
}

int main() {
	ComputeBits();
	if (LOCAL) {
		freopen("scores.txt", "r", stdin);
		for (int t = 0; t < TMAX; t++) {
			int tid;
			double score;
			scanf("%d %lf", &tid, &score);
			base_score[tid] = score;
		}
		freopen("tmp-scores.txt", "w", stdout);
		double total_base_score = 0.0, total_score = 0.0;
		for (int t = 0; t < TMAX; t++) {
			GenerateTest(t);
			int ttype = t < 20 ? 0 : t < 40 ? 1 : t < 60 ? 2 : 3;
			if (!ShouldRunTest(t, ttype)) {
				printf("%d %.9lf\n", t, base_score[t]); fflush(stdout);
				continue;
			}
			clock_t TSTART = clock();
			TEND = TSTART + 1.1 * TIME_LIMIT * CLOCKS_PER_SEC / (ttype == 0 ? 100 : ttype == 1 ? 10 : ttype == 2 ? 2 : 1);
			t_in_file = 1;
			Solve();
			double duration = (double) (clock() - TSTART) / CLOCKS_PER_SEC;
			int LSinit = LS;
			CheckSolution();
			LS = LSinit;
			double score = (double) bsmin / (LS + LT);
			total_base_score += base_score[t];
			total_score += score;
			fprintf(stderr, "### t=%d (%d): LS=%d LT=%d I=%d D=%d W=%d time=%.2lf bsmin=%d sc=%.3lf(%.4lf) trsc=%.4lf\n\n", t, ttype, LS, LT, I, D, W, duration, bsmin, score, 100.0 * base_score[t] / score, 100.0 * total_base_score / total_score);
			printf("%d %.9lf\n", t, score); fflush(stdout);
		}
	} else {
		//freopen("x.txt", "r", stdin);
		clock_t TSTART = clock();
		clock_t RTEND = TSTART + TIME_LIMIT * CLOCKS_PER_SEC;
		int T;
		scanf("%d", &T);
		for (t_in_file = 1; t_in_file <= T; t_in_file++) {
			TSTART = clock();
			TEND = (RTEND - TSTART) / (T - t_in_file + 1);
			ReadInput();
			Solve();
			WriteOutput();
		}
	}
	return 0;
}
