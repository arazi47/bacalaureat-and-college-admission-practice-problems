// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_026.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

void sterge(int v[100], int &n, int st, int fin)
{
    if (fin >= n)
        return;

    for (int i = 1; fin + i < n; ++i)
        v[st + i - 1] = v[fin + i];

    n -= (fin - st + 1);
}

int main()
{
    ifstream f("numere.txt");
    int n, v[100];
    f >> n;
    for (int i = 0; i < n; ++i)
        f >> v[i];

    int i = 0;
    while (i < n - 1)
    {
        if (v[i] == v[i + 1])
            sterge(v, n, i + 1, i + 1);
        else
            ++i;
    }

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';

    return 0;
}

