#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define INITIAL_CAPACITY 10
#define GROWTH_FACTOR 2

typedef struct {
    int *values;
    int size;
    int capacity;
} DynamicArray;

typedef struct {
    DynamicArray *uniqueValues; // Use a dynamic array for unique values
} RandomSet;

DynamicArray* createDynamicArray(int capacity) {
    DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    arr->values = (int*)malloc(sizeof(int) * capacity);
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

void resizeDynamicArray(DynamicArray *arr) {
    arr->capacity *= GROWTH_FACTOR;
    arr->values = (int*)realloc(arr->values, sizeof(int) * arr->capacity);
}

void insertDynamicArray(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        resizeDynamicArray(arr);
    }
    arr->values[arr->size++] = value;
}

bool containsDynamicArray(DynamicArray *arr, int value) {
    for (int i = 0; i < arr->size; ++i) {
        if (arr->values[i] == value) {
            return true;
        }
    }
    return false;
}

void destroyDynamicArray(DynamicArray *arr) {
    free(arr->values);
    free(arr);
}

RandomSet* createSet() {
    RandomSet *set = (RandomSet*)malloc(sizeof(RandomSet));
    set->uniqueValues = createDynamicArray(INITIAL_CAPACITY);
    return set;
}

bool contains(RandomSet *set, int value) {
    return containsDynamicArray(set->uniqueValues, value);
}

void insert(RandomSet *set, int value) {
    if (!contains(set, value)) {
        insertDynamicArray(set->uniqueValues, value);
    }
}

void removeValue(RandomSet *set, int value) {
    for (int i = 0; i < set->uniqueValues->size; ++i) {
        if (set->uniqueValues->values[i] == value) {
            // Swap with the last element and reduce size
            set->uniqueValues->values[i] = set->uniqueValues->values[set->uniqueValues->size - 1];
            set->uniqueValues->size--;
            return;
        }
    }
}

int getRandom(RandomSet *set) {
    if (set->uniqueValues->size > 0) {
        int randomIndex = rand() % set->uniqueValues->size;
        return set->uniqueValues->values[randomIndex];
    } else {
        return -1;
    }
}

void printSet(RandomSet *set) {
    printf("Set: { ");
    for (int i = 0; i < set->uniqueValues->size; ++i) {
        printf("%d ", set->uniqueValues->values[i]);
    }
    printf("}\n");
}

void destroySet(RandomSet *set) {
    destroyDynamicArray(set->uniqueValues);
    free(set);
}

int main() {
    srand((unsigned int)time(NULL));

    RandomSet *mySet = createSet();

    insert(mySet, 5);
    insert(mySet, 10);
    insert(mySet, 15);
    insert(mySet, 20);
    insert(mySet, 25);

    printSet(mySet);

    removeValue(mySet, 15);

    printSet(mySet);

    int randomValue = getRandom(mySet);
    printf("Random Value: %d\n", randomValue);

    destroySet(mySet);

    return 0;
}
