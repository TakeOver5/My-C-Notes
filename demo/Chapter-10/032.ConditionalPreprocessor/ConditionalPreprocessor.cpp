/*
 * 時間：2018/10/04
 * 功能：
 *      根據判斷打印字串。
 * 目的：
 *      練習條件式編譯。
 */

#include <stdio.h>
#include <stdlib.h>
#define RICE
#undef NOODLE

int main(void){
    
    #ifdef RICE
        printf("I like rice the best!\n");
    #endif
    
    #ifdef NOODLE
        printf("I like noodle the best!\n");
    #endif
    
    system("pause");
    return 0;
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    I like rice the best!
    
    ----------------------------------------------  
*/