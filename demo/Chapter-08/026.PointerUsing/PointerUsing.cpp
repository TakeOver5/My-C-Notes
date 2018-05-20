/*
 * 時間：2018/04/21
 * 功能：
 *      輸出 x 和 ptr 值。
 * 目的：
 *      指標的使用。
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(void){
    // & 取得變數的地址
    // * 間接參考，指使用指標取得某個記憶體的內容。
    
    int *ptr, x = 5;
    
    /* &x 是取 x 位址，(如果沒有 & 那麼就變成取 x 的值)
       讓 x 位址複製到 p，也就是說現在 p 的內容為變數 x 的位址 */
    ptr = &x;
    
    /* 透過 ptr 將 x 的值設為 10 */
    *ptr = 10;
    
    // &x 取得 x 位址 
    printf("x address:%X\n", &x);
    
    // ptr 現在的內容是 x 的位址
    printf("ptr address:%X\n", ptr);
    
    // 輸出 x 的值
    printf("x value:%d\n", x);
    
    // 藉由 * 間接參考，取得現在 ptr 內容位址的值。
    printf("ptr value:%d\n", *ptr);
     
    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    x address:28FF38
    ptr address:28FF38
    x value:10
    ptr value:10
    
    ----------------------------------------------  
 */