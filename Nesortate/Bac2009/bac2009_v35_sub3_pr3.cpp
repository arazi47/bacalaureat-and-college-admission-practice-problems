// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_035.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

bool incepeSiSeTerminaCuAceeasiCifra(int n)
{
    int uc = n % 10;
    while (n > 9)
        n /= 10;

    return n == uc;
}

int main()
{
    int n, x[100];
    ifstream f("numere.in");
    f >> n;
    while (f >> n)
    {
        if (incepeSiSeTerminaCuAceeasiCifra(n))
            cout << n << ' ';
    }

    return 0;
}
