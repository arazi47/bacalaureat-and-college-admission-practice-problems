// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_037.pdf
// Problema 3

#include <iostream>

using namespace std;

int main()
{
    int n, v[100], k;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cin >> k;

    int pe; // primul element
    for (int i = 0; i < k; ++i)
    {
        pe = v[0];
        for (int j = 0; j < n - 1; ++j)
            v[j] = v[j + 1];
        v[n - 1] = pe;
    }

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';

    return 0;
}
