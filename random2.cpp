#include <iostream>
#include <cstring>

using namespace std;

void suma_cifrelor()
{
    int n, s = 0;
    cin >> n;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }

    cout << s;
}

void oglindit()
{
    int n;
    cin >> n;
    int n2 = 0;
    while (n)
    {
        n2 = n2 * 10 + n % 10;
        n /= 10;
    }

    cout << n2;
}

void elimina_cifre_pare()
{
    int n, n2 = 0;
    cin >> n;
    while (n)
    {
        if ((n % 10) % 2 != 0)
            n2 = n2 * 10 + n % 10;

        n /= 10;
    }
    while (n2)
    {
        n = n * 10 + n2 % 10;
        n2 /= 10;
    }

    cout << n;
}

void palindrom()
{
    int n, copie_n;
    cin >> n;
    copie_n = n;
    int o = 0; // Oglindit
    while (n)
    {
        o = o * 10 + n % 10;
        n /= 10;
    }

    if (copie_n == o)
        cout << "DA";
    else
        cout << "NU";
}

void palindroame_din_interval()
{
    int a, b;
    cin >> a >> b;
    int o = 0; // Oglindit
    int copie;
    int copie2;
    while (a <= b)
    {
        copie = a;
        copie2 = a;
        o = 0;

        while (copie)
        {
            o = o * 10 + copie % 10;
            copie /= 10;
        }

        if (copie2 == o)
            cout << o << " este\n";

        ++a;
    }
}

void suma_cif_afisare()
{
    int n;
    int v[100];
    cin >> n;
    int suma;
    cout << "suma: ";
    cin >> suma;
    int s;
    int copie;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        s = 0;
        copie = v[i];

        while (v[i])
        {
            s += v[i] % 10;
            v[i] /= 10;
        }

        if (s == suma)
            cout << copie << " are suma data\n";
    }
}

void media_aritm_a_palindroamelor()
{
    int n;
    cin >> n;
    int o;
    int n2;
    int palindrom_cnt = 0;
    int palindrom_suma = 0;
    while (n != 0)
    {
        o = 0;
        n2 = n;
        while (n)
        {
            o = o * 10 + n % 10;
            n /= 10;
        }
        if (n2 == o)
        {
            palindrom_cnt++;
            palindrom_suma += o;
        }
        cin >> n;
    }

    cout << palindrom_suma / palindrom_cnt;
}

void divizori()
{
    int n;
    cin >> n;
    for (int d = 2; d <= n / 2; ++d)
        if (n % d == 0)
            cout << d << ' ';
}

void suma_div()
{
    int n;
    int s = 0;
    cin >> n;
    for (int d = 2; d <= n / 2; ++d)
        if (n % d == 0)
            s += d;

    cout << s;
}

void prim()
{
    int n;
    cin >> n;
    bool prim = 1;
    for (int d = 2; d*d <= n; ++d)
        if (n % d == 0)
    {
        prim = 0;
        break;
    }

    if (prim) cout << "DA";
    else cout << "NU";
}

void cmmdc()
{
    int a, b;
    cin >> a >> b;

    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    cout << a;
}

void afis_n_nr_prime()
{
    int n;
    cin >> n;
    int nr = 2;
    int cnt = 1;
    int copie;
    bool prim;
    while (cnt <= n)
    {
        prim = 1;
        copie = nr;
        for (int d = 2; d*d <= copie; ++d)
            if (copie % d == 0)
            {
                prim = 0;
                break;
            }
        if (prim)
        {
            cout << nr << ' ';
            ++cnt;
        }
        ++nr;
    }
}

int main()
{
    //afis_n_nr_prime();

    //cmmdc();

    //prim();

    //suma_div();

    //divizori();

    //media_aritm_a_palindroamelor();

    //suma_cif_afisare();

    //palindroame_din_interval();

    //palindrom();

    //elimina_cifre_pare();

     //oglindit();

    //suma_cifrelor();

    /*
    int m, n, x, p = 0;
    cin >> m >> n >> x;
    while (m < n && p == 0)
    {
        if (m % x == 0 && n % x == 0)
            p = x;
        else if (m % x == 0)
            --n;
        else
            ++m;
    }

    cout << m << ' ' << n;*/
/*
    int m, n, p = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        m = i;
        while (m % 2 == 0)
            m /= 2;
        if (m == 1)
            p = i;
    }

    cout << p;*/

/*
    int a,b,c = 1;
    cin >> a >> b;
    while (b > 0)
    {
        if (b % 2 == 1)
            c = (c*a) % 10;
        a = (a*a) % 10;
        b /= 2;
    }

    cout << c;*/

    /*
    char s1[] = "bacalaureat";
    char s2[20];
    strcpy(s2,s1+5);cout<<s2<<endl; s2[3]='\0';
    cout << s2;
    */

/*
    int x, s, f, p;
    s = 0;
    f = 2;
    cin >> x;
    while (x > 1)
    {
        p = 0;

        while (x % f == 0)
        {
            x = x / f;
            ++p;
        }

        s += p;
        ++f;
    }

    cout << s;*/

    return 0;
}