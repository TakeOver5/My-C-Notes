/*
 * 時間：2018/04/01
 * 功能：
 *      輸入一個 n 整數，計算最接近 n 之根號值的整數。
 * 目的：
 *      練習函式的使用。
 */

#include <stdio.h>
#include <stdlib.h>

int SQRT(int);                  //函式雛型的宣告

int main(void){
    
    int n;
    printf("Input n:");
    scanf("%d", &n);
    
    printf("%d\n", SQRT(n));
    
    system("pause");
    return 0;
}

int SQRT(int n){
    
    int i;
    
    if(n < 1) return -1;        /* error input */
    
    for(i = 1; i < n; i++)
        if(i*i > n) break;      /* i 已經超過 n^(1/2) */
    
    /*利用三元運算子，判斷 i 平方 與 i-1 平方誰較接近 n，
      如果判斷為真，即 i*i-n 的值較小，較接近 n，則傳回 i；否則，則傳回 i-1*/
    
    return (i*i - n) < (n - (i-1)*(i-1)) ? i : i-1;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input n:57
    8
    
    ----------------------------------------------
    
    心得：
        呼叫一個函式之前，必須先宣告該函式的函式雛型，才能呼叫。
        不然就是將函式定義在 main 函式之前。
 */