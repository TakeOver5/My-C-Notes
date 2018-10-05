/*
 * 時間：2018/10/05
 * 功能：
 *      輸入三個數字，判斷三個數字中的最大數字。
 * 目的：
 *      巨集使用。
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b, c) (a > b) ? (a > c) ? a : c : (b > c) ? b : c

int main(void){
    
    int x, y, z;
    
    printf("Input three numbers:");
    scanf("%d %d %d", &x, &y, &z);
    
    printf("The maximum value in %d, %d and %d is %d\n", x, y, z, MAX(x, y, z));
    
    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input three numbers:9 12 31
    The maximum value in 9, 12 and 31 is 31
    
    ----------------------------------------------  
*/