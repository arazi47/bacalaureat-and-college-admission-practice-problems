// https://drive.google.com/file/d/0B0NnkrRhUimbLW5DUTZtUTlvWVk/view
// Problema 1

#include <iostream>
#include <cstring>

using namespace std;

int spatiiDinText(char s[])
{
    int cnt = 0;
    for (int i = 0; i < strlen(s); ++i)
        if (isspace(s[i]))
            ++cnt;

    return cnt;
}

int cuvinteCuMinimTreiCaractere(char s[])
{
    char t[256];
    strcpy(t, s);

    int cnt = 0;
    char *cuvant = strtok(t, " ");
    while (cuvant)
    {
        if (strlen(cuvant) >= 3)
            ++cnt;

        cuvant = strtok(NULL, " ");
    }

    return cnt;
}

void afiseazaDupaRegula(char s[])
{
    char *cuvant = strtok(s, " ");
    while (cuvant)
    {
        cuvant[0] = toupper(cuvant[0]);
        cout << cuvant << endl;

        cuvant = strtok(NULL, " ");
    }
}

// ex:
// s[] = "examenul de    admitere e usor"
int main()
{
    char s[256];
    cin.getline(s, 255);
    cout << spatiiDinText(s) << endl;
    cout << cuvinteCuMinimTreiCaractere(s) << endl;
    afiseazaDupaRegula(s);

    return 0;
}
