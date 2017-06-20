// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_062.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    bool v[100] = {};
    int n;
    ifstream f("date.in");
    while (f >> n)
    {
        if (!v[n])
            v[n] = true;
    }

    ofstream g("date.out");
    for (int i = 1; i <= 99; i += 2)
        if (v[i])
            g << i << ' ';
    g << endl;
    for (int i = 98; i >= 0; i -= 2)
        if (v[i])
            g << i << ' ';

    return 0;
}
