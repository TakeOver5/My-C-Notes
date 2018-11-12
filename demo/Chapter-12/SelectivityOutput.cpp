/*
 * 時間：2018/10/12
 * 功能：
 *      檔案選擇性輸入。
 * 目的：
 *      將註解省略輸出，然後打印出其餘程式碼。
 */
#include <stdio.h>
#include <stdlib.h>
int main(void){
    //This will not print !
    char fn[] = "SelectivityOutput.cpp";
    FILE *fp;
    char buf[80];
    fp = fopen(fn, "r");
    
    while(fgets(buf, 80, fp) != NULL){
        int i = 0;
        /* '\0' 是字串的結束符 */
        while(buf[i] != '\0'){
            /* 搜尋註解 // 符號 */
            if((buf[i] == '/' && buf[i+1] == '/') ||
               (buf[i] == '/' && buf[i+1] == '*') ||
               (buf[i] == '*' && buf[i+1] == '/') ||
               (buf[i] == ' ' && buf[i+1] == '*' && buf[i+2] == ' ')){
                /* 把搜尋到的註解符號取代為結束符，
                   這樣輸出到該行時，會直接結束該行 */
                //buf[i] = '\0';
                /* 如果從 i 取代結束符，那麼會造成縮排格式問題，
                   所以需要從 0 開始取代，整行直接結束 */
                buf[0] = '\0';
                //buf[i+1] = '\0';
                break;
            }
            i++;
        }
        /* 將字串輸出至螢幕 */
        fputs(buf, stdout);
    }
    fclose(fp);
    system("pause");
    return 0;
}
/*
 *  ------------ 在 cmd 的輸出結果 ---------------
 *   
 *  該程式執行時，會輸出註解外的程式碼。
 *   
 *  ----------------------------------------------
 */