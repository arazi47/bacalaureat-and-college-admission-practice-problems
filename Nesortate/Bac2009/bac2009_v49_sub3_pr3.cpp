// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_049.pdf
// Problema 3

#include <iostream>

using namespace std;

int main()
{
    int n, v[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (v[i] > v[j])
            {
                int t = v[i];
                v[i] = v[j];
                v[j] = t;
            }

    for (int i = 1; i < n; ++i)
        if (!(v[i] == v[i - 1] + i))
        {
            cout << "NU";
            return 0;
        }

    cout << "DA";

    return 0;
}
