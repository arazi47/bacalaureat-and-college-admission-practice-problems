// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2013-septembrie-informatica.pdf
#include <iostream>

using namespace std;

int X[1000], n;
int Y[1000], m;

void citire()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> X[i];
}

bool prim(int n)
{
    for (int d = 2; d * d <= n; ++d)
        if (n % d == 0)
            return false;
    return true;
}

void OrdoneazaY()
{
    bool schimbare;
    int tmp;

    do
    {
        schimbare = false;
        for (int i = 0; i < m - 1; ++i)
        {
            if (Y[i] > Y[i + 1])
            {
                tmp = Y[i];
                Y[i] = Y[i + 1];
                Y[i + 1] = tmp;
                schimbare = true;
            }
        }
    } while (schimbare == true);
}

void tiparesteY()
{
    if (m == 0)
        cout << "Sirul Y e vid.";
    else
    {
        OrdoneazaY();

        for (int i = 0; i < m; ++i)
            cout << Y[i] << ' ';
    }
}

// Returneaza adevarat daca nr nu se afla in sirul Y
bool NrNuEsteInY(int nr)
{
    for (int i = 0; i < m; ++i)
        if (Y[i] == nr)
            return false;

    return true;
}

void construiesteYPentruNr(int n)
{
    int d = 2, p;

    while (n > 1)
    {
        p = 0;
        while (n % d == 0)
        {
            ++p;
            n /= d;
        }

        if (prim(d) && p == 1 && NrNuEsteInY(d))
            Y[m++] = d;

        ++d;
    }
}

int main()
{
    citire();
    for (int i = 0; i < n; ++i)
        construiesteYPentruNr(X[i]);
    tiparesteY();

    return 0;
}
