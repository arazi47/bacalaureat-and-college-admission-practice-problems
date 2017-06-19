// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_083.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.in");
    int x, n, lungmin = -1, nrmaxcurr = -1, nrmaxever = -1;
    n = 0;
    while (f >> x)
    {
        // salvam maximul pentru sirul curent
        if (x > nrmaxcurr)
            nrmaxcurr = x;

        // s-a terminat sirul
        if (x == 0)
        {
            // daca suntem la primul sir
            if (lungmin == -1)
            {
                lungmin = n;
                nrmaxever = nrmaxcurr;
            }
            // daca am gasit un sir de lungime mai mica decat precedentul
            else if (n < lungmin)
            {
                lungmin = n;
                nrmaxever = nrmaxcurr;
            }

            // va creste la cand iese din if
            n = -1;

            // resetam maximul pentru sirul curent
            nrmaxcurr = -1;
        }
        ++n;
    }

    cout << nrmaxever;

    return 0;
}
