#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>

using namespace std;

const int MAX_P = 12;
const int MAX_G = 6;

struct pomiar {
	char nazwa[MAX_P];
	char godzina1[MAX_G];
	char godzina2[MAX_G];
	float temp1;
	float temp2;
};

void wczytaj_plik(fstream& ifs, const char nazwaWE[], float d)
{
	int licznik = 0;
	float roznica;
	pomiar p;

	ifs.open(nazwaWE, ios::in);
	ofstream ofsw("Wzrosty_output.txt");

	while (ifs >> p.nazwa >> p.godzina1 >> p.godzina2 >> p.temp1 >> p.temp2)
	{
		roznica = p.temp2 - p.temp1;
		if (roznica >= d)
		{
			ofsw << p.nazwa
				<< setw(10) << p.godzina1
				<< setw(10) << roznica << endl;
			licznik++;
		}

	}

	ofsw << "Liczba zapisanych pomiarow: " << licznik;

	ifs.close();
	ifs.clear();

	ofsw.close();
}

float wczytaj_prog(fstream& ifs2)
{
	float prog;

	ifs2.open("Prog.txt", ios::in);
	ifs2 >> prog;

	return prog;
}



int main()
{
	fstream ifs;
	fstream ifs2;

	float prog1 = wczytaj_prog(ifs2);

	wczytaj_plik(ifs, "Pomiary.txt", prog1);

}
