#include<bits/stdc++.h> 

using namespace std;

int main() {
    string a = "asd";
    vector<string> A;
    A.push_back(a);
    int c = 2;
    char b = static_cast<char>(c);
    cout<<b<<endl;
    A[0].push_back(b);
    cout<<A[0]<<endl;
}