/*
 * 時間：2018/11/13
 * 功能：
 *      佇列的模擬。
 * 目的：
 *      使用單向鏈結串列模擬佇列。
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    /* 上一節點 */
    struct node *prev;
    /* 下一節點 */
    struct node *next;
} NODE;

int flag;

/* 最後一個被新增的資料都會指向這個指標 */
NODE *front = NULL;

/* 每次準備 dequeue 的資料都會指向這個指標 */
NODE *rear = NULL;
void enqueue(int);
int dequeue(void);
void printQueue(void);

int main(void){
    int choice=0, n;
    while(choice != -1){
        printf("1-> enqueue 2-> dequeue 3-> printf current queue\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("what do you want to enqueue? ");
                    scanf("%d", &n);
                    enqueue(n);
                    break;
            case 2: n = dequeue();
                    printf("%d was dequeued from queue\n", n);
                    break;
            case 3: printQueue();
                    break;
        }
    }
    
    system("pause");
    return 0;
}

void enqueue(int data){
    NODE *tmp;
    if((tmp = (NODE*)malloc(sizeof(NODE))) == NULL){
        fprintf(stderr, "memory not enough!");
        exit(1);
    }
    
    /* 第一筆資料建置，每一次準備 pop 的資料都會指向 rear */
    if(front == NULL && rear == NULL)
        rear = tmp;
    
    /* 如果是第一筆後的資料建置，
       那麼將上一筆資料的 prev 指向當前建置資料地址 */
    if(front != NULL)
        front->prev = tmp;
    
    tmp->prev = NULL;
    tmp->data = data;
    tmp->next = front;
    front = tmp;
}

int dequeue(void){
    /* tmp 存取當前 rear 的 data */
    int tmp = rear->data;
    if(flag == 1){
        fprintf(stderr, "queue is empty!\n");
        exit(1);
    }
    else{
        if(front == rear){
            flag = 1;
            free(rear);
            return tmp;
        }
        /* 當前 rear 指向上一筆資料地址 */
        rear = rear->prev;
        /* 隨後釋放 rear 的下一筆資料的記憶體 */
        free(rear->next);
        /* 當前 rear 的下一筆資料地址為「NULL」*/
        rear->next = NULL;
        return tmp;
    }
}

void printQueue(void){
    NODE *tmp = front;
    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}