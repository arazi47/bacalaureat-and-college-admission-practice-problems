// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_058.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.txt");
    int n = 0, v[100];
    while (f >> v[n])
        ++n;

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (v[i] > v[j])
            {
                int t = v[i];
                v[i] = v[j];
                v[j] = t;
            }

    cout << v[2] << ' ' << v[1] << ' ' << v[0];

    return 0;
}
