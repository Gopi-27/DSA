#include<stdio.h>
#include<stdlib.h>
struct TNode{
    struct TNode* left;
    int Tdata;
    struct TNode* right;
};
typedef struct TNode TNode;

struct QNode{
    TNode* Qdata;
    struct QNode* next;
};
typedef struct QNode QNode;

struct Queue{
   QNode* Front;
   QNode* Rear;
};
typedef struct Queue Queue;

Queue* Create_A_Queue(){
    Queue* nq = (Queue*)malloc(sizeof(Queue));
    nq->Front = NULL;
    nq->Rear = NULL;
    return nq;
}

void QPush(Queue* Q,TNode* val){
    QNode* nn = (QNode*)malloc(sizeof(QNode));
    nn->Qdata = val;
    nn->next = NULL;
    if(Q->Front == NULL){
        Q->Front = nn;
        Q->Rear = nn;
        return;
    }
    Q->Rear->next = nn;
    Q->Rear = nn;
    return ;    
}

void QPop(Queue* Q){
    if(Q->Front == NULL)return;
    Q->Front = Q->Front->next;
    return;
}

int Qsize(Queue* Q){
    QNode* slow = Q->Front;
    QNode* fast = Q->Front;
    int size = 0;
    while(1){
        size++;
        if(fast == NULL)return (size - 1) * 2;
        if(fast->next == NULL)return (size * 2) - 1;
        slow = slow->next;
        fast = fast->next->next;
    }
    // return 0;
}

QNode* QFront(Queue* Q){
    return Q->Front->Qdata;
}
int Qempty(Queue* Q){
    if(Q->Front == NULL)return 1;
    return 0;
}


int StrNum(char* str){
    int sign = 1;
    int idx = 0;
    if(str[0] == '-' || str[0] == '+'){
        if(str[0] == '-')sign = - 1;
        idx++;
    }
    int num = 0;
    while(str[idx] != '\0'){
        num =(num * 10 ) + (str[idx] - '0');
        idx++;
    }
    return sign * num;
}

char** Convert_To_2D(char* s, int* returnSize){
    char** Ans =(char**)calloc(1000,sizeof(char*));
    for(int i = 0; i < 1000; i++){
        Ans[i] = (char*)calloc(10,sizeof(char));
    }
    int r = 0;
    int row = 0;
    int col = 0;
    while(s[r] != '\0'){
        while(s[r] != ' ' && s[r] != '\0'){
            Ans[row][col] = s[r];
            col++;
            r++;
        }
        if(s[r] == ' '){
            r++;
            row++;
            col = 0;
        }
    }
    *returnSize = row + 1;
    return Ans;
}
TNode* Create_A_TNode(char* s){
    TNode* nn = (TNode*)malloc(sizeof(TNode));
    nn->Tdata = StrNum(s);
    nn->left = NULL;
    nn->right = NULL;
    free(s);
    return nn;
}

TNode* BuildTree(char* s){
    if(strlen(s) == 0 || s[0] == 'N')return NULL;
    int n = 0;
    char** str = Convert_To_2D(s,&n);
    // for(int i = 0; i < n; i++){
    //     printf("%s\n",str[i]);
    // }
    Queue* Q = Create_A_Queue();
    int idx = 0;
    TNode* root = Create_A_TNode(str[idx]);
    // printf("%d\n",root->Tdata);
    QPush(Q,root);
    idx++;
    while( !Qempty(Q) > 0 && idx < n){
        TNode* CurNode = QFront(Q);
        // printf("%d \n",CurNode->Tdata);
        QPop(Q);
        if(str[idx][0] != 'N'){
            CurNode->left = Create_A_TNode(str[idx]);
            QPush(Q,CurNode->left);
        }
        idx++;
        if(idx >= n)break;
        if(str[idx][0] != 'N'){
            CurNode->right = Create_A_TNode(str[idx]);
            QPush(Q,CurNode->right);
        }
        idx++;
    }
    free(s);
    free(str);
    return root;
}

void PostOrder(TNode* root){
    if(root == NULL)return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->Tdata);
    return;
}
void InOrder(TNode* root){
    if(root == NULL)return;
    InOrder(root->left);
    printf("%d ",root->Tdata);
    InOrder(root->right);
    return;
}
void PreOrder(TNode* root){
    if(root == NULL)return;
    printf("%d ",root->Tdata);
    PreOrder(root->left);
    PreOrder(root->right);
    return;
}
void LevelOrder(TNode* root){
    if(root == NULL)return;
    Queue* Q = Create_A_Queue();
    QPush(Q,root);
    while(!Qempty(Q)){
        int len = Qsize(Q);
        for(int i = 0; i < len; i++){
            TNode* CurNode = QFront(Q);
            QPop(Q);
            printf("%d ",CurNode->Tdata);
            if(CurNode->left != NULL)QPush(Q,CurNode->left);
            if(CurNode->right != NULL)QPush(Q,CurNode->right);
        }

    }
    return ;
}

int main(){
    char* str = (char *)calloc(10000,sizeof(char));
    scanf("%[^\n]s",str);
    // printf("%s\n",str);
    TNode* root = BuildTree(str);
    printf("----------------------------------------------------------------------\n");
    printf("****************************** SELECT YOUR ORDER  ********************\n");
    printf("\t\t 1. PRE - ORDER TRANSVERSAL\n");
    printf("\t\t 2. IN - ORDER TRANSVERSAL\n");
    printf("\t\t 3. POST - ORDER TRANSVERSAL\n");
    printf("\t\t 4. LEVEL - ORDER TRANSVERSAL\n");
    printf("-----------------------------------------------------------------------\n");
    int choice;
    scanf("%d",&choice);
    // printf("%d\n",choice);
    switch(choice){
        case 1 :
            printf("PRE - ORDER TRANSVERSAL :\n");
            PreOrder(root);
            break;
        case 2 :
            printf("IN - ORDER TRANSVERSAL : \n");
            InOrder(root);
            break;
        case 3 :
            printf("POST - ORDER TRANSVERSAL :\n");
            PostOrder(root);
            break;
        case 4 :
            printf("LEVEL - ORDER TRANSVERSAL :\n");
            LevelOrder(root);
            break;
        default :
            printf("XXXXX-------- INVALID CHOICE ----------XXXXXX\n");
            break;
    }

    return 0;
}
