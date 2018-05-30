/*
 * 時間：2018/05/29
 * 功能：
 *      去除字串。
 * 目的：
 *      字串的使用。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    
    int i, len;
    char str[80];
    
    while(1){
        gets(str);
        len = strlen(str);
        
        for(i = 0; i < len/2; i++){
            if(str[i] != str[len - i - 1]){
                printf("%s 不是迴文\n", str);
                break;
            }
        }
        
        if(i >= len/2)
            printf("%s 是回文\n", str);
        
    }
    
    system("pause");
    return 0;
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    apa
    apa 是回文
    12345678
    12345678 不是迴文
    
    ----------------------------------------------  
 */