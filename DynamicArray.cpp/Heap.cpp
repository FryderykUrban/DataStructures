#pragma once
#include "Heap.h"
#include <iostream>
#include <fstream>

void Heap::add(int value) {
	
		int* newHeap = new int[this->size + 1];					 //nowa tablica wieksza o 1 element
		newHeap[this->size] = value;							//ustawienie wartosci na koniec nowej tablicy
		
		if (this->heap != NULL) {                   
			for (int i = 0; i < this->size; i++) {
				newHeap[i] = this->heap[i];						//kopjujemy wartości poprzedniej tablicy do nowej
			}
			delete[] this->heap;							   //usuwamy starą tablicę
		}

		this->size++;										//zwiększamy rozmiar tablicy
		this->heap = newHeap;								//stara tablica na nową
		repairHeap();										// przywrócenie wlasnosci kopca
	}

void Heap::heapify(int index) {
	
	
	if (index > (size / 2) && index <= size)					//odrzucenie korzenia oraz wyjscia poza rozmiar
		return;
	int bigger = index;
	if (this->heap[bigger] < this->heap[leftChild(index)] && leftChild(index) < this->size) {   //sprawdzenie która wartosc jest wieksza
		bigger = leftChild(index);
	}
	if (this->heap[bigger] < this->heap[rightChild(index)] && rightChild(index) < this->size) {
		bigger = rightChild(index);
	}

	if (this->heap[index] != this->heap[bigger]) {
		int temp;
		temp = this->heap[index];							//zamiana miejscami wartosci
		this->heap[index] = this->heap[bigger];
		this->heap[bigger] = temp;
		heapify(bigger);									//wywolanie heapify dla indexu wiekszej wartosci oraz ponowne dla indexu poniewaz wartosc w nim sie zmienila
		heapify(index);
	}
}

void Heap::remove() {	

	if (this->heap[0] != NULL) {							//jesli pusty to wyswietl wiadomosc
		this->heap[0] = this->heap[this->size - 1];			//zamiana korzenia z ostatnim najmniejszym elementem
		size--;												//zmniejszenie rozmiaru
		heapify(0);											//przywrócenie max do korzenia
		
	}
	else { std::cout << "empty, not deleting" << std::endl; }
}

void Heap::search(int elem) {
	 
	int count = 0;							//zliczenie ilosci wystapien elemntu w kopcu
	for (int i = 0; i < size; i++) {		//jesli wystepuje wartosc bedzie !=0
		if (this->heap[i] == elem) {
			count++;
		}
	}
	if (!count == 0) {
		std::cout << "The value exist in heap" << std::endl;
	}
	else {
		std::cout << "The value does not exist in heap" << std::endl;
	}
}

void Heap::readFromFile() {
	std::string fileName;
	std::string line;
	std::cout << "Enter file name\n";
	std::cin >> fileName;
	std::ifstream file;						//stworzenie obiektu ifstream powiazanego z filename
	file.open(fileName);

	if (!file) {                              // jesli nie udalo sie otworzyc pliku
		std::cout << "Error during opening file" << std::endl;
	}
	else {
		
		this->heap = new int[size + 1];
		int newSize= 0;
		getline(file, line);								//pobranie lini
		newSize = atoi(line.c_str());						//funkcja zwracajaca wartosc lanucha znakow przekonwertowana na int
		
		for (int i = 0; i < newSize; i++) {
			getline(file, line);
			add(atoi(line.c_str()));					//dodaje kolejne wczytane wartosci do kopca
		}
		file.close();										//zakonczenie operacji na pliku
	}
}

std::string Heap::show() {
	int height = floor(log2(this->size));
	int width = pow(2, height) * 2;
	int aHeight = 0;
	int bigSpaceSize = 0;
	double smallSpaceSize = 0;
	double bigSpaceCounter = 0;
	int heapIterator = 0;


	std::string output = "";

	for (; aHeight <= height; aHeight++) {
		bigSpaceCounter = pow(2, aHeight) - 1;		//ilość
		bigSpaceSize = smallSpaceSize;
		smallSpaceSize = pow(2, height - aHeight) - 1;


		for (int i = 0; i < smallSpaceSize; i++) {		//..wyspacjowanie"
			output += " ";
		}
		do {
			if (heapIterator + 1 <= this->size) {				//pobranie elementu a jesli nie to miejsce dalej
				output += std::to_string(this->heap[heapIterator++]);
			}
			else {
				output += " ";
			}
			if (bigSpaceCounter > 0) {						//miejsce w druga strone
				for (int i = 0; i < bigSpaceSize; i++) {
					output += " ";
				}
			}
		} while (bigSpaceCounter-- > 0);
		for (int i = 0; i < smallSpaceSize; i++) {
			output += " ";
		}
		output += '\n';                                //newline
	}
	return output;


}

void Heap::generateRandomData(int sizeNew) {

	this->heap = new int[size + 1];											
	srand(time(NULL));
	int random = 0;
	
	for (int i = 0; i < sizeNew; ++i) {						
		random = ((std::rand() % 100) + 1);					//wygenerowanie pseudorandomowej wartosci z podanego zakresu i dodanie jej do kopca
		add(random);
	}
	this->size = sizeNew;									//przypisanie nowego rozmiaru
}

int Heap::leftChild(int index) {				//zwraca wartosc która odpowiada wartosci lewego potomka dla zadanego indeksu 
		if (index == 0) {
			return  1;
		}
		else {
			return index * 2;
		}
	}
	
int Heap::rightChild(int index) {				//zwraca wartosc która odpowiada wartosci prawego potomka dla zadanego indeksu 
		if (index == 0) {
			return 2;
		}
		else {
			return index * 2 + 1;
		}
	}

int Heap::parent(int index) {					//zwraca wartosc która odpowiada wartosci rodzica dla zadanego indeksu 
		return floor(index / 2);
	}

void Heap::repairHeap() {																	//przywrócenie własności kopca
		int last = this->size - 1;
		while (this->heap[last] > this->heap[parent(last)]) {				//jestli rodzic ma wieksza wartosc to zamieniamy miejscami
			int temp;
			temp = this->heap[last];
			this->heap[last] = this->heap[parent(last)];
			this->heap[parent(last)] = temp;
			last = parent(last);											//ustawienie elementu ostatni na ten zamieniony
		}
	}
	
void Heap::menu() {
	int userChoice;

	do {
		std::cout << "1.Add" << std::endl;
		std::cout << "2.Remove " << std::endl;
		std::cout << "3.Search" << std::endl;
		std::cout << "4.Read from file" << std::endl;
		std::cout << "5.Random" << std::endl;
		std::cout << "6.Show heap" << std::endl;
		std::cout << "7.Exit" << std::endl;
		std::cin >> userChoice;
		switch (userChoice) {
		case 1: {
			std::cout << "Value you want to add: \n";
			std::cin >> userChoice;
			add(userChoice);
			break;
		}
		case 2: {
			std::cout << "Deleting root \n";
			remove();
			break;
		}
		case 3: {
			std::cout << "Value that you are looking for: \n";
			std::cin >> userChoice;
			search(userChoice);
			break;
		}
		case 4: {
			readFromFile();
			break;
		}
		case 5: {
			std::cout << "How many values you want to generate: \n";
			std::cin >> userChoice;
			generateRandomData(userChoice);
			break;
		}
		case 6: {
			std::cout << show() << std::endl;
			break;
		}
		}
	} while (userChoice != 7);
}

	
