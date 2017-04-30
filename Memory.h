#pragma once
#include "header.h"

class Memory
{
public:
	int iloscRamek;
	int iloscStron;
	int liczbaOdwolan;
	std::vector<int> Ramki;
	std::vector<int> Odwolania;
	std::vector<int> bityOdwolan;
	int zajeteRamki;
	int ostatnia;

	Memory(int r, int s, int o);
	~Memory();

	bool czyJest(int a);
	bool czyPelna();
	void ciagOdwolan();
	void wyczysc();
	void bity();
	void wstawStrone(int a);
	void ustawBit(int a);

	void usunFIFO();
	void usunRAND();
	void usunOPT(int pos);
	void usunLRU(int pos);
	void usunALRU();
};