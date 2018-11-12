/*
 * 時間：2018/11/12
 * 功能：
 *      後序運算式的計算。
 * 目的：
 *      堆疊的應用。
 */

#include <stdio.h>
#include <stdlib.h>
#define NUM 100
int stack[NUM];
int top = -1;
void push(int);
int pop(void);
int eval(char*);

int main(void){
    char str[80];
    while(1){
        printf("請輸入一個 postfix 運算式：");
        gets(str);
        printf("%s = %d\n", str, eval(str));
    }
    return 0;
}

int eval(char *str){
    char *p = str;
    while(*p){
        if(*p >= '0' && *p <= '9')
            /* 因為字元轉換整數是 ASCII 碼， 
               並不是預期的數字，因此需要減去 '0' ASCII 碼的值 
               0~9 對應在 ASCII 碼裡的 30 ~ 39，
               例如：字元「5」轉換 ASCII 碼是「35」，減去 '0' = 35 - 30 = 5*/
            push(*p-'0');
        else{
            switch(*p){
                case '+': push(pop() + pop());
                          break;
                case '-': push(pop() - pop());
                          break;
                case '*': push(pop() * pop());
                          break;
                case '/': push(pop() / pop());
                          break;
                default : return -1;
            }
        }
        p++;
    }
    return pop();
}

void push(int n){
    if(top == NUM - 1){
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
    
    請輸入一個 postfix 運算式：12+
    12+ = 3
    請輸入一個 postfix 運算式：34-
    34- = 1
    請輸入一個 postfix 運算式：12+3*
    12+3* = 9
    請輸入一個 postfix 運算式：46-3+1*
    46-3+1* = 5
    
    ----------------------------------------------
*/