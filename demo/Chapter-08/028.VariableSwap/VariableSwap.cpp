/*
 * 時間：2018/04/22
 * 功能：
 *      變數交換。
 * 目的：
 *      練習指標操作。
 */

#include <stdio.h>
#include <stdlib.h>
void swap(int *, int *);

int main(void){
    
    int x = 5, y = 10;
    swap(&x, &y);
    printf("x = %d y = %d\n", x, y);
    
    system("pause");
    return 0;
}

void swap(int *x, int *y){
    
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    x = 10 y = 5
    
    ----------------------------------------------  
 */