// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-05.11.2016.pdf

#include <iostream>

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

// X = (1,2,2,3,3,3,4,5,5,5,5,5,6,7,7,7,7,7,7,7,8,9,10,11,...)
int determinaElement(int k)
{
    int n = 0, cnt = 0;
    while (cnt < k)
    {
        ++n;
        if (prim(n))
            cnt += n;
        else
            ++cnt;
    }

    return n;
}

int urmatorulDivizorPrim(int n, int ultimulDivizorGasit)
{
    if (prim(n) || ultimulDivizorGasit == -1)
        return -1;

    for (int d = ultimulDivizorGasit + 1; d <= n / 2; ++d)
        if (n % d == 0 && prim(d))
            return d;

    return -1;
}

// Afiseaza elementele sirului X care sunt intre pozitiile intervalului (inchis) [a,b]
// X = (1,2,3,4,2,5,6,2,3,7,8,2,9,3,10,2,5,11,12,2,3,13,14,2,7,...)
// Indexarea sirului incepe de la 1
void determinaElementS2(int a, int b)
{
    int n = 0, cnt = 0, ultdiv;
    while (cnt < b)
    {
        ++n;
        ++cnt;
        if (cnt >= a)
            cout << n << ' ';
        ultdiv = 0;
        while (cnt < b)
        {
            ultdiv = urmatorulDivizorPrim(n, ultdiv);
            if (ultdiv != -1)
            {
                ++cnt;
                if (cnt >= a)
                    cout << ultdiv << ' ';
            }
            else
                break;
        }
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    // Indexarea incepe de la 0 in functia facuta de mine
    determinaElementS2(a, a + b);

    return 0;
}
