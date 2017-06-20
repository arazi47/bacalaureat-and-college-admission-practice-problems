// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_055.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

void cifre(int a, int &b)
{
    b = 0;
    bool v[10] = {};
    while (a)
    {
        if (!v[a % 10])
            v[a % 10] = true;
        a /= 10;
    }

    for (int i = 0; i < 10; ++i)
        if (v[i])
            b = b * 10 + i;
}

int main()
{
    ifstream f("date.in");
    int n, nr;

    // marimea sirului
    f >> n;

    while (f >> n)
    {
        cifre(n, nr);
        if (n == nr)
            cout << n << ' ';
    }

    return 0;
}
