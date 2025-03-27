#include <graphics.h>
#include <iostream>
#include <conio.h> 
#include <sstream> 
#include "header.h"

void memoryOperations(MemoryManager& memoryManager) {
    int key;
    std::string input;
    bool running = true;

    while (running) {
        cleardevice();

        setcolor(WHITE);
        outtextxy(50, 30, const_cast<char*>("Press the following keys:"));
        line(55,40,90,40);
        outtextxy(50, 50, const_cast<char*>("'a' -> Allocate memory"));
        outtextxy(50, 70, const_cast<char*>("'d' -> Deallocate memory at address"));
        outtextxy(50, 90, const_cast<char*>("'q' -> Quit"));
        outtextxy(50, 90, const_cast<char*>("'Press Enter key to proceed next'"));
        

		memoryManager.waitForEnter();
		
        memoryManager.displayVisualization();

        key = getch();

        switch (key) {
        case 'a': {
            int y = 50;
            MemoryBlock* current = memoryManager.head;
            while (current) {
                y += 30 + 10;  //block height+gap
                current = current->next;
            }

            outtextxy(50, y + 10, const_cast<char*>("Enter memory size to allocate:"));
            input = "";
            while (true) {
                key = getch();
                if (key == 13) {  
                    break;
                } else if (key == 8 && !input.empty()) {  
                    input.erase(input.size() - 1, 1);  
                    outtextxy(50, y + 30, const_cast<char*>("                    "));  
                    outtextxy(50, y + 30, const_cast<char*>(input.c_str()));
                } else {
                    input += static_cast<char>(key);
                    outtextxy(50, y + 30, const_cast<char*>(input.c_str()));
                }
            }

            std::istringstream(input) >> key;
            memoryManager.allocate(key);
            break;
        }

        case 'd': {
            int y = 50;
            MemoryBlock* current = memoryManager.head;
            while (current) {
                y += 30 + 10;  // Block height + gap
                current = current->next;
            }

            outtextxy(50, y + 10, const_cast<char*>("Enter start address to deallocate:"));
            input = "";
            while (true) {
                key = getch();
                if (key == 13) {  
                    break;
                } else if (key == 8 && !input.empty()) {  
                    input.erase(input.size() - 1, 1);  
                    outtextxy(50, y + 30, const_cast<char*>("                    "));
                    outtextxy(50, y + 30, const_cast<char*>(input.c_str()));
                } else {
                    input += static_cast<char>(key);
                    outtextxy(50, y + 30, const_cast<char*>(input.c_str()));
                }
            }

            std::istringstream(input) >> key;
            memoryManager.deallocate(key);
            break;
        }

        case 'q':
            running = false;
            break;

        default:
            setcolor(RED);
            outtextxy(50, 150, const_cast<char*>("Invalid key pressed. Try 'A', 'D', or 'Q'."));
            break;
        }

        delay(1000);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\include");

    MemoryManager memoryManager(200);

    memoryOperations(memoryManager);  

    closegraph();  
    return 0;
}
