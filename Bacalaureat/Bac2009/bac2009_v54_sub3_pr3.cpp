// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_054.pdf
// Problema 3

#include <iostream>

using namespace std;

void inv(int a, int &b)
{
    b = 0;
    while (a)
    {
        b = b * 10 + (a % 10);
        a /= 10;
    }
}

int main()
{
    int n, nr1, nr2, pal1, pal2;
    cin >> n;
    nr1 = n - 1;
    nr2 = n + 1;
    while (true)
    {
        inv(nr1, pal1);
        if (nr1 == pal1)
            break;

        --nr1;
    }

    while (true)
    {
        inv(nr2, pal2);
        if (nr2 == pal2)
            break;

        ++nr2;
    }

    if (n - nr1 < nr2 - n)
        cout << nr1 << endl;
    else
        cout << nr2 << endl;

    return 0;
}
