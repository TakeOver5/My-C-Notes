/*
 * 時間：2018/10/03
 * 功能：
 *      交換變數。
 * 目的：
 *      使用前置處理器，定義一個巨集，交換兩個變數。
 */

#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) (t = x, x = y, y = t)

int main(void){
    
    int x = 3, y = 4, temp;
    SWAP(x, y, temp);
    printf("x = %d, y = %d\n", x, y);
    system("pause");
    return 0;
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    x = 4, y = 3
    
    ----------------------------------------------  
*/