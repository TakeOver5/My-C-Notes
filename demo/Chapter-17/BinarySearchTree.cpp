/*
 * 時間：2018/11/13
 * 功能：
 *      二元搜尋樹的建置。
 * 目的：
 *      二元樹的應用。
 */

#include <stdio.h>
#include <stdlib.h>
#define isleaf(p)(p->lchild == NULL && p->rchild == NULL) ? 1:0
typedef struct node {
    int key;
    struct node* lchild;
    struct node* rchild;
    struct node* parent;
} NODE;
NODE* search(int, NODE*);
NODE* search2(int, NODE*);
void insert(int, NODE**);
void bdelete(int, NODE*);
void inorder(NODE*);
NODE* leftmost(NODE*);
NODE* rightleast(NODE*);

int main(void){
    int choice = 0, n;
    NODE *root = NULL;
    NODE *tmp;
    while(choice != -1){
        printf("1-> search 2-> insert 3-> delete 4-> inorder print\n");
        printf("enter your choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("what do you want to search? ");
                    scanf("%d", &n);
                    tmp = search(n, root);
                    if(tmp == NULL)
                        printf("Not found in BST!\n");
                    else
                        printf("Found in BST\n");
                    break;
            case 2: printf("what do you want to insert? ");
                    scanf("%d", &n);
                    /* 因為可能更改 root 自身，所以需要使用雙重指標 */
                    insert(n, &root);
                    break;
            case 3: printf("what do you want to delete? ");
                    scanf("%d", &n);
                    bdelete(n, root);
                    break;
            case 4: inorder(root);
                    printf("\n");
                    break;
        }
    }
    system("pause");
    return 0;
}
/* 左邊子樹最大的節點，中序立即前行者 */
NODE* leftmost(NODE *p){
    if(p->lchild == NULL)
        return NULL;
    
    /* 欲刪除節點，先往左一步，在一路向右 */
    p = p->lchild;
    
    /* 找到最右邊的元素，這樣會最接近欲刪除的節點 */
    while(p->rchild != NULL)
        p = p->rchild;
    
    /* 範例坑 */
    /* 如果最左邊的元素，左樹存在，則指向它 */
    //if(p->lchild != NULL)
    //p = p->lchild;
    
    return p;
}
/* 右邊子樹最小節點，中序立即後行者 */
NODE* rightleast(NODE *p){
    if(p->rchild == NULL)
        return NULL;
    
    /* 指向刪除節點的右樹 */
    p = p->rchild;
    
    /* 找到最左邊的元素 */
    while(p->lchild != NULL)
        p = p->lchild;
    
    /* 範例坑 */
    /* 如果最右邊的的元素，右樹存在，則指向它 */
    //if(p->rchild != NULL)
    //p = p->rchild;
    
    return p;
}

