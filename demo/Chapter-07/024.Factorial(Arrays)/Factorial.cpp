/*
 * 時間：2018/04/16
 * 功能：
 *      輸入 n，計算 n!。
 * 目的：
 *      使用陣列進行大數運算。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    short a[200];
    
    int carry = 0, k, m = 0, i, n;      // m 記錄目前所在位數, carry 記錄該進位的數目。
    
    for(i = 0; i < 200; i++)
        a[i] = 0;
    
    a[m] = 1;
    
    printf("Input n:");
    scanf("%d", &n);
    
    for(k = 2; k <= n; k++){
        for(i = 0; i <= m; i++){
            
            a[i] *= k;
            
            //乘上 k 後，在加上 carry(進位)。
            a[i] += carry;
            
            //先記算 carry 值，如果在最高位(i == m)時又必須進位(carry != 0)時，整個數字會又多一位(m++)。
            if((carry = a[i]/10) != 0 && i == m)
                m++;
            
            //因為十位數已設定給 carry，所以只須留下一位。
            a[i] %= 10;
        }
    }
    
    printf("%d! = ", n);
    
    for(i = m; i >= 0; i--)
        printf("%d", a[i]);
    
    printf("\n");
    
    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input n:50
    50! = 30414093201713378043612608166064768844377641568960512000000000000
    
    ----------------------------------------------  
 */