#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};
typedef struct Node Node;

Node* Create_A_Node(int val){
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->data = val;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
Node* Insert(Node* root ,int val){
    if(root == NULL){
       return Create_A_Node(val);
    }
    if(root->data > val){
        root->left = Insert(root->left,val);
        return root;
    }
    root->right = Insert(root->right,val);
    return root;
}
void InOrder(Node* root){
    if(root == NULL)return;
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
    return;
}

int main(){
  // No.of Nodes you want to insert
    int n;
    scanf("%d",&n);
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int val;
        scanf("%d",&val);
        root = Insert(root,val);
    }
  // Checking Wheater tree build correct or not
    InOrder(root);
}
