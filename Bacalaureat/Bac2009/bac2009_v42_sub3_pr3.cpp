// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_042.pdf
// Problema 3

#include <iostream>

using namespace std;

int P(int a[100], int n, int k)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] < a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }

    int sum = 0;
    for (int i = 0; i < k; ++i)
        sum += a[i];

    return sum;
}

int main()
{
    int n, v[100], k;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cin >> k;
    cout << P(v, n, k);

    return 0;
}
