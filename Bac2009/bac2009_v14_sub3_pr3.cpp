// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_014.pdf
// Problema 3

#include <iostream>

using namespace std;

// n = 19
// val = 3 3 0 9 2 1 2 1 3 7 1 5 2 7 1 0 3 2 3
int main()
{
    int n, val, v[10] = {};
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        ++v[val];
    }

    for (int i = 0; i < 10; ++i)
    {
        while (v[i])
        {
            cout << i << ' ';
            --v[i];
        }
    }

    return 0;
}

