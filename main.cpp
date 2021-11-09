#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include "Pila.h"
#include "Lista.h"
#include "HashMap.h"
#include <string>



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

//estadisticas

void estad(int t, int i, int m, int r10, int r20, int r30, int r40, int r50, int r60, int r70, int r80, int r90, int r100, int r110 )
{
    float pinfectados, pmuertes;
    cout<<"El total de casos registrados es de "<<t<<endl;
    cout<<"El total de casos infectados es de "<<i<<endl;
    cout<<"El total de fallecidos es de "<<m<<endl;
    pinfectados=(i*100)/t;
    pmuertes=(m*100)/i;
    cout<<"El porcentaje de infectados por muestra es de %"<<pinfectados<<endl;
    cout<<"El porcentaje de fallecidos por infectados es de %"<<pmuertes<<endl;
    cout<<"El rango etario de 1 a 10 es de "<<r10<<endl;
    cout<<"El rango etario de 11 a 20 es de "<<r20<<endl;
    cout<<"El rango etario de 21 a 30 es de "<<r30<<endl;
    cout<<"El rango etario de 31 a 40 es de "<<r40<<endl;
    cout<<"El rango etario de 41 a 50 es de "<<r50<<endl;
    cout<<"El rango etario de 510 a 60 es de "<<r60<<endl;
}

int funcestad(string fileName)
{
    int cinfectados=-1, cmuertes=-1,casos4050=-1,rango10=0,rango20=0,rango30=0,rango40=0,rango50=0,rango60=0,rango70=0,rango80=0,rango90=0,rango100=0,rango110=0;
    fstream fin;
    fin.open("./" + fileName, ios::in);

    Lista<string> row;
    string line, word;
    int confirmed = 0;
    int total = -1;

    while (getline(fin, line))
    {
        total++;
        row.vaciar();
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
            row.insertarUltimo(word); //nos agrega en la lista word
        }

        if (row.getDato(20).compare("Confirmado") == 0 || total==0) //Filtramos los casos confirmados
            {
            cinfectados++;
            cout << endl;
            }
        if (row.getDato(14).compare("SI") == 0 || total==0) //Filtramos los casos confirmados
            {
            cmuertes++;
            cout << endl;
            }
        string años;

        if (row.getDato(20).compare("Confirmado") == 0 || total==0)
        {
            if (row.getDato(2).compare("NA") != 0)
            {
                int edad=0;
                stringstream(row.getDato(2))>>edad;

                if (edad>0 || edad <= 10)
                {
                    rango10 ++;
                }
                if (edad>= 11 || edad >=20)
                {
                    rango20++;
                }
                if (edad>= 21 || edad >=30)
                {
                    rango30++;
                }
                if (edad>= 31 || edad >=40)
                {
                    rango40++;
                }
                if (edad>=41 || edad >=50)
                {
                    rango50++;
                }
                if (edad>= 51 || edad >=60)
                {
                    rango60++;
                }
                if (edad>= 61 || edad >=70)
                {
                    rango70++;
                }
                if (edad>= 71 || edad >=80)
                {
                    rango80++;
                }
                if (edad>= 81 || edad >=90)
                {
                    rango90++;
                }
                if (edad>= 91 || edad >=100)
                {
                    rango100++;
                }
                if (edad>= 101 || edad >=110)
                {
                    rango110++;
                }
            }
        }

    }
    cout<<"rango 10 "<<rango10<<endl;
    estad(total,cinfectados,cmuertes,rango10,rango20,rango30,rango40,rango50,rango60,rango70,rango80,rango90,rango100,rango110);
    return 0;
}
//termina estad




unsigned int miHashFunc(string clave)
{
    unsigned int idx=0;
    for(int i=0; i<clave.length(); i++){
        idx += clave[i];
    }
    return idx;
}


void p_casos(string fileName)
{
    int colsOfInterest[] = {5};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    int confirmadoscaba = -1,  confirmadosbsas = -1, confirmadosjujuy=-1, confirmadossalta=-1, confirmadosstafe=-1, confirmadosformosa = -1;

    fstream fin;
    fin.open("./" + fileName, ios::in);

    Lista<string> row;
    string line, word;


    HashMap<string,int> th (23, &miHashFunc);
    int tamanio = 23;


    int total = -1;

    while (getline(fin, line))
    {
        total++;
        row.vaciar();
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
            row.insertarUltimo(word);
        }

        if (row.getDato(20).compare("Confirmado") == 0 || total==0) //Filtramos los casos confirmados
        {
            int a=1;
            for (int i = 0; i < nColumns; i++)
            {
                try{
                    th.put(row.getDato(colsOfInterest[i]),a);
                }catch(int error) {
                    if (error==409){
                        //a=a++;
                        th.put(row.getDato(colsOfInterest[i]),a++);
                    }
                }


            }
            }

            cout << endl;
        }
    th.print();
    }





int funcmuertes(string fileName)
{
    int colsOfInterest[] = {5};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    int muertescaba =-1;
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

        if (row[14].compare("SI") == 0 || total==0) //Filtramos los casos confirmados
            {
            for (int i = 0; i < nColumns; i++)
            {
                //cout << row[colsOfInterest[i]] << " ";

                p.push(row[colsOfInterest[i]]);
            }
            if (p.pop().compare("CABA") == 0 || total==0)
            {
                muertescaba++;
            }

            cout << endl;
            }
    }
    //cout<<muertescaba;

    //return muertescaba;
}






void exploreHeaders(string fileName)
// Imprime los nombres de las columnas del archivo csv
{
    int i=0;
    fstream fin;

    fin.open("./" + fileName, ios::in);
    string headers, header;
    getline(fin, headers); //nosmuestraprimerafila
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
          //p_casos(argv[i+1]);
          //funcmuertes(argv[i+1]);
          funcestad(argv[i+1]);
            break;
        }
    }

    return 0;
}

