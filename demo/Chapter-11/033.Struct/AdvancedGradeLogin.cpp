/*
 * 時間：2018/10/10
 * 功能：
 *      模擬成績登入系統，並且排序。
 * 目的：
 *      結構陣列的使用。
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef struct grade{
    int co_num;
    int g[10];
    double average;
} GD;

typedef struct student{
    char name[10];
    double average;
    GD gd;
} STU;

void enter(STU*);
void sort(STU*, int);

int main(void){
    
    int i;
    STU stu[5];
    for(i=0; i<5; i++)
        enter(&stu[i]);
    
    sort(stu, 5);
    
    for(i=0; i<5; i++)
        printf("%s 的平均成績為 %lf\n", stu[i].name, stu[i].gd.average);
    
    
    system("pause");
    return 0;
}

void enter(STU* s){
    
    int i;
    printf("請輸入您的名稱：");
    scanf("%s", s->name);
    printf("請輸入課程數目：");
    scanf("%d", &s->gd.co_num);
    
    for(i=0; i<s->gd.co_num; i++){
        printf("請輸入第 %d 個成績：", i+1);
        scanf("%d", &s->gd.g[i]);
    }
    
    s->gd.average = 0;
    for(i=0; i<s->gd.co_num; i++)
        s->gd.average += s->gd.g[i];
    
    s->gd.average /= s->gd.co_num;
}

void sort(STU* a, int size){
    int i,j;
    STU k;
    
    for(i=1; i<size; i++){
        for(j = size-1; j >= i; j--){
            if(a[j-1].gd.average > a[j].gd.average){
                k = a[j-1];
                a[j-1] = a[j];
                a[j] = k;
            }
        }
    }
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    請輸入您的名稱：JASON
    請輸入課程數目：2
    請輸入第 1 個成績：99
    請輸入第 2 個成績：96
    請輸入您的名稱：ALICE
    請輸入課程數目：2
    請輸入第 1 個成績：89
    請輸入第 2 個成績：94
    請輸入您的名稱：WENDY
    請輸入課程數目：2
    請輸入第 1 個成績：78
    請輸入第 2 個成績：91
    請輸入您的名稱：CODY
    請輸入課程數目：2
    請輸入第 1 個成績：91
    請輸入第 2 個成績：96
    請輸入您的名稱：RYAN
    請輸入課程數目：2
    請輸入第 1 個成績：93
    請輸入第 2 個成績：96
    WENDY 的平均成績為 84.500000
    ALICE 的平均成績為 91.500000
    CODY 的平均成績為 93.500000
    RYAN 的平均成績為 94.500000
    JASON 的平均成績為 97.500000
    
    ----------------------------------------------
*/