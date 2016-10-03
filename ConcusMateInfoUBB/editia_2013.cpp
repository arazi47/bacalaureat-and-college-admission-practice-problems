// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-2013.pdf

#include <iostream>

using namespace std;

void citeste(int &n, int X[])
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> X[i];
}

bool prefix(int a, int b)
{
    while (b > a)
    {
        if (b / 10 == a)
            return true;
        b /= 10;
    }
    return false;
}

void detsecv2(int st, int &en, int X[])
{
    int i = st, j = st + 1;
    while (prefix(X[i], X[j]))
    {
        ++i;
        ++j;
    }

    en = j;
}

void detsecv(int n, int X[], int &secvs, int &secve)
{
    int max_e = 0, max_s = 0;
    for (int i = 1; i < n - 1; ++i)
        if (prefix(X[i], X[i + 1]))
        {
            secvs = i;
            detsecv2(secvs, secve, X);

            if (secve - secvs > max_e - max_s)
            {
                max_e = secve;
                max_s = secvs;
                i = secve + 1;
            }
        }

        secvs = max_s;
        secve = max_e;
}

int main()
{
    int n, X[100], secvs = 0, secve = 0;
    citeste(n, X);
    detsecv(n, X, secvs, secve);
    if (secve - secvs > 0)
    {
        while (secvs != secve)
        {
            cout << X[secvs] << ' ';
            ++secvs;
        }
    }
    else
        cout << "Secventa este vida";

    return 0;
}
