/*
 * 時間：2018/11/13
 * 功能：
 *      堆疊的模擬。
 * 目的：
 *      使用單向鏈結串列模擬堆疊。
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} NODE;

NODE *top = NULL;

void push(int);
int pop(void);
void printStack();

int main(void){
    int choice=0, n;
    while(choice != -1){
        printf("1-> push 2-> pop 3-> print stack(from top to bottom)\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("what do you want to push? ");
                    scanf("%d", &n);
                    push(n);
                    break;
            case 2: printf("%d was popped from stack\n", pop());
                    break;
            case 3: printStack();
                    break;
        }
    }
    while(top) pop();
    system("pause");
    return 0;
}

void push(int data){
    NODE *p;
    if((p = (NODE*)malloc(sizeof(NODE))) == NULL){
        fprintf(stderr, "memory not enough!");
        exit(1);
    }
    p->data = data;
    /* p 的下一個節點，指向目前的頂端節點 
       如果是第一筆資料，則指向 NULL 表示末端 */
    p->next = top;
    /* top 表示目前的頂端 */
    top = p;
}

int pop(void){
    NODE tmp;
    if(top == NULL){
        fprintf(stderr, "stack is empty!");
        exit(1);
    }
    /* tmp 等於 *top 指向的資料 */
    tmp = *top;
    /* 釋放 top，但 tmp 資料仍存在，所以不影響 tmp */
    free(top);
    /* top 指向 tmp 的下一個節點 */
    top = tmp.next;
    return tmp.data;
}

void printStack(){
    NODE *tmp = top;
    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

