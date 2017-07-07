#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "Bote.h"

using namespace std;
enum TamanioBote { Submarino = 2, Destruidor = 3, Battleship = 4, Carrier = 5 };
void impBorda(int m[][10]);
void inMatriz(int m[][10]);
void impBordaJuego(int m[][10]);
int colFilas(int col, int &fila, int TamanioBote, char d);
char obtDir(int d);
int comEspa(int m[][10], int c, int r, int s, char d);
void editMatriz(int m[][10], int col, int fila, int TamanioBote, char dir);
bool conjuntoBote(int m[][10], int TamanioBote, int nombre, vector<Bote> &IistaBotes);
void editBoteInfo(int m[][10], int c, int r, int TamanioBote, char d, vector<Bote> &IistaBotes, int nombre);
int playGame(int m[][10], vector<Bote> &IistaBotes);
int obtEspacio(int m[][10], int fila, int col);



/*void impBorda(int m[][10])  //imprime los barcos en sus respectivos lugares
{
    cout << "   0|1|2|3|4|5|6|7|8|9" << endl << endl;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(j==0)
            {
                cout << i << "  " ;
            }
            cout << m[i][j] ;
            if(j!=9)
            {
                cout << "|";
            }
        }
    cout << endl;
    }
    cout << endl;
}*/

void inMatriz(int m[][10])
{
    for(int col=0; col<10; col++)
    {
        for(int fila=0; fila<10; fila++)
        {
            m[col][fila]=0;
        }
    }
}





void impBordaJuego(int m[][10])
{
    cout << "   0|1|2|3|4|5|6|7|8|9" << endl << endl;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(j==0)
            {
                cout << i << "  " ;
            }
            if(m[i][j]==1)
            {
                cout << 1;
            } else if(m[i][j]==9)
            {
                cout << 9;
            } else
            {
                cout << 0;
            }


            if(j!=9)
            {
                cout << "|";
            }
        }
    cout << endl;
    }
    cout << endl;
}


bool conjuntoBote(int m[][10], int TamanioBote, int nombre, vector<Bote> &IistaBotes)
//coloca las los botes en la matriz
{
    srand(time(0));
    int col=0;
    int fila=0;
    char d='v';
    bool colocacion=true;//si la colocacion no es correcta
    char check='v';
    int cS=0;


    d=obtDir(rand()%10);  //bote
    col=colFilas(col, fila, TamanioBote, d);  //retorna la columna y fila del bote

    while(colocacion)
    {
        if(d=='h')
        {
            cS=comEspa(m, col, fila, TamanioBote, d);//verifica si un bote n se sobrepone en otro bote
            if(cS==1)//Si el barco se superpone, genere otra columna aleatoria, fila y dirección e inicie el bucle de nuevo
            {
                d=obtDir(rand()%10);
                col=colFilas(col, fila, TamanioBote, d);
                cS==0;
                continue;
            }
            editMatriz(m, col, fila, TamanioBote, d);//lugar del bote en la matriz
            editBoteInfo(m, col, fila, TamanioBote, d, IistaBotes, nombre);//crear el bote
            return 0;
        }//
        else if(d=='v')
        {
            cS=comEspa(m, col, fila, TamanioBote, d);
            if(cS==1)
            {
                d=obtDir(rand()%10);
                col=colFilas(col, fila, TamanioBote, d);
                cS==0;
                continue;
            }
            editMatriz(m, col, fila, TamanioBote, d);
            editBoteInfo(m, col, fila, TamanioBote, d, IistaBotes, nombre);
            return 0;
        }
     }
}


char obtDir(int d)
{
    if(d>4)
        {
            return 'h';  //selecciona donde poner al azar el barco
        }
        else
        {
            return 'v';
        }
}


