// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-14.01.2017.pdf

#include <iostream>

using namespace std;

int revers(int n)
{
    int r = 0;
    while (n)
    {
        r = r * 10 + n % 10;
        n /= 10;
    }

    return r;
}

bool palindrom(int n)
{
    return n == revers(n);
}

// varianta eficienta
bool palindrom2(int n)
{
    // nu poate fi palindrom daca se termina cu 0
    // pentru ca reversul numarului nu poate
    // incepe cu 0
    if (n % 10 == 0)
        return false;

    int m = 0;
    while (n)
    {
        m = m * 10 + n % 10;
        if (m == n)
            return true;

        n /= 10;
        if (m == n)
            return true;
        else if (m > n)
            return false;
    }

    return false;
}

int zerouriFactorial(int n)
{
    int cnt = 0;
    for (int d = 5; n / d >= 1; d *= 5)
        cnt += n / d;

    return cnt;
}

// Returneaza al n-lea termen al sirului Fibonacci
int nfib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return nfib(n - 2) + nfib(n - 1);
}

// Reprezinta numarul n pe biti
// Al k-lea bit este 1 daca exista cifra k in n
int configuratie(int n)
{
    int b = 0;
    while (n)
    {
        b |= 1 << (n % 10);
        n /= 10;
    }

    return b;
}

bool proprietate(int a, int b)
{
    int n1 = configuratie(a);
    int n2 = configuratie(b);

    return n1 == n2;
}

int main()
{
    // afiseaza numerele din intervalul [a, b)
    // care sunt in proprietatea P cu n
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = a; i < b; ++i)
        if (proprietate(i, n))
            cout << i << '\n';

    return 0;
}
