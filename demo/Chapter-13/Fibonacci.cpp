/*
 * 時間：2018/10/14
 * 功能：
 *      費氏數列計算。
 * 目的：
 *      根據使用者輸入的 n 值，動態配置 n 個元素的記憶體。
 */

#include <stdio.h>
#include <stdlib.h>

int f(int, int[]);

int main(void){
    int i, n, *cache;
    scanf("%d", &n);
    cache = (int*) malloc(n*sizeof(int));
    
    for(i=0;i<n;i++)
        cache[i] = 0;
    printf("f(%d) = %d\n", n, f(n-1, cache));
    free(cache);
    system("pause");
    return 0;
}

int f(int n, int cache[]){
    
    if(cache[n] == 0)
        if(n==0 || n==1)
            return 1;
        else
            cache[n] = f(n-1, cache) + f(n-2, cache);
        
    return cache[n];
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    10
    f(10) = 55
    
    ----------------------------------------------
*/