#pragma once
#include <iostream>
#include <fstream>
#include "List.h"

listEl::listEl() {
    this->value = 0;
    this->next = NULL;
    this->prev = NULL;
}

listEl::~listEl() {};

List::List() {
    this->head = NULL;
}

List::~List(){};

void List::addAtBeggining(int value) {

    listEl* element = new listEl();
    element->next = head;	                    // przypisujemy stary element głowy do naszego elementu
    element->prev = NULL;	                    //element staje sie głowa czyli nie bedzie mial poprzedniego

    if (head) {                                  // jestli lista nie jest pusta
        head->prev = element;                    //to glowa staje sie wartoscią poprzednia czyli elementem
    }
    head = element;                             // glowa staje sie elementem i przypisujemy mu wartosc
    element->value = value;
}

void List::addAtEnd(int value) {

    listEl* element = new listEl(); 
    element->value = value;
    element->next = NULL;               //jesli na końcu to nie ma następnika

    if (this->head == NULL) {           //jesli jest pusta to staje sie glowa
        this->head = element;
        return;
    }

    listEl* temp = this->head;          
    while (temp->next != NULL) {
        temp = temp->next;                  //poprzednikiem glowy staje sie nowy element
    }                                       //nastepnikiem glowy staje sie nowy element

    temp->next = element;
    element->prev = temp;
}

void List::add(int value, int index) {

    if (index <= 0) {                           //jesli wartosc jest mniejsza lub =0 to dodajemy na poczatku
        addAtBeggining(value);
        return;
    }

    listEl* temp = head;
    listEl* element = new listEl();
    element->value = value;                     //tworzymy nowy element 
    int i = 0;
 
    while (temp != NULL) {
        if (temp->next == NULL) {           // jesli nie ma nastepnika
            temp->next = element;
            element->prev = temp;
            return;
        }
        if (i == index) {                                        
            temp->prev->next = element;                            //ustawiamy wskazniki elementów
            element->next = temp;
            element->prev = temp->prev;
            temp->prev = element;
            return;
        }
        i++;
        temp = temp->next;
    }
}

void List::generateRandomData(int size) {
  
    srand(time(NULL));
    int random = ((std::rand() % 100) + 1);

    listEl* element = new listEl();
    head = element;
    head->next = NULL;
    head->prev = NULL;
    head->value = random;

    for (int i = 0; i < size - 1; ++i) {            
        random = ((std::rand() % 100) + 1);
        listEl* element = new listEl();
        element->next = head;
        element->prev = NULL;

        if (head) {                             //dodajemy elementy tak jak w przypadku addAtBeggining
            head->prev = element;
        }
        head = element;
        element->value = random;
    }
}

void List::readFromFile() {

    std::string fileName;
    std::string line;
    std::cout << "Enter file name\n";
    std::cin >> fileName;                   //wczytanie nazwy pliku
    std::ifstream file;                     //stworzenie obiektu ifstream powiazanego z filename
    file.open(fileName);

    if (!file) {                                // jesli nie udalo sie otworzyc pliku
        std::cout << "Error during opening file" << std::endl;
    }
    else {
        getline(file, line);                            //pobranie linii
        int newSize = atoi(line.c_str());               //funkcja zwracajaca wartosc lanucha znakow przekonwertowana na int

        getline(file, line);
        listEl* element = new listEl();
        head = element;
        head->next = NULL;
        head->prev = NULL;
        head->value = atoi(line.c_str());

        int tempvalue;
        int i = 1;
        while (getline(file, line) && i < newSize) {
            tempvalue = atoi(line.c_str());                                                 //wczytywanie kolejnych wartosci elementów

            element = new listEl();
            listEl* temp = head;                    
            while (temp->next != NULL) {
                temp = temp->next;
            }
            element->value = tempvalue;                     //ywstawienie wskaznikow elementów
            element->next = NULL;
            temp->next = element;
            element->prev = temp;
            i++;
        }
        file.close();
    }
}

listEl *List::search(int value) {                   

    listEl* temp = head;
    while (temp != NULL) {
        if (temp->value == value) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void List::removeAtBeggining() {
    if (head == NULL) {                                                     //jesli lsita pusta
        std::cout << "No values to delete" << std::endl;
    }
    else {
        listEl* temp = head;
        head = head->next;
        if (head != NULL) {                     //jesli istenieje next to usuwamy jego wskaznik na poprzedzający element
            head->prev = NULL;
        }
        delete temp;                            //usuwamy element
    }
}

void List::removeAtEnd() {
    if (head == NULL) {                                                         //jesli list pusta
        std::cout << "No values to delete" << std::endl;
    }
    else {
        listEl* temp = NULL;
        listEl* lastelement = head;
        if (lastelement->next == NULL) {
            removeAtBeggining();
            return;
        }   
        while (lastelement->next != NULL) {             //szukamy ostatniego elementu czyli takiego bez nastepnika
            lastelement = lastelement->next;
        }
        temp = lastelement;                              
        lastelement = lastelement->prev;                    //temp staje sie ostatnim elementem, ostatni element staje sie poprzednikiem i kasujemy temp
        lastelement->next = NULL;
        delete temp;
    }
    
}

void List::remove(int index) {
    if (head == NULL) {
        std::cout << "No values to delete" << std::endl;
    }
    else {
        listEl* temp = head;
        int counter = 0;
        while (temp->next != NULL) {                //zliczenie elementów
            ++counter;
            temp = temp->next;
        }
        temp = head;
        if (counter <= index) {                                               //usuniecie z konca
            removeAtEnd();
        }
        else if (index == 0) {                                               //z poczatku
            removeAtBeggining();
        }
        else {
            counter = 1;                            //zaczynamy od pierwszego elemetu i dochodzimy do indexu
            while (counter <= index) {
                temp = temp->next;
                ++counter;
            }
            listEl* indexnode = new listEl();               //ustawienie wartosci wskazników
            indexnode = temp;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete indexnode;
        }
    }
}

std::string List::show() {
    std::string output = "";
    listEl* temp = head;
    if (temp != NULL) {
        do {

            output += std::to_string(temp->value);
            output += " ";
            temp = temp->next;

        } while (temp != nullptr);
    }
    else std::cout << "Empty";
    return output;
}

void List::menu() {
    int userChoice, index;
    listEl* element;

    do {
        std::cout << "1.Add at beggining" << std::endl;
        std::cout << "2.Add at end" << std::endl;
        std::cout << "3.Add" << std::endl;
        std::cout << "4.Remove at beggining" << std::endl;
        std::cout << "5.Remove at end" << std::endl;
        std::cout << "6.Remove" << std::endl;
        std::cout << "7.Search" << std::endl;
        std::cout << "8.Read from file" << std::endl;
        std::cout << "9.Random" << std::endl;
        std::cout << "10.Show list" << std::endl;
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
            std::cout << "Index: \n";
            std::cin >> userChoice;
            std::cout << "Value: \n";
            std::cin >> index;
            add(index, userChoice);
            break;
        }
        case 4: {
            removeAtBeggining();
            break;
        }
        case 5: {
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

            element = search(userChoice);
            if (element == NULL) {
                std::cout << "Value does not exist" << std::endl;
            }
            else {
                std::cout << "Value exists" << std::endl;
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