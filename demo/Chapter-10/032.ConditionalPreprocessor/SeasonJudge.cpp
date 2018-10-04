/*
 * 時間：2018/10/05
 * 功能：
 *      輸入季節單字得到對應的中文翻譯。
 * 目的：
 *      條件編譯練習。
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SPRING "春天"
#define SUMMER "夏天"
#define AUTUMN "秋天"
#define WINTER "冬天"

int main(void){
    
    char str[80];
    printf("Input a season word:");
    scanf("%s", str);
    
    #ifdef SPRING
        if(!strcmp(str, "spring"))
            printf("spring is %s\n", SPRING);
    #endif
    
    #ifdef SUMMER
        if(!strcmp(str, "summer"))printf("%d",!strcmp(str, "summer"));
            printf("summer is %s\n", SUMMER);
    #endif
    
    #ifdef AUTUMN
        if(!strcmp(str, "autumn"))
            printf("autumn is %s\n", AUTUMN);
    #endif
    
    #ifdef WINTER
        if(!strcmp(str, "winter"))
            printf("winter is %s\n", WINTER);
    #endif
    
    system("pause");
    return 0;
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input a season:winter
    winter is 冬天
    
    ----------------------------------------------  
*/