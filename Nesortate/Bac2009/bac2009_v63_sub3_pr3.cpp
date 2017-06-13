// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_063.pdf
// Problema 3

#include <iostream>

using namespace std;

bool verif(int n)
{
    int v[9], m = 0;
    while (n)
    {
        v[m++ ] = n % 10;
        n /= 10;
    }

    for (int i = 0; i < m - 2; ++i)
        if (v[i] % 2 && v[i + 1] % 2 && v[i + 2] % 2)
            return true;

    return false;
}

int main()
{
    int n;
    cin >> n;

    if (verif(n / 1000))
        cout << "Da";
    else
        cout << "Nu";

    return 0;
}
