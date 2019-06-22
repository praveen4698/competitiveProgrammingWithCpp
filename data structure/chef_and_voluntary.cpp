#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            string S;
            cin>>S;
            int x,y,A=0,B=0;
            cin>>x>>y;
            for(char s:S)
            {
                if( s == 'a')
                    A++;
                else
                    B++;
            }
            int ra = A/x;
            int rb = B/y;
            queue<char> ans;
            if( ra > rb)
            {
                if(ra > B)
                {
                    int prev = 0;
                    while(A > 0)
                    {
                        prev++;
                        ans.push('a');
                        A--;
                        if(A > 0 && prev == x)
                        {
                            prev = 0;
                            if( B > 0)
                            {
                                B--;
                                ans.push('b');

                            }
                            else
                            {
                                ans.push('*');
                            }
                        }
                    }
                }
                else
                {
                    if( A%x != 0)
                        ra++;
                    if( B%y != 0)
                        rb++;
                  //  printf("yo\n");
                    while(ra != rb)
                    {
                        //printf("%d %d\n",ra,rb);
                        for(int i=0;i<x;++i)
                        {
                            ans.push('a');
                            A--;
                        }
                        ra--;
                        ans.push('b');
                        B--;
                        if( B == 0)
                            break;
                        rb = B/y;
                        if( B%y != 0)
                            rb++;

                    }
                    int turn = 0;
                    int prev = 0;
                 //   cout<<B;
                    while(A>0 || B>0)
                    {
                        if(turn == 0)
                        {
                            A--;
                            ans.push('a');
                            prev++;
                            if(A == 0)
                            {
                                turn = 1;
                                prev = 0;
                            }

                        }
                        else
                        {
                            B--;
                            ans.push('b');
                            prev++;
                        }
                        if(turn == 0 && prev == x)
                        {
                            turn = 1;
                            prev = 0;
                        }
                        if(turn == 1 && prev == y)
                        {
                            turn = 0;
                            prev = 0;
                        }
                    }
                }
            }
            else if( rb > ra)
            {
                if( rb > A )
                {
                    int prev = 0;
                    while(B > 0)
                    {
                        prev++;
                        ans.push('b');
                        B--;
                        if(B > 0 && prev == x)
                        {
                            prev = 0;
                            if( A > 0)
                            {
                                A--;
                                ans.push('a');

                            }
                            else
                            {
                                ans.push('*');
                            }
                        }
                    }
                }
                else
                {
                   if( A%x != 0)
                        ra++;
                    if( B%y != 0)
                        rb++;
                    while(ra != rb)
                    {
                        for(int i=0;i<y;++i)
                        {
                            ans.push('b');
                            B--;
                        }
                        rb--;
                        ans.push('a');
                        A--;
                        if( A == 0)
                            break;
                        ra = A/x;
                        if( A%x != 0)
                            ra++;
                    }
                    int turn = 0;
                    int prev = 0;
                    while(A>0 || B>0)
                    {
                        if(turn == 0)
                        {
                            B--;
                            ans.push('b');
                            prev++;
                            if(B == 0)
                            {
                                turn = 1;
                                prev = 0;
                            }

                        }
                        else
                        {
                            A--;
                            ans.push('a');
                            prev++;
                        }
                        if(turn == 0 && prev == y)
                        {
                            turn = 1;
                            prev = 0;
                        }
                        if(turn == 1 && prev == x)
                        {
                            turn = 0;
                            prev = 0;
                        }
                    }
                }

            }
            else
            {
                if( A%x != 0)
                    ra++;
                if( B%y != 0)
                    rb++;
                if( ra >= rb)
                {
                    int turn = 0;
                    int prev = 0;
                    while(A>0 || B>0)
                    {
                        if(turn == 0)
                        {
                            A--;
                            ans.push('a');
                            prev++;
                            if(A == 0)
                            {
                                turn = 1;
                                prev = 0;
                            }

                        }
                        else
                        {
                            B--;
                            ans.push('b');
                            prev++;
                        }
                        if(turn == 0 && prev == x)
                        {
                            turn = 1;
                            prev = 0;
                        }
                        if(turn == 1 && prev == y)
                        {
                            turn = 0;
                            prev = 0;
                        }
                    }
                }
                else
                {
                    int turn = 0;
                    int prev = 0;
                    while(A>0 || B>0)
                    {
                        if(turn == 0)
                        {
                            B--;
                            ans.push('b');
                            prev++;
                            if(B == 0)
                            {
                                turn = 1;
                                prev = 0;
                            }

                        }
                        else
                        {
                            A--;
                            ans.push('a');
                            prev++;
                        }
                        if(turn == 0 && prev == y)
                        {
                            turn = 1;
                            prev = 0;
                        }
                        if(turn == 1 && prev == x)
                        {
                            turn = 0;
                            prev = 0;
                        }
                    }
                }
            }


            while(!ans.empty())
            {
                cout<<ans.front();
                ans.pop();
            }
            printf("\n");
        }
        return 0;
    }
