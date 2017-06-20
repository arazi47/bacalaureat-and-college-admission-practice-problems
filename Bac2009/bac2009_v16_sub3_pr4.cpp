// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_016.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.txt");
    int n, v[10] = {};
    while (f >> n)
    {
        while (n)
        {
            ++v[n % 10];
            n /= 10;
        }
    }

    for (int i = 9; i >= 0; --i)
    {
        while (v[i])
        {
            cout << i;
            --v[i];
        }
    }

    return 0;
}

