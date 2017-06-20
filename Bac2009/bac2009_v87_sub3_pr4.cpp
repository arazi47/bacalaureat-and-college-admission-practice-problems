// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_087.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int sumaCifPare(int n)
{
    int s = 0;
    while (n)
    {
        if ((n % 10) % 2 == 0)
            s += n % 10;
        n /= 10;
    }

    return s;
}

int sumaCifImpare(int n)
{
    int s = 0;
    while (n)
    {
        if ((n % 10) % 2)
            s += n % 10;
        n /= 10;
    }

    return s;
}

int main()
{
    int n, nrAparitii, nrmin = -1;
    ifstream f("bac.txt");
    while (f >> n)
    {
        if (nrmin == -1 && sumaCifPare(n) == sumaCifImpare(n))
        {
            nrmin = n;
            nrAparitii = 1;
        }
        else if (nrmin != -1 && n == nrmin)
            ++nrAparitii;
        else if (nrmin != -1 && n < nrmin && sumaCifPare(n) == sumaCifImpare(n))
        {
            nrmin = n;
            nrAparitii = 1;
        }
    }

    cout << nrmin << ' ' << nrAparitii;

    return 0;
}
