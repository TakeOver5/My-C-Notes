/*
 * 時間：2018/10/07
 * 功能：
 *      好友名單存取。
 * 目的：
 *      結構的使用。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct friends{
    char name[10];
    char phone[15];
    char birth[15];
} FRIENDS;

void show(FRIENDS [], int);
FRIENDS enter(void);

int main(void){
    
    int now = 0;
    char ch;
    FRIENDS f[20];
    
    while(1){
        
        printf("請問你要 1)輸出好友名單 2)新增好友資料 0)離開：");
        scanf("%c", &ch);
        
        if(ch == '1'){
            if(now != 0) show(f, now);
            else printf("目前尚無資料\n");
        }
        else if(ch == '2'){
            if(now >= 20) 
                printf("名單已滿！\n");
            else{
                f[now] = enter();
                now++;
            }
        }
        else if(ch == '0') break;
        /* 使用 fflush 函式，則是預防在輸入錯誤時，
           程式會多讀取一個換行字元 */
        fflush(stdin);
    }
    
    system("pause");
    return 0;
    
}

void show(FRIENDS f[], int size){
    
    int i;
    for(i=0; i<size; i++){
        printf("===================================\n");
        printf("%10s 的電話：%-15s\n", f[i].name, f[i].phone);
        printf("%10s 的生日：%-15s\n", f[i].name, f[i].birth);
    }
    printf("===================================\n");
    
}

FRIENDS enter(void){
    
    FRIENDS temp;
    
    printf("請輸入名稱：");
    scanf("%s", temp.name);
    printf("請輸入電話號碼：");
    scanf("%s", temp.phone);
    printf("請輸入生日：");
    scanf("%s", temp.birth);
    
    return temp;
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    請問你要 1)輸出好友名單 2)新增好友資料 0)離開：2
    請輸入名稱：David
    請輸入電話號碼：0912345678
    請輸入生日：1111/04/25
    請問你要 1)輸出好友名單 2)新增好友資料 0)離開：2
    請輸入名稱：Dell
    請輸入電話號碼：0987654321
    請輸入生日：2222/08/31
    請問你要 1)輸出好友名單 2)新增好友資料 0)離開：1
    ===================================
        David 的電話：0912345678
        David 的生日：1111/04/25
    ===================================
        Dell 的電話：0987654321
        Dell 的生日：2222/08/31
    ===================================
    請問你要 1)輸出好友名單 2)新增好友資料 0)離開：0
    
    ----------------------------------------------
*/
