#include "header.h"

MemoryBlock::MemoryBlock(int s, int sz) : start(s), size(sz), isFree(true), next(NULL) {}

MemoryManager::MemoryManager(int totalSize) {
    head = new MemoryBlock(0, totalSize);
}

MemoryManager::~MemoryManager() {
    MemoryBlock* current = head;
    while (current) {
        MemoryBlock* temp = current;
        current = current->next;
        delete temp;
    }
}

void MemoryManager::allocate(int size) {
    MemoryBlock* current = head;
    while (current) {
        if (current->isFree && current->size >= size) {
            int remainingSize = current->size - size;
            current->isFree = false;
            current->size = size;

            if (remainingSize > 0) {
                MemoryBlock* newBlock = new MemoryBlock(current->start + size, remainingSize);
                newBlock->next = current->next;
                current->next = newBlock;
            }

            std::cout << "Allocated memory block starting at " << current->start << " with size " << size << ".\n";
            displayVisualization();
            return;
        }
        current = current->next;
    }
    std::cout << "Failed to allocate memory. Not enough free space.\n";
    displayError("Failed to allocate memory.");
}

void MemoryManager::deallocate(int startAddress) {
    MemoryBlock* current = head;
    while (current) {
        if (current->start == startAddress && !current->isFree) {
            current->isFree = true;
            std::cout << "Deallocated memory block starting at " << startAddress << ".\n";
            mergeBlocks();
            displayVisualization();
            return;
        }
        current = current->next;
    }
    std::cout << "No allocated block found at address " << startAddress << ".\n";
    displayError("Memory block not found.");
}

void MemoryManager::display() {
    MemoryBlock* current = head;
    std::cout << "\nMemory Blocks:\n";
    std::cout << "Start\tSize\tStatus\n";
    while (current) {
        std::cout << current->start << "\t" << current->size << "\t" << (current->isFree ? "Free" : "Used") << "\n";
        current = current->next;
    }
}

void MemoryManager::mergeBlocks() {
    if (!head) return;

    MemoryBlock* current = head;

    while (current && current->next) {
        if (current->isFree && current->next->isFree) {
            // Merge the current and next free blocks
            current->size += current->next->size;
            MemoryBlock* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next; // Move to the next block
        }
    }
}



void MemoryManager::displayVisualization() {
    int x = 50, y = 50;
    int blockHeight = 30;

    cleardevice();  

    MemoryBlock* current = head;
    while (current) {
        int color = current->isFree ? GREEN : RED;
        setfillstyle(SOLID_FILL, color);
        bar(x, y, x + current->size, y + blockHeight);

        setcolor(WHITE);
        char buffer[50];
        sprintf(buffer, "Start: %d, Size: %d", current->start, current->size);
        outtextxy(x + 5, y + 5, buffer);

        y += blockHeight + 10;
        current = current->next;
    }

    delay(1000);  
}

void MemoryManager::displayError(const char* message) {
    setcolor(RED);
    char tempMessage[255];  
    strcpy(tempMessage, message);  

    outtextxy(50, 200, tempMessage);
}

void MemoryManager::waitForEnter() {
    while (true) {
        int key = getch();
        if (key == 13) { 
            break;
        }
    }
}