// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_017.pdf

#include <iostream>

using namespace std;

int interval(int v[100], int n)
{
    int a = v[0], b = v[n - 1];
    if (a > b)
    {
        a += b;
        b = a - b;
        a -= b;
    }

    int cnt = 2;
    for (int i = 1; i < n - 1; ++i)
        if (v[i] >= a && v[i] <= b)
            ++cnt;

    return cnt;
}

int main()
{
    int n, v[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << interval(v, n);

    return 0;
}

