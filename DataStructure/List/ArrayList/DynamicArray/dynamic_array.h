// https://d-michail.github.io/assets/teaching/data-structures/013_VectorImplementation.en.pdf
#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

typedef struct _DynamicArray* Vector; 
typedef int Data;

Vector VectorCreate();

void VectorDestroy(Vector);

void VectorAdd(Vector, Data);

void VectorAddAt(Vector, int, Data);

Data VectorRemove(Vector);

Data VectorRemoveAt(Vector, int);

Data VectorGet(Vector, int);

int VectorIsEmpty(Vector);

int VectorSize(Vector);

void VectorClear(Vector);

void VectorPrint(Vector);

#endif  // _DYNAMIC_ARRAY_H_
