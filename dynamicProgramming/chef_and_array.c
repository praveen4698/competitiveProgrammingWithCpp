#include <stdio.h>

#define NMAX 1111

int A[NMAX][NMAX], sum[NMAX][NMAX];
int M, N;

void ReadInput() {
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &A[i][j]);
}

void ComputePrefixSums() {
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			sum[i][j] += A[i][j];
		}
}

int rowmax[NMAX][NMAX], dq[NMAX][2], dqli, dqls;

void ProcessQueries() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int a, b, ans = -1;
		scanf("%d %d", &a, &b);
		// Find max elements in b-length interval along rows.
		for (int i = 1; i <= M; i++) {
			dqli = 0; dqls = -1;
			for (int j = 1; j <= N; j++) {
				while (dqli <= dqls && dq[dqls][0] < A[i][j]) dqls--;
				dqls++;
				dq[dqls][0] = A[i][j];
				dq[dqls][1] = j;
				if (j >= b) {
					while (dq[dqli][1] < j - b + 1) dqli++;
					rowmax[i][j] = dq[dqli][0];
				}
			}
		}
		// Find max elements in axb-matrices along columns.
		for (int j = b; j <= N; j++) {
			dqli = 0; dqls = -1;
			for (int i = 1; i <= M; i++) {
				while (dqli <= dqls && dq[dqls][0] < rowmax[i][j]) dqls--;
				dqls++;
				dq[dqls][0] = rowmax[i][j];
				dq[dqls][1] = i;
				if (i >= a) {
					while (dq[dqli][1] < i - a + 1) dqli++;
					//fprintf(stderr, "a=%d b=%d i=%d j=%d: max=%d sum=%d\n", a, b, i, j, dq[dqli][0], sum[i][j] - sum[i - a][j] - sum[i][j - b] + sum[i - a][j - b]);
					int cans = a * b * dq[dqli][0] - (sum[i][j] - sum[i - a][j] - sum[i][j - b] + sum[i - a][j - b]);
					if (ans < 0 || cans < ans) ans = cans;
				}
			}
		}
		printf("%d\n", ans);
	}
}

int main() {
	//freopen("x.txt", "r", stdin);
	ReadInput();
	ComputePrefixSums();
	ProcessQueries();
	return 0;
}
