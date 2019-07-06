#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    map<char,int> M1,M2;
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            string S,S1;
            cin>>S;
            M1.clear();
            M2.clear();
            for(auto s:S)
                M1[s]++;
            cin>>S1;
            for(auto s:S1)
                M2[s]++;
            int flag = 0;
            if(S.size() == 1)
            {
                printf("B\n");

                flag = 4;
                continue;
            }
            for(int i=0;i<26;++i)
            {
                if(M1[i+'a'] > 1 && M2[i+'a'] == 0)
                {
                    printf("A\n");
                    flag = 2;
                }
                if(flag == 0 &&  M1[i+'a'] > 0 && M2[i+'a'] == 0)
                {
                     flag = 1;

                }
            }
            if( flag == 0)
            {

                printf("B\n");

            }
            else if(flag == 1)
            {
                flag = 0;
                for(int i=0;i<26;++i)
                {
                    if(M2[i+'a'] > 0 && M1[i+'a'] == 0)
                    {
                        flag = 1;
                        M2[i+'a']--;
                        break;
                    }
                }
                if( flag == 0)
                {
                    printf("A\n");

                }
                else
                {
                    printf("B\n");
                }
            }

        }
        return 0;
    }

