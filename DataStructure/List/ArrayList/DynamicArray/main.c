#include <stdio.h>
#include "dynamic_array.h"

int main(void)
{
    Vector v = VectorCreate();
    for (int i = 0; i < 10; ++i)
        VectorAdd(v, i);
    
    VectorPrint(v);
    return 0;
}
