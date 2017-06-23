// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_001.pdf

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    ifstream f("bac.txt");
    int x;
    while (f >> x)
    {
        if (x % n == 0)
            cout << x << ' ';
    }

    return 0;
}

