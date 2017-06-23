// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_081.pdf
// Problema 3

#include <iostream>

using namespace std;

int medie(int n, int v[100])
{
    int s = 0;
    for (int i = 0; i < n; ++i)
        s += v[i];
    return s / n;
}

int main()
{
    int n, v[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << medie(n, v);

    return 0;
}
