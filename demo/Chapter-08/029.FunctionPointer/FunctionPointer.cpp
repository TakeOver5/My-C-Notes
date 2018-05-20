/*
 * 時間：2018/04/22
 * 功能：
 *      計算 x + y。
 * 目的：
 *      練習指標操作。
 */

#include <stdio.h>
#include <stdlib.h>

int add(int, int);

int main(void){
    
    /* 宣告函式指標 p，具有兩個整數引數 */
    int ans, (*p)(int, int);
    
    /* 將 p 指向函式 add */
    p = add;
    
    /* 間接呼叫 add 函式 */
    ans = (*p)(10, 5);
    
    printf("%d\n", ans);
    
    system("pause");
    return 0;
}

int add(int x, int y){
    
    return x + y;
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    15
    
    ----------------------------------------------  
 */