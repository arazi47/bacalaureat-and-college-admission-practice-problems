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
crescator...
*/
void BI_57_S3_4()
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
    } while (ch);
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

int main()
{
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
