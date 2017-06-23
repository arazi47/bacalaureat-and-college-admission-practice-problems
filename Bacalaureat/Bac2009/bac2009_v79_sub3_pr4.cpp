// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_079.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    ifstream f("numere.in");
    // numarul de elemente ale sirului
    f >> n;

    // vector de frecventa al numerelor
    bool v[101] = {};

    while (f >> n)
        if (!v[n])
            v[n] = true;

    bool aparToateNumerele = true;
    for (int i = 1; i < 101; ++i)
    {
        if (!v[i])
        {
            cout << i << ' ';
            if (aparToateNumerele)
                aparToateNumerele = false;
        }
    }

    if (aparToateNumerele)
        cout << "NU LIPSESTE NICIUN NUMAR";

    return 0;
}
