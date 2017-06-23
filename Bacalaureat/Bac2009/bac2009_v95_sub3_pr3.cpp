// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_095.pdf
// Problema 3

#include <iostream>

using namespace std;

int f(int n, int v[100])
{
    int cntNeg = 0, cntPoz = 0;
    for (int i = 0; i < n; ++i)
        if (v[i] > 0)
            ++cntPoz;
        else
            ++cntNeg;

    if (cntPoz == cntNeg)
        return 0;
    else if (cntNeg > cntPoz)
        return -1;
    else
        return 1;
}

int main()
{
    int n, v[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << f(n, v);

    return 0;
}
