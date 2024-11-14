#include <iostream>

using namespace std;

class Cofetarie
{
public:
	string nume;
	int nrAngajati;
	bool esteVegana;
	float adaos;
	const int anDeschidere; 
	static int TVA;

	Cofetarie():adaos(30),anDeschidere(2024)
	{
		this->nume = "Delice";
		this->nrAngajati = 3;
		this->esteVegana = true;
	}

	Cofetarie(string nume, int nrAngajati, bool vegan, float adaos, int an):anDeschidere(an)
	{
		this->nume = nume; 
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
	}

	void afisare()
	{
		cout << "Nume: " << this->nume << endl;
		cout << "Numarul de angajati: " << this->nrAngajati << endl;
		cout << "Are produse vegane? " << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "An deschidere: " << this->anDeschidere << endl;
		cout << "Adaos: " << this->adaos << endl;
		cout << "TVA: " << Cofetarie::TVA << endl;
	}

	static void modificaTVA(int NoulTva)
	{
		Cofetarie::TVA = NoulTva; 
	}

	static int calculeazaNrTotalAngajati(int NrCofetarii, Cofetarie* vector)
	{
		int suma = 0;
		for (int i = 0; i < NrCofetarii; i++)
		{
			suma += vector[i].nrAngajati;
		}
		return suma;
	}
};

int Cofetarie::TVA = 19; 

//int main()
//{
//	Cofetarie c1;
//	c1.afisare(); 
//
//	Cofetarie c2("Dolce Vita", 10, 0, 100, 2019);
//	c2.afisare();
//
//	Cofetarie* pointer;
//	pointer = new Cofetarie("Ana State", 3, false, 2020, 20);
//	//(*pointer).afisare();
//	pointer->afisare();
//
//	delete pointer;
//
//	//-> - dereferentiere + accesare
//	//[i](index) - deplasare + dereferentiere
//	int nrCofetarii = 3;
//	Cofetarie* vector;
//	vector = new Cofetarie[nrCofetarii];
//
//	for (int i = 0; i < nrCofetarii; i++)
//	{
//		vector[i].afisare();
//	}
//
//	cout << "Numarul total angajati: " << Cofetarie::calculeazaNrTotalAngajati(nrCofetarii, vector);
//	
//	delete[]vector;
//	
//	return 0;
//}
