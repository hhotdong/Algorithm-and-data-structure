// https://d-michail.github.io/assets/teaching/data-structures/013_VectorImplementation.en.pdf
#include <stdio.h>
#include <stdlib.h>  // malloc(), free(), abort()
#include <assert.h>  // assert()
#include "dynamic_array.h"

#define INIT_CAPACITY 2
#define min(x,y) ((x) < (y) ? (x) : (y))

struct _DynamicArray {
    Data* arr;
    int size;
    int capacity;
};

Vector VectorCreate()
{
    Vector v = (Vector) malloc(sizeof(struct _DynamicArray));
    if (v == NULL)
    {
        fprintf(stderr, "Not enough memory!\n");
        abort();
    }

    v->size = 0;
    v->capacity = INIT_CAPACITY;
    v->arr = (Data*) malloc(sizeof(Data) * v->capacity);
    if (v->arr == NULL)
    {
        fprintf(stderr, "Not enough memory!\n");
        abort();
    }
    printf("Vector created with capacity %d.\n", v->capacity);
    return v;
}

void VectorDestroy(Vector v)
{
    assert(v);

    free(v->arr);
    free(v);
    printf("Vector destroyed.\n");
}

static void VectorDoubleCapacity(Vector v)
{
    assert(v);

    int newCapacity = 2 * v->capacity;
    Data* newArr = (Data*) realloc(v->arr, sizeof(Data) * newCapacity);        
    if (newArr == NULL)
    {
        fprintf(stderr, "Not enough memory!\n");
        abort();
    }
    printf("Resize array from %d to %d.\n", v->capacity, newCapacity);
    v->capacity = newCapacity;
}

static void VectorHalfCapacity(Vector v)
{
    assert(v);

    if (v->capacity <= INIT_CAPACITY)
        return;

    int newCapacity = v->capacity / 2;
    Data* newArr = (Data*) realloc(v->arr, sizeof(Data) * newCapacity);
    if (newArr == NULL)
    {
       fprintf(stderr, "Not enough memory!\n");
       abort();
    }
    printf("Resize array from %d to %d.\n", v->capacity, newCapacity);
    v->capacity = newCapacity;
    v->size = min(v->size, v->capacity);
}

void VectorAdd(Vector v, Data data)
{
    assert(v);

    if (v->size >= v->capacity)
        VectorDoubleCapacity(v);
    v->arr[v->size++] = data;
    printf("Element added(%d).\n", data);
}

void VectorAddAt(Vector v, int i, Data data)
{
    assert(v);

    if (i < 0 || i >= v->size)
    {
        fprintf(stderr, "Out of index!\n");
        abort();
    }
    
    if (v->size >= v->capacity)
        VectorDoubleCapacity(v);

    for (int j = v->size; j > i + 1; --j)
        v->arr[j] = v->arr[j-1];
    
    v->arr[i] = data;
    ++(v->size);
    printf("Element added(%d) at index(%d).\n", data, i);
}

Data VectorRemove(Vector v)
{
    if (VectorIsEmpty(v))
    {
        fprintf(stderr, "No element found to remove!\n");
        abort();
    }
    Data rData = v->arr[v->size - 1];
    --(v->size);
    printf("Element removed(%d).\n", rData);
    return rData;
}

Data VectorRemoveAt(Vector v, int i)
{
    if (i < 0 || i >= v->size)
    {
        fprintf(stderr, "Out of index!\n");
        abort();
    }

    Data rData = v->arr[i];
    for (int j = i+1; j < v->size; ++j)
        v->arr[j-1] = v->arr[j];
    --(v->size);

    if (4 * v->size < v->capacity)
        VectorHalfCapacity(v);
    printf("Element removed(%d) at index(%d).\n", rData, i);
    return rData;
}

Data VectorGet(Vector v, int i)
{
    assert(v);

    if (i < 0 || i >= v->size)
    {
        fprintf(stderr, "Out of index!\n");
        abort();
    }
    return v->arr[i];
}

int VectorIsEmpty(Vector v)
{
    assert(v);
    return v->size == 0;
}

int VectorSize(Vector v)
{
    assert(v);
    return v->size;
}

void VectorClear(Vector v)
{
    assert(v);
    v->size = 0;
    while (v->capacity > INIT_CAPACITY)
        VectorHalfCapacity(v);
    printf("Vector cleared.\n");
}

void VectorPrint(Vector v)
{
    printf("Vector elements: ");
    for (int i = 0; i < v->size; ++i)
        printf("%d ", v->arr[i]);
    printf("\n");
}
