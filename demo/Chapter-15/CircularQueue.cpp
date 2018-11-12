/*
 * 時間：2018/11/12
 * 功能：
 *      環形佇列程式。
 * 目的：
 *      佇列的應用。
 */

#include <stdio.h>
#include <stdlib.h>
#define NUM 6
typedef struct queue{
    int q[NUM];
    int rear;
    int front;
} Queue;

Queue qu;
void printQueue(void);
void enqueue(int);
int dequeue(void);
int main(void){
    
    int choice=0, n;
    qu.rear = 0;
    qu.front = 0;
    while(choice != -1){
        printf("1-> enqueue 2-> dequeue 3-> printf current queue\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("what do you want to enqueue? ");
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
    }
    system("pause");
    return 0;
}

void enqueue(int n){
    /* 當儲存第六筆資料時，rear 會等於 5 
       之後 +1 = 6，接著在利用 NUM(佇列總數)求餘數 
       會得到 0，這樣如此就能開始從陣列第 0 個開始儲存資料 */
    qu.rear = (qu.rear+1) % NUM;
    /* 假設你從未取出佇例元素，那麼 front 為 0，
       這樣當 enqueue 第六筆資料，就會相撞，表示佇列為滿，
       這就是為什麼佇列只能存取 N-1 個元素 */
    if(qu.rear == qu.front){
        fprintf(stderr, "queue is full!\n");
        system("pause");
        exit(1);
    }
    else
        qu.q[qu.rear] = n;
}

int dequeue(void){
    if(qu.front == qu.rear){
        fprintf(stderr, "queue is empty!\n");
        system("pause");
        exit(1);
    }
    else{
        /* 使用與 enqueue 一樣的手法，當 front 超出環型佇列大小時 
           會到陣列開頭 */
        qu.front = (qu.front+1) % NUM;
        return qu.q[qu.front];
    }
}

void printQueue(void){
    int i;
    /* (i + NUM - 1) % NUM 這裡比較特殊，讓 i + NUM -1 最後在求 NUM 餘， 
       便可讓陣列倒著走，而 (i + NUM - 1) % NUM 是向前走 
       只要先加 NUM 在 %NUM 那麼 i 就只會在 0~NUM 範圍裡，
       而加 1 或 -1 只是控制前走或後走 */
       
    /* 堆疊輸出 */
    //for(i=qu.rear; i != qu.front; i=(i+NUM-1)%NUM)
        
    /* 佇列輸出 */
      for(i=(qu.front+1); i != qu.front; i=(i+NUM+1)%NUM)
        printf("%d ", qu.q[i]);
    printf("\n");
}