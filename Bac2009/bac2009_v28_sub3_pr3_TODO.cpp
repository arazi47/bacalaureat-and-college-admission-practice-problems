// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_028.pdf
// Problema 3

#include <iostream>

using namespace std;

float ma(float v[50], int n)
{
    float sum = 0;
    for (int i = 0; i <= n; ++i)
        sum += v[i];

    return sum / n;
}

//! Nu cred ca-i corect
int main()
{
    int n, cnt = 0;
    cin >> n;
    float v[50];
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 1; i < n; ++i)
        if (ma(v, i - 1) == v[i])
            ++cnt;

    cout << cnt;

    return 0;
}

