// Simulare clasa a XII-a informatica 2017, ultima problema

#include <iostream>
#include <fstream>

using namespace std;

// In fisierul bac.in se gasesc marimile celor doi vectori, apoi elementele lor
/*
    bac.in:
    5 6
    12 18 19 28 37
    273 274 291 282 296 384
*/

int main()
{
    int a[10000], b[10000], m, n;
    ifstream f("bac.in");
    f >> m >> n;
    int x;
    int k = 0;
    for (int i = 0; i < m; ++i)
    {
        f >> x;
        if (x % 2 == 0)
            a[k++] = x;
    }
    m = k;

    k = 0;
    for (int i = 0; i < n; ++i)
    {
        f >> x;
        if (x % 2 == 0)
            b[k++] = x;
    }
    n = k;

    if (m + n == 0)
    {
        cout << "nu exista";
        return 0;
    }

    for (int i = 0; i < m; ++i)
        cout << a[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; ++i)
        cout << b[i] << ' ';
    cout << endl;

    --m;
    --n;

    while (m >= 0 && n >= 0)
    {
        if (a[m] > b[n])
            cout << a[m--] << ' ';
        else if (a[m] < b[n])
            cout << b[n--] << ' ';
        else // egale
        {
            cout << a[m--] << ' ';
            --n;
        }
    }

    while (m >= 0)
        cout << a[m--] << ' ';

    while (n >= 0)
        cout << b[n--] << ' ';

    return 0;
}
