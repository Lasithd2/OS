#include<stdio.h>
#include<stddef.h>

char heap[25000];

struct LinkedList{
 size_t size;
 int free;
 struct LinkedList *next; 
};

struct LinkedList *freeList=(void*)heap;

void initialize();
void split(struct LinkedList *memoryBlock,size_t size);
void *MyMalloc(size_t requiredSize);
void merge();
void MyFree(void* pointer);
