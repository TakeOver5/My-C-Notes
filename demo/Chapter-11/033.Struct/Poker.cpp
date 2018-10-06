/*
 * 時間：2018/10/06
 * 功能：
 *      玩牌比大小。
 * 目的：
 *      結構的使用。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card{
    
    /* 0123 respectively stand for 
       clubs, diamonds, hearts and spades */
    int flower; 
    
    /* 0 ~ 12 represent The number between 2 to A */
    int num;
    
} CARD;

int main(void){
    
    char const *fl[] = {"梅花", "磚塊", "紅心", "黑桃"};
    int choice;
    CARD player, banker;
    srand(time(NULL));
    printf("請問你想比 1)大 還是比 2)小 ?");
    scanf("%d", &choice);
    
    do{
        printf("發牌中...\n");
        
        player.flower = rand() % 4;
        player.num = rand() % 13;
        
        banker.flower = rand() % 4;
        banker.num = rand() % 4;
        
        if(player.num == 12)
            printf("您拿到的牌是 %s A\n", fl[player.flower]);
        else
            printf("您拿到的牌是 %s %d\n", fl[player.flower], player.num + 2);
        
        if(banker.num == 12)
            printf("電腦拿的牌是 %s A\n", fl[banker.flower]);
        else
            printf("電腦拿的牌是 %s %d\n", fl[banker.flower], banker.num + 2);
        
        if(choice == 1){
            if((player.num * 10 + player.flower) > (banker.num * 10 + banker.flower))
                printf("你贏了！\n");
            else
                printf("你輸了！\n");
        } else {
            if((player.num * 10 + player.flower) > (banker.num * 10 + banker.flower))
                printf("你輸了！\n");
            else
                printf("你贏了！\n");
        }
            
        printf("=============================================\n");
        
        printf("再玩一次嗎？  1)大  2)小  0)不玩了：");
        scanf("%d", &choice);
        
    }while(choice != 0);
    
    system("pause");
    return 0;
    
}

/*  
    ------------ 在 cmd 的輸出結果 ---------------
  
    請問你想比 1)大 還是比 2)小 ?1
    發牌中...
    您拿到的牌是 紅心 11
    電腦拿的牌是 紅心 3
    你贏了！
    =============================================
    再玩一次嗎？  1)大  2)小  0)不玩了：2
    發牌中...
    您拿到的牌是 紅心 12
    電腦拿的牌是 紅心 3
    你輸了！
    =============================================
    再玩一次嗎？  1)大  2)小  0)不玩了：0
    
    ----------------------------------------------  
*/