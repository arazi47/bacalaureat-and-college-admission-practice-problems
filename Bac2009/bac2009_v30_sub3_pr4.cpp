// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_030.pdf
// Problema 4

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool exista(int n, int v[], int val)
{
    for (int i = 0; i < n; ++i)
        if (v[i] == val)
            return true;

    return false;
}

//! Foarte probabil sa fie incorect
int main()
{
    ifstream f("numere.in");
    int n, v[100];
    f >> n;
    float val;
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        f >> val;
        if (!exista(k, v, floor(val)))
            v[k++] = floor(val);
        if (!exista(k, v, ceil(val)))
            v[k++] = ceil(val);
    }
    n = k;

    //for (int i = 0; i < n; ++i)
    //    cout << v[i] << ' ';
    //cout << endl;

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (v[i] > v[j])
                swap (v[i], v[j]);

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (v[i] == v[j] - 1)
                cout << v[i] << ' ' << v[j] << endl;

    return 0;
}