void editMatriz(int m[][10], int col, int fila, int TamanioBote, char dir)
//pone los respectivos numers del bot en la atriz
{
    if(dir=='h')
    {
        for(int i=0; i<TamanioBote; i++)
        {
            m[fila][col]=TamanioBote;
            col++;
            cout << endl;
        }
    }
    else if(dir=='v')
    {
        for(int i=0; i<TamanioBote; i++)
        {
            m[fila][col]=TamanioBote;
            fila++;
            cout << endl;
        }
    }
    else
    {
        cout << "Error!  la direccion se paso" << endl;
    }
    //impBorda(m);
}


int comEspa(int m[][10], int c, int r, int s, char d)
//compruba que los botes no se obresalan
{
    int check=0;
    if(d=='h')
    {
        for(int i=c; i<c+s; i++)
        {
        check=m[r][i];
                if(check!=0)
                {
                    return 1;
                }
        }


        return 0;
    }
    else
    {
        for(int i=r; i<r+s; i++)
        {
        check=m[i][c];
                if(check!=0)
                {
                    return 1;


                }
        }


        return 0;
    }
}
int colFilas(int col, int &fila, int TamanioBote, char d)
{
    switch(TamanioBote) //genera los botes en la columna y fila y confirma ue no se salgan de la brda
    {
        case Submarino:
            if(d=='h')
            {
                col=rand()%8;
                fila=rand()%10;
            }
            else
            {
                col=rand()%10;
                fila=rand()%8;
            }
            break;
        case Destruidor:
            if(d=='h')
            {
                col=rand()%7;
                fila=rand()%10;
            }
            else
            {
                col=rand()%10;
                fila=rand()%7;
            }
            break;
        case Battleship:
            if(d=='h')
            {
                col=rand()%6;
                fila=rand()%10;
            }
            else
            {
                col=rand()%10;
                fila=rand()%6;
            }
            break;
        case Carrier:
            if(d=='h')
            {
                col=rand()%5;
                fila=rand()%10;
            }
            else
            {
                col=rand()%10;
                fila=rand()%5;
            }
    }
    return col;
}




