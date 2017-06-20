// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_031.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int max = -100, min = 100;
    ifstream f("numere.txt");
    int a, b;
    f >> a; // numarul de perechi, nu ne trebuie
    while (f >> a >> b)
    {
        if (a > max)
            max = a;
        if (b < min)
            min = b;
    }

    cout << max << ' ' << min;
    return 0;
}
