// https://drive.google.com/file/d/0B0NnkrRhUimbcFFmM05yT21QOFk/view
// Problema 1

#include <iostream>

using namespace std;

int nr_cifre_binare(int n)
{
    int cnt = 0;
    while (n)
    {
        ++cnt;
        n /= 2;
    }

    return cnt;
}

// 12345, ord 3 ==> return 3
int cifra_binara_ordin_k(int n, int k)
{
    for (int i = 1; i < k; ++i)
        n /= 10;

    return n % 10;
}

bool binar_simetric(int n)
{
    int r = 0, c = n;
    while (c)
    {
        r = r * 10 + c % 10;
        c /= 10;
    }

    return n == r;
}

int main()
{

    return 0;
}
