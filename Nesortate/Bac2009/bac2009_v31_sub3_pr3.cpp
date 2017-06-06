// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_031.pdf
// Problema 3

#include <iostream>

using namespace std;

float suma(float x[], int n, int m)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (x[i] > x[j])
            {
                float tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }

    float sum = 0;
    for (int i = 0; i < m; ++i)
        sum += x[i];

    return sum;
}

int main()
{
    int n, m;
    float x[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    cin >> m;
    cout << suma(x, n, m);
    return 0;
}
