// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_082.pdf
// Problema 3

#include <iostream>

using namespace std;

int suma(int n, int v[100])
{
    int s = 0;
    for (int i = 0; i < n; ++i)
        if (v[i] % 10 == (v[i] / 10) % 10)
            s += v[i];

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
