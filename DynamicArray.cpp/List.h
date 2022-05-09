#pragma once
#include <string>


class listEl                        //deklaracja elementu listy
{
public:
    listEl* prev, * next;
    int value;
    listEl();
    ~listEl();
};

class List {
    private:
        listEl* head, * tail;

    public:
        List();                             //konstruktor
        ~List();                            //destruktor
        void addAtEnd(int input);           //dodanie wartosci na koniec
        void add(int index, int input);     //dodanie wartosci na index
        void addAtBeggining(int input);     // dodanie wartosci na poczatek
        void removeAtBeggining();           //usuniecie poczatek
        void removeAtEnd();                 //usuniecie koniec
        void remove(int index);             //usuniecie z indexu
        listEl * search(int value);         //wyszukanie wartosci
        void menu();                        // menu wyboru
        std::string show();                 //wyswietlenie
        void generateRandomData(int count); //generowanie pseudolosowych liczb
        void readFromFile();                //wczytywanie danych z pliku
       
    };
    

