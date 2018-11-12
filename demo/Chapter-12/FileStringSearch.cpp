/*
 * 時間：2018/10/12
 * 功能：
 *      檔案字串的搜尋。
 * 目的：
 *      使用 strstr 函式搜尋字串。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(FILE *, char *);

int main(void){
    char fn[] = "SearchFile.txt";
    
    /* 計數行數 */
    int last = 0;
    char buf[80];
    FILE *fp;
    fp = fopen(fn, "r+");
    
    /* 將要搜尋的字串存入 buf 陣列中 */
    printf("輸入欲搜尋的子字串：");
    scanf("%s", buf);
    
    while(1){
        int line = search(fp, buf);
        if(line)
            printf("%s found in line %d.\n", buf, line + last);
        else 
            break;
        
        last += line;
    }
    
    fclose(fp);
    system("pause");
    return 0;
}

/* 從 fp 的 stream 串流，尋找 s 子字串 */
int search(FILE *fp, char *s){
    int i;
    char buf[80];
    /* fgets 函式，會從串流 stream 內讀取字串，直到遇到「\n」
       或是直到 num 個字元被讀入，之後存入字元陣列 str[buf]
       若函式執行成功，則回傳 str，反之則回傳 NULL */
       
    /* 使用 fgets 函式讀取字串，之後在使用 strstr 函式搜尋字串 
       如果該行字串沒有找到，則（i++）繼續搜尋下一行字串
       只到找到為止，之後回傳 i */
    for(i=1; fgets(buf, 80, fp) != NULL; i++){
        /* char* strstr(const char*, const char*)
           第一個參數是被搜尋字串，第二個參數是想要搜尋的子字串
           如果搜尋到第一個符合的子字串，則傳回符合位置的指標，反之則回傳 NULL */
        if(strstr(buf, s) != NULL)
            return i;
    }
    return 0;
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    > type SearchFile.txt
    to ddd
    rrrrr jijievsl;b
    rverv to gmkmbkgb
    hinhi212 to lmlvfmmvf
    efwfwfwftovfdvdv
    
    ----------------------------------------------
    
    輸入欲搜尋的子字串：to
    to found in line 1.
    to found in line 3.
    to found in line 4.
    to found in line 5.
    
    ----------------------------------------------
*/