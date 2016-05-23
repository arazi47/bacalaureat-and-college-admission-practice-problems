#include <iostream>

using namespace std;

/*
Se citeste de la tastatura numarul natural n. Se cere sa se scrie un program care
construieste si tipareste o matrice patratica de ordinul n cu urmatoarele proprietati:
a) Elementele de pe diagonala principala sunt nule.
b) Elementele de pe linia i aflate sub diagonala principala au valoarea i, iar cele de
deasupra diagonalei principale au valoarea k, unde k este al i-lea numar prim.
*/

bool prim(int x)
{
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0)
            return false;

    return true;
}

int generare(int n) /// genereaza al n-lea numar prim
{
    if (n == 0)
        return 0;

    int cnt = 0;
    int nr = 2;

    while (true)
    {
        if (prim(nr))
            ++cnt;

        if (cnt == n)
            break;

        ++nr;
    }

    return nr;
}

int main()
{
    int n;
    cin >>  n; /// matrice patratica n x n
    int A[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
        if (i == j)
            A[i][j] = 0;
        else if (i < j)
            A[i][j] = generare(i);
        else
            A[i][j] = i;
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";

    cout << endl;
    }

    return 0;
}
