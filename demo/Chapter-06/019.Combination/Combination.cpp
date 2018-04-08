/*
 * 時間：2018/04/07
 * 功能：
 *      輸入 n, r 變數計算 C(n, r) 組合數。
 * 目的：
 *      遞迴函式的使用。
 */

#include <stdio.h>
#include <stdlib.h>

int combination(int, int);

int main(void){
    
    int n, r;
    
    printf("計算組合數 C, 請輸入 n, r:");
    scanf("%d %d", &n, &r);
    printf("C(%d, %d) = %d\n", n, r, combination(n, r));
    
    system("pause");
    
    return 0;
}

int combination(int n, int r){
    
    //當 n < r 或 r < 0 都是不合法的，此時回傳 -1
    if(n < r || r < 0) return -1;
    
    //取相同數目或取 0 種方法都只有一個，所以回傳 1
    if(n == r || r == 0) return 1;
    
    //排列數 C 公式計算：C(n, r) = C(n-1, r) + C(n-1, r-1)
    return combination(n-1, r) + combination(n-1, r-1);
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    計算組合數 C, 請輸入 n, r:9 4
    C(9, 4) = 126
    
    ----------------------------------------------
 */

