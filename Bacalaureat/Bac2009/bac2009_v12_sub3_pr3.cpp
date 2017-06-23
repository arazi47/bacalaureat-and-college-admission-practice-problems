// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_012.pdf
// Problema 3

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

int nrAparitii(int n, int v[], int val)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (v[i] == val)
            ++cnt;

    return cnt;
}

// numere.txt
// 1 2 3 4 7 20 60
// 3 5 7 8 9 10 12 20 24
int main()
{
    ifstream f("numere.txt");
    int n = 0, val;
    int v[200];
    while (f >> val)
        if (val % 5 == 0)
            insereazaCrescator(n, v, val);

    for (int i = 0; i < n; ++i)
    {
        if (v[i] == -1)
            continue;
        if (nrAparitii(n, v, v[i]) > 1)
        {
            for (int j = n - 1; j >= i; --j)
                if (v[j] == v[i])
                    v[j] = -1;
        }
        else
            cout << v[i] << ' ';
    }

    return 0;
}

