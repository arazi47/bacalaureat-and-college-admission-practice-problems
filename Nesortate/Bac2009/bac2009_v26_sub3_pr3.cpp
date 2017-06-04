// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_026.pdf
// Problema 3

#include <iostream>

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
    int n, st, fin, v[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cin >> st >> fin;

    sterge(v, n, st, fin);

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';

    return 0;
}

