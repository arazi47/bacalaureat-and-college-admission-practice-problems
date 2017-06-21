// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_098.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

void insereazaCrescator(int &n, int v[], int x)
{
    int j = n - 1;
    while (j >= 0 && x < v[j])
    {
        v[j + 1] = v[j];
        --j;
    }

    v[j + 1] = x;
    ++n;
}

int main()
{
    int n = 0, v[6000], x;
    ifstream f("date.txt");
    f >> x >> x;
    while (f >> x)
        if (x % 2 == 0)
            insereazaCrescator(n, v, x);

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';

    return 0;
}
