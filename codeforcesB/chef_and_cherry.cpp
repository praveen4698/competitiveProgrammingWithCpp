#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    string S[101];
    int main()
    {
      //  stringstream s;
      //  cin>>s;
        //string s;

        while(1)
        {
            string s;
            getline(cin,s);
            cout<<s.length();
            if( s.length() < 5)
                break;
            int c = 0;
            int a = 0;
            int sh = 0;
            int flag = 0;
            int cr = 5;
            int ar = 5;
            for(int i=0;i<10;++i)
            {
                if(i%2 == 0)
                    cr--;
                else
                    ar--;

                if(i%2 == 0 && s[i] == '1')
                    c++;
                if( i%2 == 1 && s[i] == '1')
                    a++;
                if( c-a > ar)
                {
                    flag =1 ,sh = i+1;
                    break;
                }
                if( a-c > cr)
                {
                    flag = 2,sh = i+1;
                    break;
                }
            }
            if( flag == 0)
            {
                for(int i=10;i<20;++i)
                {
                    if( i%2 == 0 && s[i] == '1')
                        c++;
                    if( i%2 == 1 && s[i] == '1')
                        a++;
                    if( i%2 == 1 && c>a)
                    {
                        flag = 1,sh=i+1;
                        break;
                    }
                    if( i%2 == 1 && a > c)
                    {
                        flag = 2,sh=i+1;
                        break;
                    }

                }
            }
            if( flag == 1)
                cout<<"TEAM-A "<<sh<<endl;
            else if( flag == 2)
                cout<<"TEAM-B "<<sh<<endl;
            else
                cout<<"TIE"<<endl;
        }
        return 0;
    }

