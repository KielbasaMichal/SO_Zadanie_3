#include "Memory.h"

Memory::~Memory()
{
}

Memory::Memory(int ramki, int strony, int odwolania)
{
	iloscRamek = ramki;
	iloscStron = strony;
	liczbaOdwolan = odwolania;
	Ramki.resize(ramki);
	bityOdwolan.resize(ramki);
	Odwolania.resize(odwolania);
	zajeteRamki = 0;
	ostatnia = 0;
	ciagOdwolan();
	bity();
}

bool Memory::czyJest(int a)
{
	bool b = false;
	for (int i = ostatnia; i < ostatnia + iloscRamek; i++)
	{
		if (Ramki[i % iloscRamek] == a)
		{
			b = true;
			break;
		}
	}
	return b;
}

bool Memory::czyPelna()
{
	return (zajeteRamki == iloscRamek);
}

void Memory::ciagOdwolan()
{
	for (int i = 0; i < liczbaOdwolan; i++)
	{
		Odwolania[i] = (rand() % iloscStron) + 1;
		for (int j = 1; j < (rand() % 4) + 2; j++)
		{
			if (i < liczbaOdwolan - 1)
			{
				i++;
				Odwolania[i] = Odwolania[i - 1] + (rand() % 2) - 2;
				if (Odwolania[i] <= 0 || Odwolania[i] >= iloscRamek) Odwolania[i] = (Odwolania[i - 1] + (rand() % 5) + 1) % iloscStron;
			}
		}
	}
}

void Memory::wyczysc()
{
	for (int i = 0; i < iloscRamek; i++)
	{
		Ramki[i] = 0;
		zajeteRamki = 0;
		bityOdwolan[i] = -1;
		ostatnia = 0;
	}
}

void Memory::bity()
{
	for (int i = ostatnia; i < ostatnia + iloscRamek; i++)
	{
		bityOdwolan[i % iloscRamek] = -1;
	}
}

void Memory::wstawStrone(int a)
{
	for (int i = ostatnia; i < ostatnia + iloscRamek; i++)
	{
		if (Ramki[i % iloscRamek] == 0)
		{
			for (int j = 0; j < 4; j++)
			{
				if (!czyJest(a + j - 2))
				{
					Ramki[(i + j) % iloscRamek] = a + j;
					bityOdwolan[(i + j) % iloscRamek] = 0;
				}
				else
					i--;

				if (zajeteRamki < iloscRamek)
					zajeteRamki++;
			}

			break;
		}
	}
}

void Memory::ustawBit(int a)
{
	for (int i = ostatnia; i < ostatnia + iloscRamek; i++)
	{
		if (Ramki[i % iloscRamek] == a)
		{
			bityOdwolan[i % iloscRamek] = 1;
			break;
		}
	}
}

void Memory::usunFIFO()
{
	Ramki[ostatnia] = 0;
	ostatnia++;
	ostatnia %= iloscRamek;
	zajeteRamki--;
}

void Memory::usunRAND()
{
	if (zajeteRamki < iloscRamek)
	{
		Ramki[rand() % iloscRamek] = 0;
		zajeteRamki--;
	}
}

void Memory::usunOPT(int pos)
{
	int najdluzszyCzas = 0;
	int doUsuniecia = 0;

	for (int i = 0; i < iloscRamek; i++)
	{
		int czas = 0;
		for (int j = pos; j < liczbaOdwolan; j++)
		{
			czas++;
			if (Ramki[i] == Odwolania[j] || j == liczbaOdwolan - 1)
			{
				if (czas > najdluzszyCzas)
				{
					najdluzszyCzas = czas;
					doUsuniecia = i;
				}
				break;
			}
		}
	}

	Ramki[doUsuniecia] = 0;
	zajeteRamki--;
}

void Memory::usunLRU(int pos)
{
	int najdluzszyCzas = 0;
	int doUsuniecia = 0;

	for (int i = 0; i < iloscRamek; i++)
	{
		int czas = 0;
		for (int j = pos; j >= 0; j--)
		{
			czas++;
			if (Ramki[i] == Odwolania[j] || j == 0)
			{
				if (czas > najdluzszyCzas)
				{
					najdluzszyCzas = czas;
					doUsuniecia = i;
				}
				break;
			}
		}
	}

	Ramki[doUsuniecia] = 0;
	zajeteRamki--;
}

void Memory::usunALRU()
{
	for (int i = ostatnia; i < ostatnia + iloscRamek; i++)
	{
		if (bityOdwolan[i % iloscRamek] == 1) bityOdwolan[i % iloscRamek] = 0;
		else if (bityOdwolan[i % iloscRamek] == 0)
		{
			bityOdwolan[i % iloscRamek] = -1;
			Ramki[i % iloscRamek] = 0;
			zajeteRamki--;
			ostatnia++;
			break;
		}
	}
}
