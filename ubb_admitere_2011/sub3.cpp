// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-admitere-2011-informatica.pdf
//! Nu se iau doar valorile distincte (To-Do)

#include <iostream>

using namespace std;

bool palindrom(int nr)
{
    int copie = nr, inv = 0;

    while (nr)
    {
        inv = inv * 10 + nr % 10;
        nr /= 10;
    }

    // Daca numarul este egal cu inversul lui, este palindrom
    return (copie == inv);
}

int X[100], n = 0;
int Y[100], palindroame[100], marimeY = 0, marimeP = -1;
void citeste()
{
    while(cin >> X[n] && X[n] != 0)
        n++;
}

// Vectorul palindroame contine palindroamele nesortate
// Pentru ca in problema se specifica faptul ca vectorul
// Y trebuie sa fie construit direct ordonat
// Cu siguranta ca exista si o metoda mai rapida, si poate
// Nici n-am avea nevoie de alt vector. Doar ca sunt lenes.
void construiesteY()
{
    int tmp;
    bool schimbare;

    do
    {
        schimbare = false;

        for (int i = 0; i < marimeP - 1; ++i)
            if (palindroame[i] < palindroame[i + 1])
            {
                tmp = palindroame[i];
                palindroame[i] = palindroame[i + 1];
                palindroame[i + 1] = tmp;

                schimbare = true;
            }
    } while (schimbare);

    marimeY = marimeP;

    for (int i = 0; i < marimeY; ++i)
        Y[i] = palindroame[i];
}

void afisare()
{
    for (int i = 0; i < marimeY; ++i)
        cout << Y[i] << ' ';
}

int main()
{
    citeste();

    for (int i = 0; i < n; ++i)
    {
        if (palindrom(X[i]))
        {
            ++marimeP;
            palindroame[marimeP] = X[i];
        }
    }

    // Nu s-au introdus palindroame
    if (marimeP == -1)
        cout << "Sirul Y e vid";
    else
    {
        construiesteY();
        afisare();
    }

    return 0;
}
