/*
 * 時間：2018/04/03
 * 功能：
 *      輸入 n，計算費氏數列的第 n 項。
 * 目的：
 *      練習遞迴函式。
 */

#include <stdio.h>
#include <stdlib.h>

int f(int);

int main(void){
    
    int n;
    
    printf("Input n:");
    scanf("%d", &n);
    
    printf("f(%d) = %d\n", n, f(n));
    
    system("pause");
    return 0;
    
}

int f(int n){
    
    //費氏數列公式：f(n) = f(n-1) + f(n-2)
    
    if(n == 1 || n == 2)
        return 1;
    
    return f(n-1) + f(n-2);
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input n:8
    f(8) = 21
    
    ----------------------------------------------  
 */