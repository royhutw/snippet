#include <stdio.h>
#include <stdlib.h>

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
typedef void (*fptrdispose_SqList)(SqList*);
typedef struct _SqList {
    int *data;
    int _Count;
    // interface to access member functions
    fptrdispose_SqList dispose_SqList;
    fptrGetCount GetCount;
    fptrSetCount SetCount;
}SqList;
SqList* SqList_new(const int pCount);
void dispose_SqList(SqList* const self);
static int SetCount(SqList* const self, const int const pCount);
static int GetCount(SqList* const self);

/* method */
static int SetCount_imp(SqList* const self, const int const i){
    if (i == 0 || i < 0 || i > MAXCOUNT)
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
    /* initialize count of the SqList */
    _Obj->SetCount(_Obj, pCount);
    return _Obj;
}

int main(int argc, char *argv[])
{
    int i;
    i = 10;
    SqList *L = SqList_new(i);
    printf("%d\n", L->GetCount(L));
    L->dispose_SqList(L);
    printf("End");
    return 0;
}
