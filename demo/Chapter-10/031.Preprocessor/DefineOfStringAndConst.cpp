/*
 * 時間：2018/10/03
 * 功能：
 *      打印字串。
 * 目的：
 *      練習字串與常數的定義。
 */

#include <stdio.h>
#include <stdlib.h>
#define CPU "Central Processing Unit" //定義字串
#define PI 3.14159 //定義常數

int main(void){
    
    printf("CPU is short for %s\n", CPU);
    printf("π = %f\n", PI);
    
    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    CPU is short for Central Processing Unit
    π = 3.141590
    
    ----------------------------------------------  
*/