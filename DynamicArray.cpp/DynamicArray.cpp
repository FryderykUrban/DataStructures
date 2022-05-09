#pragma once
#include <iostream>
#include <fstream>
#include "DynamicArray.h"


DynamicArray::DynamicArray() {
    this->size = 0;
    this->table = new int[size];                
}

DynamicArray::~DynamicArray() {
    delete[] this->table;
    this->size = 0;
}

void DynamicArray::addAtEnd(int input) {   
    this->size++;
    int* tempTab = new int[this->size];         //zwiekszenie rozmiaru

    for (int i = 0; i < this->size; i++) {
        tempTab[i] = this->table[i];            //kopiowanie elementów z poprzedniej tablicy
    }

    delete[] table;
    tempTab[this->size - 1] = input;            //dodanie ostatniego elementu na koniec
    this->table = tempTab;
}

void DynamicArray::addAtBeggining(int input) {
    this->size++;
    int* tempTab = new int[this->size];

    for (int i = size-1; i > 0; i--) {
        tempTab[i] = this->table[i-1];
    }
    tempTab[0] = input;
    delete[] table;
    this->table = tempTab;
}

void DynamicArray::readFromFile() {
    
    std::string fileName;
    std::string line;
    std::cout << "Enter file name\n";                       //wczytanie nazwy pliku
    std::cin >> fileName;   
    std::ifstream file;                                     //stworzenie obiektu ifstream powiazanego z filename
    file.open(fileName);

    if (!file) {                                   // jesli nie udalo sie otworzyc pliku
        std::cout << "Error during opening file" << std::endl;
    }
    else {
        getline(file, line);
        int newSize = atoi(line.c_str());                       //funkcja zwracajaca wartosc lanucha znakow przekonwertowana na int
        this->table = new int[newSize];                         
        this->size = newSize;

        int i = 0;
        while (getline(file, line) && i < newSize) {                    //pobieranie kolejnych wartosci elementów i dodawanie ich na kolejne indexy tablicy
            this->table[i] = atoi(line.c_str());
            i++;
        }
        file.close();
    }
}

void DynamicArray::generateRandomData(int count) {
    int* randomTab = new int[count];                        //utworzenie tablicy o zadanej wielkosci

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        randomTab[i] = ((std::rand() % 100) + 1);               //wygenerowanie pseudolosowych watosci i wspianie ich do tablicy
    }

    delete[] this->table;
    this->size = count;
    this->table = randomTab;                                    //zamiana tablic
}

void DynamicArray::add(int index, int input) {

    this->size++;                                                                           
    int* tempTab = new int[this->size];

    if (index >= size)                                                      //w przypadku wyjscia poza obszar
        throw std::out_of_range("Inserting element outside of array!");

    for (int i = 0; i < this->size; i++) {
        if (i < index) { tempTab[i] = table[i]; }
        if (i == index) {                                                          
            tempTab[i] = input;
        } 
        else if (i > index) { tempTab[i] = table[i - 1]; }
    }
    delete[] table;
    this->table = tempTab;
}

void DynamicArray::removeAtEnd() {
    if (this->size != 0) {
        this->size--;
        int* tempTab = new int[this->size];

        for (int i = 0; i < this->size; i++) {
            tempTab[i] = this->table[i];
        }

        delete[] table;
        this->table = tempTab;
    }
    else std::cout << "Empty array" << std::endl;
}

void DynamicArray:: removeAtBeggining() {
    if (this->size != 0) {
    this->size--;
    int* tempTab = new int[this->size];

    for (int i = 0; i < this->size; i++) {
        tempTab[i] = this->table[i+1];
    }

    delete[] table;
    this->table = tempTab;
    }
    else std::cout << "Empty array" << std::endl;
}

void DynamicArray::remove(int index) {
    this->size--;
    int* tempTab = new int[this->size];
    int Iterator = 0;

    for (int tempIterator = 0; tempIterator < this->size; Iterator++) {
        if (Iterator != index) {
            tempTab[tempIterator++] = this->table[Iterator];
        }
    }

    delete[] table;
    this->table = tempTab;
}

std::string DynamicArray::search(int value) {
    std::string output = "";

    for (int i = 0; i < this->size; i++) {
        if (this->table[i] == value) {                                
            output += std::to_string(i);
            output += " ";
        }
    }
    return output;
}

std::string DynamicArray::show() {
    std::string output = "";

    for (int i = 0; i < this->size; i++) {
        output += std::to_string(this->table[i]);
        output += " ";
    }
    return output;
}

void DynamicArray::menu() {
    int userChoice, index;

    do {
     //   userChoice = 0;

        std::cout << "1.Add at beggining" << std::endl;
        std::cout << "2.Add at end" << std::endl;
        std::cout << "3.Add" << std::endl;
        std::cout << "4.Remove at beggining" << std::endl;
        std::cout << "5.Remove at end" << std::endl;
        std::cout << "6.Remove" << std::endl;
        std::cout << "7.Search" << std::endl;
        std::cout << "8.Read from file" << std::endl;
        std::cout << "9.Random" << std::endl;
        std::cout << "10.Show array" << std::endl;
        std::cout << "11.Exit" << std::endl;
        std::cin >> userChoice;
        switch (userChoice) {
        case 1: {
            std::cout << "Value you want to add: \n";
            std::cin >> userChoice;
            addAtBeggining(userChoice);
            break;
        }
        case 2: {
            std::cout << "Value you want to add: \n";
            std::cin >> userChoice;
            addAtEnd(userChoice);
            break;
        }
        case 3: {
            std::cout << "Value you want to add: \n";
            std::cin >> userChoice;
            std::cout << "Index you want to enter the value: \n";
            std::cin >> index;
            add(index, userChoice);
            break;
        }
        case 4: {
            std::cout << "Deleting value from beggining \n";
            removeAtBeggining();
            break;
        }
        case 5: {
            std::cout << "Deleting value from end \n";
            removeAtEnd();
            break;
        }
        case 6: {
            std::cout << "Index you want to delete: \n";
            std::cin >> userChoice;
            remove(userChoice);
            break;
        }
        case 7: {
            std::cout << "Value that you are looking for: \n";
            std::cin >> userChoice;
            std::string values;
            values = search(userChoice);
            if (values != "") {
                std::cout << "Found at index: " << values << std::endl;
            }
            else {
                std::cout << "Value does not exist" << std::endl;
            }
            break;
        }
        case 8: {
            readFromFile();
            break;
        }
        case 9: {
            std::cout << "How many values you want to generate: \n";
            std::cin >> userChoice;
            generateRandomData(userChoice);
            break;
        }
        case 10: {
            std::cout << show() << std::endl;
            break;
        }
        }
    } while (userChoice != 11);
}

