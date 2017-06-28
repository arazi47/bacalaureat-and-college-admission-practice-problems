// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_022.pdf

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.txt");
    int a, b, nr;

    // numarul de perechi
    f >> a;

    while (f >> a >> b)
    {
        nr = 1;
        while (2 * nr < b)
            nr *= 2;

        if (nr < a || nr > b)
            cout << 0 << ' ' ;
        else
            cout << nr << ' ';
    }

    return 0;
}

