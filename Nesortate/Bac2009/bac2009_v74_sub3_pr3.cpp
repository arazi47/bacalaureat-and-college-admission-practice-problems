// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_074.pdf
// Problema 3

#include <iostream>

using namespace std;

void cifra(int n, int &x)
{
    x = 0;
    while (n)
    {
        if (n % 10 > x)
            x = n % 10;
        n /= 10;
    }
}

int main()
{
    int n, x;
    cin >> n;
    cifra(n, x);

    if (x <= 4)
        cout << "Da";
    else
        cout << "Nu";

    return 0;
}
