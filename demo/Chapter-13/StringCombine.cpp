/*
 * 時間：2018/10/14
 * 功能：
 *      字串連結。
 * 目的：
 *      根據使用者輸入的字串，動態配置記憶體。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int i=0, j=0;
    char s1[80], s2[80], *p;
    
    /* gets 會取得使用者輸入字串，但不包含 "\n" 
       puts 輸出字串會，會直接進行換行 */
    gets(s1);
    gets(s2);
    
    p = (char*) malloc((strlen(s1)+strlen(s2)+1)*sizeof(char));
    
    /* *(s1+i) = s1[i] */
    while(*(s1+i)){
        *(p+i) = *(s1+i);
        i++;
    }
    
    while(*(s2+j)){
        *(p+i) = *(s2+j);
        i++; j++;
    }
    
    *(p+i) = '\0';
    
    puts(p);
    free(p);
    system("pause");
    
    return 0;
    
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    HaHa
     this is fun
    HaHa this is fun
    
    ----------------------------------------------
*/