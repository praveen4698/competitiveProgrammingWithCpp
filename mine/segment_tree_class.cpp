#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9+7;

class segment_tree{
    
    private:
        class tree_node{

            public:
                int range;
                int a,lazy;
                int left,right;
                tree_node(){
                    a = 0;
                    lazy = 0;
                }

                void assign_leaf(int arg1){
                    a = arg1;
                }

                void merge(tree_node &left,tree_node &right){
                    a = left.a + right.a;
                 }
                 void lazy_update(){

                    return;
                 }
                 void lazy_transfer(){
                      return ;
                 }
                 void add_lazy(int a){

                    return ;
                 }

        };


        vector<tree_node> nodes;
        vector<int> A;
    
    public:
        segment_tree(int n){
            A.resize(n);
            nodes.resize(4*n);
        }

        ~segment_tree(){
           
            A.clear();
            nodes.clear();
        }

        void addvalue(int a){
            A.push_back(a);
        }

        
        void buildtree(int st,int left,int right){
            
            nodes[st].left = left;
            nodes[st].right = right;

            if(left == right ){
                nodes[st].assign_leaf(A[st]);
            }

            int mid = (right + left)>>1;

            buildtree(st<<1,left,mid);
            buildtree(st<<1|1,mid+1,right);

            nodes[st].merge(nodes[st<<1],nodes[st<<1|1]);
        }

        int  querysolver(int st,int left,int right){

            nodes[st].lazy_transfer();
            nodes[st].lazy_update();
        
            if( nodes[st].left > right || nodes[st].right < left){

                // answer not be considered in the query;    
                return 0;
            }

            if( nodes[st].left >= left && nodes[st].right <= right){
                
                return nodes[st].a;
            }

            
            int a = querysolver(st<<1,left,right);
            int b = querysolver(st<<1|1,left,right);
            
            return a+b;

        }

        void query(int left,int right){

            printf("%d\n",querysolver(1,left,right));

        }
        void update(int st,int left,int right,int value){
             

            nodes[st].lazy_transfer();
            nodes[st].lazy_update();


            if( nodes[st].left > right || nodes[st].right < left){

                // answer not be considered in the query;    
                return ;
            }

            if( nodes[st].left >= left && nodes[st].right <= right){
                
                nodes[st].add_lazy(value);
                return ;
            }

            
            update(st<<1,left,right,value);
            update(st<<1|1,left,right,value);
            
            nodes[st].merge(nodes[st>>1],nodes[st>>1|1]);
            return ;


        }


};
int main()
{
    int n = 1;
    segment_tree tree(n);

    return 0;
}
