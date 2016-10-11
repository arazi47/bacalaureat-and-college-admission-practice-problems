// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2015.pdf

#include <iostream>

using namespace std;

int sumacif(int n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }

    return s;
}

void sortare(int n, int v[])
{
    int tmp;
    bool ch;
    do
    {
        ch = false;
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
            if (v[i] % 2 == 0 && v[j] % 2 == 0 &&
                sumacif(v[i]) < sumacif(v[j]))
        {
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            ch = true;
        }
    } while (ch);

}

// y => valoarea lui x in polinom
int polinom_iterativ(int n, int v[], int y)
{
    int rez = 0;
    for (int i = 0; i < n; ++i)
        rez = rez * y + v[i];
    return rez;
}

int polinom_recursiv(int n, int v[], int y)
{
    if (n == 0)
        return v[0];

    return y * polinom_recursiv(n - 1, v, y) + v[n];
}


int main()
{
    return 0;
}
