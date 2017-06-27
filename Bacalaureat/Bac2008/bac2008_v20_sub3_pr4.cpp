// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_020.pdf

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    bool v[9999 + 1] = {};
    int x;
    ifstream f1("nr1.txt");
    ifstream f2("nr2.txt");

    // numarul de elemente ale sirurilor
    f1 >> x;
    f2 >> x;

    while (f1 >> x)
    {
        if (!v[x])
            v[x] = true;
    }

    while (f2 >> x)
    {
        if (v[x])
            cout << x << ' ';
    }

    return 0;
}

