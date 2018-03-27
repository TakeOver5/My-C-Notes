/*
 * 時間：2018/03/27
 * 功能：
 *      輸出變數至螢幕。
 * 目的：
 *      熟悉 printf() 函式與變數使用。
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i = 10, j = 20;
    printf("This program show how to print variables:\n");
    printf("i = %d, j = %d\n", i, j);
    
    system("pause");
    return 0;
}

/*  
 *  ------------ 在 cmd 的輸出結果 ---------------
 *
 *  This program show how to print variables
 *  i = 10, j = 20
 *
 *  ----------------------------------------------
 */