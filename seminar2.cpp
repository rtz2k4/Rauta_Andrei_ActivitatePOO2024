#include <iostream>
//
using namespace std;

struct Farmacie {
	char* nume;
	string adresa;
	int nrMedicamente;
	float* preturi;
};

const int nrFarmacii = 3;

void afisareFarmacii(Farmacie f)
{
	cout << "Nume: " << f.nume << endl;
	cout << "Adresa: " << f.adresa << endl;
	cout << "Numarul de medicamente: " << f.nrMedicamente << endl;
	cout << "Preturi: ";
	for (int i = 0; i < f.nrMedicamente; i++)
	{
		cout << f.preturi[i] << ",";
	}
}

Farmacie citireFarmacii()
{
	Farmacie f;
	cout << "Introduceti numele farmaciei: ";
	char buffer[100];
	cin >> buffer;
	f.nume = new char[strlen(buffer) + 1];
	strcpy_s(f.nume, strlen(buffer) + 1, buffer); 
	cout << "Introduceti adresa farmaciei: "; 
	cin >> f.adresa;
	cout << "Introduceti numarul de medicamente ";
	cin >> f.nrMedicamente;
	cout << "Introduceti preturile: ";
	f.preturi = new float[f.nrMedicamente];
	for (int i = 0; i < f.nrMedicamente; i++)
	{
		cin >> f.preturi[i];
	}
	return f;
}

//int main()
//{
//	Farmacie* pointer;
//	pointer = new Farmacie();
//	pointer->nume = new char[strlen("Catena" + 1)];
//	strcpy_s(pointer->nume, strlen("Catena" + 1), "Catena"); 
//	pointer->adresa = "Romana"; 
//	pointer->nrMedicamente = 5;
//	pointer->preturi = new float(pointer->nrMedicamente); 
//	for (int i = 0; i < pointer->nrMedicamente; i++)
//	{
//		pointer->preturi[i] = i++; 
//	}
// 
//	afisareFarmacii(*pointer);
//	delete pointer;
//
//	Farmacie* vector;
//	vector = new Farmacie[nrFarmacii];
//
//	for (int i = 0; i < nrFarmacii; i++)
//	{
//		vector[i] = citireFarmacii();
//	}
//
//	for (int i = 0; i < nrFarmacii; i++)
//	{
//		afisareFarmacii(vector[i]);
//	}
//
//	for (int i = 0; i < nrFarmacii; i++)
//	{
//		delete vector[i].nume;
//		delete vector[i].preturi;
//	}
//
//	delete vector;
//	return 0;
//}
