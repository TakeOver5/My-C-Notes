/*
 * 時間：2018/05/26
 * 功能：
 *      去除字串。
 * 目的：
 *      字串的使用。
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 void exclude(char*, char*);
 
 int main(void){
     
     char str1[] = "what a wonderful world!";
     char str2[] = " wonderful";
     
     
     exclude(str1, str2);
     
     puts(str1);
     
     system("pause");
     return 0;
     
 }
 
 void exclude(char *s1, char *s2){
     
     int i, s2_len = strlen(s2);
     
     //由於過程中由於 s1 長度隨時在改變，所以使用 (int)strlen(s1) - s2_len 檢查 i 是否超過範圍
     //由於 strlen 回傳的值型態為 size_t 不同於 int，所以須經過 (int) 轉型。
     for(i = 0; i < (int)strlen(s1) - s2_len; i++){
         //使用 strncmp 檢查在 s1 中是否有和 s2 相同的部份。
         if(!strncmp(s1 + i, s2, s2_len)){
             //如果有相同，則以後方字串使用 strcpy 函式複製覆蓋。
             strcpy(s1 + i, s1 + i + s2_len);
             i--;
         }
     }
 }
 
 /*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    what a world!
    
    ----------------------------------------------  
 */