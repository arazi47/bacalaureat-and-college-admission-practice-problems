// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_017.pdf

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int poz = 1, x, nr;
    ifstream f("numere.txt");

    // numarul elementelor din sir
    f >> x;

    // elementul caruia trebuie sa ii determinam pozitia
    // in sirul ordonat
    f >> nr;

    while (f >> x)
    {
        if (x < nr)
            ++poz;
    }

    cout << poz;

    return 0;
}

