// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_015.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

/*
bac.in:
12 15 68 13 17 90 31 42

rezultat:
17 31
*/

int main()
{
    ifstream f("bac.in");
    int nr1 = -1, nr2 = -1, n;
    while (f >> n)
    {
        if (n % 2)
        {
            if (nr1 == -1)
                nr1 = n;
            else if (nr2 == -1)
                nr2 = n;
            else
            {
                nr1 = nr2;
                nr2 = n;
            }
        }
    }

    cout << nr1 << ' ' << nr2;

    return 0;
}

