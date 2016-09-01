// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2015-septembrie-informatica.pdf

#include <iostream>

using namespace std;

// Pentru n = 91, se afiseaza 13
// Pentru n = 22, se afiseaza 11
// Programul afiseaza cel mai mare divizor al lui n
int main()
{
    int n, x, y, z;
    cin >> n;
    x = 1;
    y = n / 2;

    while (x && y > 0)
    {
        z = n;

        while (z >= y)
            z -= y;

        x = z;
        --y;
    }
    ++y;

    cout << y;
    return 0;
}
