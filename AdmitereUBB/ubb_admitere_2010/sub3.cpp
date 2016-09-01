// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2010-informatica.pdf

#include <iostream>

using namespace std;

int n;
int rez[100][100];

bool Prime(int n)
{
    for (int d = 2; d * d <= n; ++d)
        if (n % d == 0)
            return false;
    return true;
}

int NthPrimeNumber(int m)
{
    int cnt = 0;
    for (int nr = 2; ; ++nr)
    {
        if (Prime(nr))
            ++cnt;

        if (cnt == m)
            return nr;
    }
}

void printResult()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << rez[i][j] << ' ';

        cout << endl;
    }
}

int main()
{
    cin >> n;

    // Incepem indexarea de la 1
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                rez[i][j] = 0;
            if (i > j) // Sub diagonala principala
                rez[i][j] = i;
            if (i < j) // Deasupra diagonalei principale
                rez[i][j] = NthPrimeNumber(i);
        }

    printResult();

    return 0;
}
