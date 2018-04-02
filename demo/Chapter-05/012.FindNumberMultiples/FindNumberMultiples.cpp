/*
 * 時間：2018/04/01
 * 功能：
 *      根據使用者輸入兩個整數「num」「mult」，接著印出 1 ~ num 區間 mult 的倍數。
 * 目的：
 *      熟悉 while, break, continue 的應用。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int num, mult;
    
    while(true){
        printf("Input a number set range(Input 0 end program):");
        scanf("%d", &num);
        
        if(num == 0) break;
        
        printf("Input a number set search multiples:");
        scanf("%d", &mult);
        
        for(int i = 1; i <= num; i++){
            
            if(i % mult != 0)
                continue;
            
            printf("%d ", i);
        }
        
        printf("\n");
    }
    
    printf("End of program.");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input a number set range(Input 0 end program):100
    Input a number set search multiples:7
    7 14 21 28 35 42 49 56 63 70 77 84 91 98
    Input a number set range(Input 0 end program):121
    Input a number set search multiples:11
    11 22 33 44 55 66 77 88 99 110 121
    Input a number set range(Input 0 end program):0
    End of program.
    
    ----------------------------------------------
 */