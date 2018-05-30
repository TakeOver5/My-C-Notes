/*
 * 時間：2018/05/21
 * 功能：
 *      編碼加密與解密。
 * 目的：
 *      字串的使用。
 */
 
#include <stdio.h>
#include <stdlib.h>

char* encode(char *);
char* decode(char *);

int main(void){
    
    char ch, str[80];
    printf("Input a string:");
    
    gets(str);
    
    printf("You want 1)encdoe 2)decode:");
    scanf("%c", &ch);
    
    if(ch == '1'){
        puts("After encode:");
        puts(encode(str));
        
    } else if(ch == '2'){
        puts("After decoed:");
        puts(decode(str));
        
    } else
        puts("Unknown input");
    
    system("pause");
    return 0;
}

char* encode(char *str){
    char *r = str;
    while(*str){
        *str += 13;
        str++;
    }
    
    return r;
}

char* decode(char *str){
    
    char *r = str;
    while(*str){
        *str = *str - 13;
        str++;
    }
    
    return r;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input a string:993ha
    You want 1)encdoe 2)decode:1
    After encode:
    FF@un
    
    Input a string:FF@un
    You want 1)encdoe 2)decode:2
    After decoed:
    993ha
    
    ----------------------------------------------  
 */