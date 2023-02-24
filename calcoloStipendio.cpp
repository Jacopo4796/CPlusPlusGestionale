#include <iostream>
#include <fstream>
using namespace std;

string cerca(string nomeFile, string code)
{
    string risultato = "";
    ifstream fileAperto(nomeFile);
    if (fileAperto.is_open())
    {
        string line;
        while (getline(fileAperto, line))
        {
            for (int i = 0; i < 6; i++)
            {
                if (line[i] != code[i])
                {
                    break;
                }
                else if (i == 4) // Ultimo carattere della matricola
                {
                    for (int j = 6; j < line.length(); j++)
                    {
                        risultato += line[j];
                    }
                }
            }
        }
    }
    else
    {
        cout << "Impossibile aprire il file .txt . \n";
    }
    return risultato;
}

void findNameByCode(string code)
{
    string risultato = cerca("matricola.txt", code);
    cout << "La matricola " << code << " corrisponde al nome dell'impiegato " << risultato << "\n";
}

void findSalaryByCode(string code)
{
    cout << "Alla matricola " << code << " corrisponde uno stipendio di " << cerca("stipendio.txt", code) << ". \n";
}

void findStraordinaryByCode(string code)
{
    cout << "La matricola " << code << " ha maturato " << cerca("straordinari.txt", code) << " ore di straordinario. \n";
}

void findSalaryByName(string name)
{
    ifstream fileAperto("matricola.txt");
    string code = "";
    if (fileAperto.is_open())
    {
        string line;
        while (getline(fileAperto, line))
        {
            int k = 0;
            for (int i = 6; i < line.length(); i++)
            {
                if (line[i] != name[k])
                {
                    break;
                }
                else if (k == name.length() - 1) // Ultimo carattere della matricola
                {
                    for (int j = 0; j < 5; j++)
                    {
                        code += line[j];
                    }
                }
                k++;
            }
        }
        fileAperto.close();
    }
    else
    {
        cout << "Impossibile aprire il file .txt .\n";
    }
    string stipendioValore = cerca("stipendio.txt", code);
    cout << "Il dipendente " << name << ", avente matricola " << code << ", percepisce uno stipendio di " << stipendioValore << ". \n";
}

void findSalaryAndStraordinaryByCode(string code)
{
    int retribuzione = stoi(cerca("stipendio.txt", code));
    int compensoExtra = stoi(cerca("straordinari.txt", code));
    int retribuzioneTot = retribuzione + compensoExtra * 35;
    cout << "Lo stipendio, comprensivo di straordinari, del dipendente avente matricola " << code << " ammonta a " << retribuzioneTot << ". \n";
}

int main()
{
    cout << "Benvenuto nel programma di calcolo stipendi. \n";
    bool flag = true;
    while (flag) // Ciclo inserimento Menù
    {
        cout << "----------------------------------------------------------\n";
        cout << "Queste sono le funzionalità che puoi usare: \n";
        cout << "  DATI IN INPUT           DATI IN OUTPUT \n";
        cout << "1.  Matricola   ->             Nome \n";
        cout << "2.  Matricola   ->           Stipendio \n";
        cout << "3.  Matricola   ->          Straordinari \n";
        cout << "4.    Nome      ->           Stipendio \n";
        cout << "5.  Matricola   ->  Stipendio + Straordinari (35h) \n";
        cout << "0.    EXIT \n";
        cout << "----------------------------------------------------------\n";

        cout << "Scegli la funzionalità che vuoi usare: \n";
        int scelta;
        cin >> scelta;
        cout << "Inserisci il parametro che vuoi cercare: \n";
        string input;
        cin >> input;

        if (scelta < 0 || scelta > 5)
        {
            cout << "Scelta non valida. \n";
        }
        else
        {
            if (scelta == 1 && input.length() == 5)
            {
                findNameByCode(input);
            }
            else if (scelta == 2 && input.length() == 5)
            {
                findSalaryByCode(input);
            }
            else if (scelta == 3)
            {
                findStraordinaryByCode(input);
            }
            else if (scelta == 4)
            {
                findSalaryByName(input);
            }
            else if (scelta == 5)
            {
                findSalaryAndStraordinaryByCode(input);
            }
            else if (scelta == 0)
            {
                flag = false;
            }
            else
            {
                cout << "Scelta non valida. \n";
            }
        }
    }
    cout << "Fine \n";
}