// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2014-iulie-informatica.pdf
#include <iostream>

using namespace std;

int X[1500], m = 1;
int n;
int A[10][10];

int PrimaCifra(int n)
{
    int inv = 0;
    while (n)
    {
        inv = inv * 10 + n % 10;
        n /= 10;
    }

    return inv % 10;
}

int UltimaCifra(int n)
{
    return n % 10;
}

int CifraMaxima(int n)
{
    int m = 0;
    while (n)
    {
        if (n % 10 > m)
            m = n % 10;

        n /= 10;
    }

    return m;
}

void DeterminaX()
{
    const int nrElem = 2 * n * n * n; // 2 * n^3

    for (int i = 1; m <= nrElem; ++i)
    {
        X[m++] = i;

        for (int d = 2; d <= i / 2; ++d)
            if (i % d == 0)
                X[m++] = d;
    }

    for (int i = 1; i <= m; ++i)
        cout << X[i] << ' ';
    cout << endl << endl;

}

// Nu merge
void DeterminaA()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i + j < n + 1) // Deasupra diagonalei secundare
                A[i][j] = UltimaCifra(X[n * n + i + j]);
            else if (i + j > n + 1) // Sub diagonala secundare
                A[i][j] = PrimaCifra(X[n * n + i + j]);
            else if (i + j == n + 1)
                A[i][j] = CifraMaxima(X[n * n + i * i]);

            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int N[100], k;
void OrdoneazaN()
{
    int tmp;
    bool schimbare;

    do
    {
        schimbare = false;
        for (int i = 0; i < k - 1; ++i)
        {
            if (N[i] > N[i + 1])
            {
                tmp = N[i];
                N[i] = N[i + 1];
                N[i + 1] = tmp;
                schimbare = true;
            }
        }
    } while (schimbare);
}

void FormeazaNrMax()
{
    OrdoneazaN();
    int nr = 0;
    for (int i = k - 1; i >= 0; --i)
        nr = nr * 10 + N[i];

    cout << nr << ' ';
}

void DeterminaNrMaxime()
{
    for (int i = 1; i <= n; ++i)
    {
        k = 0;
        for (int j = 1; j <= n; ++j)
            N[k++] = A[j][i];
        FormeazaNrMax();
    }
}

int main()
{
    cin >> n;
    DeterminaX();
    DeterminaA();
    DeterminaNrMaxime();

    return 0;
}
