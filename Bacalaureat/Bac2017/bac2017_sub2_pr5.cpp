#include <iostream>

using namespace std;

int main()
{
    int n, m, a[51][51];

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    int el = a[n][m];
    for (int i = 1; i <= m; ++i)
        a[i][1] = a[n][i] = el;

    for (int i = 1; i <= n; ++i)
        a[1][i] = a[i][m] = el;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }

    return 0;
}

