#include <iostream>
#include "DynamicArray.h"
#include "List.h"
#include "Heap.h"
#include "Tests.h"
#include "Time.h"


using namespace std;
DynamicArray dynamicarray;
List list;
Heap heap;
Time timee;
double timeSum = 0;
double timeAvg = 0;
int numberOfTests = 100;
int randomIndex=0;
int randomValue = 0;

void addBegginingTest(int dataCount) {
  
    for (int i = 0; i < numberOfTests; i++) {
        dynamicarray.generateRandomData(dataCount);
        timee.startTime();
        dynamicarray.addAtBeggining(12);
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "Add at Beggining test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void addEndTest(int dataCount) {
   
    for (int i = 0; i < numberOfTests; i++) {
        dynamicarray.generateRandomData(dataCount);
        timee.startTime();
        dynamicarray.addAtEnd(12);
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "Add at End test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void addTest(int dataCount) {
    
   
    for (int i = 0; i < numberOfTests; i++) {
        randomIndex = ((std::rand() % dataCount));
        dynamicarray.generateRandomData(dataCount);
        timee.startTime();
        dynamicarray.add(randomIndex, 10);
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "Add test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void removeBegginingTest(int dataCount) {

    for (int i = 0; i < numberOfTests; i++) {
        dynamicarray.generateRandomData(dataCount);
        timee.startTime();
        dynamicarray.removeAtBeggining();
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "Remove Beggining test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void removeEndTest(int dataCount) {

    for (int i = 0; i < numberOfTests; i++) {
        dynamicarray.generateRandomData(dataCount);
        timee.startTime();
        dynamicarray.removeAtEnd();
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "Remove End test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void removeTest(int dataCount) {
  
    for (int i = 0; i < numberOfTests; i++) {
        randomIndex = ((std::rand() % dataCount));
        dynamicarray.generateRandomData(dataCount);
        timee.startTime();
        dynamicarray.remove(randomIndex);
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "Remove test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void searchTest(int dataCount) {
    
    for (int i = 0; i < numberOfTests; i++) {
        randomValue = ((std::rand() % 1000));
        dynamicarray.generateRandomData(dataCount);
        timee.startTime();
        dynamicarray.search(randomValue);
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "Search test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void Tests::arrayTest() {
     addBegginingTest(1000);
     addBegginingTest(2000);
     addBegginingTest(5000);
     addBegginingTest(10000);
     addBegginingTest(20000);
  

     addEndTest(1000);
     addEndTest(2000);
     addEndTest(5000);
     addEndTest(10000);
     addEndTest(20000);
   
     addTest(1000);
     addTest(2000);
     addTest(5000);
     addTest(10000);
     addTest(20000);

     removeBegginingTest(1000);
     removeBegginingTest(2000);
     removeBegginingTest(5000);
     removeBegginingTest(10000);
     removeBegginingTest(20000);


     removeEndTest(1000);
     removeEndTest(2000);
     removeEndTest(5000);
     removeEndTest(10000);
     removeEndTest(20000);

     removeTest(1000);
     removeTest(2000);
     removeTest(5000);
     removeTest(10000);
     removeTest(20000);


     searchTest(1000);
     searchTest(2000);
     searchTest(5000);
     searchTest(10000);
     searchTest(20000);
}


void addLBegginingTest(int dataCount) {

    for (int i = 0; i < numberOfTests; i++) {
        list.generateRandomData(dataCount);
        timee.startTime();
        list.addAtBeggining(12);
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "L: Add at Beggining test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void addLEndTest(int dataCount) {

    for (int i = 0; i < numberOfTests; i++) {
        list.generateRandomData(dataCount);
        timee.startTime();
        list.addAtEnd(12);
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "L: Add at End test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void addLTest(int dataCount) {


    for (int i = 0; i < numberOfTests; i++) {
        randomIndex = ((std::rand() % dataCount));
        list.generateRandomData(dataCount);
        timee.startTime();
        list.add(randomIndex, 10);
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "L: Add test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void removeLBegginingTest(int dataCount) {

    for (int i = 0; i < numberOfTests; i++) {
        list.generateRandomData(dataCount);
        timee.startTime();
        list.removeAtBeggining();
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "L: Remove Beggining test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void removeLEndTest(int dataCount) {

    for (int i = 0; i < numberOfTests; i++) {
        list.generateRandomData(dataCount);
        timee.startTime();
        list.removeAtEnd();
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "L: Remove End test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void removeLTest(int dataCount) {

    for (int i = 0; i < numberOfTests; i++) {
        randomIndex = ((std::rand() % dataCount));
        list.generateRandomData(dataCount);
        timee.startTime();
        list.remove(randomIndex);
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "L: Remove test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void searchLTest(int dataCount) {

    for (int i = 0; i < numberOfTests; i++) {
        randomValue = ((std::rand() % 1000));
        list.generateRandomData(dataCount);
        timee.startTime();
        list.search(randomValue);
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "L: Search test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void Tests::listTest() {
    addLBegginingTest(1000);
    addLBegginingTest(2000);
    addLBegginingTest(5000);
    addLBegginingTest(10000);
    addLBegginingTest(20000);


    addLEndTest(1000);
    addLEndTest(2000);
    addLEndTest(5000);
    addLEndTest(10000);
    addLEndTest(20000);

    addLTest(1000);
    addLTest(2000);
    addLTest(5000);
    addLTest(10000);
    addLTest(20000);


    removeLBegginingTest(1000);
    removeLBegginingTest(2000);
    removeLBegginingTest(5000);
    removeLBegginingTest(10000);
    removeLBegginingTest(20000);


    removeLEndTest(1000);
    removeLEndTest(2000);
    removeLEndTest(5000);
    removeLEndTest(10000);
    removeLEndTest(20000);

    removeLTest(1000);
    removeLTest(2000);
    removeLTest(5000);
    removeLTest(10000);
    removeLTest(20000);


    searchLTest(1000);
    searchLTest(2000);
    searchLTest(5000);
    searchLTest(10000);
    searchLTest(20000);
}

void addHTest(int dataCount) {

    for (int i = 0; i < numberOfTests; i++) {
        randomValue = ((std::rand() % dataCount));
        heap.generateRandomData(dataCount);
        timee.startTime();
        heap.add(randomValue);
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "H: Add test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void removeHTest(int dataCount) {

    for (int i = 0; i < numberOfTests; i++) {
        heap.generateRandomData(dataCount);
        timee.startTime();
        heap.remove();
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "H: Remove test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void searchHTest(int dataCount) {

    for (int i = 0; i < numberOfTests; i++) {
        randomValue = ((std::rand() % 1000));
        heap.generateRandomData(dataCount);
        timee.startTime();
        heap.search(randomValue);
        timeSum += timee.getTime();
    }
    timeAvg = timeSum / numberOfTests;
    std::cout << "H: Search test for " << dataCount << " elements : " << timeAvg << std::endl;
}

void Tests::heapTest() {
   
    addHTest(1000);
    addHTest(2000);
    addHTest(5000);
    addHTest(10000);
    addHTest(20000);


    removeHTest(1000);
    removeHTest(2000);
    removeHTest(5000);
    removeHTest(10000);
    removeHTest(20000);


    searchHTest(1000);
    searchHTest(2000);
    searchHTest(5000);
    searchHTest(10000);
    searchHTest(20000);
}