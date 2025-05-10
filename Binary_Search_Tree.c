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
Node* InOrderSucc(Node* root){
    // finding the root which have in the minimum value
    // the minimum always exists in the left part of the tree
    if(root->left == NULL)return root;
    return InOrderSucc(root->left);
}
 
Node* Delete(Node* root,int val){
    // The Node is not found
    if(root == NULL)return root;
    // the value at root is more than than required value so, move left
    if(root->data > val){
        root->left = Delete(root->left,val);
        return root;
    }
    // the value at root is less than than required value so, move right
    if(root->data < val){
        root->right = Delete(root->right,val);
        return root;
    }
    // reached to the required node
        // three Cases
        // 1.NO children
        // 2.ONE children
        // 3.TWO children
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(root->left == NULL || root->right == NULL){
        Node* temp;
        if(root->left == NULL){
                temp = root->right;
        }else{
             temp = root->left;
        }
        free(root);
        return temp;
    }
    Node* temp = InOrderSucc(root->right);
    root->data = temp->data;
    temp = Delete(temp,temp->data);
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
    int val;
    for(int i = 0; i < n; i++){
        scanf("%d",&val);
        root = Insert(root,val);
    }
    // Checking Wheater tree build correct or not
    InOrder(root);
    scanf(" %d",&val);
    root = Delete(root,val);
    // Checking Wheater deletion made correct or not
    printf("\n");
    InOrder(root);
}
