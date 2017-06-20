// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_063.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

// In exemplul de pe website, rezultatul este 6
// E gresit. De fapt, este 7
// Se ia si penultimul numar (116)
int main()
{
    int a, b, c, cnt = 0;
    ifstream f("date.in");
    f >> a >> b;
    while (f >> c)
    {
        if (b < a + c)
            ++cnt;

        a = b;
        b = c;
    }

    cout << cnt;

    return 0;
}
