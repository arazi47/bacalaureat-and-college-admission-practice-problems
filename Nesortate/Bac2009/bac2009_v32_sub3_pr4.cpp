// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_032.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

void insereazaCrescator(int &n, int v[], int val)
{
    int j = n - 1;
    while (j >= 0 && val < v[j])
    {
        v[j + 1] = v[j];
        --j;
    }

    v[j + 1] = val;
    ++n;
}

int nrcif(int n)
{
    int cnt = 0;
    while (n)
    {
        ++cnt;
        n /= 10;
    }

    return cnt;
}

int main()
{
    int n, v[100];
    ifstream f("numere.txt");
    int i = 0;
    while (f >> n)
        insereazaCrescator(i, v, n);

    n = i;
    int cnt = 0;
    i = 0;
    int m[2] = {}, k = 0;
    while (i < n && k < 2)
    {
        if (nrcif(v[i]) == 2)
            m[k++] = v[i];
        ++i;
    }

    if (k == 2)
        cout << m[0] << ' ' << m[1];
    else
        cout << 0;

    return 0;
}