void editBoteInfo(int m[][10], int c, int r, int TamanioBote, char d, vector<Bote> &IistaBotes, int nombre)
//crea los botes
{
    switch(nombre)
    {
        case 1:
            if(d=='h')
            {
                vector<int> r1 (5);
                //agrega los datos en las coordenadas se usa el at
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (5);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Aircraft Carrier
            Bote carrierBote('h', 5, r1, c1, 0, "Aircraft Carrier");
            IistaBotes.push_back(carrierBote);
            }
            else if(d=='v')
            {
                vector<int> r1 (5);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (5);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Aircraft Carrier
            Bote carrierBote('v', 5, r1, c1, 0, "Aircraft Carrier");
            IistaBotes.push_back(carrierBote);
            }
            break;
        case 2:
            if(d=='h')
            {
                vector<int> r1 (4);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (4);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Battleship 1
            Bote battleship1Bote('h', 4, r1, c1, 0, "Battleship 1");
            IistaBotes.push_back(battleship1Bote);
            }
            else if(d=='v')
            {
                vector<int> r1 (4);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (4);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Battleship 1
            Bote battleship1Bote('v', 4, r1, c1, 0, "Battleship 1");
            IistaBotes.push_back(battleship1Bote);
        }
        break;
        case 3:
            if(d=='h')
            {
                vector<int> r1 (4);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (4);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Battleship 2
            Bote battleship2Bote('h', 4, r1, c1, 0, "Battleship 2");
            IistaBotes.push_back(battleship2Bote);
            }
            else if(d=='v')
            {
                vector<int> r1 (4);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (4);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Battleship 2
            Bote battleship2Bote('v', 4, r1, c1, 0, "Battleship 2");
            IistaBotes.push_back(battleship2Bote);
            }
            break;
        case 4:
            if(d=='h')
            {
                vector<int> r1 (3);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (3);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
             //Destruidor 1
             Bote Destruidor1Bote('h', 3, r1, c1, 0, "Destruidor 1");
             IistaBotes.push_back(Destruidor1Bote);
             }
             else if(d=='v')
             {
                vector<int> r1 (3);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (3);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
             //Destruidor 1
             Bote Destruidor1Bote('v', 3, r1, c1, 0, "Destruidor 1");
             IistaBotes.push_back(Destruidor1Bote);
             }
             break;
        case 5:
        if(d=='h')
        {
            vector<int> r1 (3);
            for (int i=0; i<(int)r1.size(); ++i)
            {
                r1.at(i)=r;
            }
            vector<int> c1 (3);
            for (int i=0; i<(int)c1.size(); ++i)
            {
                c1.at(i)=c;
                c++;
            }
        //Destruidor 2
        Bote Destruidor2Bote('h', 3, r1, c1, 0, "Destruidor 2");
        IistaBotes.push_back(Destruidor2Bote);
        }
        else if(d=='v')
        {
            vector<int> r1 (3);
            for (int i=0; i<(int)r1.size(); ++i)
            {
                r1.at(i)=r;
                r++;
            }
            vector<int> c1 (3);
            for (int i=0; i<(int)c1.size(); ++i)
            {
                c1.at(i)=c;
            }
            //Destruidor 2
            Bote Destruidor2Bote('v', 3, r1, c1, 0, "Destruidor 2");
            IistaBotes.push_back(Destruidor2Bote);
        }
            break;
        case 6:
            if(d=='h')
            {
                vector<int> r1 (3);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (3);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Destruidor 3
            Bote Destruidor3Bote('h', 3, r1, c1, 0, "Destruidor 3");
            IistaBotes.push_back(Destruidor3Bote);
            }
            else if(d=='v')
            {
                vector<int> r1 (3);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (3);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Destruidor 3
            Bote Destruidor3Bote('v', 3, r1, c1, 0, "Destruidor 3");
            IistaBotes.push_back(Destruidor3Bote);
            }
            break;
        case 7:
            if(d=='h')
            {
                vector<int> r1 (2);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (2);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Submarino1
            Bote Submarino1Bote('h', 2, r1, c1, 0, "Submarino 1");
            IistaBotes.push_back(Submarino1Bote);
            }
            else if(d=='v')
            {
                vector<int> r1 (2);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (2);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Submarino 1
            Bote Submarino1Bote('v', 2, r1, c1, 0, "Submarino 1");
            IistaBotes.push_back(Submarino1Bote);
            }
            break;
        case 8:
            if(d=='h')
            {
                vector<int> r1 (2);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (2);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Submarino 2
            Bote Submarino2Bote('h', 2, r1, c1, 0, "Submarino 2");
            IistaBotes.push_back(Submarino2Bote);
            }
            else if(d=='v')
            {
                vector<int> r1 (2);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (2);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Submarino 2
            Bote Submarino2Bote('v', 2, r1, c1, 0, "Submarino 2");
            IistaBotes.push_back(Submarino2Bote);
            }
            break;
        case 9:
            if(d=='h')
            {
                vector<int> r1 (2);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (2);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Submarino 3
            Bote Submarino3Bote('h', 2, r1, c1, 0, "Submarino 3");
            IistaBotes.push_back(Submarino3Bote);
            }
            else if(d=='v')
            {
                vector<int> r1 (2);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (2);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Submarino 3
            Bote Submarino3Bote('v', 2, r1, c1, 0, "Submarino 3");
            IistaBotes.push_back(Submarino3Bote);
            }
            break;
        case 10:
        if(d=='h')
        {
            vector<int> r1 (2);
            for (int i=0; i<(int)r1.size(); ++i)
            {
                r1.at(i)=r;
            }
            vector<int> c1 (2);
            for (int i=0; i<(int)c1.size(); ++i)
            {
                c1.at(i)=c;
                c++;
            }
        //Submarino 4
        Bote Submarino4Bote('h', 2, r1, c1, 0, "Submarino 4");
        IistaBotes.push_back(Submarino4Bote);
        }
        else if(d=='v')
        {
            vector<int> r1 (2);
            for (int i=0; i<(int)r1.size(); ++i)
            {
                r1.at(i)=r;
                r++;
            }
            vector<int> c1 (2);
            for (int i=0; i<(int)c1.size(); ++i)
            {
                c1.at(i)=c;
            }
        //Submarino 4
        Bote Submarino4Bote('v', 2, r1, c1, 0, "Submarino 4");
        IistaBotes.push_back(Submarino4Bote);
        }
        break;
    }
}


