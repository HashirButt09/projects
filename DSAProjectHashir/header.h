#ifndef HEADER_H
#define HEADER_H
#include <graphics.h>
#include <iostream>

struct MemoryBlock {
    int start;        
    int size;         
    bool isFree;      
    MemoryBlock* next; 

    MemoryBlock(int s, int sz);
};

struct MemoryManager {
    MemoryBlock* head;

    MemoryManager(int totalSize);
    ~MemoryManager();

    void allocate(int size);
    void deallocate(int startAddress);

    void display();
    void mergeBlocks();
    void displayVisualization();
    void displayError(const char* message);
    void waitForEnter();
};

#endif 

