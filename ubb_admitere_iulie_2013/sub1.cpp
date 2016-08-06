// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2013-informatica.pdf

#include <iostream>

using namespace std;

// Returneaza al k-lea element din sirul lui Fibonacci
int Fibonacci(int k)
{
    if (k <= 2)
        return 1;

    int a, b, c;
    a = b = 1;
    int cnt = 2;

    do
    {
        ++cnt;

        c = a + b;
        a = b;
        b = c;

        if (cnt == k)
            return c;

    } while (true);
}

int main()
{
    return 0;
}
