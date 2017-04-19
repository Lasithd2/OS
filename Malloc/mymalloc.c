#include<stdio.h>
#include<stddef.h>
#include "mymalloc.h"

void initialize(){
     
     freeList->size=25000-sizeof(struct LinkedList);
     freeList->free=1;
     freeList->next=NULL;
     }

void split(struct LinkedList *memoryBlock,size_t size){
     
     struct LinkedList *new=(void*)((void*)memoryBlock+size+sizeof(struct LinkedList));
     new->size=(memoryBlock->size)-size-sizeof(struct LinkedList);
     new->free=1;
     new->next=memoryBlock->next;
     memoryBlock->size=size;
     memoryBlock->free=0;
     memoryBlock->next=new;
     }

void *MyMalloc(size_t requiredSize){
     
     
     struct LinkedList *cur,*prev;
 
     void *startAdress;
 
     if((freeList->size==0)){
                             
        initialize();
        printf("heap initialized\n");
        }
        cur=freeList;
     
     while((((cur->size)<requiredSize)||((cur->free)==0))&&(cur->next!=NULL)){
         prev=cur;
         cur=cur->next;
         }
         
      if((cur->size)==requiredSize){
                                   
            cur->free=0;
            startAdress=(void*)(++cur);
            printf("Memory block with required size found");
            return startAdress;
            }
                                   
      else if((cur->size)>(requiredSize+sizeof(struct LinkedList))){
            split(cur,requiredSize);
            startAdress=(void*)(++cur);
            printf("Memory block larger than required size found\n");
            return startAdress;
            }
     else{
            startAdress=NULL;
            printf("No sufficient space in heap to allocate\n");
            return startAdress;
         }
}

void merge(){
     
     struct LinkedList *cur,*prev;
     cur=freeList;
     while((cur!=NULL) && (cur->next!=NULL)){
     if((cur->free) && (cur->next->free)){
                    
          cur->size=cur->size+(cur->next->size)+sizeof(struct LinkedList);
          cur->next=cur->next->next;
          }
     prev=cur;
     cur=cur->next;
     }
}

void MyFree(void* pointer){
     
     struct LinkedList* cur=pointer;
     --cur;
     cur->free=1;
     merge();
    
 
}
