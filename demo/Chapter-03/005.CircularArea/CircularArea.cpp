/*
 * 時間：2018/03/29
 * 功能：
 *      給予一個圓半徑計算圓形面積。
 * 目的：
 *      認識常數的使用與宣告。
 */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415   //使用前置處理器定義常數，編譯器看到 PI 關鍵字會以 3.1415 代替

int main(void){
    double r;
    printf("Input a radius:");
    scanf("%lf", &r);
    printf("Circular area = %lf\n", r*r*PI);
    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input a radius:4
    Circular area = 50.264000
    
    ----------------------------------------------
 */