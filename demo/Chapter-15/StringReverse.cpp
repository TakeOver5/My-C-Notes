/*
 * 時間：2018/11/12
 * 功能：
 *      輸入字串，字串會反轉後輸出。
 * 目的：
 *      瞭解堆疊特性。
 */

#include <stdio.h>
#include <stdlib.h>
#define NUM 100
int stack[NUM];
int top = -1;
void push(int);
int pop(void);

int main(void){
    char str[80];
    /* 重複輸入字串直到讀取到結束字串 */
    while(scanf("%s", str) != EOF){
        char *p = str;
        while(*p){
            push(*p);
            p++;
        }
        while(top >= 0)
            printf("%c", pop());
        printf("\n");
    }
    
    return 0;
}

void push(int n){
    if(top == NUM-1){
        fprintf(stderr, "stack is full!");
        return;
    }
    stack[++top] = n;
}

int pop(void){
    if(top == -1){
        fprintf(stderr, "stack is empty!");
        exit(1);
    }
    
    return stack[top--];
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    cool
    looc
    program
    margorp
    
    ----------------------------------------------
*/