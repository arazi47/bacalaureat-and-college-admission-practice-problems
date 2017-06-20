// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_067.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    ifstream f("numere.txt");
    // numarul de elemente ale sirului
    f >> n;
    int a, b;
    f >> a;
    while (f >> b)
    {
        if (a != b)
        {
            cout << a << ' ';
            a = b;
        }
    }

    // ultimul numar
    cout << b;

    return 0;
}
