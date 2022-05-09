#pragma once
#include <string>

class Heap {

public:
	void add(int value);		//dodanie wartosci do kopca oraz przywrócenie jego własności
	void remove();				//usunięcie korzenia
	void search(int elem);		// wyszukiwanie wartosci	
	void readFromFile();		//wczytanie danych z pliku	
	std::string show();			// wyswietlenie kopca
	void generateRandomData(int size);	//generowanie pseudolosowych danych
	void menu();						// menu wyboru opcji w kopcu

private:
	int* heap = { nullptr };
	int size = 0;
	void heapify(int pos);				//wartosc maksymalna na górze
	void repairHeap();					//przywrócenie własności kopca
	int parent(int pos);				//pozycja rodzica
	int leftChild(int pos);				// pozycja lewego dziecka
	int rightChild(int pos);			// pozycja prawego dziecka


};

