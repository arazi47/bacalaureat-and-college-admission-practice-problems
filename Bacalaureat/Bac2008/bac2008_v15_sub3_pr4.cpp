// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_015.pdf

#include <iostream>
#include <fstream>

using namespace std;

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

int main()
{
    ifstream f("bac.in");
    int a = -1, b = -1, n;

    while (f >> n)
    {
        if (prim(n))
        {
            if (a == -1)
                a = n;
            else if (b == -1)
                b = n;
            else
            {
                a = b;
                b = n;
            }
        }
    }

    if (a == -1 || b == -1)
        cout << "Numere prime insuficiente.";
    else
        cout << a << ' ' << b;

    return 0;
}

