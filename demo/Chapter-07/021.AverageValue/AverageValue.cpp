/*
 * 時間：2018/04/09
 * 功能：
 *      輸入 5 個數字，儲存在陣列中，之後計算平均值。
 * 目的：
 *      一維陣列的應用。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int i, nums[5], total = 0;
    
    for(i=0; i<5; i++){
        printf("Input nums[%d] number:", i);
        scanf("%d", &nums[i]);
    }
    
    for(i=0; i < 5; i++)
        total += nums[i];
    
    printf("Average value = %f\n", (double)total/5);
    
    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input nums[0] number:10
    Input nums[1] number:20
    Input nums[2] number:30
    Input nums[3] number:40
    Input nums[4] number:50
    Average value = 30.000000
    
    ----------------------------------------------  
 */