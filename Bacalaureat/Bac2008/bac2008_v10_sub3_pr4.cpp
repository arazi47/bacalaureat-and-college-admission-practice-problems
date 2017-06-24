// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_010.pdf

#include <iostream>
#include <fstream>

using namespace std;

struct produs
{
	int suma;

	// constructor
	produs()
	{
		suma = 0;
	}
};

int main()
{
    produs produse[9999 + 1];
    int tip, cantitate, pret;
    ifstream f("produse.txt");

    while (f >> tip >> cantitate >> pret)
    	produse[tip].suma += cantitate * pret;

    for (int i = 1; i < 9999 + 1; ++i)
    	if (produse[i].suma != 0)
    		cout << i << ' ' << produse[i].suma << endl;

    return 0;
}

