#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define FAIL -1
#define MIN(a,b) ({ \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b; \
})
#define MAX(a,b) ({ \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; \
})

#define MAXCOUNT 20

/* forward declaration */
typedef struct _SqList SqList;
typedef int (*fptrGetCount)(SqList*);
typedef int (*fptrSetCount)(SqList*, int);
typedef int (*fptrInsert)(SqList*, int, int);
typedef void (*fptrdispose_SqList)(SqList*);
typedef int (*fptrGet)(SqList*, int);
typedef int (*fptrContains)(SqList*, int);
typedef int (*fptrIndexOf)(SqList*, int);
typedef int (*fptrRemove)(SqList*, int);
typedef int (*fptrRemoveAt)(SqList*, int);
typedef struct _SqList {
    int *data;
    int _Count;
    // interface to access member functions
    fptrdispose_SqList dispose_SqList;
    fptrGetCount GetCount;
    fptrSetCount SetCount;
    fptrInsert Insert;
    fptrGet Get;
    fptrContains Contains;
    fptrIndexOf IndexOf;
    fptrRemove Remove;
    fptrRemoveAt RemoveAt;
}SqList;
SqList* SqList_new(const int pCount);
void dispose_SqList(SqList* const self);
static int SetCount(SqList* const self, const int const pCount);
static int GetCount(SqList* const self);
static int Insert(SqList* const self, const int const index, const int const d);
static int Get(SqList* const self, const int const index);
static int Contains(SqList* const self, const int const d);
static int IndexOf(SqList* const self, const int const d);
static int Remove(SqList* const self, const int const d);
static int RemoveAt(SqList* const self, const int const index);

/* method */
static int SetCount_imp(SqList* const self, const int const i){
    if (i < 0 || i > MAXCOUNT || self->_Count == MAXCOUNT)
        return FAIL;
    self->_Count = i;
        return 0;
}

/* method */
static int GetCount_imp(SqList* const self){
    if (self->_Count < 0 || self->_Count > MAXCOUNT)
        return FAIL;
    else
        return self->_Count;
}

/* method */
static int Insert_imp(SqList* const self, const int const index, const int const d)
{
    int i = 0;
    if (index < 0 || index >= MAXCOUNT)
        return FAIL;
    if ( index <= self->_Count )
    {
        for ( i = self->_Count; i >= index; i-- )
        {
            self->data[i+1] = self->data[i];
        }
    }
    self->data[index] = d;
    self->_Count++;
    return 0;
}

/* method */
int Get_imp(SqList* const self, const int const index)
{
    if (index < 0 || index >= MAXCOUNT)
        return FAIL;
    return self->data[index];
}

/* method */
static int Contains_imp(SqList* const self, const int const d)
{
    int i = 0;
    for (i=0; i<self->_Count; i++)
        if (self->data[i] == d)
            return TRUE;
    return FALSE;
}

static int IndexOf_imp(SqList* const self, const int const d)
{
    int i = 0;
    if (!self->Contains(self, d))
        return FAIL;
    if ( i != self->_Count-1 )
    {
        for(i=0;i<self->_Count;i++)
            if (self->data[i] == d)
                return i;
    }
    return FAIL;
}

/* method*/
static int Remove_imp(SqList* const self, const int const d)
{
    int i = 0;
    for (i = self->IndexOf(self, d);i<self->_Count;i++)
        self->data[i] = self->data[i+1];
    self->_Count--;
    return 0;
}

/* method */
static int RemoveAt_imp(SqList* const self, const int const index)
{
    int i = 0;
    if (index < 0 || index > MAXCOUNT || self->_Count == MAXCOUNT)
        return FAIL;
    for (i=index; i < self->_Count; i++)
        self->data[i] = self->data[i+1];
    self->_Count--;
    return 0;
}

/* method */
void dispose_SqList_imp(SqList* const self)
{
    if (self != NULL)
    {
        free(self->data);
        free(self);
    }
}

/* & : address of
   * : value of indirect access */
SqList* SqList_new(const int pCount){
    SqList* _Obj = NULL;
    /* allocating memory */
    _Obj = malloc(sizeof(SqList));
    _Obj->data = malloc(sizeof(int) * MAXCOUNT);
    if (_Obj == NULL)
        return NULL;
    _Obj->_Count = 0;
    /* initialize member function pointer */
    _Obj->dispose_SqList = dispose_SqList_imp; /* destructor pointing to destrutor of itself */
    _Obj->SetCount = SetCount_imp;
    _Obj->GetCount = GetCount_imp;
    _Obj->Insert = Insert_imp;
    _Obj->Get = Get_imp;
    _Obj->Contains = Contains_imp;
    _Obj->IndexOf = IndexOf_imp;
    _Obj->Remove = Remove_imp;
    _Obj->RemoveAt = RemoveAt_imp;
    /* initialize count of the SqList */
    _Obj->SetCount(_Obj, pCount);
    return _Obj;
}

int main(int argc, char *argv[])
{
    int i, d = 0;
    SqList *L = SqList_new(0);
    printf("Initialize successfully. Length of List: %d\n", L->GetCount(L));

    for (i=0; i<=5 ;i++)
        L->Insert(L, 0, i);
    printf("Insert 0,1,2,3,4,5 into the list: ");
    for (i=0; i<= (L->GetCount(L)-1); i++)
        printf("[%d]:%d, ", i, L->Get(L, i) );
    printf("Total Elements: %d\n", L->GetCount(L));

    d = 3;
    if (L->Contains(L, d))
        printf("The list contain: %d\n", d);
    else
        printf("The list does not contain: %d\n", d);

    L->Remove(L, 3);
    printf("After remove the value \"3\": ");
        for (i=0; i<= (L->GetCount(L)-1); i++)
            printf("[%d]:%d, ", i, L->Get(L, i) );
    printf("\n");

    L->RemoveAt(L, 3);
    printf("After remove \"index of 3\": ");
        for (i=0; i<= (L->GetCount(L)-1); i++)
            printf("[%d]:%d, ", i, L->Get(L, i) );
    printf("\n");

    L->dispose_SqList(L);
    printf("End");
    return 0;
}
