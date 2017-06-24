// http://bacinfo.cnlr.ro/subiecte-bac/2008/e_informatica_intensiv_c_iii_011.pdf

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("numere.txt");
    int n, max;

    // numarul elementelor
    f >> n;

    f >> n;
    max = n;
    cout << max << ' ';
    while (f >> n)
    {
    	if (n > max)
    		max = n;

    	cout << max << ' ';
    }

    return 0;
}

