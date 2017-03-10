// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2010-informatica.pdf

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

int kprim(int i)
{
    int n = 1, cnt = 0;
    do
    {
        ++n;
        if (prim(n))
            ++cnt;
    } while (cnt < i);
    return n;
}

void construieste(int n, int a[][101])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) // diagonala principala
                a[i][j] = 0;
            else if (i > j) // sub diagonala principala
                a[i][j] = i;
            else // deasupra diagonalei principale
                a[i][j] = kprim(i);
        }
}

void afiseaza(int n, int a[][101])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
    int n, a[101][101];
    cin >> n;

    construieste(n, a);
    afiseaza(n, a);

    return 0;
}
