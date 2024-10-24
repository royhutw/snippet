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
typedef Status (*func_t4)(SqList *, ElemType);
struct list {
    ElemType data[MAXSIZE];
    int length;
    func_t GetLength, ListTraverse, ListEmpty, ClearList;
    func_t2 GetElem, ListDelete;
    func_t3 ListInsert;
    func_t4 LocateElem;
};

/* method */
static int GetLength_imp(SqList *self){
    return self->length;
}

/* method */
/* 起始條件：順序線性串列L已存在，1 <= i <= SqList->length */
/* 動作結果：用e傳回L中第i個資料元素的值,注意i是指位置，第1個位置的陣列是從0開始 */
static Status GetElem_impl(SqList *self, int i, ElemType *e) {
    if(self->length==0 || i<1 || i>self->length)
        return -1;
    *e = self->data[i-1];
    return 0;
}

/* method */
/* 起始條件：順序線性串列L已存在,1 <= i <= SqList->length */
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

/* method */
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

/* method */
/* 起始條件：順序線性串列L已存在。動作結果：若L為空表，則傳回TRUE，否則傳回FALSE */
Status ListEmpty_impl(SqList *self)
{ 
	if(self->length==0)
		return TRUE;
	else
		return FALSE;
}

/* method */
/* 起始條件：順序線性串列L已存在。動作結果：將L重設為空表 */
Status ClearList_impl(SqList *self)
{ 
    self->length=0;
    return OK;
}

/* method */
/* 起始條件：順序線性串列L已存在 */
/* 動作結果：傳回L中第1個與e滿足關系的資料元素的位序。 */
/* 若這樣的資料元素不存在，則傳回值為0 */
int LocateElem_impl(SqList *self, ElemType e)
{
    int i;
    if (self->length==0)
            return 0;
    for(i=0;i<self->length;i++)
    {
            if (self->data[i]==e)
                    break;
    }
    if(i>=self->length)
            return 0;

    return i+1;
}

/* method */
/* 起始條件：順序線性串列L已存在，1<=i<=ListLength(L) */
/* 動作結果：移除L的第i個資料元素，並用e傳回其值，L的長度減1 */
Status ListDelete_impl(SqList *self,int i,ElemType *e) 
{ 
    int k;
    if (self->length==0)               /* 線性串列為空 */
		return ERROR;
    if (i<1 || i>self->length)         /* 移除位置不正確 */
        return ERROR;
    *e=self->data[i-1];
    if (i<self->length)                /* 若果移除不是最後位置 */
    {
        for(k=i;k<self->length;k++)/* 將移除位置後繼元素前移 */
			self->data[k-1]=self->data[k];
    }
    self->length--;
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
    (*self)->ListEmpty = ListEmpty_impl;
    (*self)->ClearList = ClearList_impl;
    (*self)->LocateElem = LocateElem_impl;
    (*self)->ListDelete = ListDelete_impl;
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

    printf("L->GetLength(L)=%d \n",L->GetLength(L));
    i=L->ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=L->ClearList(L);
    printf("清理L後：L->GetLength(L)=%d\n",L->GetLength(L));
    i=L->ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            L->ListInsert(L,j,j);
    printf("在L的表尾依次插入1～10後：L->data=");
    L->ListTraverse(L);

    printf("L->GetLength(L)=%d \n",L->GetLength(L));

    L->ListInsert(L, 1, 0);
    printf("在L的標頭插入0後：L->data=");
    L->ListTraverse(L);
    printf("L->GetLength(L)=%d \n",L->GetLength(L));

    L->GetElem(L, 5, &e);
    printf("第5個元素的值為：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=L->LocateElem(L,j);
            if(k)
                    printf("第%d個元素的值為%d\n",k,j);
            else
                    printf("沒有值為%d的元素\n",j);
    }

    k=L->GetLength(L); /* k為表長 */
    for(j=k+1;j>=k;j--)
    {
            i=L->ListDelete(L,j,&e); /* 移除第j個資料 */
            if(i==ERROR)
                    printf("移除第%d個資料失敗\n",j);
            else
                    printf("移除第%d個的元素值為：%d\n",j,e);
    }
    printf("依次輸出L的元素：");
    L->ListTraverse(L); 

    j=5;
    L->ListDelete(L,j,&e); /* 移除第5個資料 */
    printf("移除第%d個的元素值為：%d\n",j,e);

    printf("依次輸出L的元素：");
    L->ListTraverse(L); 

    free(L);
    return 0;
}
