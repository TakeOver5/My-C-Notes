/*
 * 時間：2018/11/12
 * 功能：
 *      產生 30 個亂數，排序後輸出。
 * 目的：
 *      BubbleSort Sort 使用。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
#define SWAP(x, y ,t) (t = x, x = y, y = t)

int main(void){
    int a[SIZE];
    int i, j, num, temp, flag;
    srand(time(NULL));
    printf("How many number do you want?(less than %d)", SIZE);
    scanf("%d", &num);
    for(i=0; i<num; i++) a[i] = rand() % 100;
    
    for(i=num-1; i>=1; i--){                /* 相鄰資料兩兩比較的過程共 n-1 回合 */
        flag = 0;                           /* flag 用來記錄有無發生交換。沒有的話，表示排序完畢 */
        for(j=0; j<=i-1; j++){              /* 內部迴圈用來進行每一回合的兩兩比較 */
            if(a[j] > a[j+1]){              /* 若左邊的資料大於右邊的資料，就交換，flag 設定為「1」 */
                SWAP(a[j], a[j+1], temp);
                flag = 1;
            }
        }
        if(flag = 0)                        /* 若 flag 仍為「0」，表示沒有發生交換，已經排序完畢 */
            break;                          /* 排序完畢便強制離開外部迴圈 */
    }
    
    for(i=0; i<num; i++) printf("%d ", a[i]);
    printf("\n");
    system("pause");
    return 0;
}