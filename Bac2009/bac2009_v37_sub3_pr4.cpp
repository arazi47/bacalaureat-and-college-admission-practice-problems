// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_037.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

// Doar antetul trebuie scris
// Se specifica in cerinta
int nrdiv(int x);

// Programul da eroare de compilare deoarece
// Am scris doar definitia functiei nrdiv
int main()
{
    int n;
    ifstream f("bac.in");
    f >> n;
    int nr1;
    while (f >> n)
        if (nrdiv(n) % 2 == 0)
        {
            nr1 = n;
            break;
        }

    int nr2;
    while (f >> n)
        if (nrdiv(n) % 2 == 0)
            nr2 = n;

    cout << nr1 << ' ' << nr2;

    return 0;
}
