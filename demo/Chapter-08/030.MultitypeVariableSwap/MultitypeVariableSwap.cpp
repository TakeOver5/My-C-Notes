/*
 * 時間：2018/04/23
 * 功能：
 *      多型變數交換。
 * 目的：
 *      練習指標操作。
 */
 
#include <stdio.h>
#include <stdlib.h>

void swap(void *, void *, int);

int main(void){
    
    int a = 252117761, b = 666;
    double c = 3, d = 6;
    swap(&a, &b, sizeof(int));
    swap(&c, &d, sizeof(double));
    
    printf("a = %d, b = %d\n", a, b);
    printf("c = %lf, d = %lf\n", c, d);

    system("pause");
    return 0;
}

void swap(void *x, void *y, int size){
    
    int i;
    
    char *p = (char *)x;    //將 void 指標型態轉換為 char 指標型態
    char *q = (char *)y;
    char temp;
    
    /* 因為指標已經被轉型為 char 型態，
       char 型態只占 1 byte，所以 i++ 時，也只會前進 1 byte */ 
    for(i = 0; i < size; i++, p++, q++){   
        
        temp = *p;
        *p = *q;
        *q = temp;
        
    }
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    a = 666, b = 252117761
    c = 6.000000, d = 3.000000
    
    ----------------------------------------------  
 */