// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_020.pdf

#include <iostream>

using namespace std;

void nule(int a[100], int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] == 0 && a[j] != 0)
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}

int main()
{
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    nule(a, n);
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';

    return 0;
}

