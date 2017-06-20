// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_084.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int CMMMC(int a, int b)
{
    int copieA = a, copieB = b, r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return (copieA * copieB) / a;
}

int main()
{
    ifstream f("numere.in");
    int a, b;
    ofstream g("numere.out");
    while (f >> a >> b)
        g << CMMMC(a, b) << endl;

    return 0;
}
