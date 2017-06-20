// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_045.pdf
// Problema 3

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    float v[100];
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    bool afiseaza;
    for (int i = 0; i < n - 1; ++i)
    {
        afiseaza = true;
        // nu putem incepe j-ul de la i + 1
        // din cauza ca pot fi mai multe aparitii ale aceluiasi numar
        for (int j = 0; j < n; ++j)
            if (v[i] == v[j] && i != j)
            {
                afiseaza = false;
                break;
            }
        if (afiseaza)
            cout << v[i] << ' ';
    }

    return 0;
}
