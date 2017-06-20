// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_073.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

int cautare(int n, int x[], int v)
{
    if (v > x[n - 1] && n > 0)
        return n - 1;

    for (int i = 0; i < n - 1; ++i)
        if (v > x[i] && v < x[i + 1])
            return i + 1;

    return 0;
}

// Nu merge!
int main()
{
    int n = 0, x[1000], v;
    ifstream f("sir.in");
    while (f >> v)
    {
        int poz = cautare(n, x, v);
        //cout << v << ' ' << poz << endl;

        for (int i = n; i > poz; --i)
            x[i] = x[i - 1];
        x[poz] = v;
        ++n;
    }

    for (int i = 0; i < n; ++i)
        cout << x[i] << ' ';

    return 0;
}
