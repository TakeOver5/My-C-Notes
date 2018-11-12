/*
 * 時間：2018/10/12
 * 功能：
 *      添加好友名單與輸出好友名單。
 * 目的：
 *      使用 fprint() 與 fscanf() 串流輸出入函式。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct friends{
    char name[10];
    char phone[15];
    char birth[15];
} FRIENDS;

void show(char *);
void enter(char *);

int main(void){
    
    char ch;
    char LIST[] = "FriendList.txt";
    
    while(1){
        printf("請問您要 1)輸出好友名單 2)新增好友資料：");
        scanf("%c", &ch);
        if(ch == '1')
            show(LIST);
        else if(ch == '2')
            enter(LIST);
        /* 由於 scanf 本身的問題，在 scanf 成功回傳之後
           stdin 裡面可能還有一些不正確的資料
           若是不使用 fflush(stdin)，再次呼叫 scanf 的話
           這些不正確的資料，就可能會讓 scanf 失敗，或回傳不正確的東西 */
        /* 但 fflush 不應該用在 stdin 而是 stdout 
           某些編譯器可能不持支這個語法 */
        //fflush(stdin);
        
        /* C 語言把鍵盤，顯示器等設備當做文件來處理。
           也就是說從鍵盤輸入相當於從一個文件中讀入；向顯示器輸出相當向一個文件寫出
           而 stdin 是 C 標準庫定義的標準文件之一，它與鍵盤相關聯，
           我一般把它理解為指向鍵盤這個「文件」的指針。
           
           而 rewind() 函式的作用是把文件的當前位罝指針指向文件頭。
           上述兩者結合，rewind(stdin) 的作用，
           
           也就是把「指向鍵盤（一個文件）的指針從當前位置挪到鍵盤（一個文件）開頭」，
           相當於拋棄當前鍵盤暫存區中的數據，重新開始輸入。
        */
        rewind(stdin);
    }
    
    system("pause");
    return 0;
}

void show(char *fn){
    FRIENDS f;
    FILE *fp;
    if((fp = fopen(fn, "r")) == NULL){
        printf("將檔案開啟錯誤！\n");
        return;
    }
    /* 從指標文件 fp 的文件中(fp)，
       按控制格式讀取數據("%s")，存取到對應的變數中(f.name) */
    while(fscanf(fp, "%s", f.name) != EOF){
        fscanf(fp, "%s", f.phone);
        fscanf(fp, "%s", f.birth);
        printf("===================================\n");
        printf("%10s 的電話：%-15s\n", f.name, f.phone);
        printf("%10s 的生日：%-15s\n", f.name, f.birth);
    }
    printf("===================================\n");
    fclose(fp);
}

void enter(char *fn){
    FRIENDS temp;
    FILE *fp;
    fp = fopen(fn, "a");
    
    printf("請輸入名稱：");
    scanf("%s", temp.name);
    /* 將 temp.name 的資料，寫入文件指標 fp 指向的文件中 
       因為 fscanf 函式，遇到空白會停止，所以在控制字串中加入空白("%s ")，分隔資料 */
    fprintf(fp, "%s ", temp.name);
    
    printf("請輸入電話號碼：");
    scanf("%s", temp.phone);
    fprintf(fp, "%s ", temp.phone);
    
    printf("請輸入生日：");
    scanf("%s", temp.birth);
    fprintf(fp, "%s\n", temp.birth);
    
    fclose(fp);
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    請問您要 1)輸出好友名單 2)新增好友資料：2
    請輸入名稱：LISA
    請輸入電話號碼：0909090909
    請輸入生日：1994/12/12
    請問您要 1)輸出好友名單 2)新增好友資料：2
    請輸入名稱：PETER
    請輸入電話號碼：0911111111
    請輸入生日：1003/03/13
    請問您要 1)輸出好友名單 2)新增好友資料：1
    ===================================
        LISA 的電話：0909090909
        LISA 的生日：1994/12/12
    ===================================
        PETER 的電話：0911111111
        PETER 的生日：1003/03/13
    ===================================
    
    ----------------------------------------------
*/