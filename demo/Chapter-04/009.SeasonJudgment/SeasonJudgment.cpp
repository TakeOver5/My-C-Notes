/*
 * 時間：2018/04/01
 * 功能：
 *      給予一個月份，得出該月份對應的季節。
 * 目的：
 *      認識 switch 使用。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int month;
    printf("Input a month:");
    scanf("%d", &month);
    
    switch(month){
        case 1:
        case 2:
        case 3:
            printf("The month is spring\n");
            break;
            
        case 4:
        case 5:
        case 6:
            printf("The month is summer\n");
            break;
            
        case 7:
        case 8:
        case 9:
            printf("The month is autumn\n");
            break;
        
        case 10:
        case 11:
        case 12:
            printf("The month is winter\n");
            break;
            
        default:
            printf("Error month\n");
            break;
    }
    
    system("pause");
    return 0;
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    Input a month:4
    The month is summer
    
    ----------------------------------------------
 */