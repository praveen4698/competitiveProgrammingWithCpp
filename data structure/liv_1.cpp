#include<bits/stdc++.h>
using namespace std;

int prime[1000001];

void sieve(){
    prime[0] = 1;
    prime[1] = 1;

    for(int i=2; i<=1000000; i++){
        if(!prime[i]){
            for(int j=2; i*j<=1000000; j++)
                prime[i*j] = 1;
        }
    }
}
vector<vector<int> > queue_and_stack (vector<int> A) {
  vector<vector<int> > v;
  vector<int> v1;
  vector<int> v2;

  for(int i=0; i<A.size(); i++){
      if(!prime[A[i]])
         v1.push_back(A[i]);
      else
         v2.push_back(A[i]);
  }

  reverse(v2.begin(),v2.end());
  v.push_back(v1);
  v.push_back(v2);

  return v;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n;
    cin » n;
    vector<int> A(n);
    for(int i_A=0; i_A<n; i_A++)
    {
      cin » A[i_A];
    }

    vector<vector<int> > out_;
    out_ = queue_and_stack(A);
    for(int i_out_=0; i_out_<out_.size(); i_out_++)
    {
      cout « out_[i_out_][0];
      for(int j_out_=1; j_out_<out_[i_out_].size(); j_out_++)
      {
        cout « " " « out_[i_out_][j_out_];
      }
      cout « "\n";
    }
}
