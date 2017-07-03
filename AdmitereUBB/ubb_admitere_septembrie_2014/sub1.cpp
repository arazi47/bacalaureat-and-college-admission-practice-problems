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

// 3 metode diferite de interschimbare a numerelor a si b
void SubI_C_1(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;

    cout << a << ' '<< b << endl;
}

void SubI_C_2(int a, int b)
{
    a = a * b;
    b = a / b;
    a = a / b;

    cout << a << ' ' << b << endl;
}

void SubI_C_3(int a, int b)
{
    int t = a;
    a = b;
    b = t;

    cout << a << ' ' << b << endl;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << SubI_B_1(a, b); // Euclid
    cout << endl;
    cout << SubI_B_2(a, b); // Scaderi repetate
    cout << endl;
    SubI_C_1(a, b); // Interschimbare
    SubI_C_2(a, b);
    SubI_C_3(a, b);

    return 0;
}

