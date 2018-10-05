/*
 * 時間：2018/10/05
 * 功能：
 *      輸入一個數字，判斷是否在 1~10 之間。
 * 目的：
 *      巨集使用。
 */

#include <stdio.h>
#include <stdlib.h>
#define RANGE(a, b, x) (x > a && x < b) ? 1 : 0

int main(void){
    
    
    int x;
    printf("Input a number:");
    scanf("%d", &x);
    
    if(RANGE(0, 10, x))
        printf("%d is between 0 to 10\n", x);
    else
        printf("%d is not between 0 to 10\n", x);
    
    
    system("pause");
    return 0;
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input a number:5
    5 is between 0 to 10
    
    ----------------------------------------------  
*/