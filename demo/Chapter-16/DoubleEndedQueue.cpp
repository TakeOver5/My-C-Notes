/*
 * 時間：2018/11/13
 * 功能：
 *      雙向串列的模擬。
 * 目的：
 *      雙向鏈結串列的應用。
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
} NODE;

NODE *front = NULL;
NODE *rear = NULL;
int flag = 0;

/* 前端置入資料 */
void push_front(int);
/* 後端置入資料 */
void push_rear(int);
/* 前端取出資料 */
int pop_front(void);
/* 後端取出資料 */
int pop_rear(void);
/* 打印 */
void printDeque(void);

int main(void){
    int choice=0, n;
    while(choice != -1){
        printf("1-> push_front 2-> push_rear 3-> pop_front 4-> pop_rear\n");
        printf("5-> printf current deque\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("what do you want to push: ");
                    scanf("%d", &n);
                    push_front(n);
                    break;
            case 2: printf("what do you want to push: ");
                    scanf("%d", &n);
                    push_rear(n);
                    break;
            case 3: printf("%d was popped from deque\n", pop_front());
                    break;
            case 4: printf("%d was popped from deque\n", pop_rear());
                    break;
            case 5: printDeque();
                    break;
        }
    }
    
    /* 釋放記憶體 */
    while(!flag)
        pop_front();
    return 0;
}

void push_front(int data){
    NODE *tmp;
    if(((tmp = (NODE*)malloc(sizeof(NODE))) == NULL)){
        fprintf(stderr, "merroy not enough!");
        exit(1);
    }
    tmp->data = data;
    /* 初始化 */
    if(front == NULL && rear ==NULL){
        rear = tmp;
        front = tmp;
        tmp->prev = NULL;
        tmp->next = NULL;
    }
    else{
        /* 新資料的下一筆資料指向現在的 front */
        tmp->next = front;
        /* 新資料的上一筆資料設定為「NULL」 */
        tmp->prev = NULL;
        /* 令當前 front 的 prev 指向新增的資料 */
        front->prev = tmp;
        /* 令 front 為現在新增的資料 */
        front = tmp;
    }
}

void push_rear(int data){
    NODE *tmp;
    if((tmp = (NODE*)malloc(sizeof(NODE))) == NULL){
        fprintf(stderr, "memory not enough!");
        exit(1);
    }
    tmp->data = data;
    if(front == NULL && rear == NULL){
        rear = tmp;
        front = tmp;
        tmp->prev = NULL;
        tmp->next = NULL;
    }
    else{
        tmp->prev = rear;
        tmp->next = NULL;
        rear->next = tmp;
        rear = tmp;
    }
}

int pop_front(void){
    int tmp = front->data;
    if(flag == 1){
        fprintf(stderr, "deque is empty!");
        exit(1);
    }else{
        if(front == rear){
            flag = 1;
            free(front);
            front = NULL;
            rear = NULL;
            return tmp;
        }
        else{
            /* 讓當前 front 指向下一筆資料 */
            front = front->next;
            /* 釋放取出資料的 front 記憶體*/
            free(front->prev);
            /* 令當前 front 的 prev 指向 NULL */
            front->prev = NULL;
            return tmp;
        }
    }
}

int pop_rear(void){
    int tmp = rear->data;
    if(flag == 1){
        fprintf(stderr, "deque is empty");
        exit(1);
    }else{
        if(front == rear){
            flag = 1;
            free(rear);
            front = NULL;
            rear = NULL;
            return tmp;
        }
        else{
            rear = rear->prev;
            free(rear->next);
            rear->next = NULL;
            return tmp;
        }
    }
}

void printDeque(void){
    NODE *tmp = front;
    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}