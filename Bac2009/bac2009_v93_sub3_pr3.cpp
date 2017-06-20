// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_093.pdf
// Problema 3

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[100];
    int st = 1, fin = n;
    bool stg = true;
    for (int i = 0; i < n; ++i)
    {
        if (stg)
            v[i] = st++;
        else
            v[i] = fin--;

        stg = !stg;
    }

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';

    return 0;
}
