/*
 * 時間：2018/04/11
 * 功能：
 *      亂數產生陣列元素值，根據使用者欲搜尋的關鍵值來搜尋陣列，
 *      如果關鍵值出現，則回傳該索引值，反之關鍵值未出現，則回傳 -1。
 * 目的：
 *      亂數產生陣列元素值。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int search(int [], int, int, int);

int main(void){
    
    const int SIZE = 20;
    int i, nums[SIZE], from = 0, key, ans = 0;
    
    srand(time(NULL));
    
    for(i=0; i < SIZE; i++)
        nums[i] = rand() % 10 + 1;
        
    
    printf("Input search value (1~10) : ");
    scanf("%d", &key);
    
    while(ans != -1){
        ans = search(nums, from, SIZE, key);
        
        if(ans == -1){
            if(!from) 
                printf("%d not found\n", key);
        }
        else{
            printf("%d found at a [%d] = %d\n", key, ans, nums[ans]);
            from = ans + 1;
        }
    }
    
    system("pause");
    return 0;
}

int search(int nums[], int from, int size, int key)
{
    for(int i=from; i<size; i++)
        if(nums[i] == key)
            return i;
    return - 1;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input search value (1~10) : 6
    6 found at a [5] = 6
    6 found at a [6] = 6
    
    ----------------------------------------------  
 */