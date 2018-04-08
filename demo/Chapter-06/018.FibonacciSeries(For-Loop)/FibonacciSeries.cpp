/*
 * 時間：2018/04/03
 * 功能：
 *      輸入 n，計算費氐數列的第 n 項。
 * 目的：
 *      練習使用迴圈來寫費氏數列。
 */

#include <stdio.h>
#include <stdlib.h>

int f(int);

int main(void){
    
    int n;
    
    printf("Input n:");
    scanf("%d", &n);
    
    printf("f(%d) = %d\n", n, f(n));
    
    system("pause");
    return 0;
    
}

int f(int n){
    
    int i, sum, pre = 0, fi = 1;
    
    for(i = 1; i < n; i++){
        sum = pre + fi;             //加出下一項
        pre = fi;                   //紀錄前一項
        fi = sum;                   //第 i 項
    }
    
    return fi;
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input n:8
    f(8) = 21
    
    ----------------------------------------------  
 */