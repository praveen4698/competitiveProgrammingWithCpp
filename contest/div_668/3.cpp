#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
static const int INF = 0x3f3f3f3f;
static const long long int INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long int MOD = 1e9+7;
const long long int  mod = 998244353;


int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        string A;
        cin>>A;
        int actual_zero = 0;
        int actual_one = 0;
        int question_mark = 0;
        for(int i=0;i<k;++i) {
            if( A[i] == '1')
                actual_one++;
            else if( A[i] == '0')
                actual_zero++;
            else 
                question_mark++;

        }

        int question_mark_zero = (question_mark+actual_one-actual_zero)/2;

        int flag = 1;
        if( question_mark_zero < 0 or question_mark_zero > question_mark) {
            flag = -1;
        }
        int question_mark_one = question_mark - question_mark_zero;
        if( flag == 1) {
            for(int i=k;i<n;++i) {
                int j = i-k;
                if( A[i] == A[j]) {
                    continue;
                }
                else if( A[j] == '0') {
                    actual_zero--;
                    if( actual_zero < 0) {
                        flag = -1;
                        break;
                    }
                    if( A[i] == '1') {
                        flag = -1;
                        break;
                    }
                    else {
                        question_mark_zero++;
                    }
                }
                else if( A[j] == '1') {
                    actual_one--;
                    if( actual_one < 0) {
                        flag = -1;
                        break;
                    }
                    if( A[i] == '0') {
                        flag = -1;
                        break;
                    }
                    else {
                        question_mark_one++;
                    }
                }
                else {
                    if( A[i] == '1') {
                        question_mark_one--;
                        actual_one++;
                        if( question_mark_one< 0) {
                            flag = -1;
                            break;
                        }
                    }
                    else if( A[i] == '0') {
                        question_mark_zero--;
                        actual_zero++;
                        if( question_mark_zero < 0) {
                            flag = -1;
                            break;
                        }
                    }
                }

                if( question_mark_zero + actual_zero != actual_one + question_mark_one) {
                    flag = -1;
                    break;
                }
            }
        }

        if( flag == 1) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