int playGame(int m[][10], vector<Bote> &IistaBotes)
{
    bool gameInProgress=true;
    int fila=0;
    int col=0;
    int adivin=0;
    int pum=0;
    int miss=0;
    int espacio=0;
    char d='g';
    string btnombre=" ";
    int bomba=0;


    while(gameInProgress)
    {
        impBordaJuego(m);
        //impBorda(m);
        cout << "Ingresa la coordinada de la fila: ";
        cin >> fila;
        cout << "Ingresa la coordinada de la columna: ";
        cin >> col;
        cout << endl;
        adivin++;
        espacio=obtEspacio(m, fila, col);


        switch(espacio)
        {
            case 0:
                cout << "fallaste" << endl;
                m[fila][col]=9;
                miss++;
                break;
            case 1:
                cout << "Este espacio ya ha sido bombardeado. ¡Has desperdiciado una bomba!" << endl;
                break;
            case 2:
                m[fila][col]=1;
                pum++;


                btnombre=IistaBotes[6].obtBote(fila, col);  //
                if(btnombre=="Submarino 1")
                {
                    cout << "Has bombardeado" << btnombre << "!" << endl;
                    IistaBotes[6].conjuntoPum();
                    bomba=IistaBotes[6].checkBomba(Submarino);
                    if(bomba==9)
                    {
                        cout << "Has bombardeado a Submarino 1." << endl;
                    }
                } else if(btnombre.empty())
                {
                    btnombre=IistaBotes[7].obtBote(fila, col);
                    if(btnombre=="Submarino 2")
                    {
                        cout << "Has bombardeado " << btnombre << "!" << endl;
                        IistaBotes[7].conjuntoPum();
                        bomba=IistaBotes[7].checkBomba(Submarino);
                        if(bomba==9)
                        {
                            cout << "Has bombardeado Submarino 2." << endl;
                        }
                    } else if(btnombre.empty())
                    {
                        btnombre=IistaBotes[8].obtBote(fila, col);  //
                        cout << "Has bombardeado " << btnombre << "!" << endl;
                        IistaBotes[8].conjuntoPum();
                        bomba=IistaBotes[8].checkBomba(Submarino);
                        if(bomba==9)
                        {
                            cout << "Has bombardeado Submarino 3." << endl;
                        }
                    } else if(btnombre.empty())
                    {
                        btnombre=IistaBotes[9].obtBote(fila, col);  //verifica sies el 4
                        cout << "Has bombardeado " << btnombre << "!" << endl;
                        IistaBotes[9].conjuntoPum();
                        bomba=IistaBotes[9].checkBomba(Submarino);
                        if(bomba==9)
                        {
                            cout << "Has bombardeado Submarino 4." << endl;
                        }
                    }
                }
                btnombre.clear();
                break;
            case 3:
                m[fila][col]=1;
                pum++;


                btnombre=IistaBotes[3].obtBote(fila, col);  //verificar i es destructor 1
                if(btnombre=="Destruidor 1")
                {
                    cout << "Has bombardeado " << btnombre << "!" << endl;
                    IistaBotes[3].conjuntoPum();
                    bomba=IistaBotes[3].checkBomba(Destruidor);
                    if(bomba==9)
                    {
                        cout << "Has bombardeado Destruidor 1." << endl;
                    }
                } else if(btnombre.empty())
                {
                    btnombre=IistaBotes[4].obtBote(fila, col);
                    if(btnombre=="Destruidor 2")
                    {
                        cout << "Has bombardeado" << btnombre << "!" << endl;
                        IistaBotes[4].conjuntoPum();
                        bomba=IistaBotes[4].checkBomba(Destruidor);
                        if(bomba==9)
                        {
                            cout << "Has bombardeado Destruidor 2." << endl;
                        }
                    } else if(btnombre.empty())
                    {
                        btnombre=IistaBotes[5].obtBote(fila, col);
                        cout << "Has bombardeado " << btnombre << "!" << endl;
                        IistaBotes[5].conjuntoPum();
                        bomba=IistaBotes[5].checkBomba(Destruidor);
                        cout << "bomba es " << bomba << endl;
                        if(bomba==9)
                        {
                            cout << "Has bombardeado Destruidor 3." << endl;
                        }
                    }
                }
                btnombre.clear();
                break;
            case 4:
                m[fila][col]=1;
                pum++;


                btnombre=IistaBotes[1].obtBote(fila, col);
                if(btnombre=="Battleship 1")
                {
                    cout << "Has bombardeado " << btnombre << "!" << endl;
                    IistaBotes[1].conjuntoPum();
                    bomba=IistaBotes[1].checkBomba(Battleship);
                    if(bomba==9)
                    {
                        cout << "Has bombardeado Battleship 1." << endl;
                    }
                }
                if(btnombre.empty())
                {
                    btnombre=IistaBotes[2].obtBote(fila, col);
                    cout << "Has bombardeado" << btnombre << "!" << endl;
                    IistaBotes[2].conjuntoPum();
                    bomba=IistaBotes[2].checkBomba(Battleship);
                    if(bomba==9)
                    {
                        cout << "Has bombardeado Battleship 2." << endl;
                    }
                }
                btnombre.clear();
                break;
            case 5:
                cout << "Has bombardeado el aircraft carrier! " << endl;
                m[fila][col]=1;
                pum++;
                IistaBotes[0].conjuntoPum();
                bomba=IistaBotes[0].checkBomba(Carrier);
                if(bomba==9)
                {
                    cout << "Has bombardeado el aircraft carrier." << endl;
                }
                break;
        }//termino del switch
        if(pum==30)
        {
            gameInProgress=false;
        }
    }//


    cout << "¡Gracias por jugar! Usted uso " << adivin << " movimientos!" << endl;


}//se  termina la funcion


