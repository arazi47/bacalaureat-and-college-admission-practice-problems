// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2017.pdf

#include <iostream>

using namespace std;

int cmmdc(int a, int b)
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

int cmmmc(int a, int b)
{
    return (a * b) / cmmdc(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    int lcm = cmmmc(a, b);

    cout << lcm / a - 1 + lcm / b - 1 << endl;

    // Stim ca cmmmc(a, b) = (a * b) / cmmdc(a, b)
    // Ecuatia poate fi scrisa si asa:
    int gcd = cmmdc(a, b);
    cout << a / gcd - 1 + b / gcd - 1;

    return 0;
}
