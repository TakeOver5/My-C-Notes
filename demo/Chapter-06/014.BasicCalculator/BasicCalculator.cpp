/*
 * 時間：2018/04/01
 * 功能：
 *      根據輸入的運算子，呼叫對應的函式，回傳計算結果。
 * 目的：
 *      練習函式的使用。
 */

#include <stdio.h>
#include <stdlib.h>

//函式雛型的宣告
int add(int, int);
int minus(int, int);
int multiply(int, int);
float divide(int, int);

int main(void){
    
    int x, y;
    char choice;
    
    printf("Input a calculation formula:");
    scanf("%d %c %d", &x, &choice, &y);
    
    switch(choice){
        case '+':
            printf("%d + %d = %d\n", x, y, add(x,y));
            break;
        
        case '-':
            printf("%d - %d = %d\n", x, y, minus(x,y));
            break;
        
        case '*':
            printf("%d * %d = %d\n", x, y, multiply(x,y));
            break;
            
        case '/':
            printf("%d / %d = %f\n", x, y, divide(x,y));
            break;
    }
    
    system("pause");
    return 0;
}

int add(int x, int y){
    return x + y;
}

int minus(int x, int y){
    return x - y;
}

int multiply(int x, int y){
    return x * y;
}

float divide(int x, int y){
    return (float)x / y;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input a calculation formula:12-5
    12 - 5 = 7
    
    ----------------------------------------------
 */