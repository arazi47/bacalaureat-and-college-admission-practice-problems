// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-17.12.2016.pdf

#include <iostream>

using namespace std;

int numar_vecini(int n, int m, int a[101][101], int i, int j)
{
    int cnt = 0;

    if (i > 1 && a[i - 1][j] == 1)
        ++cnt;
    if (i < n && a[i + 1][j] == 1)
        ++cnt;
    if (j > 1 && a[i][j - 1] == 1)
        ++cnt;
    if (j < m && a[i][j + 1] == 1)
        ++cnt;

    return cnt;
}

void citire(int &n, int &m, int a[101][101])
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
}

bool este_impadurita(int n, int m, int a[101][101])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == 0)
                return false;

    return true;
}

void initializeaza_matrice(int n, int m, int a[101][101], int b[101][101])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            b[i][j] = a[i][j];
}

void impadurire(int n, int m, int a[101][101], bool &sePoate, int &nrZile)
{
    bool am_plantat;
    int b[101][101];
    do
    {
        am_plantat = false;
        initializeaza_matrice(n, m, a, b);

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (a[i][j] == 0 && numar_vecini(n, m, b, i, j) >= 2)
                {
                    a[i][j] = 1;
                    am_plantat = true;
                }

        if (am_plantat)
            ++nrZile;
    } while (am_plantat);

    if (este_impadurita(n, m, a))
        sePoate = true;
}

int main()
{
    int n, m, a[101][101];
    bool sePoate = false;
    int nrZile = 0;

    citire(n, m, a);
    impadurire(n, m, a, sePoate, nrZile);

    if (sePoate)
        cout << "sePoate = true";
    else
        cout << "sePoate = false";
    cout << endl;
    cout << "nrZile = " << nrZile;

    return 0;
}
