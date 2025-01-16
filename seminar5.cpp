#include <iostream>

using namespace std; 

class Cofetarie {
private: 
    string nume;
    int nrAngajati;
    float *salarii;
    bool esteVegana; 
    int anDeschidere;
    float adaos;
    static int TVA;

public:
    Cofetarie() : adaos(30), anDeschidere(2024) {
        this->nume = "Delice";
        this->nrAngajati = 0; 
        this->esteVegana = true; 
        this->salarii = NULL;
    }


    Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) : anDeschidere(an) {
        this->nume = nume; 
        this->nrAngajati = nrAngajati; 
        this->esteVegana = vegan; 
        this->adaos=adaos; 
        this->salarii = new float[nrAngajati];
        for(int i=0; i<nrAngajati; i++)
        {
            this->salarii[i] = 1000 + i*100;
        }
    }

    Cofetarie(const Cofetarie& c) : anDeschidere(c.anDeschidere) {
        this->nume = c.nume;
        this->nrAngajati = c.nrAngajati;
        this->salarii = new float[c.nrAngajati];
        for(int i=0; i<nrAngajati; i++)
        {
            this->salarii[i] = c.salarii[i];
        }

        this->esteVegana = c.esteVegana;
        this->adaos = c.adaos;
    }



    Cofetarie operator+(Cofetarie c) const {
        Cofetarie temp = *this; // copie a obiectului curent
        temp.nrAngajati = this->nrAngajati + c.nrAngajati;
        float* aux = new float[temp.nrAngajati];
        for(int i=0; i<this->nrAngajati; i++)
        {
            aux[i] = this->salarii[i];

        }

        for(int i=0; i<c.nrAngajati; i++)
        {
            aux[i+this->nrAngajati] = c.salarii[i];
        }

        if (temp.salarii != NULL)
        {
            delete[]temp.salarii;
            return temp;

        }
        temp.salarii = aux;
        return temp;


    }



    Cofetarie& operator+=(Cofetarie c) {
        *this = *this + c; 
        return *this;

    }


    Cofetarie operator+(float salariu) const {
        Cofetarie temp = *this;
        if(temp.salarii != NULL)
        {
            delete[]temp.salarii;
        }

        temp.salarii = new float[temp.nrAngajati+1];
        for(int i=0; i<temp.nrAngajati; i++)
        {
            temp.salarii[i] = this->salarii[i];
        }

        temp.salarii[temp.nrAngajati] = salariu;
        temp.nrAngajati++;
        return temp;
    }


    friend ostream& operator<<(ostream& output, Cofetarie c);



    float& operator[](int index)
    {
        if(index>0 && index<this->nrAngajati)
        {
            return this->salarii[index];
        }

        else {
            throw "Index in afara limitelor";
        }
    }


    ~Cofetarie()
    {
        if(this->salarii)
        {
            delete[] this->salarii;
            cout<<"Destructor apelat"<<endl;}
    }

    
};



ostream& operator<<(ostream& output, Cofetarie c) {
	output << "Nume:" << c.nume << endl;
	output << "Nr angajati:" << c.nrAngajati << endl;
	if (c.salarii != NULL) {
		for (int i = 0; i < c.nrAngajati; i++) {
			cout << c.salarii[i] << ", ";
		}
		cout << endl;
	}
	output << "Are produse vegane:" << (c.esteVegana ? "DA" : "NU") << endl;
	output << "An deschidere:" << c.anDeschidere << endl;
	output << "Adaos:" << c.adaos << endl;
	output << "TVA:" << Cofetarie::TVA << endl;
	return output;



    
}




int Cofetarie::TVA = 2;

int main ()
{

    Cofetarie c2("Minimal", 3, false, 2020, 10);
    cout<<c2[1]<<endl;
    c2[1] = 2000;
    cout<<c2[1]<<endl;
    cout<<c2;



}


    

