// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2014-septembrie-informatica.pdf

#include <iostream>

using namespace std;

// a) Se afiseaza valoarea 10
// b) 6 42 42 7 7 (intai se calculeaza CMMDC dintre 6 42 42 = 6, apoi 42 42 7 = 7, apoi 42 7 7 = 7 => 6 + 7 + 7 = 20
// c) Programul calculeaza cei mai mari divizori comuni a trei numere consecutive
void SubiectulII()
{
    int a, b, c, s = 0, x, y, z;

    cin >> a >> b;
    for (int i = 1; i <= 3; ++i)
    {
        cin >> c;
        x = a;
        y = b;
        z = c;

        // Putem observa algoritmul pentru determinarea
        // celui mai mare divizor comun (metoda scaderilor repetate)
        // pentru 3 numere
        do
        {
            if (x < y)
                y = y - x;
            if (y < z)
                z = z - y;
            if (z < x)
                x = x - z;
        } while (!(x == y && y == z)); // Deoarece nu exista repeta...pana cand (conditie) in C++ folosim repeta...cat timp (!conditie)

        s = s + x;
        a = b;
        b = c;
    }

    cout << s;
}

int main()
{
    SubiectulII();

    return 0;
}
