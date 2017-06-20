// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_029.pdf
// Problema 3

#include <iostream>

using namespace std;

int multipli(int a, int b, int c)
{
    int cnt = 0;
    while (a <= b)
    {
        if (a % c == 0)
            ++cnt;
        ++a;
    }

    return cnt;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << multipli(a, b, c);

    return 0;
}

