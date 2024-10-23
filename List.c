#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20          /* 儲存空間起始分配量 */
typedef int ElemType;       /* ElemType型態根據實際情況而定，這裡假設為int */
typedef int Status;         /* Status是函數的型態,其值是函數結果狀態程式碼，如OK等 */

/* forward declaration */
typedef struct list SqList;
typedef Status (*func_t)(SqList *);
typedef Status (*func_t2)(SqList *, int, ElemType *);
typedef Status (*func_t3)(SqList *, int, ElemType);

struct list {
    ElemType data[MAXSIZE];
    int length;
    func_t GetLength, ListTraverse;
    func_t2 GetElem;
    func_t3 ListInsert;
};

static int GetLength_imp(SqList *self){
    return self->length;
}

/* method */
/* 起始條件：順序線性串列L已存在，1 <= i <= self->length */
/* 動作結果：用e傳回L中第i個資料元素的值,注意i是指位置，第1個位置的陣列是從0開始 */
static Status GetElem_impl(SqList *self, int i, ElemType *e) {
    if(self->length==0 || i<1 || i>self->length)
        return -1;
    *e = self->data[i-1];
    return 0;
}

/* method */
/* 起始條件：順序線性串列L已存在,1 <= i <= self->length */
/* 動作結果：在L中第i個位置之前插入新的資料元素e，L的長度加1 */
static Status ListInsert_impl(SqList *self, int i, ElemType e) {
	int k;
	if (self->length ==MAXSIZE)  /* 順序線性串列已經滿 */
		return ERROR;
	if (i<1 || i>self->length+1)/* 當i比第一位置小或是比最後一位置後一位置還要大時 */
		return ERROR;

	if (i<=self->length)        /* 若插入資料位置不在表尾 */
	{
		for(k=self->length-1;k>=i-1;k--)  /* 將要插入位置之後的資料元素向後搬移一位 */
			self->data[k+1]=self->data[k];
	}
	self->data[i-1]=e; /* 將新元素插入 */
	self->length++;

	return OK;       
}

/* 起始條件：順序線性串列L已存在 */
/* 動作結果：依次對L的每個資料元素輸出 */
Status ListTraverse_impl(SqList *self)
{
	int i;
    for(i=0;i<self->length;i++)
        printf("%d ", self->data[i]);
    printf("\n");
    return OK;
}

/* & : address of
   * : value of indirect access */
/* call-by-value */
int init_list(SqList **self) {
    if (NULL == (*self = (SqList*)malloc(sizeof(SqList))))
        return -1;
    (*self)->length = 0;
    (*self)->GetLength = GetLength_imp;
    (*self)->GetElem = GetElem_impl;
    (*self)->ListInsert = ListInsert_impl;
    (*self)->ListTraverse = ListTraverse_impl;
    return 0;
}

int main(int argc, char *argv[])
{

    Status i;
    int j, k;
    ElemType e;

    SqList *L = NULL;
    /* 起始化順序線性串列 */
    init_list(&L);
    printf("\n起始化L後：L.length=%d\n",L->GetLength(L));

    for (j=1;j<=5;j++)
        i=L->ListInsert(L, 1, j);
    printf("在L的標頭依次插入1～5後：L.data=");
    L->ListTraverse(L);

    free(L);
    return 0;
}
