// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2014-septembrie-informatica.pdf

#include <iostream>

using namespace std;

// Cel mai mare divizor comun (Euclid)
int SubI_B_1(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

// Cel mai mare divizor comun (scaderi repetate)
int SubI_B_2(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else if (a < b)
            b = b - a;
    }

    return a;
}

// Interschimbarea a doua numere intregi in 3 secvente
void SubI_C(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;

    cout << a << ' '<< b;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << SubI_B_1(a, b); // Euclid
    cout << '\n';
    cout << SubI_B_2(a, b); // Scaderi repetate
    cout << '\n';
    SubI_C(a, b); // Interschimbare

    return 0;
}
