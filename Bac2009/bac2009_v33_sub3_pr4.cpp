// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_033.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int diferenta(int x, int y)
{
    if (x > y)
        return x - y;
    else
        return y - x;
}

int nrcif(int n)
{
    int cnt = 0;
    while (n)
    {
        ++cnt;
        n /= 10;
    }

    return cnt;
}

// ideea e sa fac un vector de frecventa
// pentru maximul dintre numerele de n cifre
// v[1] - maximul numerelor de o cifra
// v[2] - maximul numerelor de doua cifre
// etc
int main()
{
    int n, v[10] = {};
    ifstream f("numere.txt");
    f >> n;
    int nrc;
    int max3cif = 0;
    while (f >> n)
    {
        nrc = nrcif(n);
        if (nrc == 3 && n > max3cif)
        {
            // setez v[3] ca fiind fostul maxim de 3 cifre
            // (pentru ca tot se poate sa se scada maximul de 3 cifre cu un alt numar de 3 cifre)
            v[3] = max3cif;
            max3cif = n; // n este acum maximul de 3 cifre
        }
        else if (n > v[nrc])
            v[nrc] = n;
    }

    // fac diferenta dintre maximul numerelor de o cifra si maximul de 3 cifre
    int difmin = diferenta(v[1], max3cif);
    int nr = v[1];
    // incerc cu restul numerelor maxime
    for (int i = 2; i < 10; ++i)
        if (diferenta(v[i], max3cif) < difmin)
        {
            difmin = diferenta(v[i], max3cif);
            nr = v[i];
        }

    // afisez numarul maxim de 3 cifre si numarul cu care am facut diferenta minima
    cout << max3cif << ' ' << nr;

    return 0;
}
