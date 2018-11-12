/*
 * 時間：2018/11/12
 * 功能：
 *      多項式計算。
 * 目的：
 *      佇列的應用。
 */

#include <stdio.h>
#include <stdlib.h>
#define NUM 100
typedef struct queue{
    int q[NUM];
    int rear;
    int front;
} Queue;
Queue qu;
int S(int, int);
void enqueue(int);
int dequeue(void);

int main(void){
    int i, t, n , ans = 0;
    qu.rear = -1;
    qu.front = -1;
    printf("請輸入多項之常數項係數：");
    while(scanf("%d", &n) != EOF){
        enqueue(n);
        printf("請輸入多項式之高一項係數(結束請同時按下 ctrl 鍵和 z 鍵)");
    }
    printf("請輸入變數之值：");
    scanf("%d", &n);
    for(i=0;;i++){
        if(qu.rear != qu.front){
            t = dequeue();
            ans = ans + t * S(n,i);
        }
        else break;
    }
    
    printf("f(%d) = %d\n", n, ans);
    
    return 0;
}

void enqueue(int n){
    if(qu.rear == NUM - 1){
        fprintf(stderr, "queue is full\n");
        return;
    }
    else
        qu.q[++qu.rear] = n;
}

int dequeue(void){
    if(qu.front == qu.rear){
        fprintf(stderr, "queue is empty!\n");
        exit(1);
    }
    else
        return qu.q[++qu.front];
}

int S(int x, int n){
    int i, tmp = x;
    if(n==0) return 1;
    for(i=1; i<n; i++)
        x = x*tmp;
    return x;
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    請輸入多項之常數項係數：1
    請輸入多項式之高一項係數(結束請同時按下 ctrl 鍵和 z 鍵)2
    請輸入多項式之高一項係數(結束請同時按下 ctrl 鍵和 z 鍵)3
    請輸入多項式之高一項係數(結束請同時按下 ctrl 鍵和 z 鍵)^Z
    請輸入變數之值：5
    f(5) = 86
    
    ----------------------------------------------
*/