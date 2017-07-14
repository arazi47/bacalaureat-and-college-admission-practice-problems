// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-17.12.2016.pdf

#include <iostream>

using namespace std;

// maximul este 100, insa indexarea incepe de la 1
#define MAX 100 + 1

void citire(int &n, int &m, bool a[MAX][MAX])
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
}

int numarVecini(int n, int m, bool a[MAX][MAX], int i, int j)
{
    int vecini = 0;
    if (i > 1 && a[i - 1][j])
        ++vecini;
    if (i < n && a[i + 1][j])
        ++vecini;
    if (j > 1 && a[i][j - 1])
        ++vecini;
    if (j < m && a[i][j + 1])
        ++vecini;

    return vecini;
}

bool impadurita(int n, int m, bool a[MAX][MAX])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == 0)
                return false;
}

// initializeaza matricea a cu valorile matricei a
void initializeazaMatrice(int n, int m, bool a[MAX][MAX], bool b[MAX][MAX])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            b[i][j] = a[i][j];
}

void impadureste(int n, int m, bool a[MAX][MAX], bool &sePoate, int &nrZile)
{
    sePoate = false;
    nrZile = 0;

    // verifica daca s-a plantat cel putin un copac in ziua curenta
    bool plantat;
    bool b[MAX][MAX];

    do
    {
        plantat = false;
        initializeazaMatrice(n, m, a, b);

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                // daca un copac aflat la coordonatele (i, j) are cel putin 2 vecini
                // se poate planta alt copac
                if (a[i][j] == 0 && numarVecini(n, m, b, i, j) >= 2)
                {
                    a[i][j] = 1;
                    if (!plantat)
                        plantat = true;
                }
            }
        }

        if (plantat)
            ++nrZile;
        else
            break;
    } while (!impadurita(n, m, a));

    if (impadurita(n, m, a))
        sePoate = true;
    else
        sePoate = false;
}

int main()
{
    int n, m;
    bool a[MAX][MAX];
    bool sePoate;
    int nrZile;

    citire(n, m, a);
    impadureste(n, m, a, sePoate, nrZile);

    if (sePoate)
        cout << "sePoate = true" << endl << "nrZile = " << nrZile;
    else
        cout << "sePoate = false" << endl << "nrZile = " << nrZile;

    return 0;
}

