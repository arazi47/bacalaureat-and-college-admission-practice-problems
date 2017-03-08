// http://www.cs.ubbcluj.ro/wp-content/uploads/subiect-informatica-concurs-mate-info-ubb-ro-2015.pdf

#include <iostream>

using namespace std;

double valoare_polinom_nerecursiv(double coeficienti[], int grad, double y)
{
	double rez = coeficienti[0];
	for (int i = 1; i <= grad; i++)
		rez = rez * y + coeficienti[i];
	return rez;
}

double valoare_polinom_recursiv(double coeficienti[], int grad, double y)
{
	if (grad == 0)
		return coeficienti[0];
	else
		return y * valoare_polinom_recursiv(coeficienti, grad - 1, y) + coeficienti[grad];
}

double val_polinom_nerec(double *coef, int grad, double y)
{
    int i = 0;
    double rez;
    double rezfinal = 0;
    while (i < grad + 1)
    {
        rez = 1;
        for (int j = 0; j < grad - i; ++j)
            rez *= y;

        rezfinal = rezfinal + (coef[i] * rez);
        ++i;
    }

    return rezfinal;
}

double val_polinom_rec(double *coef, int grad, double y)
{
    if (grad == 0)
        return coef[0];

    int rez = 1;
    for (int i = 0; i < grad; ++i)
        rez *= y;

    return coef[grad] * rez + val_polinom_rec(coef, grad - 1, y);
}

double euler(double eps)
{
    double r = 1;
    int n = 1;
    double termen = 1/n;
    while (termen >= eps)
    {
        r += termen;
        ++n;
        termen = termen / n;
    }

    return r + termen;
}

double euler2(double eps)
{
	double rez = 1;
	int n = 1;

	double t = 1.0 / n;

	while (t >= eps){
		rez += t; // rez reprezinta valoarea termenului x(n)
		n++;
		t = t / n; // t reprezinta valoarea 1/(n+1)! - diferenta celor doi termeni consecutivi din sir
	}

	return rez + t; // se returneaza valoarea termenului x(n+1) respectand conditia din enunt
}

int sumacif(int n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }

    return s;
}

void sortare(int n, int *v)
{
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            if (sumacif(v[i]) < sumacif(v[j]) && v[i] % 2 == 0 && v[j] % 2 == 0)
            {
                int t = v[i];
                v[i] = v[j];
                v[j] = t;
            }
        }
}

int main()
{
    /*
    double coef[3] = { 1, 2, 3 };
    int grad = 2;
    double y = 2;

    cout << valoare_polinom_nerecursiv(coef, grad, y) << endl;
    cout << valoare_polinom_recursiv(coef, grad, y) << endl;

    cout << val_polinom_nerec(coef, grad, y) << endl;
    //cout << val_polinom_rec(coef, grad, y);
    */

    /*
    double eps;
    cin >> eps;
    cout << euler(eps) << ' ' << euler2(eps);
    */

    /*
    int n, v[100];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    sortare(n, v);

    for (int i = 1; i <= n; ++i)
        cout << v[i] << ' ';
    */

    return 0;
}
