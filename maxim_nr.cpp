#include <iostream>

using namespace std;

int main()
{
/// ex: pentru n 4273
/// 2734 7342 3427 4273 si se alege numarul maxim
/// regula: prima cifra a numarului initial va deveni ultima
    int n, m = 0;
    cin >> n;

    int n2 = n, nr = 0;

    while (n2 != 0)
    {
        n2 /= 10;
        nr++;
    }

    int mult = 1; /// multiplier

    for (int i = 1; i < nr; i++)
        mult *= 10;

    n2 = n; /// start from initial number

    for (int i = 0; i < nr; i++)
    {
        n2 = (n2 % mult) * 10 + (n2 / mult);
		cout << n2 << " ";

        if (n2 > m)
            m = n2;
    }

    cout << "numarul maxim este: " << m;
}