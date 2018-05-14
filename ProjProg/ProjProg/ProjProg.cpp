#include "stdafx.h"
using namespace std;


int strzelenie_goli(int sila)
{
	int rnd = rand() % 101;
	if (sila == 1)
	{
		if (rnd <= 60)
			return 0;
		else if (rnd <= 85)
			return 1;
		else if (rnd <= 95)
			return 2;
		else if (rnd <= 99)
			return 3;
		else if (rnd <= 100)
			return 4;
	}
	else if (sila == 2)
	{
		if (rnd <= 40)
			return 0;
		else if (rnd <= 75)
			return 1;
		else if (rnd <= 90)
			return 2;
		else if (rnd <= 96)
			return 3;
		else if (rnd <= 99)
			return 4;
		else if (rnd <= 100)
			return 5;
	}
	else if (sila == 3)
	{
		if (rnd <= 25)
			return 0;
		else if (rnd <= 55)
			return 1;
		else if (rnd <= 80)
			return 2;
		else if (rnd <= 90)
			return 3;
		else if (rnd <= 95)
			return 4;
		else if (rnd <= 98)
			return 5;
		else if (rnd <= 100)
			return 6;
	}
	else if(sila == 4)
	{
		if (rnd <= 5)
			return 0;
		else if (rnd <= 15)
			return 1;
		else if (rnd <= 45)
			return 2;
		else if (rnd <= 80)
			return 3;
		else if (rnd <= 92)
			return 4;
		else if (rnd <= 97)
			return 5;
		else if (rnd <= 100)
			return 6;
	}
	else return 0;

}
class druzyny_wybor //todo
{

};
class Mecz
{
public:
	int id_meczu;
	string druzyna1;
	string druzyna2;
	int wynik_druzyna1;
	int wynik_druzyna2;

	Mecz(int id_meczu, string druzyna1, string druzyna2, int wynik_druzyna1, int wynik_druzyna2);
};
class Druzyna
{
public:
	string nazwa;
	int sila;
	int gole_strzelone=0;
	int gole_stracone=0;
	int punkty=0;
	Druzyna(){};
	Druzyna(string nazwa, int sila);
};

class Finaly
{
public:
	int id = 0;
	Druzyna druzyny[32];
	Druzyna grupa_A[4];
	Druzyna grupa_B[4];
	Druzyna grupa_C[4];
	Druzyna grupa_D[4];
	Druzyna grupa_E[4];
	Druzyna grupa_F[4];
	Druzyna grupa_G[4];
	Druzyna grupa_H[4];
	Druzyna faza_pucharowa[16];
	Mecz *mecze_rozegrane[64];
	Finaly(string nazwa);
	void wypisz()
	{
		for (int i = 0; i < 32; i++)
			cout << "\n" << druzyny[i].nazwa << " " << druzyny[i].sila;
	}
	void RozegrajMecz(Druzyna *A, Druzyna *B)
	{
		int gol_A = strzelenie_goli(A->sila);
		int gol_B = strzelenie_goli(B->sila);
		mecze_rozegrane[id] = new Mecz(id, A->nazwa, B->nazwa, gol_A, gol_B);
		A->gole_stracone = A->gole_stracone + gol_B;
		A->gole_strzelone = A->gole_strzelone + gol_A;
		B->gole_stracone = B->gole_stracone + gol_A;
		B->gole_strzelone = B->gole_strzelone + gol_B;
		if (gol_A > gol_B)
		{
			cout << "\nWygrala druzyna " << A->nazwa << " z druzyna " << B->nazwa << " wynikiem: " << gol_A << ":" << gol_B << "\n";
			A->punkty = A->punkty + 2;
		}
		else if (gol_A < gol_B)
		{
			cout << "\nWygrala druzyna " << B->nazwa << " z druzyna " << A->nazwa << " wynikiem: " << gol_B << ":" << gol_A << "\n";
			B->punkty = B->punkty + 2;
		}
		else
		{
			cout << "\nDruzyna " << B->nazwa << " zremisowala z druzyna " << A->nazwa << " wynikiem: " << gol_B << ":" << gol_A << "\n";
			A->punkty = A->punkty + 1;
			B->punkty = B->punkty + 1;
		}
		id++;
	}
	void grupowanie()//todo
	{
		int i = 0;
		while (i < 32)
		{
			for (int j = 0; j < 4; j++)
			{
				grupa_A[j] = druzyny[i];
				i++;
			}
			for (int j = 0; j < 4; j++)
			{
				grupa_B[j] = druzyny[i];
				i++;
			}
			for (int j = 0; j < 4; j++)
			{
				grupa_C[j] = druzyny[i];
				i++;
			}
			for (int j = 0; j < 4; j++)
			{
				grupa_D[j] = druzyny[i];
				i++;
			}
			for (int j = 0; j < 4; j++)
			{
				grupa_E[j] = druzyny[i];
				i++;
			}
			for (int j = 0; j < 4; j++)
			{
				grupa_F[j] = druzyny[i];
				i++;
			}
			for (int j = 0; j < 4; j++)
			{
				grupa_G[j] = druzyny[i];
				i++;
			}
			for (int j = 0; j < 4; j++)
			{
				grupa_H[j] = druzyny[i];
				i++;
			}
		}
	}
	void rozrywki_grupowe(Druzyna *grupa)
	{
		//kazdy z kazdym;
		RozegrajMecz(&grupa[0], &grupa[1]);
		RozegrajMecz(&grupa[0], &grupa[2]);
		RozegrajMecz(&grupa[0], &grupa[3]);
		RozegrajMecz(&grupa[1], &grupa[2]);
		RozegrajMecz(&grupa[1], &grupa[3]);
		RozegrajMecz(&grupa[2], &grupa[3]);

		cout << "\npunkty druzyny " << grupa->nazwa << ": " << grupa->punkty;
		cout << "\npunkty druzyny " << (grupa+1)->nazwa << ": " << (grupa+1)->punkty;
		cout << "\npunkty druzyny " << (grupa+2)->nazwa << ": " << (grupa+2)->punkty;
		cout << "\npunkty druzyny " << (grupa+3)->nazwa << ": " << (grupa+3)->punkty;
	}
	

};
Finaly::Finaly(string plk)
{
	ifstream plik(plk);
	for (int i = 0; i < 32; i++)
	{
		plik >> druzyny[i].nazwa;
		plik >> druzyny[i].sila;
	}
}
Mecz::Mecz(int id_meczu, string druzyna1, string druzyna2, int wynik_druzyna1, int wynik_druzyna2)
{
	this->id_meczu = id_meczu;
	this->druzyna1 = druzyna1;
	this->druzyna2 = druzyna2;
	this->wynik_druzyna1 = wynik_druzyna1;
	this->wynik_druzyna2 = wynik_druzyna2;
}
Druzyna::Druzyna(string nazwa, int sila)
{
	this->nazwa = nazwa;
	this->sila = sila;
	gole_stracone = gole_strzelone = punkty = 0;
}


int main()
{
	srand(time(0));

	Finaly *ff = new Finaly("plik.txt");
	ff->wypisz();
	ff->grupowanie();
	ff->rozrywki_grupowe(ff->grupa_A);
	return 0;
}