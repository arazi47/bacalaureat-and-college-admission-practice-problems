// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_074.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.in");
    int v[10] = {}, n, x;
    f >> n;
    int contineZero = false;
    for (int i = 0; i < n; ++i)
    {
        f >> x;
        ++v[x];

        if (x == 0 && !contineZero)
            contineZero = true;
    }

    if (contineZero)
    {
        for (int i = 1; i < 10; ++i)
        {
            if (v[i])
            {
                cout << i;
                --v[i];
                break;
            }
        }

        while (v[0])
        {
            cout << 0;
            --v[0];
        }

        for (int i = 1; i < 10; ++i)
            while (v[i])
            {
                cout << i;
                --v[i];
            }
    }
    else
        for (int i = 1; i < 10; ++i)
            while (v[i])
            {
                cout << i;
                --v[i];
            }

    return 0;
}
