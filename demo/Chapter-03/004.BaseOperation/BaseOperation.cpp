/*
 * 時間：2018/03/29
 * 功能：
 *      輸入兩正整數，並輸出各式運算結果。
 * 目的：
 *      熟悉基礎運算子與資料型態的轉換。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int x, y;
    printf("Input integers x and y:");
    scanf("%d %d", &x, &y);
    printf("x + y = %d\n", x + y);
    printf("x - y = %d\n", x - y);
    printf("x * y = %d\n", x * y);
    printf("x / y = %f\n", (float)x / y);   //這裡使用資料型態的轉換：(type)variable
    printf("x %% y = %d\n", x % y);         //「%%」符號，此為特殊符號，可打印求餘數符號

    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input integers x and y:23 3
    x + y = 26
    x - y = 20
    x * y = 69
    x / y = 7.666667
    x % y = 2
    
    ----------------------------------------------
 */