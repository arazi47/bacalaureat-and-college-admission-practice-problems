// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2016-iulie-informatica.pdf

#include <iostream>

using namespace std;

int F(int a, int b)
{
    int factor = a;
    for (int i = 1; i <= b - 1; ++i)
    {
        a *= factor;
        a = a % 10;
    }

    return a;
}

int FRec(int a, int b)
{
    if (b == 0)
        return 1;
    return (a * FRec(a, --b)) % 10;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << F(a, b) << ' ' << FRec(a, b);

    return 0;
}
