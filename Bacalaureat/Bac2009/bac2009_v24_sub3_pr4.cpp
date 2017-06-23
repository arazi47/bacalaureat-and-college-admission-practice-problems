// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_024.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

// probabil exista o metoda mai eficienta
// decat sa citesc de doua ori fisierul
int main()
{
    ifstream f("bac.txt");
    int n, a, b;
    f >> n;
    for (int i = 0; i < n; ++i)
        f >> a;

    f >> a >> b;

    ifstream g("bac.txt");
    g >> n;
    int val;
    int difmax = 99999;
    int valmax;
    for (int i = 0; i < n; ++i)
    {
        g >> val;
        if (val >= a && val <= b && val - a < difmax)
        {
            difmax = val - a;
            valmax = val;
        }
    }

    if (difmax != 99999)
        cout << valmax;
    else
        cout << "NU";

    return 0;
}

