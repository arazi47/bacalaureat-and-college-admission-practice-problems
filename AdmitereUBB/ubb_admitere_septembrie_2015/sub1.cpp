// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2015-septembrie-informatica.pdf

#include <iostream>

using namespace std;

bool SUBIECTUL_I_A(int n)
{
    int sumaCif, copie;
    for (int i = 1; i < n; ++i)
    {
        sumaCif = 0;
        copie = i;
        while (copie)
        {
            sumaCif += copie % 10;
            copie /= 10;
        }
        if (i + sumaCif == n)
            return true;
    }
    return false;
}

bool SUBIECTUL_I_B(int n)
{
    int div = 2, putere;

    while (n > 1)
    {
        putere = 0;
        while (n % div == 0)
        {
            ++putere;
            n /= div;
        }
        if (putere % 2 == 0)
            return true;
        else
            ++div;
    }
    return false;
}

bool SUBIECTUL_I_C_ITERATIV(int n, int X[])
{
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (X[i] == X[j])
                return false;
    return true;
}

bool SUBIECTUL_I_C_RECURSIV(int n, int X[])
{
    if (n == 1)
        return true;

    for (int i = n - 1; i >= 1; --i)
        if (X[n] == X[i])
            return false;

    return SUBIECTUL_I_C_RECURSIV(n - 1, X);
}

int main()
{
    return 0;
}
