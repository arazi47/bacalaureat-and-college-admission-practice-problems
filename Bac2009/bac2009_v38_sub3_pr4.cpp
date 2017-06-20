// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_038.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

void inter(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

int main()
{
    int n, v[1000];
    ifstream f("bac.in");
    f >> n;
    for (int i = 0; i < n; ++i)
        f >> v[i];

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (v[i] > v[j])
                inter(v[i], v[j]);

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';

    return 0;
}
