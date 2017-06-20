// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_056.pdf
// Problema 4

#include <iostream>

using namespace std;

bool prim(int x)
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

int numar(int x)
{
    --x;
    int cnt = 0;
    while (x >= 2)
    {
        if (prim(x))
            ++cnt;
        --x;
    }

    return cnt;
}

// La cateva cazuri nu da corect
int main()
{
    int a, b;
    cin >> a >> b;
    int nrPA = numar(a), nrPB = numar(b);

    if (nrPB - nrPA >= 1)
        cout << "DA";
    else
        cout << "NU";

    return 0;
}
