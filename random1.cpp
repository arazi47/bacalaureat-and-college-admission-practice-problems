#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// elimina cifrele impare din n
int cifreImpare(int n)
{
    int n2 = 0;
    bool are_cifre = false; // are cifre impare
    while (n)
    {
        if ((n % 10) % 2 == 0)
            n2 = n2 * 10 + n % 10;
        else
            are_cifre = true;
        n /= 10;
    }
    // am eliminat cifrele impare
    // doar ca sunt invers
    // trebuie sa inversam numarul curent
    // ca sa obtinem rezultatul final
    while (n2)
    {
        n = n * 10 + n2 % 10;
        n2 /= 10;
    }

    // daca numarul a avut cifre impare
    // returnam rezultatul final
    // daca nu, returnam -1
    return are_cifre ? n : -1;
}

int f(int n,int c)
{
    if(n==0)return 0;
    if(n%10==c)
        return n%100+f(n/10,c);
    return f(n/10,c);
}

// introducem in vector doar numerele pare
// si le sortam
void nr_pare()
{
    ifstream f("input.in");
    int x, m = 0, v[100];
    while (f >> x)
        if (x % 2 == 0)
            v[m++] = x;

    if (m > 0) // daca marimea vectorului e > 0, am introdus cel putin un numar par in vector
    {
        bool schimbare;
        int tmp;
        do
        {
            schimbare = false;
            for (int i = 0; i < m - 1; ++i)
                if (v[i] > v[i + 1])
                {
                    tmp = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = tmp;
                    schimbare = true;
                }
        }
        while (schimbare);

        for (int i = 0; i < m; ++i)
            cout << v[i] << ' ';
    }
    else
        cout << "nu exista";
}

bool prim(int x)
{
    for (int d = 2; d * d <= x; ++d)
        if (x % d == 0)
            return false;

    return true;
}

void numar(int x, int &nrp)
{
    nrp = 0; // Pentru orice eventualitate
    int nr = 2;
    while (nr < x)
    {
        if (prim(nr))
            ++nrp;
        ++nr;
    }
}

void BI_57()
{
    int n, q = 1, i = 1;
    cin >> n;

    while (i < n / i)
    {
        if (n % i == 0)
            q += i;
        i += 3;
    }
    cout << q;
}

void BI_57_S2_MATRICE()
{
    int v[100][100], n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; ++i)
    {
        v[a][i] = 0;
        v[i][b] = 0;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i < a && j < b)
                v[i][j] =  1;
            else if (i > a && j < b)
                v[i][j] = 3;
            else if (i > a && j > b)
                v[i][j] = 4;
            else if (i < a && j > b)
                v[i][j] = 2;
        }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << v[i][j] << ' ';

        cout << endl;
    }
}

void BI_57_S3_REC(int x)
{
    if(x)
    {
        if(x%3==0)
        {
            cout<<3;
            BI_57_S3_REC(x/3);
        }
        else
        {
            BI_57_S3_REC(x/3);
            cout<<x%3;
        }
    }
}

/*
MAXIM 100 NUMERE DE MAXIM 4 CIFRE FIECARE
scriem toate valorile distincte obtinute ca suma din input.in
sumele afisate la final trebuie sa fie ordonate crescator
sumele se calculeaza:
primul numar cu toate celelalte (in afara de el insusi)
al doilea cu toate celelalte (in afara de el insusi)
...etc...
daca avem 1 2 3
facem 1 + 2, 1 + 3, 2 + 1, 2 + 3, 3 + 1, 3 + 2
si scoatem valorile care sunt la fel (ex 1 + 2 si 2 + 1)
*/
void BI_57_S3_4() // bac info varianta 57 subiectul 3 exercitiul 4
{
    int v[100];
    int m = 0;
    int tmp;
    int vecsuma[100];
    int vecsuma_m = 0;
    ifstream f("input.in");
    while (f >> tmp)
        v[m++] = tmp;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            if (i != j) // nu adunam aceleasi numere...
                vecsuma[vecsuma_m++] = v[i] + v[j];
    bool a_fost[9999+9998] = {}; // Cea mai mare valoare pe care o putem avea (4 cifre max fiecare numar, si sunt distincte)
    int x = 0; // marimea de la vecsuma_nou unde vom ordona sumele...
    int vecsuma_nou[9999];
    for (int i = 0; i < vecsuma_m; ++i)
        if (!a_fost[vecsuma[i]]) // a_fost -> sa verificam daca numarul e unic... INEFICIENT
        {
            a_fost[vecsuma[i]] = 1;
            vecsuma_nou[x++] = vecsuma[i];
            //cout << vecsuma[i] << ' ';
        }
    // putem trece la sortarea vectorului
    // BUBBLESORT //
    bool ch; // change
    do
    {
        ch = 0;
        for (int i = 0; i < x - 1; ++i)
            if (vecsuma_nou[i] > vecsuma_nou[i + 1])
            {
                tmp = vecsuma_nou[i];
                vecsuma_nou[i] = vecsuma_nou[i + 1];
                vecsuma_nou[i + 1] = tmp;
                ch = 1;
            }
    }
    while (ch);
    // afisam vectorul final:
    // sumele in ordine crescatoare
    for (int i = 0; i < x; ++i)
        cout << vecsuma_nou[i] << ' ';
}

