/*
 * 時間：2018/04/07
 * 功能：
 *      輸入 n 設定河內塔層數，最後打印該 n 層河內塔的詳解步驟。
 * 目的：
 *      練習遞迴函式。
 */

#include <stdio.h>
#include <stdlib.h>

void move(int, char, char, char);

int main(void){
    
    int n;
    
    printf("Input n:");
    scanf("%d", &n);
    
    move(n, 'a', 'b', 'c');
    
    
    system("pause");
    return 0;
}

//move 只做 source 搬至 dest（A -> C）

void move(int n, char source, char temp, char dest){
    
    static int times = 0;
    
    if(n == 1){
        times++;
        printf("%2d times: ", times);               //步驟計數。方便邏輯解析，可以與下方輸出合併。
        printf("%c -> %c\n", source, dest);         //從 source 搬至 dest(A -> C)
    }
    else{
        move(n - 1, source, dest, temp);            //從 source 搬至 temp(A -> B)
        move(1, source, temp, dest);                //從 source 搬至 dest(A -> C)
        move(n - 1, temp, source, dest);            //從 temp 搬至 dest(B -> C)      
    }       
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
     1 times: a -> c
     2 times: a -> b
     3 times: c -> b
     4 times: a -> c
     5 times: b -> a
     6 times: b -> c
     7 times: a -> c
    
    ----------------------------------------------  
    
    心得：
        如果不懂可先跳過。
        河內塔不管多少層，永遠只有三步：
            1. 把 n - 1 個盤子，從 A -> B
            2. 把還在 A 柱的最大盤子（因只有一個盤子所以 n = 1），從 A -> C
            3. 在把 n - 1 個盤子，從 B -> C
 */