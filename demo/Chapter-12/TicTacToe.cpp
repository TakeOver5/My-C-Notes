/*
 * 時間：2018/10/11
 * 功能：
 *      井字遊戲。
 * 目的：
 *      輸入與輸出的使用。
 */

#include <stdio.h>
#include <stdlib.h>
int compare(char, char, char);

int main(void){
    int i, j, num;
    char table[3][3], ch;
    
    /* 3*3 棋盤初始化，用於記錄當前格子的狀態('O','X',' ') */
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            table[i][j] = ' ';
        
    /* 計算子數 */
    for(i=0;;i++){
        /* 當前棋盤打印 */
        for(j=0;j<3;j++){
            printf("+-+-+-+\n");
            printf("|%c|%c|%c|\n", table[j][0], table[j][1], table[j][2]);
        }
        printf("+-+-+-+\n");
        
        //根據 i 值，計算輪到 A 或 B 的階段
        ch = !(i%2) ? 'A' : 'B';
        printf("User %c 階段：", ch);
        
        //輸入一個整數，對應該數的格子下子
        scanf("%d", &num);
        if(table[num/3][num%3-1] == ' ')
            table[num/3][num%3-1] = !(i%2) ? 'O' : 'X';
        else{
            printf("已經下過了！");
            //回溯上一步
            i--;
            continue;
        }
        
        /* 當子大於等於 5 個時，就可以開始嘗試判斷勝負 */
        if(i>4)
            for(j=0;j<3;j++){
                /* 列舉所有獲勝的可能，如果 compare 函式回傳 1 表示某玩家獲勝 */
                if(compare(table[j][0], table[j][1], table[j][2]) ||
                   compare(table[0][j], table[1][j], table[2][j]) ||
                   compare(table[0][0], table[1][1], table[2][2]) ||
                   compare(table[2][0], table[1][1], table[0][2])){
                        //打印獲勝棋盤
                        for(j=0;j<3;j++){
                            printf("+-+-+-+\n");
                            printf("|%c|%c|%c|\n", table[j][0], table[j][1], table[j][2]);
                        }
                        printf("+-+-+-+\n");
                        
                        printf("User %c 獲勝！\n", ch);
                        //將 j 設為 -1，表示遊戲結束
                        j = -1;
                        break;
                   }
            }
        
        //當 j 為 -1 時，表示遊戲結束，跳出該迴圈
        if(j == -1) break;
        
        //當子為 8 個時，表示平手，遊戲結束
        if(i == 8){
            //打印平手棋盤
            for(j=0;j<3;j++){
                printf("+-+-+-+\n");
                printf("|%c|%c|%c|\n", table[j][0], table[j][1], table[j][2]);
            }
            printf("+-+-+-+\n");
            printf("平手！\n");
            break;
        }
    }
    
    system("pause");
    return 0;
}

/* 傳入三個字元，判斷三者是否相同，且並不為空白字元，
   若相同回傳 1，不同則回傳 0 */
int compare(char a, char b, char c){
    if(a == b && a == c && a != ' ')
        return 1;
    return 0;
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    +-+-+-+
    | | | |
    +-+-+-+
    | | | |
    +-+-+-+
    | | | |
    +-+-+-+
    User A 階段：4
    +-+-+-+
    | | | |
    +-+-+-+
    |O| | |
    +-+-+-+
    | | | |
    +-+-+-+
    User B 階段：5
    +-+-+-+
    | | | |
    +-+-+-+
    |O|X| |
    +-+-+-+
    | | | |
    +-+-+-+
    User A 階段：1
    +-+-+-+
    |O| | |
    +-+-+-+
    |O|X| |
    +-+-+-+
    | | | |
    +-+-+-+
    User B 階段：7
    +-+-+-+
    |O| | |
    +-+-+-+
    |O|X| |
    +-+-+-+
    |X| | |
    +-+-+-+
    User A 階段：2
    +-+-+-+
    |O|O| |
    +-+-+-+
    |O|X| |
    +-+-+-+
    |X| | |
    +-+-+-+
    User B 階段：3
    +-+-+-+
    |O|O|X|
    +-+-+-+
    |O|X| |
    +-+-+-+
    |X| | |
    +-+-+-+
    User B 獲勝！
    
    ----------------------------------------------
*/