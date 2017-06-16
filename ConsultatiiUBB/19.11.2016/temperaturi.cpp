// http://www.cs.ubbcluj.ro/wp-content/uploads/Rezolvarea-in-C-a-problemelor-prezentate-la-consultatiile-din-data-de-19.11.2016.pdf

#include <iostream>

using namespace std;

#define AN_FINAL 2015
#define MAX 100

void citire(int &anInceput, float v[MAX])
{
    cin >> anInceput;
    for (int i = 0; i <= AN_FINAL - anInceput; ++i)
        cin >> v[i];
}

float determinaTemperaturaMaxima(int n, float v[MAX])
{
    float max = v[0];
    for (int i = 1; i < n; ++i)
        if (v[i] > max)
            max = v[i];

    return max;
}

void afiseazaCeaMaiLungaPerioadaDeCresteri(int n, float v[MAX], int anInceput)
{
    int st, fin, stMax = 0, finMax = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i] < v[i + 1])
        {
            st = fin = i;
            while (v[fin] < v[fin + 1])
                ++fin;

            if (fin - st > finMax - stMax)
            {
                stMax = st;
                finMax = fin;
            }

            // Nu fin + 1, pentru ca in for mai creste o data la loop-ul urmator
            // Astfel am sari peste un element!
            i = fin;
        }
    }

    cout << anInceput + stMax << " - " << anInceput + finMax << endl;
    for (int i = stMax; i <= finMax; ++i)
        cout << v[i] << ' ';
    cout << endl;
}

void afiseazaToatePerioadeleInCareTempAuCrescut(int n, float v[MAX])
{
    int st, fin;
    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i] < v[i + 1])
        {
            st = fin = i;
            while (v[fin] < v[fin + 1])
                ++fin;

            if (fin - st > 0)
            {
                float max = v[st];
                for (int i = st + 1; i <= fin; ++i)
                    if (v[i] > max)
                        max = v[i];

                cout << max << endl;
            }

            i = fin;
        }
    }
}

// anInceput = 1999
// v[] = 15.2 12.1 10.8 11 14.6 15.8 10 11.3 12.1 12.7 13.1 13 12.8 12.6 12 11.8 11.5
int main()
{
    int anInceput;
    // sirul de temperaturi
    float v[MAX];
    citire(anInceput, v);

    // numarul de elemente al sirului de temperaturi
    int n = AN_FINAL - anInceput + 1;

    afiseazaCeaMaiLungaPerioadaDeCresteri(n, v, anInceput);
    cout << endl;
    afiseazaToatePerioadeleInCareTempAuCrescut(n, v);
    cout << endl;
    cout << determinaTemperaturaMaxima(n, v);

    return 0;
}
