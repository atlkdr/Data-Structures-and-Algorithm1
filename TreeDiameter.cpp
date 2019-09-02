#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef struct node{
    int val;
    node *left,*right;
}node;

node* newNode(int val){
    node* temp=new node;
    temp->val=val;
    temp->right=temp->left=NULL;
    return temp;
}
int height(node* temp){
    if(temp==NULL) return 0;
    else{
        return 1+max(height(temp->right),height(temp->left));
    }
}
int diameter(node* root){
    if(root == NULL) return 0;
    else{
        int lheight=height(root->left);
        int rheight=height(root->right);
        int ldiameter=diameter(root->left);
        int rdiameter=diameter(root->right);
        
        return max(lheight+rheight+1,max(ldiameter,rdiameter));
    }
}
int main(){
  node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5);
  cout<<diameter(root)<<endl;
  return 0;
}
