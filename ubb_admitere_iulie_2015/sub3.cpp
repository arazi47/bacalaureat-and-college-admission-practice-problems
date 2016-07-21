// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2015-iulie-informatica.pdf

#include <iostream>

using namespace std;

int n, m, A[101][101], X[1001], indexX;
bool ARE_SECVENTA = false;

void citire()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> A[i][j];
}

void ConstruiesteX()
{
    indexX = 0;
    for (int j = 1; j <= m; ++j)
        for (int i = 1; i <= n; ++i)
        {
            ++indexX; // incepe de la 1
            X[indexX] = A[i][j];
        }
}

bool prim(int n)
{
    for (int d = 2; d * d <= n; ++d)
        if (n % d == 0)
            return false;

    return true;
}

bool magic(int x)
{
    int x2 = x;
    int mult = 10;
    int nrc = 0;

    if (!prim(x))
        return 0;

    while (x2)
    {
        ++nrc;
        x2 /= 10;
    }

    for (int i = 0; i < nrc - 1; ++i)
    {
        if (!prim(x % mult))
            return 0;

        mult *= 10;
    }

    if (!prim(x / mult)) // prima cifra
        return 0;

    return 1;
}

void AfisareSecventa(int index1, int index2)
{
    ARE_SECVENTA = true;
    for (; index1 <= index2; ++index1)
        cout << X[index1] << ' ';
}

void DetSecvMax(int index1)
{
    bool gasit = true;
    int indexFinal = index1 + 1;
    for (int i = index1 + 1; i < indexX && gasit; ++i)
        if (magic(X[i] + X[i + 1]))
            ++indexFinal;
        else
            gasit = false;

    AfisareSecventa(index1, indexFinal);
}

void DeterminaSecventa()
{
    for (int i = 1; i < indexX; ++i) // nu <= pentru ca verificam si i + 1
        if (magic(X[i] + X[i + 1]))
            DetSecvMax(i);

}

int main()
{
    citire();
    ConstruiesteX();
    DeterminaSecventa();

    if (!ARE_SECVENTA)
        cout << "Nu exista secventa";

    return 0;
}
