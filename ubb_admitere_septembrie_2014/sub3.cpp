// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2014-septembrie-informatica.pdf

#include <iostream>

using namespace std;

bool Prim(int n)
{
    if (n == 0 || n == 1)
        return false;

    for (int d = 2; d * d <= n; ++d)
        if (n % d == 0)
            return false;

    return true;
}

bool SuperPrim(int n)
{
    int n2 = n, cifre = 0, putere = 1;

    while (n2)
    {
        putere *= 10;
        ++cifre;
        n2 /= 10;
    }

    putere /= 10; // Puterea e 10^(numarul cifrelor) acum, dar ne trebuie 10^(numarul cifrelor - 1)

    for (int i = 1; i <= cifre; ++i)
    {
        if (Prim(n))
            return true;

        n = n % putere * 10 + n / putere;
    }

    return false;
}

int main()
{


    return 0;
}
