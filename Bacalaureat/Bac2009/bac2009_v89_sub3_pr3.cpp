// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_089.pdf
// Problema 3

#include <iostream>

using namespace std;

int numar(int n, int c1, int c2)
{
    int v[10], m = 0;
    // introducem fiecare cifra a numarului n in sir
    while (n)
    {
        v[m++] = n % 10;
        n /= 10;
    }

    // inversam vectorul
    for (int i = 0; i < m / 2; ++i)
    {
        int t = v[i];
        v[i] = v[m - 1 - i];
        v[m - 1 - i] = t;
    }

    int index = -1;
    for (int i = 0; i < m; ++i)
    {
        if (v[i] == c1)
        {
            index = i + 1;
            v[i] = c2;
            break;
        }
    }

    // daca am gasit cifra c1 in numar
    // restul cifrelor vor fi 0
    if (index != -1)
    {
        for (int i = index; i < m; ++i)
            v[i] = 0;
    }

    // construim numarul final
    for (int i = 0; i < m; ++i)
        n = n * 10 + v[i];

    return n;
}

int main()
{
    int n, c1, c2;
    cin >> n >> c1 >> c2;
    cout << numar(n, c1, c2);

    return 0;
}
