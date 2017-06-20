// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_025.pdf
// Problema 3

#include <iostream>

using namespace std;

int f(int n, int a[9])
{
    int rez = 0;
    bool continePare = false;
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 == 0)
        {
            if (!continePare)
                continePare = true;

            rez = rez * 10 + a[i];
        }

    return continePare ? rez : -1;
}

int main()
{
    int n, a[9];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << f(n, a);

    return 0;
}

