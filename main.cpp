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

//estadísticas

void estad(int t, int i, int m, int ri10, int ri20, int ri30, int ri40, int ri50, int ri60, int ri70, int ri80, int ri90, int ri100, int ri110,
           int rm10, int rm20, int rm30, int rm40, int rm50, int rm60, int rm70, int rm80, int rm90, int rm100, int rm110)
{
    float pinfectados, pmuertes;
    cout<<"El total de casos registrados es de "<<t<<endl;
    cout<<"El total de casos infectados es de "<<i<<endl;
    cout<<"El total de fallecidos es de "<<m<<endl;
    pinfectados=(i*100)/t;
    pmuertes=(m*100)/i;
    cout<<"El porcentaje de infectados por muestra es de %"<<pinfectados<<endl;
    cout<<"El porcentaje de fallecidos por infectados es de %"<<pmuertes<<endl;
    cout<<endl;
    cout<<"El rango etario de infectados de 1 a 10 anios es de "<<ri10<<endl;
    cout<<"El rango etario de infectados de 11 a 20 anios es de "<<ri20<<endl;
    cout<<"El rango etario de infectados de 21 a 30 anios es de "<<ri30<<endl;
    cout<<"El rango etario de infectados de 31 a 40 anios es de "<<ri40<<endl;
    cout<<"El rango etario de infectados de 41 a 50 anios es de "<<ri50<<endl;
    cout<<"El rango etario de infectados de 51 a 60 anios es de "<<ri60<<endl;
    cout<<"El rango etario de infectados de 61 a 70 anios es de "<<ri70<<endl;
    cout<<"El rango etario de infectados de 71 a 80 anios es de "<<ri80<<endl;
    cout<<"El rango etario de infectados de 81 a 90 anios es de "<<ri90<<endl;
    cout<<"El rango etario de infectados de 91 a 100 anios es de "<<ri100<<endl;
    cout<<"El rango etario de infectados de 101 a 110 anios es de "<<ri110<<endl;
    cout<<endl;
    cout<<"El rango etario de fallecidos de 1 a 10 anios es de "<<rm10<<endl;
    cout<<"El rango etario de fallecidos de 11 a 20 anios es de "<<rm20<<endl;
    cout<<"El rango etario de fallecidos de 21 a 30 anios es de "<<rm30<<endl;
    cout<<"El rango etario de fallecidos de 31 a 40 anios es de "<<rm40<<endl;
    cout<<"El rango etario de fallecidos de 41 a 50 anios es de "<<rm50<<endl;
    cout<<"El rango etario de fallecidos de 51 a 60 anios es de "<<rm60<<endl;
    cout<<"El rango etario de fallecidos de 61 a 70 anios es de "<<rm70<<endl;
    cout<<"El rango etario de fallecidos de 71 a 80 anios es de "<<rm80<<endl;
    cout<<"El rango etario de fallecidos de 81 a 90 anios es de "<<rm90<<endl;
    cout<<"El rango etario de fallecidos de 91 a 100 anios es de "<<rm100<<endl;
    cout<<"El rango etario de fallecidos de 101 a 110 anios es de "<<rm70<<endl;

}

