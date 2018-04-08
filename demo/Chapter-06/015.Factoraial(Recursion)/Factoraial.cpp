/*
 * 時間：2018/04/07
 * 功能：
 *      輸入 n，計算 n!
 * 目的：
 *      遞迴函式的使用。
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
    
    if(n == 1) return 1;
    
    return n * factorial(n-1);
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input n:6
    6! = 720
    
    ----------------------------------------------
    
    心得：
        基本上利用遞迴函式解決一個問題時，程式會較清晰易讀，
        容易呈現自己的想法，但效率會較不佳。
 */
