#include "min_stack.h"

#include <limits.h>
#include <stdlib.h>

MinStack *minStackCreate(int maxSize) {
    MinStack *stack = (MinStack *) malloc(sizeof(MinStack));
    stack->data = (int *) malloc(maxSize * sizeof(int));
    stack->min = (int *) malloc(maxSize * sizeof(int));
    stack->capacity = maxSize;
    stack->top = -1;
    return stack;
}

void minStackPush(MinStack *obj, int x) {
    int top = obj->top + 1;
    if (top >= obj->capacity)
        return;
    obj->data[top] = x;
    int *min = obj->min;
    if (top == 0 || min[top - 1] >= x)
        min[top] = x;
    else
        min[top] = min[top - 1];
    obj->top = top;
}

void minStackPop(MinStack *obj) {
    int top = obj->top;
    if (top < 0) return;
    obj->top = top - 1;
}

int minStackTop(MinStack *obj) {
    int top = obj->top;
    if (top < 0) return INT_MAX;
    return obj->data[top];
}

int minStackGetMin(MinStack *obj) {
    int top = obj->top;
    if (top < 0) return INT_MAX;
    return obj->min[top];
}

void minStackFree(MinStack *obj) {
    free(obj->data);
    free(obj);
}
