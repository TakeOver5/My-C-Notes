/*
 * 時間：2018/10/05
 * 功能：
 *      計算圓的面積、周長和體積。
 * 目的：
 *      練習字串與常數的定義與條件編譯。
 */

#include <stdio.h>
#include <stdlib.h>
#define round
#define volume
#define R(r) (double)2*(r)*3.1415
#define A(r) (double)(r)*(r)*3.1415
#define V(r) (double)4/3*(r)*(r)*(r)*3.1415

int main(void){
    
    int r;
    printf("Input a radius:");
    scanf("%d", &r);
    
    /* #if defined = #ifdef 
       也可使用 #if !(defined round) 取代 */
    #if defined round
        printf("%lf\n", R(r));
    #endif
    
    #if defined area
        printf("%lf\n", A(r));
    #endif
    
    #if defined volume
        printf("%lf\n", V(r));
    #endif
    
    system("pause");
    return 0;
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input a radius:4
    25.132000
    268.074667
    
    ----------------------------------------------  
*/