// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-2013.pdf

#include <iostream>

using namespace std;

// in enuntul problemei nu este specificat numarul maxim de elemente
// in schimb, se specifica faptul ca indexarea incepe de la 1
#define MAX 100 + 1

void citire(int &n, int X[MAX])
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> X[i];
}

// verifica daca a este prefixul lui b
bool prefix(int a, int b)
{
    while (a < b)
    {
        if (b / 10 == a)
            return true;

        b /= 10;
    }

    return false;
}

void determinaSecventaMaxima(int n, int X[MAX], int &start, int &stop)
{
    int startMax = 0, stopMax = 0;

    for (int i = 1; i < n; ++i)
    {
        if (prefix(X[i], X[i + 1]))
        {
            start = i;
            stop = i + 1;
            while (prefix(X[stop], X[stop + 1]) && stop < n)
                ++stop;

            if (stop - start > stopMax - startMax)
            {
                startMax = start;
                stopMax = stop;
            }
        }
    }

    start = startMax;
    stop = stopMax;
}

void tiparesteSecventaMaxima(int X[MAX], int start, int stop)
{
    if (start == 0 && stop == 0)
    {
        cout << "Secventa este vida";
    }
    else
    {
        while (start <= stop)
        {
            cout << X[start] << ' ';
            ++start;
        }
    }
}

int main()
{
    int n, X[MAX];

    // indexurile primului si ultimului element din secventa maxima de prefixe
    int start, stop;
    citire(n, X);
    determinaSecventaMaxima(n, X, start, stop);
    tiparesteSecventaMaxima(X, start, stop);

    return 0;
}

