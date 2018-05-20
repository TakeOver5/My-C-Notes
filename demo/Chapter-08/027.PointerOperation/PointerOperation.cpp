/*
 * 時間：2018/04/21
 * 功能：
 *      輸出 ptr 的位址。
 * 目的：
 *      指標的運算，指標只有 +、-、++、-- 等運算子可使用。
 *      加減意義為：將指標往前(後)移動 n 個該型態的記憶體。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int *ptr, x;
    
    ptr = &x;
    printf("ptr = %X\n", ptr);
    
    //指標 ptr 將指向變數 x 後的 4 個 byte
    ptr++;
    printf("ptr++ = %X\n", ptr);
    
    //指標 ptr 將指向變數 x 後的 20*4 個 byte
    ptr += 20;
    printf("ptr + 20 = %X\n", ptr);
    
    //指標 ptr 將指向變數 x 前的 4 個 byte
    ptr--;
    printf("ptr-- = %X\n", ptr);
    
    //指標 ptr 將指向變數 x 前的 20*4 個 byte
    ptr -= 20;
    printf("ptr - 20 = %X\n", ptr);
    
    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    ptr = 28FF38
    ptr++ = 28FF3C
    ptr + 20 = 28FF8C
    ptr-- = 28FF88
    ptr - 20 = 28FF38
    
    ----------------------------------------------  
 */