// http://bacinfo.cnlr.ro/subiecte-bac/2009/e_info_intensiv_c_siii_029.pdf
// Problema 4

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n, m, A[100], B[100];
    ifstream f("numere.in");
    f >> n >> m;
    for (int i = 0; i < n; ++i)
        f >> A[i];
    for (int i = 0; i < m; ++i)
        f >> B[i];

    int iA = 0, iB = 0;
    int sum = 0;
    for (; iA < n; ++iA)
    {
        sum += A[iA];
        if (sum == B[iB])
        {
            ++iB;
            sum = 0;
        }
    }

    // Daca am parcurs ambele siruri (am ajuns la finalul fiecaruia)
    if (iA == n && iB == m)
        cout << "DA";
    else
        cout << "NU";


    return 0;
}

