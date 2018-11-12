/*
 * 時間：2018/11/12
 * 功能：
 *      二元樹的二種走訪。
 * 目的：
 *      二元樹的應用。
 */

#include <stdio.h>
#include <stdlib.h>
/* i 子樹的左右子樹公式 */
#define lchild(i) 2*i
#define rchild(i) 2*i+1
#define ENUM 13

typedef struct node{
    char data;
    struct node* lchild;
    struct node* rchild;
} NODE;

void preorder(NODE*);
void inorder(NODE*);
void postorder(NODE*);

int main(void){
    int i;
    NODE tree[ENUM+1];
    /* 這裡不像上個範例，把 ENUM/2+1，是因為鏈表特性，
       未端子樹，稱為 leaf，leaf 的左右子樹必須是 NULL 
       這樣才能確保鏈表已經知道該節點是未端。 */
    for(i=1; i<=ENUM; i++){
        /* 樹資料鍵入 
           'a' + i - 1 是因為要符合，二元樹規則，
           但又要符合英文字母，所以才要 -1 補正，否則會從 'b' 開始鍵入 */
        tree[i].data = 'a' + i - 1;
        /* 如果該節點的右樹索引小於等於 ENUM 
           那麼將該節點的 lchild 指向 tree[左樹索引]
           否則指向 NULL */
        if(lchild(i) <= ENUM)
            tree[i].lchild = &tree[lchild(i)];
        else
            tree[i].lchild = NULL;
        /* 如果該節點的左樹索引小於等於 ENUM 
           那麼將該節點的 rchild 指向 tree[右樹索引]
           否則指向 NULL */
        if(rchild(i) <= ENUM)
            tree[i].rchild = &tree[rchild(i)];
        else
            tree[i].rchild = NULL;
    }
    /* 因為二元樹的陣列索引從 1 開始所以 + 1 */
    preorder(tree+1);
    printf("\n");
    inorder(tree+1);
    printf("\n");
    postorder(tree+1);
    printf("\n");
    system("pause");
    return 0;
}

/* 前序 */
void preorder(NODE* p){
    if(p){
        printf("%c", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

/* 中序 */
void inorder(NODE* p){
    if(p){
        inorder(p->lchild);
        printf("%c", p->data);
        inorder(p->rchild);
    }
}
/* 後序 */
void postorder(NODE* p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%c", p->data);
    }
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    abdhiejkcflmg
    hdibjekalfmcg
    hidjkeblmfgca
    
    ----------------------------------------------
*/