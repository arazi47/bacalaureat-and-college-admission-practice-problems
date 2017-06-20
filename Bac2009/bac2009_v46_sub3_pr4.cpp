// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_046.pdf
// Problema 4

#include <iostream>

using namespace std;

void cifre(int nr, int &nc, int &sc)
{
    nc = sc = 0;
    while (nr)
    {
        ++nc;
        sc += (nr % 10);
        nr /= 10;
    }
}

int main()
{
    int n;
    cin >> n;
    int nc, sc;
    cifre(n, nc, sc);

    int uc; // ultima cifra
    while(n)
    {
        uc = n % 10;
        if ((sc - uc) / (nc - 1) == uc)
        {
            cout << "DA";
            return 0;
        }
        n /= 10;
    }

    cout << "NU";

    return 0;
}
