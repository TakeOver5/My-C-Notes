/*
 * 時間：2018/05/29
 * 功能：
 *      登入系統的模擬。
 * 目的：
 *      字串的使用。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_user_num(char get[], char acc[][2][10]){
    
    int i;
    for(i = 0; i < 2; i++)
        if(!strcmp(acc[i][0], get))
            return i;
        
    return -1;
    
}

int main(void){
    
    char get[10];
    char acc[][2][10] = {"root", "qkindl", "jack", "iaumew"};
    int user_num;
    
    
    do{
        printf("Login:");
        gets(get);
        user_num = find_user_num(get, acc);
        
        if(user_num != -1){
            printf("Password:");
            gets(get);
            if(!strcmp(get, acc[user_num][1])){
                printf("Welcome ~ %s\n", acc[user_num][0]);
                break;
            }
            else
                printf("Incorrect password\n");
        }
        else
            printf("UnKnown username\n");
    }while(1);
    
    
    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Login:acer
    UnKnown username
    Login:jack
    Password:123
    Incorrect password
    Login:root
    Password:qkindl
    Welcome ~ root
    
    ----------------------------------------------  
 */
 
 /*
    此處使用的三維字元陣列，也可稱為二維的字串陣列，來儲存使用者資料，示意圖如下：
    
    陣列索引 | 使用者名稱[0]        | 密碼[1]
    [0]      | "root" (acc[0][0])   | "qkindl" (acc[0][1])
    [1]      | "jack" (acc[1][0])   | "iaumew" (acc[1][1])
 */