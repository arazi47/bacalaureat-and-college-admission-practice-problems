// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_030.pdf
// Problema 3

#include <iostream>

using namespace std;

int suma(int v[], int n, int i, int j)
{
    int sum = 0;
    while (i <= j)
        sum += v[i++];

    return sum;
}

int main()
{
    int n, v[100], i, j;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cin >> i >> j;

    cout << suma(v, n, i, j);

    return 0;
}

