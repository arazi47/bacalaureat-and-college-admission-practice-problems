// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2012-informatica.pdf

#include <iostream>

using namespace std;

int n, X[100];
int m, R[100];

void citire()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> X[i];
}

bool asemenea(int n, int m)
{
    int vdf1[10] = {}, vdf2[10] = {};

    while (n)
    {
        vdf1[n % 10]++;
        n /= 10;
    }

    while (m)
    {
        vdf2[m % 10]++;
        m /= 10;
    }

    for (int i = 0; i < 10; ++i)
        // Daca cifra de pe pozitia i exista in primul vector si in al doilea nu
        if (vdf1[i] > 0 && vdf2[i] == 0)
            return false;

    return true;
}

void adauga_la_r(int val)
{
    R[m++] = val;
}

void elimina_din_x(int index)
{
    for (int i = index; i < n - 1; ++i)
        X[i] = X[i + 1];

    --n;
}

void scoate_din_x(int val)
{
    for (int i = 0; i < n; ++i)
        if (X[i] == val)
        {
            elimina_din_x(i);
            break; // Break-ul e daca avem valori multiple
            // De exemplu daca avem n = 4 si X = { 12, 21, 3, 21 }
            // Daca nu punem break ni-l ia si pe 21 de la final
            // Dar nu vrem sa faca asta, pentru ca nu e asemenea cu un numar de pe un index apropiat (plus/minus o pozitie)
        }
}

void gaseste_toate_asemenea_de_la(int startIndex)
{
    int endIndex = startIndex;
    for (int i = startIndex; i < n - 1; ++i)
        if (asemenea(X[i], X[i + 1]))
        {
            endIndex = i + 1;
        }

        for (int i = startIndex; i <= endIndex; ++i)
            adauga_la_r(X[i]);

        // Nu merge X-ul din cauza asta
        // Trebuie sa retinem undeva valorile initiale pe care trebuie sa le scoatem
        // Pentru ca indexurile se schimba cand scoatem un element
        //for (int i =  startIndex; i <= endIndex; ++i)
          //  scoate_din_x(X[i]);

        // De fapt avem valorile in R...
        for (int i = 0; i < m; ++i)
            scoate_din_x(R[i]);
}

void elimina_asemenea()
{
    for (int i = 0; i < n - 1; ++i)
        if (asemenea(X[i], X[i + 1]))
            //elimina_index(i);
            gaseste_toate_asemenea_de_la(i);
}

void afiseaza(int marime, int v[])
{
    for (int i = 0; i < marime; ++i)
        cout << v[i] << ' ';
    cout << '\n';
}

int main()
{
    citire();
    elimina_asemenea();
    cout << "X = ";
    afiseaza(n, X);
    cout << "R = ";
    afiseaza(m, R);
    return 0;
}