// returneaza cel mai mic multiplu al lui k mai mare sau egal cu a.
int multiplu(int a, int k)
{
    for (int m = a; ; ++m)
        if (m % k == 0)
            return m;
}

void multiplu_prog()
{
    int x, y, z;
    cin >> x >> y >> z;
    // verifica daca intervalul [x, y]
    // contine cel putin un multiplu
    // al lui z
    int rez = multiplu(x, z); // daca exista un multiplu de-al lui z mai mare sau egal cu x...
    if (rez <= y) // ...si acel multiplu este mai mic sau egal cu y
        cout << "da, nr: " << rez;
    else
        cout << "nu";

    // incorect!
    /*
    for (int i = x; i <= y; ++i)
        if (multiplu(i, z))
    {
        cout << "da, nr: " << i;
        return;
    }

    cout << "nu";*/
}

void BI_36_S1_2()
{
    int s = 0, v = 1, a, b;
    //cin >> v;
    while (v <= 99)
    {
        a = v % 10;
        b = (v / 10) % 10;
        s = s + a * 10 + b;
        //cin >> v;
        v++;
    }

    cout << s;
}

void BI_35_S2_5()
{
    int n, min, a[100][100];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    for (int i = 1; i <= n; ++i)
    {
        min = a[1][i];
        for (int j = 1; j <+ n; ++j)
            if (a[j][i] < min)
                min = a[j][i];

        cout << min << ' ';
    }
}

void BI_35_S3_2(int &a, int b)
{
    a = a - 5;
    b = a - 2;

    cout << a << b;
}

// Afiseaza numerele care incep si se termina cu aceeasi cifra
// Se afiseaza si cifrele < 10
void BI_35_S3_3()
{
    int n, x, copie, pc, uc, inv;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;

        if (x < 10) { cout << x << " ESTE\n"; continue; }
        uc = x % 10;
        copie = x;
        inv = 0;
        while (copie)
        {
            inv = inv * 10 + copie % 10;
            copie /= 10;
        }
        pc = inv % 10;
        //cout << pc << ' ' << uc << endl;

        if (pc == uc)
            cout << x << " ESTE\n";
    }
}

// Calculeaza suma divizorilor proprii
// Divizori proprii sunt TOTI in afara de 1 si el insusi (acestia sunt improprii)
int sum(int n)
{
    int s = 0;
    for (int d = 2; d <= n / 2; ++d)
        if (n % d == 0)
            s += d;

    return s;
}

void BI_35_S3_4()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        v[i] = sum(v[i]);
    }

    int tmp;
    // Si metoda asta e corecta
    /*
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (v[i] > v[j])
    {
        tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }*/

    bool ch;
    do
    {
        ch = false;
        for (int i = 0; i < n - 1; ++i)
        {
            if (v[i] > v[i + 1])
            {
                tmp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tmp;
                ch = true;
            }
        }
    } while (ch);

    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';
}

// Calculeaza cmmdc-ul a mai multor numere
void cmmdc_nr()
{
    int a, b, r;
    cin >> a >> b;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    int input;
    cin >> input;
    while (input)
    {
        b = input;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        cin >> input;
    }

    cout << a;
}

