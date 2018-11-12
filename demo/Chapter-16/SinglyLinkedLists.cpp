/*
 * 時間：2018/11/13
 * 功能：
 *      呈現單向鏈結串列的資料結構。
 * 目的：
 *      單向鏈結串列的應用。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} NODE;

NODE *newnode(void);
void printLists(NODE*);

int main(void){
    
    char choice;
    NODE *head, *tmp;
    /* 建立新節點 */
    head = newnode();
    /* tmp 暫存當前節點 */
    tmp = head;
    printf("請輸入串列第一個元素的值：");
    scanf("%d", &head->data);
    fflush(stdin);
    
    while(1){
        printf("你想加入一個新節點嗎？(y,n)");
        scanf("%c", &choice);
        if(choice == 'n') break;
        
        printf("請輸入欲加入的串列的值：");
        /* 分配下一個節點記憶體 */
        tmp->next = newnode();
        scanf("%d", &tmp->next->data);
        /* tmp 指向目前的下一個節點 */
        tmp = tmp->next;
        fflush(stdin);
    }
    /* 結尾結點指向 NULL 表示結點末尾 */
    tmp->next = NULL;
    printLists(head);
    /* 釋放記憶體 */
    while(head != NULL){
        NODE *tmp;
        tmp = head;
        head = head->next;
        free(tmp);
    }
    system("pause");
    return 0;
}

NODE *newnode(void){
    NODE *p;
    /* 這裡 p 配置記憶體，之後在比較是否為 NULL，表示記憶體空間是否足夠 */
    if((p = (NODE*)malloc(sizeof(NODE))) == NULL){
        fprintf(stderr, "memory not enough!");
        exit(1);
    }
    return p;
}

void printLists(NODE* head){
    NODE *tmp = head;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}