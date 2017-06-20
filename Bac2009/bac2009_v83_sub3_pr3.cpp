// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_083.pdf
// Problema 3

#include <iostream>

using namespace std;

int suma(int n, int v[100])
{
    int s = 0;
    int uc; // ultima cifra
    int copie;
    for (int i = 0; i < n; ++i)
    {
        copie = v[i];
        uc = v[i] % 10;
        while (v[i] > 9)
            v[i] /= 10;

        if (v[i] == uc)
            s += copie;
    }

    return s;
}

int main()
{
    int n, v[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << suma(n, v);

    return 0;
}
