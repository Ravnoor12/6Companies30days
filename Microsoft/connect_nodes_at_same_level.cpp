#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;  
    return temp;
}
Node* buildTree(string str)
{   
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

void connect(struct Node *p);
void printSpecial(Node *root)
{
   if (root == NULL)
     return;

   Node* next_root=NULL;

   while (root != NULL)
   {
      cout<< root->data<<" ";

      if( root->left && (!next_root) )
        next_root = root->left;
      else if( root->right && (!next_root)  )
        next_root = root->right;

      root = root->nextRight;
   }
   
   printSpecial(next_root);
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

class Solution
{
    public:
    void connect(Node *root)
    {
      queue<Node*> q;
      q.push(root);
      while(!q.empty()){
          int n = q.size();
          Node* prev = NULL;
          while(n--){
              Node* temp = q.front();
              q.pop();
              if(temp->left) q.push(temp->left);
              if(temp->right) q.push(temp->right);
              if(prev!=NULL) prev->nextRight = temp;
              prev = temp;
          }
          prev->nextRight=NULL;
      }
    }    
      
};

int main()
{
  int t;
  cin>>t;
  fflush(stdin);
  while (t--)
  {
     string s;
     getline(cin, s);
     Node* root = buildTree(s);
        
    Solution obj;
     obj.connect(root);
     printSpecial(root);
     cout<<endl;
     inorder(root);
     cout<<endl;
  }
  return 0;
}