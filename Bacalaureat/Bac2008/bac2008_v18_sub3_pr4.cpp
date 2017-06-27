// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_018.pdf

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.txt");
    int k;
    cin >> k;
    bool apareK = false;
    int x;

    int poz = 1;
    while (f >> x)
    {
        if (x == k && !apareK)
            apareK = true;
        else if (x > k)
            ++poz;
    }

    if (apareK)
        cout << poz;
    else
        cout << "nu exista";

    return 0;
}

