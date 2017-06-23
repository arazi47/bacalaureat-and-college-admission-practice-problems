// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_027.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

// Nu-s sigur daca e corect
// Dar cred ca e
int main()
{
    ifstream f("numere.in");
    int n;
    float v[100];
    f >> n;
    for (int i = 0; i < n; ++i)
        f >> v[i];

    int x = int(v[1]) - int(v[0]);
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (int(v[j]) - int(v[i]) < x)
                x = int(v[j]) - int(v[i]);

    cout << x;

    return 0;
}

