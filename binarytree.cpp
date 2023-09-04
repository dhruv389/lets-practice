#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* right;
    struct Node* left;
    
    Node(int d){
        data=d;
        right=NULL;
        left=NULL;
    }

};
void preoreder(struct Node* root){
    if(root==NULL)  return ;
    cout<<root->data<<" ";
    preoreder(root->left);
    preoreder(root->right);
}

void inoreder(struct Node*root){
    if(root==NULL) return ;
    inoreder(root->left);
    cout<< root->data<<" ";
     inoreder(root->right);
}
void postoreder(struct Node*root){
    if(root==NULL) return ;
    postoreder(root->left);
     postoreder(root->right);
    cout<< root->data<<" ";
}
int height(struct Node* root){
    if(root==NULL) return 0;
    int r= height(root->right);
    int l= height(root->left);
    return 1+max(r,l);
}

int width( struct Node*root ,int &d){
    if(root==NULL)  return 0;
    int l=width(root->left,d);
    int r=width(root->right,d);
     d=max(d,l+r+1);
 return max(l,r)+1;
}
int diameter(struct Node*root){
   int x=0;
 width(root,x);
   return x;
}

int identical(struct Node*root1, struct Node*root2){
   if(root1==NULL ||  root2==NULL) return 1;
   return (root1->data == root2->data) &&   identical(root1->left ,root2->left)  &&  identical(root1->right,root2->right);
}

int main(){
   Node*root1=new Node(1);
     root1->right=new Node(3);
      root1->left=new Node(2);
       root1->left->right=new Node(5);
root1->left->left=new Node(-4);
root1->right->left=new Node(6);
 root1->right->right=new Node(7);
  root1->right->right->right=new Node(70);

  

// // int mx=height(root);
// cout<<diameter(root1);


return 0;
}