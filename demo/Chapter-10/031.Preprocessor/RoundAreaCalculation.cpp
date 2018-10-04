/*
 * 時間：2018/10/04
 * 功能：
 *      計算圓面積。
 * 目的：
 *      巨集的使用。
 */

#include <stdio.h>
#include <stdlib.h>
#define A(r) (double)(r)*(r)*3.1415

int main(void){
    
    int r;
    
    printf("Input a radius:");
    scanf("%d", &r);
    printf("%lf\n", A(r));
    
    system("pause");
    return 0;
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input a radius:3
    28.273500
    
    ----------------------------------------------  
*/