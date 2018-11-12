/*
 * 時間：2018/10/15
 * 功能：
 *      產生 30 個亂數，排序後輸出。
 * 目的：
 *      Selection Sort 使用。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t)(t = x, x = y, y = t)

void sort(int[], int);

int main(void){
    
    int i,a[30];
    srand(time(NULL));
    for(i=0;i<30;i++) a[i] = rand() % 100;
    for(i=0;i<30;i++) printf("%d ", a[i]);
    printf("\n");
    sort(a, 30);
    for(i=0;i<30;i++) printf("%d ", a[i]);
    printf("\n");
    
    system("pause");
    return 0;
}

void sort(int a[], int n){
    int i, j, temp, min;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++)
            if(a[j] < a[min])
                min = j;
        SWAP(a[i],a[min],temp);
    }
}