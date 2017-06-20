// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_056.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.txt");
    int n = 0, v[1000], x;
    while (f >> x)
        if (!(x % 2))
            v[n++] = x;

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (v[i] > v[j])
            {
                int t = v[i];
                v[i] = v[j];
                v[j] = t;
            }

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';

    return 0;
}
