/*
 * 時間：2018/10/15
 * 功能：
 *      產生 30 個亂數，排序後輸出。
 * 目的：
 *      Insertion Sort 使用。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int[], int);

int main(void){
    
    int i, a[30];
    srand(time(NULL));
    for(i=0;i<30;i++) a[i] = rand()%100;
    for(i=0;i<30;i++) printf("%d ", a[i]);
    printf("\n");
    sort(a, 30);
    for(i=0;i<30;i++) printf("%d ", a[i]);
    printf("\n");
    system("pause");
    return 0;
}

void sort(int a[], int n){
    int i, j, now;
    /* 從第二張撲克牌開始和其他前面的撲克牌比較大小 */
    for(i=1;i<n;i++){
        /* now 就像每次拿到的新撲克牌 */
        now = a[i];
        /* 第二個迴圈就像之前拿到且已經排序的撲克牌 */
        for(j=i-1;j>=0 && now < a[j];j--)
            /* 若新撲克牌比較小，就將之前的撲克牌往後移 */
            a[j+1] = a[j];
        /* 最後將空下來的位置讓給新撲克牌 */
        a[j+1] = now;
    }
}