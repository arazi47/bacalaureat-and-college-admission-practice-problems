// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_060.pdf
// Problema 4

#include <iostream>

using namespace std;

int radical(int a)
{
    int n = 1;
    while (true)
    {
        if (n * n <= a && (n + 1) * (n + 1) > a)
            return n;
        ++n;
    }
}

int main()
{
    int x;
    cin >> x;

    // este patrat perfect
    if (radical(x) * radical(x) == x)
        cout << "DA";
    else
        cout << "NU";

    return 0;
}
