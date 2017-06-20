// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_009.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

// bac.txt:
// 12 2345 123 67 989 6 999 123 67 989 999
int main()
{
    ifstream f("bac.txt");
    bool v[1000] = {};
    int x;
    while (f >> x)
        if (x <= 999 && v[x] == false)
            v[x] = true;

    int cnt = 0;
    for (int i = 999; i >= 100 && cnt < 2; --i)
        if (!v[i])
        {
            cout << i << ' ';
            ++cnt;
        }

    return 0;
}

