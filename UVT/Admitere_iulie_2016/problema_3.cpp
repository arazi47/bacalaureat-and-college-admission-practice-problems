// https://drive.google.com/file/d/0B0NnkrRhUimbU0Ntb3IyYnhGVkk/view
// Problema 3

#include <iostream>

using namespace std;

bool estePrim(int x)
{
    if (x < 2)
        return false;
    if (x % 2 == 0 && x != 2)
        return false;
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return false;

    return true;
}

bool esteFactorPrim(int N, int x)
{
    if (!estePrim(x))
        return false;

    int d = 2;
    while (N > 1)
    {
        if (d * d > N)
            d = N;
        if (d > x)
            return false;

        if (N % d == 0 && d == x)
            return true;
        else
            while (N % d == 0)
                N /= d;

        ++d;
    }

    return false;
}

// In subiect se spune sa folosim cealalta functie, insa e mai usor asa
int esteFactorPrimRetPutere(int N, int x)
{
    if (!estePrim(x))
        return -1;

    int d = 2, p;
    while (N > 1)
    {
        if (d * d > N)
            d = N;
        if (d > x)
            return -1;

        p = 0;
        while (N % d == 0)
        {
            ++p;
            N /= d;
        }

        if (d == x)
            return p;

        ++d;
    }

    return -1;
}

int puncte(int N, int x)
{
    return esteFactorPrimRetPutere(N, x);
}

int punctaj(int v[], int N)
{
    int pct = 0;
    for (int i = 0; i < 3; ++i)
        pct += puncte(N, v[i]);

    return pct;
}

int main()
{
    int v[3], N;
    cin >> v[0] >> v[1] >> v[2];
    cin >> N;

    cout << punctaj(v, N);

    return 0;
}
