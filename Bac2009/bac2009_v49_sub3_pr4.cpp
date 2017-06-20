// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_049.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

void cmax(int a, int &b)
{
    b = 0;
    while (a)
    {
        if (a % 10 > b)
            b = a % 10;
        a /= 10;
    }
}

int main()
{
    ifstream f("bac.txt");
    int n, cifMax = 0, nrMin = 30000, cmaxFunctie;
    while (f >> n)
    {
        cmax(n, cmaxFunctie);
        if (cmaxFunctie > cifMax)
        {
            cifMax = cmaxFunctie;
            nrMin = n;
        }
        else if (cmaxFunctie == cifMax && n < nrMin)
            nrMin = n;
    }

    cout << cifMax << ' ' << nrMin;

    return 0;
}
