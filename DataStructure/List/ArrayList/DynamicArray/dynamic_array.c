#include <stdio.h>
#include <stdlib.h>  // malloc(), free()
#include "dynamic_array.h"

#define INIT_CAPACITY 2

struct _DynamicArray {
    Data* arr;
    int size;
    int capacity;
};

Vector VectorCreate()
{
    Vector v = malloc(sizeof(Vector));
    if (v == NULL)
        abort();

    v->arr = malloc(sizeof(Data) * INIT_CAPACITY);
    if (v->arr == NULL)
        abort();

    v->size = 0;
    v->capacity = INIT_CAPACITY;
    printf("Vector created\n");
    return v;
}

void VectorDestroy(Vector v)
{
    free(v->arr);
    free(v);
}

void VectorAdd(Vector v, Data data)
{
    if (v->size == v->capacity)
    {
        printf("Realloc from %d to %d\n", v->size, v->size * 2);
        void* newArr = realloc(v->arr, sizeof(Data) * v->size * 2);
        if (newArr == NULL)
           abort();

        v->capacity = v->size * 2;
    }
    v->arr[v->size] = data;
    ++(v->size);
    printf("Vector add element: %d\n", data);
}

void VectorAddAt(Vector v, int i, Data data)
{

}

Data VectorRemove(Vector v)
{
    if (VectorIsEmpty(v))
       return -1;  // TODO: 유효하지 않은 경우 어떤 값 리턴해야 하는지

    Data rData = v->arr[v->size - 1];
    v->size -= 1;
    return rData;
}

Data VectorRemoveAt(Vector v, int i)
{
    return -1;
}

Data VectorGet(Vector v, int i)
{
    if (i >= v->size)
        return -1;  // TODO: 유효하지 않은 경우 어떤 값 리턴해야 하는지

    return v->arr[i];
}

int VectorIsEmpty(Vector v)
{
    return v->size == 0;
}

void VectorClear(Vector v)
{

}

void VectorPrint(Vector v)
{
    printf("Vector elements: ");
    for (int i = 0; i < v->size; ++i)
        printf("%d ", v->arr[i]);
    printf("\n\n");
}
