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
const ll mod = 998244353;
struct comp
{
    bool operator() (const pair<int,int>& lhs, const pair<int,int> & rhs) const
    {
        return lhs.first<rhs.second;
    }
};

class Node  
{  
    public: 
    int key;  
    int jobid;
    Node *left;  
    Node *right;  
    int height;  
};  

int max(int a, int b);  

int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
  

int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
/* Helper function that allocates a  
   new node with the given key and  
   NULL left and right pointers. */
Node* newNode(int key, int data)  
{  
    Node* node = new Node(); 
    node->key = key;  
    node->jobid = data;
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; // new node is initially 
                      // added at leaf  
    return(node);  
}  
  
// A utility function to right 
// rotate subtree rooted with y  
// See the diagram given above.  
Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Update heights  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    // Return new root  
    return x;  
}  
  
// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update heights  
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    // Return new root  
    return y;  
}  
  
// Get Balance factor of node N  
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
  
// Recursive function to insert a key 
// in the subtree rooted with node and 
// returns the new root of the subtree.  
Node* insert(Node* node, int key, int jobid)  
{  
    /* 1. Perform the normal BST insertion */
    if (node == NULL)  
        return(newNode(key,jobid));  
  
    if (key < node->key)  
        node->left = insert(node->left, key, jobid);  
    else if (key > node->key)  
        node->right = insert(node->right, key, jobid);  
    else // Equal keys are not allowed in BST  
    {
        cout<<"duplicate key not allowed in BST"<<endl;
        return node;
    }  
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    /* 3. Get the balance factor of this ancestor  
        node to check whether this node became  
        unbalanced */
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, then  
    // there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->key)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  

    return node;  
}  
Node * minValueNode(Node* node)  
{  
    Node* current = node;  
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
} 
  Node* deleteNode(Node* root, int key)  
{  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    // If the key to be deleted is smaller  
    // than the root's key, then it lies 
    // in left subtree  
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
  
    // If the key to be deleted is greater  
    // than the root's key, then it lies  
    // in right subtree  
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
  
    // if key is same as root's key, then  
    // This is the node to be deleted  
    else
    {  
        // node with only one child or no child  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            free(temp);  
        }  
        else
        {  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            Node* temp = minValueNode(root->right);  
  
            // Copy the inorder successor's  
            // data to this node  
            root->key = temp->key;  
  
            // Delete the inorder successor  
            root->right = deleteNode(root->right,  
                                     temp->key);  
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL)  
    return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}  
  
void levelOrder(Node *root)  
{  
    if(root != NULL)  
    {  
          levelOrder(root->left);  
        cout << root->jobid << " "<< root->key<<endl;  
      
        levelOrder(root->right);  
    }  
}  
class cachesystem{
    multiset< pair<int, int > > S;
    map< int, int> M;
    Node *root ;
    public:
    cachesystem() {
        S.clear();
        M.clear();
        root = NULL;
    };

    void add(int data, int jobid){
        if( M.find(jobid) != M.end()){
            cout<<"dublicate jobid";
            return ;
        }
        S.insert({data, jobid});
        //root = insert(root, data, jobid);
        M[jobid] = data;
        
    }
    void remove(int jobid){
        if( M.find(jobid) == M.end() ){
            cout<<"jobid doesn't present";
            return ;
        }
        S.erase({M[jobid],jobid});
        // root = deleteNode(root, M[jobid]);
        M.erase(jobid);

    }

    vector<pair<int,int> > getAll(){
        vector<pair<int,int> > ans;
        for(auto s:S){
            ans.push_back(s);
        }
        // cout<<"Using tree"<<endl;
        // levelOrder(root);
        return ans;
    }
};
int main()
{
    cachesystem A ;
    int query, data;
    // A.add(1,4);
    // A.add(2,3);
    // A.add(0,8);
    while(1) {
        cout<<"query type :"<<endl;
        cin>>query;
        //add
        if( query == 1){
            int data, jobid;
            cout<<"enter data and jobid";
            cin>>data>>jobid;
            A.add(data,jobid);

        }
        else if( query == 2) {
            vector<pair<int,int> > ans = A.getAll();
            for(auto a:ans){
                cout<<"job id "<<a.second<<" data : "<<a.first<<endl;
            }
        }
        else{
            int jobid;
            cout<<"enter job id : ";
            cin>>jobid;
            A.remove(jobid);
        }
    }
    return 0;
}
