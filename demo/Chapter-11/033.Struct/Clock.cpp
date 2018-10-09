/*
 * 時間：2018/10/09
 * 功能：
 *      模擬時鐘。
 * 目的：
 *      time.h 的使用。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    
    time_t t;
    struct tm *Time;
    while(1) {
        /* time()函式可將從 1970 年 0 點 0 分 0 秒至
           目前經過的秒數記錄起來，該函式的引數為 time_t 型態的指標變數 */
        time(&t);
        /* 使用 localtime() 函式將該值傳換為一個 time.h 中定義的結構， 
           再取出結構中的成員來使用，該函式的引數為 time_t 型態的指標變數 */
        Time = localtime(&t);
        /* 取出結構成員 */
        printf("Current time: %02d:%02d:%02d\n", Time->tm_hour, Time->tm_min, Time->tm_sec);
        system("cls");
    }
    return 0;
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    Current time: 15:31:02
    
    ----------------------------------------------
*/