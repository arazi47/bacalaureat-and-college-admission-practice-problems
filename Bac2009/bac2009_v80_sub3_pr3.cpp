// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_080.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

bool areToateCifreleEgale(int n)
{
    if (n < 10)
        return true;

    int uc = n % 10;
    n /= 10;
    while (n > 9)
    {
        if (n % 10 != uc)
            return false;
        n /= 10;
        uc = n % 10;
    }

    return n == uc;
}

void insereazaCrescator(int &n, int v[1000], int x)
{
    int j = n - 1;
    while (j >= 0 && x < v[j])
    {
        v[j + 1] = v[j];
        --j;
    }

    v[j + 1] = x;
    ++n;
}

int main()
{
    ifstream f("bac.in");
    int x, n = 0, v[1000];
    while (f >> x)
        if (areToateCifreleEgale(x))
            insereazaCrescator(n, v, x);

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';

    return 0;
}
