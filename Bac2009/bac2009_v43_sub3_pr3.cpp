// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_043.pdf
// Problema 3

#include <iostream>

using namespace std;

int P(int n, int a[101])
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        if (i % 2 == 0 && a[i] % 2)
            sum += a[i];

    return sum;
}

int main()
{
    int n, a[101];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << P(n, a);

    return 0;
}
