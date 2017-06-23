// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_017.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.txt");
    int n, val;
    f >> n; // nu avem nevoie de marime
    f >> n; // primul element
    int poz = 1;
    while (f >> val)
    {
        // numaram cate numere sunt mai mici decat primul
        // asa aflam cate ar fi in fata lui, daca sirul
        // ar fi ordonat crescator
        if (val < n)
            ++poz;
    }

    cout << poz;

    return 0;
}

