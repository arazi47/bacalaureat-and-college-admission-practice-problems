// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2015-septembrie-informatica.pdf

#include <iostream>

using namespace std;

int n, v[100]; // marimea, vectorul de elemente

// insereaza val pe pozitia index + 1
void insereaza(int index, int val)
{
    for (int i = n; i > index; --i)
        v[i + 1] = v[i];

    v[index + 1] = val;
    ++n;
}

bool cifcomuna(int n, int m)
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
        if (vdf1[i] > 0 && vdf2[i] > 0)
            return true;

    return false;
}

// daca toate elementele de la index pana la n au o cifra comuna, e perfect
bool perfect(int index)
{
    for (int i = index + 1; i <= n; ++i)
        if (!cifcomuna(v[index], v[i]))
                return false;

    return true;
}

int O[100] = {}; // contine indexul fiecarui element din v pentru a aparea in ordine descrescatoare
int copie[100] = {}; // copie a lui v, pentru index_de_max

// Metoda ineficienta. Puteam folosi counting sort probabil...
int index_de_max()
{
    int max = 0, index;
    for (int i = 1; i <= n; ++i)
        if (copie[i] > max && copie[i] != -1)
        {
            max = copie[i];
            index = i;
        }

    copie[index] = -1; // maximul asta nu poate fi luat din nou, il setam cu -1 (de aceea ne trebuie si un vector copie)

    return index;
}

void determinaO()
{
    for (int i = 1; i <= n; ++i)
    {
        O[i] = 1; // incepem de la 1
        copie[i] = v[i];
    }

    for (int i = 1; i <= n; ++i)
        O[i] = index_de_max();
}

void citire()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
}

// determina divizorii pentru v[i] si ii insereaza in vectorul v
void determinaSiInsereazaDivizorii(int index)
{
    for (int d = 2; d <= v[index] / 2; ++d) // calculam divizorii
        if (v[index] % d == 0)
            insereaza(index, d);
}

void afisare()
{
    for (int i = 1; i <= n; ++i)
        cout << v[O[i]] << ' '; // se afiseaza v in ordinea data de O
}

int main()
{
    citire();
    for (int i = 1; i < n; ++i) // < n pentru ca ultimul element nu poate fi perfect
        if (perfect(i))
            determinaSiInsereazaDivizorii(i);
    determinaO();
    afisare();

    return 0;
}
