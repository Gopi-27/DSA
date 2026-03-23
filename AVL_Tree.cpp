#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    int Ht;
    TreeNode(int v){
        val = v;
        left = NULL;
        right = NULL;
        Ht = 1;
    }
};
int Height(TreeNode* root){
    if(!root)return 0;
    return root->Ht;
}

TreeNode* RightRotate(TreeNode* root){
    TreeNode* temp = root->left;
    TreeNode* shift = root->left->right;
    temp->right = root;
    root->left = shift;
    root->Ht = max(Height(root->left), Height(root->right)) + 1;
    temp->Ht = max(Height(temp->left), Height(temp->right)) + 1;
    return temp;
}

TreeNode* LeftRotate(TreeNode* root){
    TreeNode* temp = root->right;
    TreeNode* shift = root->right->left;
    temp->left = root;
    root->right = shift;
    root->Ht = max(Height(root->left), Height(root->right)) + 1;
    temp->Ht = max(Height(temp->left), Height(temp->right)) + 1;
    return temp;
}

TreeNode* Insert(TreeNode* root,int val){
    if(root == NULL)return new TreeNode(val);

    if(val < root->val)root->left = Insert(root->left,val);
    else if(val > root->val)root->right = Insert(root->right,val);

    root->Ht = max(Height(root->left), Height(root->right)) + 1;
    // balance
    int bal_fac = Height(root->left) - Height(root->right);

    if(bal_fac >= 2){
        // only Right Rotate
        if(val < root->left->val)root = RightRotate(root);
        // Left and Then right rotate
        else{
            root->left = LeftRotate(root->left);
            root = RightRotate(root);
        }
    }else if(bal_fac <= -2){
        if(val > root->right->val)root = LeftRotate(root);
        else{
            root->right = RightRotate(root->right);
            root = LeftRotate(root);
        }
    }
    
    return root;
    
}

TreeNode* InOrderSucc(TreeNode* root){
    if(!root->left)return root;
    return InOrderSucc(root->left);
}

TreeNode* Delete(TreeNode* root,int val){
    if(root == NULL)return NULL;
    if(val < root->val)root->left = Delete(root->left,val);
    else if(val > root->val)root->right = Delete(root->right,val);
    else{
        // no child & one child
        if(!root->left)return root->right;
        if(!root->right)return root->left;
        // two child
        //Find Inorder Successor and Replace
        TreeNode* temp = InOrderSucc(root->right);
        swap(root->val,temp->val);
        root->right = Delete(temp,val);
    }

    root->Ht = max(Height(root->left), Height(root->right)) + 1;

    int bal_fac = Height(root->left) - Height(root->right);

    if(bal_fac >= 2){
        // only Right Rotate
        int left_bal_fac = Height(root->left->left) - Height(root->left->right);
        if(left_bal_fac == 1)root = RightRotate(root);
        else {
            root->left = LeftRotate(root->left);
            root = RightRotate(root);
        }
    }else if(bal_fac <= -2){
        int right_bal_fac = Height(root->right->left) - Height(root->right->right);
        if(right_bal_fac == -1)root = LeftRotate(root);
        else{
            root->right = RightRotate(root->right);
            root = LeftRotate(root);
        }
    }

    return root;
}

void InOrder(TreeNode* root){
    if(!root)return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
    return;
}

int main(){
    TreeNode* root = NULL;
    for(int i = 1; i <= 10; i++)root = Insert(root,i);
    root = Delete(root,6);
    InOrder(root);

}
