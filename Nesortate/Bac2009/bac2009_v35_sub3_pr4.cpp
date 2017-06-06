// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_035.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int sumaDiv(int n)
{
    int d, sum = 0;
    for (d = 2; d * d < n; ++d)
        if (n % d == 0)
            sum += (d + n / d);

    if (d * d == n)
        sum += d;

    return sum;
}

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

int main()
{
    int n, v[100], val, m = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        insereazaCrescator(m, v, sumaDiv(val));
    }

    for (int i = 0; i < m; ++i)
        cout << v[i] << ' ';

    return 0;
}
