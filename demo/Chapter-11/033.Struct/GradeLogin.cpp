/*
 * 時間：2018/10/08
 * 功能：
 *      模擬成績登入系統。
 * 目的：
 *      巢狀結構的使用。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct grade{
    int co_num;         //課程數目
    int g[10];          //課程成績
    double average;     //平均成績
} GD;

typedef struct student{
    char name[10];      //學生姓名
    GD gd;              //包含 grade 結構
} STU;

int main(void){
    
    int i;
    STU s;
    printf("請輸入您的名稱：");
    scanf("%s", s.name);
    printf("請輸入課程數目：");
    scanf("%d", &s.gd.co_num);
    for(i=0; i<s.gd.co_num; i++){
        printf("請輸入第 %d 個成績：", i+1);
        scanf("%d", &s.gd.g[i]);
    }
    s.gd.average = 0;
    for(i=0; i<s.gd.co_num; i++){
        s.gd.average += s.gd.g[i];
    }
    
    s.gd.average = s.gd.average/s.gd.co_num;
    printf("%s 的平均成績為 %.2lf\n", s.name, s.gd.average);
    
    system("pause");
    return 0;
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    請輸入您的名稱：peter
    請輸入課程數目：3
    請輸入第 1 個成績：78
    請輸入第 2 個成績：94
    請輸入第 3 個成績：88
    peter 的平均成績為 86.67
    
    ----------------------------------------------
*/