/*
 * 時間：2018/04/01
 * 功能：
 *      輸入一個字元，判斷該字元為大寫英文字母、小寫英文字母或阿拉伯數字。
 * 目的：
 *      熟悉字元變數與 ASCII 碼的使用。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    char ch;
    printf("Input a character:");
    scanf("%c", &ch);
    
    if(ch >= 'a' && ch <= 'z')
        printf("The character is lowercase letter\n");
    else if(ch >= 'A' && ch <= 'Z')
        printf("The character is uppercase letter\n");
    else if(ch >= '0' && ch <= '9')
        printf("The character is Arabic numerals\n");
    else
        printf("Unknown character\n");
    
    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input a character:A
    The character is uppercase letter
    
    ----------------------------------------------
 */