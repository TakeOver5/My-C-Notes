/*
 * 時間：2018/03/29
 * 功能：
 *      使用 sizeof 運算子，計算資料型態占用的記憶體空間。
 * 目的：
 *      瞭解 sizeof 運算子的使用。
 */

#include <stdio.h>
#include <conio.h>

int main(void){
    
    printf("char = %d bytes\n", sizeof(char));
    printf("int = %d bytes\n", sizeof(int));
    printf("char = %d bytes\n", sizeof(double));
    
    getch();
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------

    char = 1 bytes
    int = 4 bytes
    char = 8 bytes
    
    ----------------------------------------------
    
    心得：
        sizeof 使用上雖像一個函式，但事實上是一個運算子。
 */
