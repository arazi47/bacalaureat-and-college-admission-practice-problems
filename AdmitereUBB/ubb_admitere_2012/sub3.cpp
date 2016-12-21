// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2012-informatica.pdf

#include <iostream>

using namespace std;

bool asemenea(int a, int b)
{
    int v[10] = {}, m[10] = {};
    while (a)
    {
        v[a % 10]++;
        a /= 10;
    }
    while (b)
    {
        m[b % 10]++;
        b /= 10;
    }

    for (int i = 0; i < 10; ++i)
        if ((v[i] > 0 && m[i] == 0) || (v[i] == 0 && m[i] > 0))
            return false;

    return true;
}

void citeste(int v[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}

int gaseste_de_la(int v[], int n, int startI)
{
    for (int i = startI; i < n - 1; ++i)
        if (!asemenea(v[i], v[i + 1]))
            return i;
}

void gaseste_numere_asemenea(int v[], int n, int R[], int &m)
{
    for (int i = 0; i < n - 1; ++i)
        if(asemenea(v[i], v[i + 1]))
        {
            int endi = gaseste_de_la(v, n, i);

            if (i != endi)
            {
                for (int k = i; k <= endi; ++k)
                {
                    bool ok = true;
                    for (int q = 0; q < m; ++q)
                    {
                        if (R[q] == v[k])
                        {
                            ok = false;
                            break;
                        }
                    }
                    if (ok)
                        R[m++] = v[k];
                }

                i = endi;
            }
        }
}

void afiseaza(int sir[], int m)
{
    if (m == 0)
    {
        cout << "R este sirul vid";
        return;
    }

    for (int i = 0; i < m; ++i)
        cout << sir[i] << ' ';
}

int main()
{
    int X[100], n;
    int R[100], m = 0;

    citeste(X, n);

    gaseste_numere_asemenea(X, n, R, m);
    cout << "X = ";
    afiseaza(X, n);
    cout << endl;
    cout << "R = ";
    afiseaza(R, m);
}
