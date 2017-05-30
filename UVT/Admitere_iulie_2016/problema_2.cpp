// https://drive.google.com/file/d/0B0NnkrRhUimbU0Ntb3IyYnhGVkk/view
// Problema 2

#include <iostream>
#include <cstring>

using namespace std;

bool eAdresaUVT(char s[])
{
    char t[256];
    strcpy(t, s);

    char x[256];
    strcpy(x, s);
    char *c = strtok(x, ".");
    c = strtok(NULL, "@");

    // nu avem nume
    if (strstr(c, "e-uvt.ro"))
        return false;

    // nu avem prenume
    if (t[0] == '.')
        return false;

    if (!strstr(t, "."))
        return false;

    if (!strstr(t, "@"))
        return false;

    if (!strstr(t, "e-uvt.ro"))
        return false;

    return true;
}

void afiseazaNumeSiPrenume(char s[])
{
    char t[256];
    strcpy(t, s);
    char *c = strtok(t, ".");
    c[0] = toupper(c[0]);
    cout << c << ' ';
    c = strtok(NULL, "@");
    c[0] = toupper(c[0]);
    cout << c;
}

int main()
{
    char s[256];
    cin >> s;
    if (eAdresaUVT(s))
    {
        cout << "Este adresa UVT, iar numele este ";
        afiseazaNumeSiPrenume(s);
    }
    else
        cout << "Nu este adresa UVT";

    return 0;
}
