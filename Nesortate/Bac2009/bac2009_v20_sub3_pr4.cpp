// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_020.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

// Prima mea idee a fost sa fac cu un singur vector de frecventa
// Si daca aparitiile erau >= 2, atunci dadeam cout
// Dar exista un bug:
// Daca intr-un fisier apare de doua ori un numar
// Si in celalalt fisier nu apare
// Tot ar fi afisat, desi nu e corect
// De aceea, folosesc doi vectori de frecventa
int main()
{
    int n;
    bool v1[9999 + 1] = {}, v2[9999 + 1] = {};

    ifstream f("nr1.txt");
    ifstream g("nr2.txt");

    // marimile
    f >> n;
    g >> n;

    while (f >> n)
        if (!v1[n])
            v1[n] = true;

    while (g >> n)
        if (!v2[n])
            v2[n] = true;

    for (int i = 0; i < 9999 + 1; ++i)
        if (v1[i] && v2[i])
            cout << i << ' ';

    return 0;
}

