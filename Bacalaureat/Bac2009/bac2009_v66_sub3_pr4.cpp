// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_066.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in_b("b.txt");
    int min, x;
    in_b >> min;
    while (in_b >> x)
        if (x < min)
            min = x;

    ifstream in_a("a.txt");
    int cnt = 0;
    while (in_a >> x)
    {
        if (x < min)
        {
            //cout << x << ' ';
            ++cnt;
        }
    }

    cout << cnt;

    return 0;
}
