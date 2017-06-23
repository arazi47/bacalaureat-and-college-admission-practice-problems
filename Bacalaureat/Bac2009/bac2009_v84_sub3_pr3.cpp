// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_084.pdf
// Problema 3

#include <iostream>

using namespace std;

int main()
{
    int n, x, spare = 0, simpare = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (!(x % 2))
            spare += x;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (x % 2 && x < spare)
            simpare +=  x;
    }

    cout << simpare;

    return 0;
}
