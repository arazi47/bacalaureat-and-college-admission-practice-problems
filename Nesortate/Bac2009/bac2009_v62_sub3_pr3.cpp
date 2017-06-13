// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_062.pdf
// Problema 3

#include <iostream>

using namespace std;

void fibo(int n, int v[])
{
    int cnt = 0;
    if (n >= 1)
        v[cnt++] = 1;
    if (n >= 2)
        v[cnt++] = 1;
    int a = 1, b = 1, c;
    while (cnt < n)
    {
        c = a + b;
        a = b;
        b = c;

        if (c % 2)
        {
            v[cnt++] = c;
        }
    }
}

int main()
{
    int n, v[30];
    cin >> n;
    fibo(n, v);
    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';

    return 0;
}
