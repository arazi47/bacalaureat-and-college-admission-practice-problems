// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_077.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("bac.in");
    int v[101] = {}, aparitiiMax = 0;
    int n;
    f >> n;
    while (f >> n)
    {
        ++v[n];
        if (v[n] > aparitiiMax)
            aparitiiMax = v[n];
    }

    for (int i = 0; i < 101; ++i)
        if (v[i] == aparitiiMax)
            cout << i << ' ';

    return 0;
}
