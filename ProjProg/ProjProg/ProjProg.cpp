#include "stdafx.h"
#include "math.h"
using namespace std;

/*int strzelenie_goli(int sila)
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
	else if (sila == 4)
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
}*/ //stare strzelanie
int strzelenie_goli(float sila)
{
	int rnd;
	rnd = rand() % 100;
	if ((float)rnd <= (100.0 - 5 * sila))
		return 0;
	else if ((float)rnd <= ((100.0 - 5 * sila) + (3 + 2 * sila)))
		return 1;
	else if ((float)rnd <= ((100.0 - 5 * sila) + (3 + 2 * sila) + (2 * sila)))
		return 2;
	else 
		return 3;
}
float kartka(int sila, float sila_tmp) //cos nie bangla
{
	return 0;
	int rnd;
	rnd = rand() % 100;
	if (rnd > 98)
		return 1;
	else
		return 0;
}
void konkurs_karnych(int *tab,int sila1, int sila2)	//do testow
{
	tab[0] = 0;
	tab[1] = 0;
	int licznik=5;
	int rnd;

	while (licznik > 0)
	{
		if (sqrt(tab[0] - tab[1]) > licznik)
			break;

		rnd = rand() % 100;
		if ((rnd - sila1) <= 85)
			tab[0]=tab[0]+1;

		if (sqrt(tab[0] - tab[1]) > licznik)
			break;
		
		rnd = rand() % 100;
		if ((rnd - sila2) <= 85)
			tab[1] = tab[1] + 1;

		licznik--;
	}
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
	string kontynent;
	int sila;
	float sila_tmp;
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
	int l_druzyn = 16;
	Druzyna druzyny[32];
	Druzyna sila1[8];
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
	Druzyna *grupy[8] = { &grupa_A[0], &grupa_B[0], &grupa_C[0], &grupa_D[0], &grupa_E[0], &grupa_F[0], &grupa_G[0], &grupa_H[0] };
	Finaly(string nazwa);
	void wypisz()
	{
		cout << "\n\n*** Wszystkie druzyny ***";
		for (int i = 0; i < 32; i++)
			cout << "\n" << druzyny[i].nazwa << " " << druzyny[i].sila;
	}
	void wypisz_grupy()
	{
		cout << "\n\n*** Wszystkie grupy ***";
		char tmp = 'A';
		for (int i = 0; i < 8; i++)
		{
			cout << "\nGrupa " << tmp << ":\n";
			for (int j = 0; j < 4; j++)
				cout << grupy[i][j].nazwa << " sila: " << grupy[i][j].sila << " punkty: " << grupy[i][j].punkty << " bilans: " << grupy[i][j].gole_strzelone - grupy[i][j].gole_stracone << "\n";
			tmp++;
		}
	}
	void sortowanie_tablicy()
	{
			for (int i = 0; i < 31; i++)
				for (int j = 0; j < 31; j++)
					if ((druzyny + j)->sila < (druzyny + j + 1)->sila)
						swap(j, j + 1);
	}
	void sortowanie_grupy(Druzyna *grupy)
	{
		int bilans1;
		int bilans2;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (grupy[j].punkty < (grupy[j + 1]).punkty)
				{
					Druzyna tmp;
					tmp = grupy[j];
					grupy[j] = grupy[j + 1];
					grupy[j + 1] = tmp;
				}

		if (grupy[3].punkty == grupy[2].punkty)
		{
			bilans1 = grupy[3].gole_strzelone - grupy[3].gole_stracone;
			bilans2 = grupy[2].gole_strzelone - grupy[2].gole_stracone;

			if (bilans1 > bilans2)
			{
				Druzyna tmp;
				tmp = grupy[3];
				grupy[3] = grupy[2];
				grupy[2] = tmp;
			}
			else if (bilans1 == bilans2)
			{
				if (grupy[3].gole_strzelone > grupy[2].gole_strzelone)
				{
					Druzyna tmp;
					tmp = grupy[3];
					grupy[3] = grupy[2];
					grupy[2] = tmp;
				}
			}
			else if (grupy[3].gole_strzelone == grupy[2].gole_strzelone)
			{
				int gol_3;
				int gol_2;
				int id = szukaj_meczu(grupy[3].nazwa, grupy[2].nazwa);

				if (mecze_rozegrane[id]->druzyna1 == grupy[3].nazwa)
				{
					gol_3 = mecze_rozegrane[id]->wynik_druzyna1;
					gol_2 = mecze_rozegrane[id]->wynik_druzyna2;
				}
				else
				{
					gol_2 = mecze_rozegrane[id]->wynik_druzyna1;
					gol_3 = mecze_rozegrane[id]->wynik_druzyna2;
				}

				if (gol_3 > gol_2)
				{
					Druzyna tmp;
					tmp = grupy[3];
					grupy[3] = grupy[2];
					grupy[2] = tmp;
				}
				else if (gol_3 == gol_2)
				{
					int rnd = rand() % 2;
					if (rnd == 0)
					{
						Druzyna tmp;
						tmp = grupy[3];
						grupy[3] = grupy[2];
						grupy[2] = tmp;
					}
				}
					
			}
			
		}
		if (grupy[2].punkty == grupy[1].punkty)
		{
			bilans1 = grupy[2].gole_strzelone - grupy[2].gole_stracone;
			bilans2 = grupy[1].gole_strzelone - grupy[1].gole_stracone;

			if (bilans1 > bilans2)
			{
				Druzyna tmp;
				tmp = grupy[2];
				grupy[2] = grupy[1];
				grupy[1] = tmp;
			}
			else if (bilans1 == bilans2)
			{
				if (grupy[2].gole_strzelone > grupy[1].gole_strzelone)
				{
					Druzyna tmp;
					tmp = grupy[2];
					grupy[2] = grupy[1];
					grupy[1] = tmp;
				}
			}
			else if (grupy[2].gole_strzelone == grupy[1].gole_strzelone)
			{
				int gol_3;
				int gol_2;
				int id = szukaj_meczu(grupy[2].nazwa, grupy[1].nazwa);

				if (mecze_rozegrane[id]->druzyna1 == grupy[2].nazwa)
				{
					gol_3 = mecze_rozegrane[id]->wynik_druzyna1;
					gol_2 = mecze_rozegrane[id]->wynik_druzyna2;
				}
				else
				{
					gol_2 = mecze_rozegrane[id]->wynik_druzyna1;
					gol_3 = mecze_rozegrane[id]->wynik_druzyna2;
				}

				if (gol_3 > gol_2)
				{
					Druzyna tmp;
					tmp = grupy[2];
					grupy[2] = grupy[1];
					grupy[1] = tmp;
				}
				else if (gol_3 == gol_2)
				{
					int rnd = rand() % 2;
					if (rnd == 0)
					{
						Druzyna tmp;
						tmp = grupy[2];
						grupy[2] = grupy[1];
						grupy[1] = tmp;
					}
				}

			}
		}
		if (grupy[1].punkty == grupy[0].punkty)
		{
			bilans1 = grupy[1].gole_strzelone - grupy[1].gole_stracone;
			bilans2 = grupy[0].gole_strzelone - grupy[0].gole_stracone;

			if (bilans1 > bilans2)
			{
				Druzyna tmp;
				tmp = grupy[1];
				grupy[1] = grupy[0];
				grupy[0] = tmp;
			}
			else if (bilans1 == bilans2)
			{
				if (grupy[1].gole_strzelone > grupy[0].gole_strzelone)
				{
					Druzyna tmp;
					tmp = grupy[1];
					grupy[1] = grupy[0];
					grupy[0] = tmp;
				}
			}
			else if (grupy[1].gole_strzelone == grupy[0].gole_strzelone)
			{
				int gol_3;
				int gol_2;
				int id = szukaj_meczu(grupy[1].nazwa, grupy[0].nazwa);

				if (mecze_rozegrane[id]->druzyna1 == grupy[1].nazwa)
				{
					gol_3 = mecze_rozegrane[id]->wynik_druzyna1;
					gol_2 = mecze_rozegrane[id]->wynik_druzyna2;
				}
				else
				{
					gol_2 = mecze_rozegrane[id]->wynik_druzyna1;
					gol_3 = mecze_rozegrane[id]->wynik_druzyna2;
				}

				if (gol_3 > gol_2)
				{
					Druzyna tmp;
					tmp = grupy[1];
					grupy[1] = grupy[0];
					grupy[0] = tmp;
				}
				else if (gol_3 == gol_2)
				{
					int rnd = rand() % 2;
					if (rnd == 0)
					{
						Druzyna tmp;
						tmp = grupy[1];
						grupy[1] = grupy[0];
						grupy[0] = tmp;
					}
				}

			}
		}
	}
	int szukaj_meczu(string druzyna_a, string druzyna_b)
	{
		for (int i = 0; i < 48; i++)
		{
			if (mecze_rozegrane[i]->druzyna1 == druzyna_a && mecze_rozegrane[i]->druzyna2 == druzyna_b)
				return i;
			if (mecze_rozegrane[i]->druzyna1 == druzyna_b && mecze_rozegrane[i]->druzyna2 == druzyna_a)
				return i;
		}
		return -1;
	}
	void wypisz_puchar()
	{
		cout << "\n*** FAZA PUCHAROWA ***";
		for (int i = 0; i < l_druzyn; i=i+2)
		{
			cout << "\n";
			cout << faza_pucharowa[i].nazwa<<"\n";
			cout << faza_pucharowa[i+1].nazwa << "\n";
		}
	}
	void rozgrywki_pucharowe()
	{
		int k;
		while (l_druzyn>1)
		{
			wypisz_puchar();
			for (int i = 0; i < l_druzyn; i++)
			{
				faza_pucharowa[i].punkty = 0;
				faza_pucharowa[i].gole_stracone = 0;
				faza_pucharowa[i].gole_strzelone = 0;
			}

			k = 0;

			for (int i = 0; i < l_druzyn; i = i + 2)
			{
					
				Rozegraj_mecz_puchar(&faza_pucharowa[i], &faza_pucharowa[i + 1]);

				if (faza_pucharowa[i].punkty > faza_pucharowa[i + 1].punkty)
					faza_pucharowa[k] = faza_pucharowa[i];
				else
					faza_pucharowa[k] = faza_pucharowa[i + 1];

				k++;
				l_druzyn--;
			}
		}
		cout << "\n\n ***** ZWYCIEZCA *****\n";
		cout << faza_pucharowa[0].nazwa;
	}
	void RozegrajMecz(Druzyna *A, Druzyna *B)
	{
		int gol_A = 0;
		int gol_B = 0;

		for (int i = 0; i < 6; i++)
		{

			gol_A = gol_A + strzelenie_goli(A->sila_tmp);
			gol_B = gol_B + strzelenie_goli(B->sila_tmp);
			A->sila_tmp = A->sila_tmp - kartka(A->sila,A->sila_tmp);
			B->sila_tmp = B->sila_tmp - kartka(B->sila, B->sila_tmp);
		}

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
	void Rozegraj_mecz_puchar(Druzyna *A, Druzyna *B)
	{
		int gol_A = 0;
		int gol_B = 0;
		for (int i = 0; i < 6; i++)
		{
			gol_A = gol_A + strzelenie_goli(A->sila_tmp);
			gol_B = gol_B + strzelenie_goli(B->sila_tmp);
			A->sila_tmp = A->sila_tmp - kartka(A->sila, A->sila_tmp);
			B->sila_tmp = B->sila_tmp - kartka(B->sila, B->sila_tmp);
		}
		if(gol_A==gol_B)
			for (int i = 0; i < 2; i++)
			{
				gol_A = gol_A + strzelenie_goli(A->sila_tmp);
				gol_B = gol_B + strzelenie_goli(B->sila_tmp);
				A->sila_tmp = A->sila_tmp - kartka(A->sila, A->sila_tmp);
				B->sila_tmp = B->sila_tmp - kartka(B->sila, B->sila_tmp);
			}
		if (gol_A == gol_B)
		{
			int tab[2];
			while (gol_A == gol_B)
			{
				cout << "\n*** konkurs rzutow karnych ***";
				cout << "\nwynik przed: " << gol_A << " : " << gol_B;
				konkurs_karnych(tab, A->sila, B->sila);
				gol_A += tab[0];
				gol_B += tab[1];
			}
		}

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
		id++;


	}
	void swap(int i, int j)
	{
		Druzyna tmp;
		tmp = druzyny[i];
		druzyny[i] = druzyny[j];
		druzyny[j] = tmp;
	}
	void grupowanie()
	{   
		//Seed druzyn z sila 1 do grup;
		int licznik = 0;
		int l, i = 0;

		

		while (licznik < 8)
		{
			if (i == 32)
			{
				break;
			}			
			
			if ((druzyny + i)->sila == 4)
			{
				sila1[licznik] = druzyny[i];
				swap(i, 31 - licznik);
				licznik++;
			}

			i++;
		}
		for (int i = 0; i < 8; i++)
			grupy[i][0] = sila1[i];

		
		licznik = 23;
		while (licznik > 20)
		{
			l = rand() % (licznik+1);
			grupa_A[1] = druzyny[l];
			swap(l, licznik);
			licznik--;

			l = rand() % (licznik + 1);
			grupa_A[2] = druzyny[l];
			swap(l, licznik);
			licznik--;

			l = rand() % (licznik + 1);
			grupa_A[3] = druzyny[l];
			swap(l, licznik);
			licznik--;
		}
		while (licznik > 17)
		{
			l = rand() % (licznik + 1);
			grupa_B[1] = druzyny[l];
			swap(l, licznik);
			licznik--;

			l = rand() % (licznik + 1);
			grupa_B[2] = druzyny[l];
			swap(l, licznik);
			licznik--;

			l = rand() % (licznik + 1);
			grupa_B[3] = druzyny[l];
			swap(l, licznik);
			licznik--;
		}
		while (licznik > 14)
		{
			l = rand() % (licznik + 1);
			grupa_C[1] = druzyny[l];
			swap(l, licznik);
			licznik--;
			l = rand() % (licznik + 1);
			grupa_C[2] = druzyny[l];
			swap(l, licznik);
			licznik--;
			l = rand() % (licznik + 1);
			grupa_C[3] = druzyny[l];
			swap(l, licznik);
			licznik--;
		}
		while (licznik > 11)
		{
			l = rand() % (licznik + 1);
			grupa_D[1] = druzyny[l];
			swap(l, licznik);
			licznik--;
			l = rand() % (licznik + 1);
			grupa_D[2] = druzyny[l];
			swap(l, licznik);
			licznik--;
			l = rand() % (licznik + 1);
			grupa_D[3] = druzyny[l];
			swap(l, licznik);
			licznik--;
		}
		while (licznik > 8)
		{
			l = rand() % (licznik + 1);
			grupa_E[1] = druzyny[l];
			swap(l, licznik);
			licznik--;
			l = rand() % (licznik + 1);
			grupa_E[2] = druzyny[l];
			swap(l, licznik);
			licznik--;
			l = rand() % (licznik + 1);
			grupa_E[3] = druzyny[l];
			swap(l, licznik);
			licznik--;
		}
		while (licznik > 5)
		{
			l = rand() % (licznik + 1);
			grupa_F[1] = druzyny[l];
			swap(l, licznik);
			licznik--;
			l = rand() % (licznik + 1);
			grupa_F[2] = druzyny[l];
			swap(l, licznik);
			licznik--;
			l = rand() % (licznik + 1);
			grupa_F[3] = druzyny[l];
			swap(l, licznik);
			licznik--;
		}
		while (licznik > 2)
		{
			l = rand() % (licznik + 1);
			grupa_G[1] = druzyny[l];
			swap(l, licznik);
			licznik--;
			l = rand() % (licznik + 1);
			grupa_G[2] = druzyny[l];
			swap(l, licznik);
			licznik--;
			l = rand() % (licznik + 1);
			grupa_G[3] = druzyny[l];
			swap(l, licznik);
			licznik--;
		}
		while (licznik >= 0)
		{
			l = rand() % (licznik + 1);
			grupa_H[1] = druzyny[l];
			swap(l, licznik);
			licznik--;
			l = rand() % (licznik + 1);
			grupa_H[2] = druzyny[l];
			swap(l, licznik);
			licznik--;
			l = rand() % (licznik + 1);
			grupa_H[3] = druzyny[l];
			swap(l, licznik);
			licznik--;
		}
		

	}
	void rozrywki_grupowe(Druzyna *grupa)
	{
		RozegrajMecz(&grupa[0], &grupa[1]);
		RozegrajMecz(&grupa[0], &grupa[2]);
		RozegrajMecz(&grupa[0], &grupa[3]);
		RozegrajMecz(&grupa[1], &grupa[2]);
		RozegrajMecz(&grupa[1], &grupa[3]);
		RozegrajMecz(&grupa[2], &grupa[3]);
	}
	void przydzielenie_do_drzewa()
	{
		faza_pucharowa[0] = grupa_A[0];
		faza_pucharowa[1] = grupa_B[1];
		faza_pucharowa[2] = grupa_C[0];
		faza_pucharowa[3] = grupa_D[1];
		faza_pucharowa[4] = grupa_E[0];
		faza_pucharowa[5] = grupa_F[1];
		faza_pucharowa[6] = grupa_G[0];
		faza_pucharowa[7] = grupa_H[1];
		faza_pucharowa[8] = grupa_B[0];
		faza_pucharowa[9] = grupa_A[1];
		faza_pucharowa[10] = grupa_D[0];
		faza_pucharowa[11] = grupa_C[1];
		faza_pucharowa[12] = grupa_F[0];
		faza_pucharowa[13] = grupa_E[1];
		faza_pucharowa[14] = grupa_H[0];
		faza_pucharowa[15] = grupa_G[1];

		for (int i = 0; i < 16; i++)
		{
			faza_pucharowa[i].sila_tmp = (float)faza_pucharowa[i].sila;
		}
	}
};
Finaly::Finaly(string plk)
{
	ifstream plik(plk);
	for (int i = 0; i < 32; i++)
	{
		plik >> druzyny[i].nazwa;
		plik >> druzyny[i].sila;
		druzyny[i].sila_tmp = 1.0*druzyny[i].sila;
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
	sila_tmp = 1.0*sila;
}


int main()
{
	srand(time(0));

	Finaly *ff = new Finaly("plik.txt");
	
	ff->wypisz();
	ff->sortowanie_tablicy();
	ff->grupowanie();

	for (int i = 0; i < 8; i++)
		ff->rozrywki_grupowe(ff->grupy[i]);
	
	ff->wypisz_grupy();

	for (int i = 0; i < 8; i++)
		ff->sortowanie_grupy(ff->grupy[i]);

	ff->wypisz_grupy();

	ff->przydzielenie_do_drzewa();
	ff->rozgrywki_pucharowe();

	cout << "\n\n";
	return 0;
}