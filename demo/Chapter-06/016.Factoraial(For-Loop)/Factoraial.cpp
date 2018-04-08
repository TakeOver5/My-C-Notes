/*
 * 時間：2018/04/07
 * 功能：
 *      輸入 n，計算 n!
 * 目的：
 *      使用迴圈計算階乘，比較遞迴函式的執行速度。
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int);

int main(void){
    
    int n;
    printf("Input n:");
    scanf("%d", &n);
    printf("%d! = %d\n", n, factorial(n));
    
    system("pause");
    return 0;
}

int factorial(int n){
    
    int i, fac = 1;
    
    for(i = 1; i <= n; i++)
        fac = fac * i;
    
    return fac;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input n:6
    6! = 720
    
    ----------------------------------------------
    
    心得：
        當 n 值變大，遞迴與非遞迴程式在執行速度上有明顯差異，
        非遞迴方式，其執行效率較高。
 */