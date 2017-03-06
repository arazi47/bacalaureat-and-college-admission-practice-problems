// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2014.pdf

#include <iostream>

using namespace std;

int cmmmc(int a, int b)
{
    int r, a1 = a, b1 = b;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return (a1 * b1) / a;
}

int cmmmcSir(int n, int* X)
{
    int c = cmmmc(X[0], X[1]);
    for (int i = 2; i < n; ++i)
        c = cmmmc(c, X[i]);

    return c;
}

int c1(int n)
{
    int v[9], l = 0;
    while (n)
    {
        v[l++] = n % 10;
        n /= 10;
    }

    int t = v[0];
    v[0] = v[l - 1];
    v[l - 1] = t;

    int rez = 0;
    for (int i = l - 1; i >= 0; --i)
        rez = rez * 10 + v[i];

    return rez;
}

int c2(int n)
{

}

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

bool superPrim(int n)
{
    while (prim(n))
        n /= 10;

    return (n == 0);
}

void insereazaDesc(int &n, int* X, int val)
{
    for (int i = 0; i < n; ++i)
        if (X[i] == val)
            return;

    int j = n - 1;
    while (j >= 0 && val > X[j])
    {
        X[j + 1] = X[j];
        --j;
    }

    X[j + 1] = val;
    ++n;
}

void citeste(int &n, int A[][50])
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];
}

void tipareste(int n, int *v)
{
    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';
}

void construiesteX(int &l, int *X, int n, int A[][50])
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (i > j && i + j < n - 1)
            {
            //cout << A[i][j] << ' ';
                if (superPrim(A[i][j]))
                    insereazaDesc(l, X, A[i][j]);
            }
            else if (i < j && i + j > n - 1)
            {
                //cout << A[i][j] << ' ';
                if (superPrim(A[i][j]))
                    insereazaDesc(l, X, A[i][j]);
            }
        }
}

int main()
{
    int n, A[50][50];
    citeste(n, A);

    int l = 0, X[100];
    construiesteX(l, X, n, A);

    if (l == 0)
        cout << "Sirul este vid";
    else
        tipareste(l, X);

    return 0;
}