void descompunere_factori_primi()
{
    int n, p;
    int d = 2; // Divizor
    cin >> n; // Numar
    while (n > 1)
    {
        p = 0; // Putere

        while (n % d == 0)
        {
            ++p;
            n /= d;
        }

        if (p)
            cout << d << " la puterea " << p << endl;

        ++d;
    }
}

void fibonacci()
{
    int a, b, c = 0;
    a = b = 1;
    int cautat;
    cin >> cautat;
    if (cautat == 1)
    {
        cout << "GASIT";
        return;
    }
    while (c < cautat)
    {
        c = a + b;
        a = b;
        b = c;

        if (c == cautat)
        {
            cout << "GASIT";
            return;
        }
    }

    cout << "nu face parte din fibonacci";
}

void BI_36_S2_5()
{
    int n, m, v[100][100];
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> v[i][j];

    int min;
    for (int i = m; i >= 1; --i)
    {
        min = v[i][1];
        for (int j = 1; j <= n; ++j)
            if (v[j][i] < min)
                min = v[j][i];

        cout << min << ' ';
    }
}

// Returneaza ultima cifra para a parametrului
// Daca parametrul nu contine cifre pare, returneaza -1
int cifra(int a)
{
    if (a == 0)
        return 0;

    while (a)
    {
        if ((a % 10) % 2 == 0)
            return a % 10;

        a /= 10;
    }

    return -1;
}

void BI_36_S3_3()
{
    int n;
    cin >> n;
    int x;
    int vdf[10] = {};
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        vdf[cifra(x)]++;
    }
    int nr = 0;
    for (int i = 10 - 1; i >= 0; --i)
    {
        while (vdf[i])
        {
            nr = nr * 10 + i;
            vdf[i]--;
        }
    }

    cout << nr;
}

int main()
{
    //BI_36_S3_3();

    //cout << cifra(0);
    //cout << cifra(8345);

    //BI_36_S2_5();

    //int x;
    //char s[] = "EAENMX";
    //x = strlen(s);
    //for (int i = 0; i < x / 2; i++)
    //    cout << s[i] << s[x - i - 1];

    //fibonacci();

    //descompunere_factori_primi();

    //cmmdc_nr();

    //BI_35_S3_4();

    //BI_35_S3_3();

    //int a = 3, b = 9;
    //BI_35_S3_2(b, a);
    //BI_35_S3_2(b, b);

    //BI_35_S2_5();

    /*
    char c[] = "tamara";
    for (int i = 0; i < 3; i++)
        c[i] = c[i + 1];
    cout << c;
    */

    //BI_36_S1_2();

    //multiplu_prog();

    //BI_57_S3_4();

    //BI_57_S3_REC(38);

    //BI_57_S2_MATRICE();

    // Doar daca e vocala
    //char c;
    //cin >> c;
    //cout << strchr("aeiou", c);

    //BI_57();

    /*
    int a,b;
    int nrpa = 0, nrpb = 0;
    cin >> a >> b;
    numar(a, nrpa);
    numar(b, nrpb);
    // hackfix, functia numar calculeaza cate numere prime sunt mai mici ca si primul parametru
    // iar la punctul b) ni se cere sa calculam daca exista cel putin un nr prim intre
    // a si b, INCLUSIV a si b!
    if (prim(a))
        nrpa++;
    if (prim(b))
        nrpb++;
    cout << nrpa << ' ' << nrpb << '\n';
    if (nrpb - nrpa > 0)
        cout << "sunt numere prime intre a si b";
    else
        cout << "nu sunt numere prime intre a si b";*/

    //nr_pare();

    //cout << f(12, 3) << ' ' << f(21114,1);

    /*char c;
    cin >> c;
    if (tolower(c) == c)
        cout << "da";
    else
        cout << "nu";*/

    //int n;
    //cin >> n;
    //cout << cifreImpare(n);
    /*
        int n;
        int r = 0;
        cin >> n;
        do
        {
            r = (r * 10 + n % 10) * 10;
            n /= 100;
        } while (n >= 10);
        cout << r;*/

    /*
        int n1, n2;
        int w;
        ifstream f("input.in");
        f >> n1;
        while (f >> n2)
        {
            w = n1;
            while (w + 1 < n2)
                cout << ++w << ' ';
        n1 = n2;
        }
    */

    return 0;
}