int funcestad(string fileName)
{
    int cinfectados=-1, cmuertes=-1,casos4050=-1,rangoi10=0,rangoi20=0,rangoi30=0,rangoi40=0,rangoi50=0,rangoi60=0,rangoi70=0,rangoi80=0,rangoi90=0,rangoi100=0,rangoi110=0,
    rangom10=0,rangom20=0,rangom30=0,rangom40=0,rangom50=0,rangom60=0,rangom70=0,rangom80=0,rangom90=0,rangom100=0,rangom110=0;
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
            }
        if (row.getDato(14).compare("SI") == 0 || total==0) //Filtramos los casos confirmados
            {
            cmuertes++;
            }
        string años;

        //Cantidad de infectados por rango etario (rango de 10 años)
        if (row.getDato(20).compare("Confirmado") == 0 || total==0)
        {
            if (row.getDato(2).compare("NA") != 0)
            {
                int edad;
                stringstream(row.getDato(2))>>edad;

                if (edad>0 && edad <= 10)
                {rangoi10 ++;}
                if (edad>= 11 && edad <=20)
                {rangoi20++;}
                if (edad>= 21 && edad <=30)
                {rangoi30++;}
                if (edad>= 31 && edad <=40)
                {rangoi40++;}
                if (edad>=41 && edad <=50)
                {rangoi50++;}
                if (edad>= 51 && edad <=60)
                {rangoi60++;}
                if (edad>= 61 && edad <=70)
                {rangoi70++;}
                if (edad>= 71 && edad <=80)
                {rangoi80++;}
                if (edad>= 81 && edad <=90)
                {rangoi90++;}
                if (edad>= 91 && edad <=100)
                {rangoi100++;}
                if (edad>= 101 && edad <=110)
                {rangoi110++;}
            }
        }
        //Cantidad de muertes por rango etario (rango de 10 años)
        if (row.getDato(14).compare("SI") == 0 || total==0)
        {
            if (row.getDato(2).compare("NA") != 0)
            {
                int edad;
                stringstream(row.getDato(2))>>edad;

                if (edad>0 && edad <= 10)
                {rangom10 ++;}
                if (edad>= 11 && edad <=20)
                {rangom20++;}
                if (edad>= 21 && edad <=30)
                {rangom30++;}
                if (edad>= 31 && edad <=40)
                {rangom40++;}
                if (edad>=41 && edad <=50)
                {rangom50++;}
                if (edad>= 51 && edad <=60)
                {rangom60++;}
                if (edad>= 61 && edad <=70)
                {rangom70++;}
                if (edad>= 71 && edad <=80)
                {rangom80++;}
                if (edad>= 81 && edad <=90)
                {rangom90++;}
                if (edad>= 91 && edad <=100)
                {rangom100++;}
                if (edad>= 101 && edad <=110)
                {rangom110++;}
            }
        }
    }

    estad(total,cinfectados,cmuertes,rangoi10,rangoi20,rangoi30,rangoi40,rangoi50,rangoi60,rangoi70,rangoi80,rangoi90,rangoi100,rangoi110,
          rangom10,rangom20,rangom30,rangom40,rangom50,rangom60,rangom70,rangom80,rangom90,rangom100,rangom110);
    return 0;
}
//termina estadísticas


//p_casos

//Funcion Tabla Hash
/*
unsigned int miHashFunc(string clave)
{
    int idx;
    for(int i=0; i<clave.length(); i++){
       switch (i)
       {
           case 1: "Buenos Aires";
           break;
           case 2: "CABA";
           break;
           case 3: "Catamarca";
           break;
           case 4: "Chaco";
           case 5: "Chubut";
           break;
           case 6: "Córdoba";
           break;
           case 7: "Corrientes";
           break;
           case 8: "Entre Ríos";
           break;
           case 9: "Formosa";
           break;
           case 10: "Jujuy";
           break;
           case 11: "La Pampa";
           break;
           case 12: "La Rioja";
           break;
           case 13: "Mendoza";
           break;
           case 14: "Misiones";
           break;
           case 15: "Neuquén";
           break;
           case 16: "Río Negro";
           break;
           case 17: "Salta";
           break;
           case 18: "San Juan";
           break;
           case 19: "San Luis";
           break;
           case 20: "Santa Cruz";
           break;
           case 21: "Santa Fe";
           break;
           case 22: "Santiago del Estero";
           break;
           case 23: "Tierra del Fuego";
           break;
           case 24: "Tucumán";
           break;
       }
    }
    return idx;
}
 */
