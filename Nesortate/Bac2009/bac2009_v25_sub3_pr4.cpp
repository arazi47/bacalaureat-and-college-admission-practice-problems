// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_025.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    ifstream f("numar.txt");
    double n;
    f >> n;
    int p = 1;

    // cat timp numarul are zecimale
    while (n != (int)n)
    {
        n *= 10;
        p *= 10;
    }

    // simplificam numaratorul si numitorul
    // cu CMMDCul lor
    int cm = cmmdc(n, p);
    n /= cm;
    p /= cm;

    cout << n << ' ' << p;

    return 0;
}

