#include <iostream>
#include "DynamicArray.h"
#include "List.h"
#include "Heap.h"
#include "Tests.h"


int main() {
    Tests test;
    Heap heap;
    List list;
    DynamicArray dynamicarray;
    int userChoice;

    do {
        userChoice = 0;
        std::cout << "1.Dynamic Array" << std::endl;
        std::cout << "2.List" << std::endl;
        std::cout << "3.BinHeap" << std::endl;
        std::cout << "4.Time" << std::endl;
        std::cout << "5.Exit" << std::endl;
        std::cin >> userChoice;

        switch (userChoice) {
        case 1: {
            dynamicarray.menu();
        }
              break;
        case 2: {
            list.menu();
        }
              break;
        case 3: {
            heap.menu();
        }
              break;
        case 4: {
            test.arrayTest();
            test.listTest();
            test.heapTest();
        }
              break;
    }
    } while (userChoice != 5);
    return  0;

}