NODE* search(int key, NODE* p){
    /* 從 root 開始，直到找到 key 值，回傳 p
       或 p 指向 NULL，回傳 NULL */
    while(p){
        if(key == p->key) return p;
        if(key < p->key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;
}

NODE* search2(int key, NODE* p){
    while(p != NULL){
        /* 如果新增資料等於當前 p->key 返回 null */
        if(key == p->key) return NULL;
        /* 如果 key 小於當前 p->key，則可判斷該 key 應置於左樹 
           反之 key 則應置於右樹 */
        if(key < p->key)
            /* 如果左樹節點 == NULL，回傳 p 
               否則當前 p 指向自身的下個左樹節點 */
            if(p->lchild == NULL)
                return p;
            else
                /* p 指向左樹地址 */
                p = p->lchild;
        else
            /* 如果右樹節點 == NULL，回傳 p 
               否則當前 p 指向自身的下個右樹節點 */
            if(p->rchild == NULL)
                return p;
            else
                p = p->rchild;
    }
    return NULL;
}

void bdelete(int key, NODE* p){
    NODE *n = search(key, p);
    /* 如果節點是葉子時 */
    if(isleaf(n)){
        /* 判斷欲刪除的父節點是否大於欲刪除的節點 
           如果父節點 key 值小於刪除 key，
           則可知道該 key 值，存在在左樹中，反之在右樹中 
           根據判斷讓欲刪除的 key 的父節點的左樹或右樹指向 null */
        if(n->parent->key > n->key)
            n->parent->lchild = NULL;
        else
            n->parent->rchild = NULL;
        /* 最後釋放 n 節點 */
        free(n);
        /* 刪除完畢終止函式 */
        return;
    }
    
    /* 如果欲刪除節點左右子樹有一方為空時 */
    
    else{
        /* L 為 N 的中序立即前行者 */
        NODE *l = leftmost(n);
        /* R 為 N 的中序立即後行者 */
        NODE *r = rightleast(n);
        /* S 為欲刪除節點的父節點 */
        NODE *s = n->parent;
        
        /* 如果刪除的節點右鏈結不存在時，執行 */
        /* 右鏈結不存在時，那麼 n 必定只會有一個左鏈結 */
        /* 所以只要考慮指向 n 的左鏈結即可*/
        if(r == NULL){
            /* 判斷 n 節點在左右子樹的哪裡，因為 n 的父子樹 s 可能是使用左右子樹其一指向 n */
            /* 如果 n 在左樹 */
            if(s->lchild == n)
                s->lchild = n->lchild;
            /* 如果 n 在右樹 */
            else
                s->rchild = n->lchild;
            
            /* 因為 P 從樹之中刪除了，如果還有記憶體指向它，它仍會存在，所以 free(p) 釋放它 */
            /* 另外 L R 同理，不過 L R 還需要存在樹中，所以不需要 free，除非 L R 是欲刪除節點本身 */
            free(n);
            return;
        }
        /* 左鏈結不存在時 */
        else if(l == NULL){
            if(s->lchild == n)
                s->lchild = n->rchild;
            else
                s->rchild = n->rchild;
            free(n);
            return;
        }
        
        /*
           欲刪除節點存在雙節點情形
           1. 刪除節點的 key = L 的 key 
           2. 如果 L 還有左鏈結存在，則 L 的父節點指向它，否則為 NULL
           3. 刪除 L 
        */
        
        /* 中序立即前行者，
           當一筆資料 x 插入在 n 的左節點時，可得知 x 比 n 小，
           但 x 越靠近右邊的資料，則會越接近 n 本身，
           這也表示最靠右的資料，為 x 子樹當中最大的節點 */
           
        n->key = l->key;
        
        /* 
           如果 L 仍有左鏈結存在，那麼使用 L 的父節點指向它 
           L 為最右邊的節點，所以 L 必定在父節點的右邊，
           而 L 本身為最右邊的節點，所以如果存在其他節點，必定在自身節點的左邊 
        */
        if(l->lchild != NULL)
            l->parent->rchild = l->lchild;
        else
            l->parent->rchild = NULL;
        
        free(l);
        
        return;
        
        
        /* 中序立即後行者，
           當一筆資料 x 插入在 n 的右節點時，可得知 x 比 n 大，
           但 x 越靠近左邊的資料，則會越接近 n 本身，
           這也表示最靠左的資料，為 x 子樹當中最小的節點 */
        n->key = r->key;
        /* 如果 R 仍有右鏈結存在，那麼使用 R 的父節點指向它 
           R 為最左邊的節點，所以 R 必定在父節點的左邊，
           而 R 本身為最左邊的節點，所以如果存在其他節點，必定在自身節點的右邊 */
        if(r->rchild != NULL)
            r->parent->lchild = r->rchild;
        else
            r->parent->lchild = NULL;
        
        free(r);
        
        return;
    }
    
}

void insert(int key, NODE **p){
    NODE *n, *tmp;
    //尋找 key 該放置的節點位置
    tmp = search2(key, *p);
    /* tmp 為 NULL 的情況，只有第一筆資料插入，或插入的資料的重複
       *p == NULL 的情況，只有第一筆資料插入時。 */
    if(tmp != NULL || *p == NULL){
        n = (NODE*)malloc(sizeof(NODE));
        n->key = key;
        n->parent = NULL;
        n->lchild = NULL;
        n->rchild = NULL;
        /* 如果當前 *p 不是第一筆插入資料(root 建立)，則進入 */
        if(*p != NULL){
            /* 判斷插入資料，是否小於搜尋到的節點值，
               根據判斷令 tmp 左樹或右樹指向 n 
               之後令 n 的父節點指向 tmp */
            if(key < tmp->key){
                tmp->lchild = n;
                n->parent = tmp;
            }
            else{
                tmp->rchild = n;
                n->parent = tmp;
            }
        }
        else
            /* 間接參照 */
            *p = n;
    }
}

/* 中序走訪 */
void inorder(NODE* p){
    if(p != NULL){
        inorder(p->lchild);
        printf("%d ", p->key);
        inorder(p->rchild);
    }
}