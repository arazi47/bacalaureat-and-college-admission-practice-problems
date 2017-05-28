// https://drive.google.com/file/d/0B0NnkrRhUimbcFFmM05yT21QOFk/view
// Problema 3

#include <iostream>

using namespace std;

// Ex:
// n = 3
// 1 2 3
// 4 5 6
// 7 8 9

int main()
{
    int n, a[101][101];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    int x = n % 2 ? n / 2 + 1 : n / 2;

    for (int k = 1; k <= x; ++k)
    {
        for (int j = k; j <= n - k + 1; ++j)
            cout << a[k][j] << ' ';

        for (int i = k + 1; i <= n - k + 1; ++i)
            cout << a[i][n - k + 1] << ' ';

        for (int j = n - k; j >= k; --j)
            cout << a[n - k + 1][j] << ' ';

        for (int i = n - k; i >= k + 1; --i)
            cout << a[i][k] << ' ';
    }

    return 0;
}
