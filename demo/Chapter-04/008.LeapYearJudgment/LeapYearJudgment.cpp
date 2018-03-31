/*
 * 時間：2018/04/01
 * 功能：
 *      給予一個年份，記算該年份是不閏年。
 * 目的：
 *      認識 if 使用。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int year;
    
    printf("Input a years:");
    scanf("%d", &year);
    
    if(!(year%4)){
        if(!(year%100) && year%400)
            printf("%d not leap\n", year);
        else
            printf("%d is leap\n", year);
    }
    else
        printf("%d not leap\n", year);
    
    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input a years:1996
    1996 is leap
    
    ----------------------------------------------
 */