unsigned int miHashFunc(string clave)
{
    int idx;
    for(int i=0; i<clave.length(); i++){
        if (clave=="Buenos Aires")
        {
            idx=0;
        }
        if (clave=="CABA")
        {
            idx=1;
        }
        if (clave=="Catamarca")
        {
            idx=2;
        }
        if (clave=="Chaco")
        {
            idx=3;
        }
        if (clave== "Chubut")
        {
            idx=4;
        }
        if (clave=="Córdoba")
        {
            idx=5;
        }
        if (clave=="Corrientes")
        {
            idx=6;
        }
        if (clave=="Entre Ríos")
        {
            idx=7;
        }if (clave=="Formosa")
        {
            idx=8;
        }
        if (clave=="Jujuy")
        {
            idx=9;
        }
        if (clave=="La Pampa")
        {
            idx=10;
        }
        if (clave=="La Rioja")
        {
            idx=11;
        }
        if (clave=="Mendoza")
        {
            idx=12;
        }
        if (clave=="Misiones")
        {
            idx=13;
        }
        if (clave=="Neuquén")
        {
            idx=14;
        }
        if (clave=="Río Negro")
        {
            idx=15;
        }
        if (clave=="Salta")
        {
            idx=16;
        }
        if (clave=="San Juan")
        {
            idx=17;
        }
        if (clave=="San Luis")
        {
            idx=18;
        }
        if (clave=="Santa Cruz")
        {
            idx=19;
        }
        if (clave=="Santa Fe")
        {
            idx=20;
        }
        if (clave=="Santiago del Estero")
        {
            idx=21;
        }
        if (clave=="Tierra del Fuego")
        {
            idx=22;
        }
        if (clave=="Tucumán")
        {
            idx=23;
        }

    }
    return idx;
}
//funpcasos

void funcasos(string fileName)
{
    int c[24][2];
    int colsOfInterest[] = {7};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    Lista<string> row;
    string line, word;

    int total = -1;
    int j=0;
    //Defino tabla Hash
    HashMap<string,int> TH (24,&miHashFunc);

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


        if (row.getDato(20).compare("Confirmado") == 0 || total==0) //filtramos confirmados
        {
            //int a=1;
            if (row.getDato(7).compare("SIN ESPECIFICAR") != 0 && row.getDato(7).compare("carga_provincia_nombre") != 0)
            {
                TH.put(row.getDato(7),1);
            }

        }

    }
    for(int i = 0; i < 24; i++)
    {
        j++;
        c[i][0]=j;
        c[i][1]=TH.get(row.getDato(7));
    }
     TH.print();
    cout<<"\nMostrando matriz\n\n";

    for(int i=0;i<24;i++){
        for(int j=0;j<2;j++){
            cout<<"         "<<c[i][j] <<"\t";
        }
        cout<<"\n";
    }

}
void p_casos(int n){

}

//termina p_casos


//p_muertes
int funcmuertes(string fileName)
{
    int c[24][2];
    int colsOfInterest[] = {7};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    Lista<string> row;
    string line, word;

    int total = -1;
    int j=0;
    //Defino tabla Hash
    HashMap<string,int> TH (24,&miHashFunc);

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


        if (row.getDato(14).compare("SI") == 0 || total==0) //filtramos confirmados
            {
            //int a=1;
            if (row.getDato(7).compare("SIN ESPECIFICAR") != 0 && row.getDato(7).compare("carga_provincia_nombre") != 0)
            {
                TH.put(row.getDato(7),1);
            }

            }

    }
    TH.print();
    }


//termina p_muertes


// casos_edad (años)

void casoedad(string fileName)
{

    int colsOfInterest[] = {5};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    Lista<string> row;
    Lista<string> p;
    string line, word;

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


       string edad="20";


        if (row.getDato(2).compare(edad) == 0 || total==0)
         {
            for (int i = 0; i < nColumns; i++)
            {
                cout<<row.getDato(colsOfInterest[i])<<endl;
            }
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
              case 1: estad;
              break;
              case 2: p_casos(n);
              break;
              case 3: p_muertes(n);
              break;
              case 4: casos_edad (años);
              break;
              case 5: casos_cui(fecha);
              break;
          }*/

        if(strcmp(argv[i], "-file") == 0){
            cout << "Nombre del Archivo: " << argv[i+1] << endl;
            //exploreHeaders(argv[i+1]);
           // exploreCSV(argv[i+1]);
          //p_casos(argv[i+1]);
            //funcasos(argv[i+1]);
          funcmuertes(argv[i+1]);
          //funcestad(argv[i+1]);
          //casoedad(argv[i+1]);
            break;
        }
    }

    return 0;
}

//termina main