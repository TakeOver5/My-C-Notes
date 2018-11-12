/*
 * 時間：2018/11/12
 * 功能：
 *      產生亂數，進行排序，在找到 key 值。
 * 目的：
 *      Binary Search 使用。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) (t=x, x=y, y=t);
#define N 10

void sort(int[], int);
int binsearch(int[], int, int, int);

int main(void){
    int i, a[N], key, result;
    for(i=0;i<N;i++) a[i] = rand() % 100;
    sort(a, N);
    for(i=0;i<N;i++) printf("%d ", a[i]);
    printf("\n");
    printf("欲搜尋的值：");
    scanf("%d", &key);
    
    result = binsearch(a, 0, N-1, key);
    if(result == -1)
        printf("Not found!\n");
    else
        printf("Found in index %d\n", result);
    
    system("pause");
    return 0;
}

void sort(int a[], int n){
    int i, j, temp, min;
    for(i=0; i<n-1; i++){ 
        min = i;
        for(j=i+1; j<n; j++)
            if(a[j] < a[min])
                min = j;
            
        SWAP(a[i], a[min], temp);
    }
}

int binsearch(int a[], int left, int right, int key){
    int middle = (left + right) / 2;
    if(left > right) return -1;
    if(key == a[middle]) return middle;
    else if(key > a[middle]) return binsearch(a, middle+1, right, key);
    else return binsearch(a, left, middle-1, key);
}