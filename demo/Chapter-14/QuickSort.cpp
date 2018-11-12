/*
 * 時間：2018/11/12
 * 功能：
 *      產生 8 個亂數，排序後輸出。
 * 目的：
 *      Quick Sort 使用。
 */

#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) (t = x, x = y, y = t)
#define N 8

void quick_sort(int*, int, int);

int main(void){
    
    int i;
    int list[N] = {8,7,6,5,4,3,2,1};
    quick_sort(list, 0, N-1);
    printf("排序結果：");
    for(i=0; i<N; i++) printf("%d", list[i]);
    
    return 0;
}

void quick_sort(int list[], int left, int right){
    int i, j, pivot, temp;
    
    //確保陣列第一個索引必須小於最後一個索引才會進行快速排序
    if(left < right){
        i = left;
        j = right + 1;
        pivot = list[left];     /* 基準值 pivot 設定為第一筆資料 */
        
        do{
            /* 此迴圈尋找比 pivot 大的資料，找到後令 i 指向該資料 */
            
            do 
                i++;
            while(list[i] < pivot);
            
            /* 此迴圈尋找比 pivot 小的資料，找到後令 j 指向該資料 */
            
            do
                j--;
            while(list[j] > pivot);
         
            /* 若 i 小於 j，就將 i 與 j 所指向的資料交換 */
            if(i < j)
                SWAP(list[i], list[j], temp);
            
        }while(i < j);
        
        /* 若 j 大於 i，就將 list[left]與索引 j 所指向的資料交換 */
        SWAP(list[left], list[j], temp);
        
        /* 遞迴呼叫以 pivot 為中心的左邊資料進行快速排序 */
        quick_sort(list, left, j-1);
        
        /* 遞迴呼叫以 pivot 為中心的右邊資料進行快速排序 */
        quick_sort(list, j+1, right);
    }
}