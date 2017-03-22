// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-17.12.2016.pdf

#include <iostream>

using namespace std;

bool prim(int n)
{
    if (n < 2)
        return false;
    if (n % 2 == 0 && n != 2)
        return false;
    for (int d = 3; d * d <= n; d += 2)
        if (n % d == 0)
            return false;

    return true;
}

void citire(int &n, int a[101][101])
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
}

int numarElementePrime(int n, int a[101][101])
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i > j && i + j < n + 1 && prim(a[i][j]))
                ++cnt;
            else if (i < j && i + j > n + 1 && prim(a[i][j]))
                ++cnt;
        }

    return cnt;
}

int main()
{
    int n, a[101][101];
    citire(n, a);
    cout << numarElementePrime(n, a);

    return 0;
}
