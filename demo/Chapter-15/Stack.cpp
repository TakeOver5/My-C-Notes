/*
 * 時間：2018/11/12
 * 功能：
 *      該程式提供 push、pop、print stack 三個功能。
 * 目的：
 *      使用陣列實現 statc。
 */

#include <stdio.h>
#include <stdlib.h>
#define NUM 100
int stack[NUM];
int top = -1;
void push(int);
int pop(void);
void printfStack(void);

int main(void){
    int choice=0, n;
    while(choice != -1){
        printf("1-> push 2-> pop 3-> print stack(from top to bottom)");
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("what do you want to phsh? ");
                    scanf("%d", &n);
                    push(n);
                    break;
            case 2: printf("%d was popped from stack\n", pop());
                    break;
            case 3: printfStack();
                    break;
        }
    }
    system("pause");
    return 0;
}

void push(int n){
    if(top == NUM - 1){
        fprintf(stderr, "stack is full!");
        exit(1);
    }
    /* 前置 ++ 會在這段程式碼之前，將 top 遞增，stack[top+1] = n */
    stack[++top] = n;
}

int pop(void){
    if(top == -1){
        fprintf(stderr, "sttack is empty!");
        exit(1);
    }
    /* 後置 -- 會優先回傳 stack[top]，之後 top 遞減 */
    return stack[top--];
}

void printfStack(void){
    int i;
    if(top == -1){
        fprintf(stderr, "stack is empty!\n");
    }
    else{
        printf("stack: ");
        for(i=top; i>=0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}