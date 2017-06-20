// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_014.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

/*
bac.txt:
11
21
30
40
51
16
17
10
1
*/

int sumaCifre(int n)
{
    int s = 0;
    while (n)
    {
        s += (n % 10);
        n /= 10;
    }

    return s;
}

int main()
{
    int val, cnt = 0;
    ifstream f("bac.txt");
    int i = 0;

    while (f >> val)
    {
        ++i;
        cout << val << ' ';
        if (i % 5 == 0)
            cout << '\n';
        if (sumaCifre(val) % 2 == 0)
            ++cnt;
    }

    // Sa nu incepem o alta linie de doua ori
    if (i % 5)
        cout << '\n';

    cout << cnt;

    return 0;
}

