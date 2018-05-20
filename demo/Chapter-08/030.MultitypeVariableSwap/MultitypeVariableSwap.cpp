/*
 * 時間：2018/04/23
 * 功能：
 *      多型變數交換。
 * 目的：
 *      練習指標操作。
 */
 
#include <stdio.h>
#include <stdlib.h>

void swap(void *, void *, int, int *, int *);

int main(void){
    
    int a = 252117761, b = 666;
    double c = 3, d = 6;
    printf("a = %p, b = %p\n", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    //printf("c = %p, d = %p\n", &c, &d);
    //printf("c = %lf, d = %lf\n", c, d);
    swap(&a, &b, sizeof(int), &a, &b);
    //swap(&c, &d, sizeof(double));
    printf("a = %p, b = %p\n", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    //printf("c = %p, d = %p\n", &c, &d);
    //printf("c = %lf, d = %lf\n", c, d);

    system("pause");
    return 0;
}

void swap(void *x, void *y, int size, int *a, int *b){
    
    int i;
    
    char *p = (char *)x;    //將 void 指標型態轉換為 char 指標型態
    char *q = (char *)y;
    char temp;
    
    /* 因為指標已經被轉型為 char 型態，
       char 型態只占 1 byte，所以 i++ 時，也只會前進 1 byte */ 
    for(i = 0; i < size; i++, p++, q++){   
    
        printf("----- %d -----\n", i);
        printf("a = %d, b = %d\n", *a, *b);
        
        temp = *p;
        *p = *q;
        *q = temp;
        
        printf("temp = %d, *p = %d, *q = %d\n", temp, *p, *q);
    }
    
    printf("---------------\n");
}