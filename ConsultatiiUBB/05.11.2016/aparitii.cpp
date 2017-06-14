// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-05.11.2016.pdf

#include <iostream>

using namespace std;

// determina numarul de aparitii
// al cifrei c in numarul n
// in baza b
int aparitii(int n, int b, int c)
{
    int cnt = 0;
    while (n)
    {
        if (n % b == c)
            ++cnt;
        n /= b;
    }

    return cnt;
}

int aparitiiRecursiv(int n, int b, int c)
{
    if (n == 0)
        return 0;

    if (n % b == c)
        return 1 + aparitiiRecursiv(n / b, b, c);
    return aparitiiRecursiv(n / b, b, c);
}

int main()
{
    int n, c, b;
    cin >> n >> b >> c;
    cout << aparitii(n, b, c) << ' ' << aparitiiRecursiv(n, b, c);

    return 0;
}