int obtEspacio(int m[10][10], int fila, int col)
{
    int espacio=0;
    espacio=m[fila][col];
    return espacio;
}


int main()
{
    int m[10][10];
    vector<Bote> IistaBotes;
    char play;
    inMatriz(m);

    conjuntoBote(m, Carrier, 1, IistaBotes);  //conjuntos de botes en la mtatrix
    conjuntoBote(m, Battleship, 2, IistaBotes);
    conjuntoBote(m, Battleship, 3, IistaBotes);
    conjuntoBote(m, Destruidor, 4, IistaBotes);
    conjuntoBote(m, Destruidor, 5, IistaBotes);
    conjuntoBote(m, Destruidor, 6, IistaBotes);
    conjuntoBote(m, Submarino, 7, IistaBotes);
    conjuntoBote(m, Submarino, 8, IistaBotes);
    conjuntoBote(m, Submarino, 9, IistaBotes);
    conjuntoBote(m, Submarino, 10, IistaBotes);

    cout << "Bienvenido a Batalla naval,presiona j para empezar a jugar" << endl << endl;
    cout << "el 1 significa que le diste y un nueve que fallaste" << endl << endl;
    cin >> play;
    if(play=='j')
    {
        playGame(m, IistaBotes);
    }
    return 0;


}
