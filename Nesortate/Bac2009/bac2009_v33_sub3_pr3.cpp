// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_033.pdf
// Problema 3

#include <iostream>

using namespace std;

int sum3(int x[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
        if (x[i] % 3 == 0)
            sum += x[i];

    return sum;
}

int main()
{
    int n, x[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    cout << sum3(x, n);

    return 0;
}
