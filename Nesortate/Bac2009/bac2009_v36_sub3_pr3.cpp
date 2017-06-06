// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_036.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

int cifra(int n)
{
    if (n == 0)
        return 0;

    while (n)
    {
        if ((n % 10) % 2 == 0)
            return n % 10;
        n /= 10;
    }

    return -1;
}

int main()
{
    int n, v[10] = {};
    ifstream f("bac.in");
    f >> n; // numarul de elemente ale sirului
    int ucp; // ultima cifra para
    bool continePare = false;
    while (f >> n)
    {
        ucp = cifra(n);
        if (ucp % 2 == 0)
        {
            ++v[ucp];
            if (!continePare)
                continePare = true;
        }
    }

    if (continePare)
    {
        for (int i = 8; i >= 0; i -= 2)
        {
            while (v[i])
            {
                cout << i;
                --v[i];
            }
        }
    }
    else
        cout << "NU EXISTA";

    return 0;
}
