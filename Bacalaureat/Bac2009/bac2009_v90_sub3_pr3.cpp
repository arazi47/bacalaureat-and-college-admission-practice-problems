// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_090.pdf
// Problema 3

#include <iostream>

using namespace std;

bool verif(int n, int a)
{
    int nrcif = 0;
    while (n)
    {
        if (n % 10 > a)
            return false;
        n /= 10;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 10; ++i)
        if (!verif(n, i))
            cout << i + 1 << ' ';
        else
            break;

    return 0;
}
