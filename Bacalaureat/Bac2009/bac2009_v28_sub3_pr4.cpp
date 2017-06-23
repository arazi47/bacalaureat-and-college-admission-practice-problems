// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_028.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int primul(int a)
{
    if (a % 2 == 0)
        return 2;
    for (int d = 3; d * d <= a; d += 2)
        if (a % d == 0)
            return d;

    return a;
}

int main()
{
    ifstream f("numere.in");

    int a, nrmax = -1;
    f >> a; // cate numere vor fi introduse
    while (f >> a)
    {
        int fact1 = primul(a);
        int fact2 = a / fact1;
        if (fact1 * fact2 == a && primul(fact1) == fact1 && primul(fact2) == fact2 && fact1 > 1 && fact2 > 1)
        {
            if (nrmax == -1)
                nrmax = a;
            else if (a > nrmax)
                nrmax = a;
        }
    }

    if (nrmax != -1)
        cout << "DA " << nrmax;
    else
        cout << "NU";

    return 0;
}

