// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_018.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int k;
    cin >> k;
    int poz = 1;
    bool gasit = false;
    int n;
    ifstream f("numere.txt");

    while (f >> n)
    {
        if (n > k)
            ++poz;
        else if (n == k && !gasit)
            gasit = true;
    }

    if (!gasit)
        cout << "nu exista";
    else
        cout << poz;

    return 0;
}

