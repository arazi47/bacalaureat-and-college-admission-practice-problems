// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_013.pdf

#include <iostream>
#include <fstream>

using namespace std;

int eliminaCifreleImpare(int n)
{
    int r = 0, p = 1;
    while (n)
    {
        if ((n % 10) % 2 == 0)
        {
            r = r + p * (n % 10);
            p *= 10;
        }

        n /= 10;
    }

    return r;
}

int main()
{
    ifstream f("bac.in");
    ofstream g("bac.out");
    int x;
    while (f >> x)
    {
        x = eliminaCifreleImpare(x);
        if (x != 0)
            g << x << ' ';
    }

	return 0;
}

