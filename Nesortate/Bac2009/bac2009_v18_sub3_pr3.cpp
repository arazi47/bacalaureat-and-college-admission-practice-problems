// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_018.pdf
// Problema 3

#include <iostream>

using namespace std;

int count(float a[100], int n)
{
    float sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];

    float ma = sum / n;

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] >= ma)
            ++cnt;

    return cnt;
}

int main()
{
    int n;
    float a[100];

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << count(a, n);

    return 0;
}

