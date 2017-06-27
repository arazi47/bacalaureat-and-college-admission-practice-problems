// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_016.pdf

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.txt");

    int v[10] = {}, x;
    while (f >> x)
    {
        while (x)
        {
            ++v[x % 10];
            x /= 10;
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

