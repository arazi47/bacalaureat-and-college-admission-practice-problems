// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_089.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

bool exista(int n, int v[], int x)
{
    for (int i = 0; i < n; ++i)
        if (v[i] == x)
            return true;
    return false;
}

void insereazaDescrescator(int &n, int v[], int x)
{
    if (exista(n, v, x))
        return;

    int j = n - 1;
    while (j >= 0 && x > v[j])
    {
        v[j + 1] = v[j];
        --j;
    }

    v[j + 1] = x;
    ++n;
}

int main()
{
    ifstream f("bac.txt");
    int k;
    cin >> k;
    int n;
    int m = 0, v[100];
    while (f >> n)
        if (n > k)
            insereazaDescrescator(m, v, n);

    for (int i = 0; i < m; ++i)
        cout << v[i] << ' ';

    return 0;
}
