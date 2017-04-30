#include <iostream>
#include "header.h"
#include "Algorithms.h"
#include "Memory.h"
using namespace std;

//https://www.ii.pwr.edu.pl/~juszczyszyn/so.htm

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	auto czyPowtorzyc = true;
	auto answer = 't';
	
	auto r = 10, s = 20, o = 1000;
	
	while (czyPowtorzyc) {
		//Ustawianie parametrow
		cout << "\nPodaj ilosc ramek: ";
		cin >> r;
		cout << "Podaj ilosc stron: ";
		cin >> s;
		cout << "Podaj ilosc odwolan: ";
		cin >> o;
		cout << endl;

		Memory mem(r, s, o);
	
		//Wykonanie algorytmow
		Algorithms::FIFO(mem);
		Algorithms::OPT(mem);
		Algorithms::LRU(mem);
		Algorithms::ALRU(mem);
		Algorithms::RAND(mem);
		
		//Opcja wyjscia z petli
		cout << "\nCzy wykonac ponownie? t/n\n";
		cin >> answer;
		if (answer == 'N' || answer == 'n')
		{
			czyPowtorzyc = false;
		}
	}
	
}