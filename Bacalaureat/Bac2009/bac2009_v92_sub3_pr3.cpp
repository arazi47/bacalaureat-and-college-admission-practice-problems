// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_092.pdf
// Problema 3

#include <iostream>

using namespace std;

void ordonare(int n, float x[])
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (x[i] > x[j])
            {
                float t = x[i];
                x[i] = x[j];
                x[j] = t;
            }
}

int main()
{
    int n, m;
    float x[100];
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    ordonare(n, x);

    for (int i = n - m; i < n; ++i)
        cout << x[i] << ' ';
    cout << endl;
    for (int i = m - 1; i >= 0; --i)
        cout << x[i] << ' ';

    return 0;
}
