#pragma once
#include <string>


    class DynamicArray {

    public:
        int* table;
        int size;

        DynamicArray();                 //konstruktor
        ~DynamicArray();                //destruktor

        void addAtEnd(int input);           //dodanie wartosci na koniec
        void add(int index, int input);     //dodanie na index
        void addAtBeggining(int input);     //dodanie na początek
        void removeAtBeggining();           //usuniecie początek
        void removeAtEnd();                 //usunięcie koniec
        void remove(int index);              //usuniecie z indexu
        std::string search(int value);       //wyszukanie wartosci
        void menu();                        //menu wyboru
        std::string show();                 //wyswietlenie
        void generateRandomData(int count);     //generowanie pseudolosowych liczb
        void readFromFile();                    //wczytywanie danych z pliku

    };



