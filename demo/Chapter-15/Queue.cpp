/*
 * 時間：2018/11/12
 * 功能：
 *      該程式提供 enqueue、dequeue 與 print queue 三個功能。
 * 目的：
 *      使用陣列實現 queue。
 */

#include <stdio.h>
#include <stdlib.h>
#define NUM 100
typedef struct queue{
    int q[NUM];
    int front;
    int rear;
} Queue;
Queue qu;
void printQueue(void);
void enqueue(int);
int dequeue(void);

int main(void){
    int choice = 0, n;
    qu.rear = -1;
    qu.front = -1;
    
    while(choice != -1){
        printf("1-> enqueue 2-> dequeue 3-> print current queue\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("what do you want to enqueue?");
                    scanf("%d", &n);
                    enqueue(n);
                    break;
            case 2: n = dequeue();
                    if(n != -1)
                        printf("%d was dequeued from queue\n", n);
                    break;
            case 3: printQueue();
                    break;
        }
        printf("rear = %d, front = %d\n", qu.rear, qu.front);
    }
    return 0;
}

/* 加入佇列 */
void enqueue(int n){
    /* 如果 rear 等於陣列大小，表示已滿 */
    if(qu.rear == NUM -1){
        fprintf(stderr, "queue is full!\n");
        return;
    }
    else
        /* 越先加入的資料，就會在陣列前面 
           而 rear 會永遠在 front 後面 */
        qu.q[++qu.rear] = n;
}

/* 取出佇列 */
int dequeue(void){
    /* 如果 front == rear 表示佇列已空 */
    if(qu.front == qu.rear){
        fprintf(stderr, "queue is empty!\n");
        return -1;
    }
    else
        /* 從前面的資料開始回傳，隨後 front ++ */
        return qu.q[++qu.front];
}

void printQueue(void){
    int i;
    /* 由於當前 front 已取出元素，
       所以打印資料要從下一個 front 開始打印 */
    for(i = qu.front+1; i <= qu.rear ; i++)
        printf("%d ", qu.q[i]);
    printf("\n");
}