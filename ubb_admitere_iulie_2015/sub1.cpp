// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2015-iulie-informatica.pdf

#include <iostream>

using namespace std;

int subI_B(int n)
{
    int n2 = n;
    int mult = 1;
    int cnt = 1; // cate cifre are numarul; incepem de la 1 pentru ca in while am scris n2 > 9
    int _max = 0;

    while (n2 > 9)
    {
        mult *= 10;
        ++cnt;
        n2 /= 10;
    }

    for (int i = 0; i < cnt; ++i)
    {
        n = (n % mult) * 10 + n / mult;

        if (n > _max)
            _max = n;
    }

    return _max;
}

// varianta nerecursiva
int subI_C_1(int n, int X[], int v)
{
    for (int i = 1; i <= n; ++i)
        if (X[i] == v)
            return i;

    return -1;
}

// varianta recursiva
int subI_C_2(int n, int X[], int v)
{
    if (n == 0)
        return -1;

    if (X[n] == v)
        return n;

    return subI_C_2(n - 1, X, v);
}

int main()
{
    return 0;
}
