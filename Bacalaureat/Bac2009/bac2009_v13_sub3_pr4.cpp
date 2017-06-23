// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_013.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int eliminaCifra(int n, int c)
{
    int rez = 0, p = 1;
    while (n)
    {
        if (n % 10 != c)
        {
            rez = rez + p * (n % 10);
            p *= 10;
        }

        n /= 10;
    }

    return rez;
}

// bac.in:
// 25 7 38 1030 45127 0 35 60 15
int main()
{
    ifstream f("bac.in");
    ofstream g("bac.out");
    int n;
    while (f >> n)
    {
        // Eliminam toate cifrele impare din n
        n = eliminaCifra(n, 1);
        n = eliminaCifra(n, 3);
        n = eliminaCifra(n, 5);
        n = eliminaCifra(n, 7);
        n = eliminaCifra(n, 9);

        if (n % 2 == 0 && n != 0)
            g << n << ' ';
    }

    return 0;
}

