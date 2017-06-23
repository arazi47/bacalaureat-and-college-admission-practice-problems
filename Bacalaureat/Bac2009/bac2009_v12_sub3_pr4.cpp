// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_012.pdf
// Problema 4

#include <iostream>

using namespace std;

void insereazaCrescator(int &n, int v[], int val)
{
    int j = n - 1;
    while (j >= 0 && val < v[j])
    {
        v[j + 1] = v[j];
        --j;
    }

    v[j + 1] = val;
    ++n;
}

bool areCifreleEgale(int n)
{
    int uc = n % 10;
    n /= 10;
    while (n)
    {
        if (uc != n % 10)
            return false;
        uc = n % 10;
        n /= 10;
    }

    return true;
}

// ex:
// n = 5
// 11111 33333 12423 59824 11111 33443
int main()
{
    int n;
    cin >> n;
    int val;
    int v[20];
    int m = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        if (areCifreleEgale(val))
            insereazaCrescator(m, v, val);
    }

    for (int i = 0; i < m; ++i)
        cout << v[i] << ' ';

    return 0;
}

