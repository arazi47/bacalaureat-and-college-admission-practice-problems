// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_015.pdf
// Problema 3

#include <iostream>

using namespace std;

/*
ex:
n = 20
rezultat: 12
*/

int nrDiv(int n)
{
    int cnt = 0;
    int d;
    for (d = 1; d * d < n; ++d)
        if (n % d == 0)
            cnt += 2;

    if (d * d == n)
        ++cnt;

    return cnt;
}

int main()
{
    int n;
    cin >> n;

    int nrMax = 1;
    for (int i = 1; i <= n; ++i)
        if (nrDiv(i) > nrDiv(nrMax))
            nrMax = i;

    cout << nrMax << endl;

    return 0;
}

