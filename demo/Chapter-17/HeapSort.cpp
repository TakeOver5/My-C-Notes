/*
 * 時間：2018/11/13
 * 功能：
 *      堆積樹的模擬。
 * 目的：
 *      Heap Sort 的應用。
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lchild(i) (2*(i))
#define rchild(i) (2*(i)+1)
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define NUM 15

void shiftdown(int, int[], int);
void buildheap(int[], int);
int extract(int[], int*);
int max(int, int, int);

int main(void){
    /* a[NUM+1] 讓陣列從索引 1 開始，已便符合二元樹的規則 */
    int i, a[NUM+1], size = NUM;
    srand(time(NULL));
    /* 產生亂數資料 */
    for(i=1; i<NUM+1; i++){
        a[i] = rand() % 20;
        printf("%3d ",a[i]);
    }
    printf("\n");
        
    /* 將陣列調整為堆積 */
    buildheap(a, size);
    
    
    
    /* 取出堆積資料，因為堆積的特性，所以 a 的資料是由小排到大 
       而堆積取出資料是由最大數開始，所以要陣列要反向存入資料 */
    for(i=NUM; i>=1; i--)
        a[i] = extract(a, &size);
    
    /* 打印資料 */
    for(i=1; i<NUM+1; i++)
        printf("%3d ", a[i]);
    
    printf("\n");
    system("pause");
    return 0;
}

int max(int x, int y, int z){
    return x > y ? (x > z ? x : z) : (y > z ? y : z);
}


int extract(int a[], int *size){
    /* 首先取出 root */
    int t=a[1];
    /* 接著將 root 與堆積的最後一個元素交換 
       並且最後一個元素之後就不算入堆積的一部份
       所以 size - 1
       函式傳入 size 的地址，以便記錄 */
    a[1] = a[((*size)--)];
    if(!(*size == 2))
        /* 接著以 root 為對象調整堆積 */
        shiftdown(1, a, *size);
    else
        /* 如果資料只剩兩筆時，比較 root 與左子樹，
           較大的資料移至 root */
        if(a[1] < a[lchild(1)]){
            int tmp;
            SWAP(a[1], a[lchild(1)], tmp);
        }
    
    /* 回傳 t */
    return t;
}


/* 將某一個新節點加入後，放置在 tree 中適當的位置
   使得 tree 成為一個 heap 結構 */
void shiftdown(int index, int a[], int size){
    int t = a[index];
    /* t 的左樹索引 */
    int l = lchild(index);
    /* t 的右樹索引 */
    int r = rchild(index);
    /* 檢查降階是否還存在左右子樹 
       例如 size = 15，t = a[8]，l = 16，r = 17
       由於左右子樹超出 size 範圍，就可知道該左右子樹不存在 */
    if(l > size || r > size) return;
    /* 比較自身節點與左右子樹的大小，接著令 a[index] 變成三者中最大數 */
    a[index] = max(t, a[l], a[r]);
    /* 如果 a[index] == t，表示沒有變動，直接調整 a[k-1] */
    if(a[index] == t) return;
    /* 如果 a[index] == a[l]，表示左樹為大兒子 */
    else if(a[index] == a[l]){
        /* 由於剛才 a[index] 變為左樹值，但左樹值還沒有改變，
           所以令 a[l] = t */
        a[l] = t;
        /* 接著以大兒子為調整對象，呼叫函式，直到不需要交換為止 */
        shiftdown(l, a, size);
    }
    /* 反之，表示右樹為大兒子 */
    else{
        a[r] = t;
        shiftdown(r, a, size);
    }
}

/* 將一個 array 轉換為 max heap 格式，此處從最後的 leaf 開始判斷 
   因此每一個 leaf 已經為 max heap，所以只要將每一個不是 leaf 的節點做一次 shiftdown
   就可將 array 轉為 heap */
void buildheap(int a[], int size){
    int i;
    /* 從最後一個有子節點的節點 a[k] 開始 
       若有 n 個節點，則最後一個節點位置 n，
       而它的父節點為：n / 2 */
    /*
       a[k]調整完畢時，接著調整 a[k-1]、a[k-2] 直到 a[k-(k-1)](即樹根 a[1])
    */
    for(i=size/2; i>=1; i--) shiftdown(i, a, size);
}

/*
    ------------ 在 cmd 的輸出結果 ---------------
    
     13   7  15   1  15   3  14   3  19  15   2   1  15   4  16
      1   1   2   3   3   4   7  13  14  15  15  15  15  16  19
    
    ----------------------------------------------
*/
