#include <iostream>
#include <fstream>
using namespace std;

void findNameByCode(string code)
{
    string nome = "";
    ifstream fileMatricole("matricola.txt"); // Apro il file giusto
    if(fileMatricole.is_open())
    {
        cout << "File matricole.txt aperto correttamente. \n";
        string line;
        while(getline(fileMatricole, line)) // Scorro le righe
        {
            for(int i = 0; i < 6; i++) // Per ogni carattere della riga 0....5
            {
                if(line[i] != code[i])
                {
                    break; // Se non uguali passo a riga successiva
                }
                else if(i == 4) // Ho trovato la matricola
                {
                    for(int j = 6; j < line.length(); j++)
                    {
                        nome += line[j];
                    }               
                }
            }
        }
        cout << "La matricola " << code << " corrisponde al nome: " << nome << "\n";
    }
    else
    {
        cout << "Impossibile aprire il file matricole.txt . \n";
    }
}

void findSalaryByCode(string code) 
{
    string stipendio = "";
    ifstream fileStipendio("stipendio.txt"); // Apro file stipendio.txt
    if(fileStipendio.is_open())
    {
        cout << "File stipendio.txt aperto correttamente. \n";
        string line;
        while(getline(fileStipendio, line)) // Scorro le righe
        {
            for(int i = 0; i < 6; i++) // Per ogni carattere della riga 0....5
            {
                if(line[i] != code[i])
                {
                    break; // Se non uguali passo a riga successiva
                }
                else if(i == 4) // Ho trovato lo stipendio
                {
                    for(int j = 6; j < line.length(); j++)
                    {
                        stipendio += line[j];
                    }               
                }
            }
        }
        cout << "Alla matricola " << code << " corrisponde lo stipendio: " << stipendio << "\n";
    }
    else
    {
        cout << "Impossibile aprire il file stipendio.txt . \n";
    }
}

void findSalaryByName(string name) // Apro file stipendio.txt
{
    string straordinario = "";
    ifstream fileStraordinari("straordinari.txt"); // Apro il file giusto
    if(fileStraordinari.is_open())
    {
        cout << "File straordinari.txt aperto correttamente. \n";
        string line;
        while(getline(fileStraordinari, line)) // Scorro le righe
        {
            for(int i = 0; i < 6; i++) // Per ogni carattere della riga 0....5
            {
                if(line[i] != name[i])
                {
                    break; // Se non uguali passo a riga successiva
                }
                else if(i == 4) // Ho trovato la matricola
                {
                    for(int j = 6; j < line.length(); j++)
                    {
                        straordinario += line[j];
                    }               
                }
            }
        }
        cout << "L'impiegato " << name << " ha accumulato " << straordinario << "ore di straordinario\n";
    }
    else
    {
        cout << "Impossibile aprire il file matricole.txt . \n";
    }
}

int main()
{
    cout << "Benvenuto nel programma di calcolo stipendi. \n";

    bool flag = true; 
    while (flag) // Ciclo inserimento Menù
    {
        cout << "----------------------------------------------------------\n";
        cout << "Queste sono le funzionalità che puoi usare: \n";
        cout << "1. Matricola  ->   Nome \n";
        cout << "2. Matricola  -> Stipendio \n";
        cout << "3.   Nome     -> Stipendio \n";
        cout << "4. "
        cout << "----------------------------------------------------------\n";
        cout << "Scegli la funzionalità che vuoi usare: \n";
        int scelta;
        cin >> scelta;
        cout << "Inserisci il parametro che vuoi cercare: \n";
        string input;
        cin >> input;

        if (scelta < 1 || scelta > 3)
        {
            cout << "Scelta non valida. \n";
        }
        else
        {
            if (scelta == 1 && input.length() == 5)
            {
                findNameByCode(input);
                flag = false; // Mi fa finire il programma
            }
            else if (scelta == 2 && input.length() == 5)
            {
                findSalaryByCode(input);
                flag = false; // Mi fa finire il programma
            }
            else if (scelta == 3)
            {
                findSalaryByName(input);
                flag = false; // Mi fa finire il programma
            }
            else
            {
                cout << "Scelta non valida. \n";
            }
        }
    }
    cout << "Fine \n";
}