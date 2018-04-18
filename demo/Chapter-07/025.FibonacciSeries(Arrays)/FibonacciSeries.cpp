/*
 * 時間：2018/04/16
 * 功能：
 *      輸入 n，計算第 n 項費氏數列。
 * 目的：
 *      使用陣列計算費氏數列。
 *      利用遞迴求出費氏數列，但求加快速度，
 *      所以將之前已計算完結果儲存在陣列中，當需要此項時，便可在陣列之中找出答案。
 */

#include <stdio.h>
#include <stdlib.h>

int f(int, int[]);

int main(void){
    int cache[50], n;
    
    for(int i = 0; i < 50; i++)
        cache[i] = 0;
    
    printf("Input n:");
    scanf("%d", &n);
    
    //想求出第 n 項值，參數 n 需要 -1，因為陣列 index 從 0 開始 
    printf("f(%d) = %d\n", n, f(n - 1, cache));
    
    system("pause");
    return 0;
}

int f(int n, int cache[]){
    
    /*在計算之前，先尋找 cache[] 陣列中是否已經求出答案，
      如果沒有，則利用 f() 函式求出答案後儲存進陣列，再將答案回傳*/
    if(cache[n] == 0)
        if(n == 0 || n == 1)
            return 1;
        else
            cache[n] = f(n - 1, cache) + f(n - 2, cache);
    
    return cache[n];
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input n:30
    f(30) = 832040
    
    ----------------------------------------------  
 */