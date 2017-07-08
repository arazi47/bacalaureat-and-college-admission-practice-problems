// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2014.pdf

#include <iostream>
#include <cmath>

using namespace std;

// metoda:
// se calculeaza cmmdc dintre cmmmc si urmatorul numar
// apoi cmmmc = (a * b) / cmmmdc(a, b)
int subI_B(int n, int X[500])
{
    int cmmmc, r;
    // intai cmmmc = primul element al sirului
    // ca sa se poata calculca cmmdc si cmmmc dintre primele doua
    cmmmc = X[0];

    for (int i = 1; i < n; ++i)
    {
        int a = cmmmc, b = X[i];
        while (X[i])
        {
            r = a % X[i];
            a = X[i];
            X[i] = r;
        }

        // cmmmc = cmmmc anterior * b / cmmdc
        // cmmdc = a (vezi while-ul de mai sus)
        cmmmc = (cmmmc * b) / a;
    }

    return cmmmc;
}

// varianta ce utilizeaza structuri repetitive
int subI_C1(int n)
{
    int copie = n;
    int putere = 1;
    while (copie > 9)
    {
        putere *= 10;
        copie /= 10;
    }

    return n % putere * 10 + n / putere;
}

// varianta ce nu utilizeaza structuri repetitive
int subI_C2(int n)
{
    // numarul de cifre ale lui n - 1
    // ex: pentru n = 1234, nrCifre = 3
    int nrCifre = log10(n);
    int putere = pow(10, nrCifre);
    return n % putere * 10 + n / putere;
}

int main()
{

    int n, X[500];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> X[i];

    cout << subI_B(n, X);


    /*
    int n;
    cin >> n;
    cout << subI_C1(n) << ' ' << subI_C2(n);
    */

    return 0;
}


