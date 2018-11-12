/*
 * 時間：2018/10/11
 * 功能：
 *      檔案複制。
 * 目的：
 *      使用二進位制串流輸出入函式。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    char ch;
    char str[] = "A.txt";
    char dst[] = "B.txt";
    
    FILE *from, *to;
    if((from = fopen(str, "rb")) == NULL) exit(1);
    if((to = fopen(dst, "wb")) == NULL) exit(1);
    
    while(fread(&ch, sizeof(ch), 1, from) != 0)
        fwrite(&ch, sizeof(ch), 1, to);
    
    fclose(from);
    fclose(to);
    
    system("pause");
    return 0;
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    完成後 B.txt 的內容會與 A.txt 一樣。
    
    此程式使用二進位制串流，因此可複製的檔案不限於文字檔
    任何檔案都可適用。
    
    ----------------------------------------------
*/