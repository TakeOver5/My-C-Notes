/*
 * 時間：2018/11/12
 * 功能：
 *      重複文字的計算。
 * 目的：
 *      動態規劃解題的應用。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 這裡的自訂結構較為特殊，結構內包含了指向結構的指標，
   這並不會造成結構大小無法判斷，因為指標的大小是固定的，
   這裡是使用了鏈結串列的技巧，
   每一筆資料都使用指標與下一筆資料連在一起。
*/
typedef struct word{
    char str[20];       // 儲存讀入的單字
    int num;            // 儲存單字的出現次數
    struct word *nxt;   // 結構指標 nxt 指向下一筆 WORD 結構
} WORD;

int main(void){
    char s[20];
    char fn[] = "TestFile.txt";
    FILE *fp;
    WORD *head, *p;
    fp = fopen(fn, "r");
    
    p = (WORD*)malloc(sizeof(WORD));
    
    /* head 與 p 的內容相同 */
    head = p;
    
    head->num = 1;
    head->nxt = NULL;
    
    /* head 先讀取第一個字串，遇到空白停止讀取 */
    fscanf(fp, "%s", head->str);
    
    /* 此處先使用 fscanf 將字串存入 s 中，在判斷是否讀到檔案結尾 */
    while(fscanf(fp, "%s", s) != EOF){
        /* *cmp 比較當前 s 是否與現有的鏈結文字相同 
           因為需要造訪所有鏈結，所以都要重頭開始(*cmp = head) */
        WORD *cmp = head;
        /* 如果 s 與現有鏈結文字相同，則 flag 設為「1」
           反之替 s 建立一個新鍵結 */
        int flag = 0;
        
        /* 迴圈會將目前讀入的單字與已讀入的單字做比對
           若有相同的資料，則表示此單字重複，
           則將該單字結構內的計數變數 num + 1 
           若單字無重複，則進入 if 區段，動態配置一塊 WORD 結構來儲存資料
           並初始化剛剛配置出的結構。 */
        while(cmp != NULL){
            /* strcmp 比較參數兩者相同如果相同，回傳「0」 
               如果相同，則當前鏈結的 num++，並 flag 設為「1」
               表示 s 存在相同字串 */
            if(!strcmp(cmp->str, s)){
                cmp->num++;
                flag = 1;
                break;
            /* 如果不是則 cmp 指向下一個鏈結 */
            } else
                cmp = cmp->nxt;     
        }
        /* 如果沒有重覆，則建立一個新鏈結 */
        if(!flag){
            /* p 的 nxt 指向一個新建立的記憶體 */
            p->nxt = (WORD*)malloc(sizeof(WORD));
            /* 計數設為「1」 */
            p->nxt->num = 1;
            /* 今 p 的 nxt 的 nxt 指向 NULL，表示鏈結的終點*/
            p->nxt->nxt = NULL;
            /* 將 s 字串複制至 p 的 nxt 的 str */
            strcpy(p->nxt->str, s);
            /* 最後令 p 指向下一個鏈結，這樣才能確保下一次建立資料，
               下一筆資料為「空」
            */
            p = p->nxt;
        }
    }
    /* 今 p 指向 head */
    p = head;
    /* 如果鏈表不為終點時，則循環下去 */
    while(p != NULL){
        /* 打印當前節點節點的字串與出現字數 */
        printf("%10s : %d times\n", p->str, p->num);
        /* 指向下個節點 */
        p = p->nxt;
    }
    
    /* free */
    while(head != NULL){
        /* 先宣告一個暫存 head 節點的 tmp */
        WORD *tmp;
        tmp = head;
        /* 之後令 head 指向下一個節點 */
        head = head->nxt;
        /* 接著 free 掉暫存的 head 節點的 tmp */
        free(tmp);
    }
    
    /* 關閉串流 */
    fclose(fp);
    system("pause");
    return 0;
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    type TestFile.txt
    this is the test file for program 13-2-3.c
    you can also test this program with any text file you wish!

        this : 2 times
          is : 1 times
         the : 1 times
        test : 2 times
        file : 2 times
         for : 1 times
     program : 2 times
    13-2-3.c : 1 times
         you : 2 times
         can : 1 times
        also : 1 times
        with : 1 times
         any : 1 times
        text : 1 times
       wish! : 1 times
    
    ----------------------------------------------
*/