/*
 * 時間：2018/10/07
 * 功能：
 *      向量的運算。
 * 目的：
 *      使用結構傳遞結構進入函式。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
    double x;
    double y;
    double z;
} V;

void enter(V*);
void vput(V*, V*, char);
V vadd(V*, V*);
double vdot(V*, V*);
V vcross(V*, V*);

int main(void){
    
    double d;
    V a,b,v;
    // 輸入兩個向量
    enter(&a);
    enter(&b);
    
    vput(&a, &b, '+');
    v = vadd(&a, &b);
    printf("(%.2lf, %.2lf, %.2lf)\n", v.x, v.y, v.z);
    
    vput(&a, &b, '.');
    d = vdot(&a, &b);
    printf("%.2lf\n", d);
    
    vput(&a, &b, 'x');
    v = vcross(&a, &b);
    printf("(%.2lf, %.2lf, %.2lf)\n", v.x, v.y, v.z);

    
    
    system("pause");
    return 0;
}

//輸出算式
void vput(V* a, V* b, char ch){
    printf("(%.2lf, %.2lf, %.2lf) %c (%.2lf, %.2lf, %.2lf) = ",
    a->x, a->y, a->z, ch, b->x, b->y, b->z);
}

//鍵入函式
void enter(V* v){
    printf("輸入一個向量(x, y, z):");
    scanf("%lf %lf %lf", &v->x, &v->y, &v->z);
}

//處理向量向加
V vadd(V* a, V* b){
    V v;
    v.x = a->x + b->x;
    v.y = a->y + b->y;
    v.z = a->z + b->z;
    
    return v;
}


//處理向量內積
double vdot(V* a, V* b){
    return a->x*b->x + a->y*b->y + a->z*b->z;
}


//處理向量外積
V vcross(V*a, V*b){
    V v;
    v.x = a->y*b->z - b->y*a->z;
    v.y = a->z*b->x - b->z*a->x;
    v.z = a->x*b->y - b->x*a->y;
    return v;
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
    輸入一個向量(x, y, z):3 1 2
    輸入一個向量(x, y, z):0 0 1
    (3.00, 1.00, 2.00) + (0.00, 0.00, 1.00) = (3.00, 1.00, 3.00)
    (3.00, 1.00, 2.00) . (0.00, 0.00, 1.00) = 2.00
    (3.00, 1.00, 2.00) x (0.00, 0.00, 1.00) = (1.00, -3.00, 0.00)
    
    ----------------------------------------------
*/