/*
 * 時間：2018/11/13
 * 功能：
 *      模擬完整二元樹的程式。
 * 目的：
 *      二元樹的應用。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10

int main(void){
    /* 陣列大小為二元樹總數 + 1
       是因為讓二元樹從 index 1 開始儲存，
       以便接下來的公式符合規則 */
    int i, tree[NUM+1];
    srand(time(NULL));
    for(i=1; i<=NUM; i++)
        tree[i] = rand()%100;
    printf("root of this tree is %d\n", tree[1]);
    
    /* i 的左子樹公式為 i * 2 
       i 的右子樹公式為 i * 2 + 1 
       為符合上述公式，才將陣列從 index 1 開始儲存 */
    for(i=1; i<=NUM; i++){
        if(2*i <= NUM)
            printf("node %d has a left child %d\n", tree[i], tree[2*i]);
        if(2*i + 1 <= NUM)
            printf("node %d has a right child %d\n", tree[i], tree[2*i+1]);
    }
    system("pause");
    return 0;
}

/*  
 *  ------------ 在 cmd 的輸出結果 ---------------
 *
 *  root of this tree is 43
 *  node 43 has a left child 85
 *  node 43 has a right child 86
 *  node 85 has a left child 67
 *  node 85 has a right child 35
 *  node 86 has a left child 31
 *  node 86 has a right child 44
 *  node 67 has a left child 92
 *  node 67 has a right child 65
 *  node 35 has a left child 54
 *
 *  ----------------------------------------------
 */