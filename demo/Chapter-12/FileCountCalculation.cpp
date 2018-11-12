/*
 * 時間：2018/10/11
 * 功能：
 *      檔案的字數計算。
 * 目的：
 *      使用串流。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    FILE *fp;
    char f[10], buf[80];
    
    //輸入檔案名稱
    scanf("%s", f);
    //打印該輸入檔案名稱的檔案
    if((fp = fopen(f, "r")) == NULL) exit(1);
    while(fgets(buf, 80, fp) != NULL)
        fputs(buf, stdout);
    
    printf("\n");
    
    /* 因串流 fp 已經到檔案尾方，
       因此使用 rewind() 函式使 fp 再度指向檔案的開頭，接著計算字數 */
    rewind(fp);
    
    /* 因為使用的是 fscanf() 函式，遇到空白也會停止，
       因此可以達到計算字數的目的。 
       串流遇到空白指向下一個串流(i++)，直到 EOF(end of file) */
    for(i=0;;i++)
        if(fscanf(fp, "%s", buf) == EOF)
            break;
    
    printf("%s 有 %d 個字\n", f, i);
    
    fclose(fp);
    system("pause");
    return 0;
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    Hello.txt
    hello!
    This is a test file for program
    Hello.txt 有 8 個字
    
    ----------------------------------------------
*/