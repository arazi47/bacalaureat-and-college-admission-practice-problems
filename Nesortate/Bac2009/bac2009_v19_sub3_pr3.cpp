// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_019.pdf
// Problema 3

#include <iostream>

using namespace std;

void aranjare(float a[100], int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] > 0 && a[j] < 0)
            {
                float tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
}

int main()
{
    int n;
    float a[100];

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    aranjare(a, n);

    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';

    return 0;
}

