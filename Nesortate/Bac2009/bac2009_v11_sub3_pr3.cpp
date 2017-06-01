// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_011.pdf
// Problema 3

#include <iostream>
#include <fstream>

using namespace std;

// numere.txt
// n = 12
// val = 4 6 3 7 8 1 6 2 7 9 10 8

int main()
{
    ifstream f("numere.txt");
    int n, val;
    f >> n;
    f >> val;
    int max = val;
    while (f >> val)
    {
        cout << max << ' ';
        if (val > max)
            max = val;
    }

    return 0;
}

