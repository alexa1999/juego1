#ifndef BOTE_H
#define BOTE_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <string>
using namespace std;
class Bote
{
  private:


        char dir;
        int longitud;
        vector<int> BoteFila;
        vector<int> Botecol;
        int golpe;
        string nombre;


    public:
        Bote();


        Bote(char d, int lgth, vector<int> r, vector<int> c, int pum, string nme)
        {
            dir=d;
            longitud=lgth;
            BoteFila=r;
            Botecol=c;
            golpe=pum;
            nombre=nme;
        }


        //conjunto Bote pum
        void conjuntoPum()
        {
            golpe++;
        }


        int checkBomba(int TamanioBote)
        {
            if(golpe>=TamanioBote)
            {
                return 9;
            }
            else
            {
                return 0;
            }
        }



        //mira el bote que es
        string obtBote(int r, int c)
        {
            for(int i=0; i<longitud; i++)
            {
                if((BoteFila[i]==r) && (Botecol[i]==c))
                {
                    return nombre;
                }
            }
            return "";
         }

};


#endif // BOTE_H
