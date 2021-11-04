#include <iostream>
#include <fstream>
#include <sstream>
#include "string.h"
#include <vector>
#include "Pila.h"


using namespace std;


void chopCSV(string fileName, int lines)
{

    string newName = fileName.substr(0, fileName.find(".csv"));
    newName += to_string(lines) + ".csv";

    fstream fin, fout;
    fin.open("./" + fileName, ios::in);
    fout.open("./" + newName, ios::out);

    string line, word;
    for (int i = 0; i < lines; i++)
    {
        getline(fin, line);
        fout << line << "\n";
    }
}

void exploreCSV(string fileName)
{
    int colsOfInterest[] = {5,14,20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word;
    int confirmed = 0;
    int total = -1;

    while (getline(fin, line))
    {
        total++;
        row.clear();
        stringstream s(line);
        while (getline(s, word, ','))
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            else
            {
                word = "NA";
            }
            row.push_back(word);
        }


        if (row[20].compare("Confirmado") == 0 || total==0)
        {
            for (int i = 0; i < nColumns; i++)
            {
                cout << row[colsOfInterest[i]] << " ";
            }
            confirmed++;
            cout << endl;
        }

    cout << "Casos confirmados: " << confirmed << " de " << total << " casos registrados." << endl;
}

}

void p_casos(string fileName)
{
    int colsOfInterest[] = {5};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    int confirmadoscaba=0;
    Pila <string> p;
    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word;
    int confirmed = 0;
    int total = -1;

    while (getline(fin, line))
    {
        total++;
        row.clear();
        stringstream s(line);
        while (getline(s, word, ','))
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            else
            {
                word = "NA";
            }
            row.push_back(word);
        }

        if (row[20].compare("Confirmado") == 0 || total==0) //Filtramos los casos confirmados
        {
            for (int i = 0; i < nColumns; i++)
            {
                cout << row[colsOfInterest[i]] << " ";

                p.push(row[colsOfInterest[i]]);
            }
            if (p.pop().compare("CABA") == 0 || total==0)
            {
                confirmadoscaba++;
            }
            cout << endl;
        }
    }
}








void exploreHeaders(string fileName)
// Imprime los nombres de las columnas del archivo csv
{
    int i=0;
    fstream fin;

    fin.open("./" + fileName, ios::in);
    string headers, header;
    getline(fin, headers); //nomuestraprimerafila
    while (i<9)
    {
       getline(fin, headers);
       stringstream s(headers);
       while (getline(s, header, ','))
       {
           cout << header << endl;
       }
       i++;
}
}

int main(int argc, char **argv)
{
    cout << "Cantidad de argumentos: " << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << "Argumento " << i << ": " << argv[i] << endl;
       /* switch () {
             case 1: p_casos(n);
             break;
             case 2: p_muertes(n);
             break;
             case 3: casos_edad (años);
             break;
             case 4: casos_cui(fecha);
             break;
             case 5: estad;
             break;
         }*/

        if(strcmp(argv[i], "-file") == 0){
            cout << "Nombre del Archivo: " << argv[i+1] << endl;
            //exploreHeaders(argv[i+1]);
           // exploreCSV(argv[i+1]);
           p_casos(argv[i+1]);
            break;
        }

    }

    return 0;
}

//funciones argumentos

/*
int p_casos(int n)
{

for (int i=1; i<=n; i++)
{
    cout<<"Las primeras "<<n<<" provincias son: " <<endl;
}
}*/




