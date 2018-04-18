/*
 * 時間：2018/04/10
 * 功能：
 *      輸入 3*3 行列式的每個元素值，之後計算行列式的值。
 * 目的：
 *      二維陣列的使用。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int line[3][3], i, j, ans = 0;
    
    for(int i=0 ; i < 3; i++){
        printf("Input determinant line %d three elements:", i+1);
        scanf("%d %d %d", &line[i][0], &line[i][1], &line[i][2]);
    }
    
    /* 一般法
    ans = line[0][0]*line[1][1]*line[2][2] + \
          line[0][1]*line[1][2]*line[2][0] + \
          line[0][2]*line[1][0]*line[2][1] - \
          line[0][2]*line[1][1]*line[2][0] - \
          line[1][2]*line[2][1]*line[0][0] - \
          line[2][2]*line[0][1]*line[1][0];
    */
    
    // 迴圈      
    for(int i=0; i < 3; i++){
        ans += line[0][i]*line[1][(i+1)%3]*line[2][(i+2)%3] - \
               line[i][2]*line[(i+1)%3][1]*line[(i+2)%3][0];
    }
          
    printf("Ans = %d\n", ans);
    
    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input determinant line 1 three elements:1 0 0
    Input determinant line 2 three elements:0 1 0
    Input determinant line 3 three elements:0 0 1
    Ans = 1
    
    ----------------------------------------------  
 */