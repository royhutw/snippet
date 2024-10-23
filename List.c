#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* forward declaration */
typedef struct list List;
typedef int (*func_t)(List *);
typedef int (*func_t2)(List *, int);

struct list {
    int data[20], length;
    func_t ListInsert;
    func_t2 GetElem;
};

/* method */
static int GetElem_impl(List *self, int i) {
    if(self->length==0 || i<1 || i>self->length)
        return -1;
    return self->data[i-1];
}

/* method */
static int ListInsert_impl(List *self) {
    return 0;
}

/* & : address of
   * : value of // indirect access */
/* call-by-value */
int init_list(List **self, int Length) {
    if (NULL == (*self = (List*)malloc(sizeof(List))))
        return -1;
    (*self)->length = Length;
    (*self)->GetElem = GetElem_impl;
    (*self)->ListInsert = ListInsert_impl;
    return 0;
}

int main(int argc, char *argv[])
{
    int i, j, k;

    List *L = NULL;
    init_list(&L, 10);

    for (i=0;i<10;i++)
    {
        L->data[i] = i * 10;
    }

    printf("%d, %d", L->GetElem(L, 3), L->length);
    return 0;
}
