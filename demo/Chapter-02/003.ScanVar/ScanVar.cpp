/*
 * 時間：2018/03/28
 * 功能：
 *      輸入整數並輸出至螢幕。
 * 目的：
 *      瞭解 scanf() 函式的使用。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    printf("Input a integer:");
    scanf("%d", &i);
    printf("The integer you give us is %d\n", i);
    system("pause");
    return 0;
}

/*  
 *  ------------ 在 cmd 的輸出結果 ---------------
 *
 *  Input a integer:10
 *  The integer you give us is 10
 *
 *  ----------------------------------------------
 */