// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-18.03.2017.pdf

#include <iostream>

using namespace std;

void citire(int &n, int a[101][101])
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
}

void determinaMinime(int n, int a[101][101], int minime[])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i < j && i + j < n + 1) // N
            {
            if (a[i][j] < minime[0])
                minime[0] = a[i][j];
            }
            else if (i < j && i + j > n + 1) // V
            {
                if (a[i][j] < minime[3])
                    minime[3] = a[i][j];
            }
            else if (i > j && i + j < n + 1) // E
            {
                if (a[i][j] < minime[2])
                    minime[2] = a[i][j];
            }
            else if (i > j && i + j > n + 1) // S
             {
                 if (a[i][j] < minime[1])
                    minime[1] = a[i][j];
             }
        }
}

void afiseaza(int n, int a[101][101])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}

void inlocuiesteMinime(int n, int a[101][101], int minime[])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i < j && i + j < n + 1 && a[i][j] == minime[0]) // N
                a[i][j] = minime[3];
            if (i < j && i + j > n + 1 && a[i][j] == minime[3]) // V
                a[i][j] = minime[1];
            if (i > j && i + j < n + 1 && a[i][j] == minime[2]) // E
                a[i][j] = minime[0];
            if (i > j && i + j > n + 1 && a[i][j] == minime[1]) // S
                a[i][j] = minime[2];
        }
}

int main()
{
    int n, a[101][101];
    citire(n, a);

    int m = 4, minime[4] = { 1000, 1000, 1000, 1000 };
    determinaMinime(n, a, minime);

    cout << "Minime: ";
    for (int i = 0; i < m; ++i)
        cout << minime[i] << ' ';
    cout << endl;

    inlocuiesteMinime(n, a, minime);
    afiseaza(n, a);

    return 0;
}
