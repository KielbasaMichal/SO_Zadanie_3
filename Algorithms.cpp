#include "Algorithms.h"



Algorithms::Algorithms()
{
}


Algorithms::~Algorithms()
{
}

void Algorithms::FIFO(Memory mem)
{
	int bledy = 0;
	for (int i = 0; i < mem.liczbaOdwolan; i++) 
	{
		if (!mem.czyJest(mem.Odwolania[i])) 
		{
			bledy++;
			if (!mem.czyPelna())
				mem.wstawStrone(mem.Odwolania[i]);
			else {
				mem.usunFIFO();
				mem.wstawStrone(mem.Odwolania[i]);
			}
		}
	}
	std::cout << "Ilosc bledow dla FIFO: " << bledy << std::endl;
	mem.wyczysc();
}

void Algorithms::LRU(Memory l)
{
	int bledy = 0;
	for (int i = 0; i < l.liczbaOdwolan; i++) {
		if (!l.czyJest(l.Odwolania[i])) {
			bledy++;
			if (!l.czyPelna()) l.wstawStrone(l.Odwolania[i]);
			else {
				l.usunLRU(i);
				l.wstawStrone(l.Odwolania[i]);
			}
		}
	}
	std::cout << "Ilosc bledow dla LRU: " << bledy << std::endl;
	l.wyczysc();

}

void Algorithms::OPT(Memory l)
{
	int bledy = 0;
	for (int i = 0; i < l.liczbaOdwolan; i++) {
		if (!l.czyJest(l.Odwolania[i])) {
			bledy++;
			if (!l.czyPelna()) l.wstawStrone(l.Odwolania[i]);
			else {
				l.usunOPT(i);
				l.wstawStrone(l.Odwolania[i]);
			}
		}
	}
	std::cout << "Ilosc bledow dla OPT: " << bledy << std::endl;
	l.wyczysc();

}

void Algorithms::ALRU(Memory l)
{
	int bledy = 0;
	for (int i = 0; i < l.liczbaOdwolan; i++) {
		if (!l.czyJest(l.Odwolania[i])) {
			bledy++;
			if (!l.czyPelna()) l.wstawStrone(l.Odwolania[i]);
			else {
				l.usunALRU();
				l.wstawStrone(l.Odwolania[i]);
			}
		}
		else {
			l.ustawBit(l.Odwolania[i]);
		}
	}
	std::cout << "Ilosc bledow dla ALRU: " << bledy << std::endl;
	l.wyczysc();
}

void Algorithms::RAND(Memory l)
{
	int bledy = 0;
	for (int i = 0; i < l.liczbaOdwolan; i++) {
		if (!l.czyJest(l.Odwolania[i])) {
			bledy++;
			if (!l.czyPelna()) l.wstawStrone(l.Odwolania[i]);
			else {
				l.usunRAND();
				l.wstawStrone(l.Odwolania[i]);
			}
		}
	}
	std::cout << "Ilosc bledow dla RAND: " << bledy << std::endl;
	l.wyczysc();
}
