#ifndef __SCHEDA_H__
#define __SCHEDA_H__
#include "listaesercizio.h"

using namespace std;
class Scheda{
      private:
  	    int ID_cliente;
        ListaEsercizio esercizi;  	  
      public:
        Scheda();             
        Scheda(int _ID_cliente, ListaEsercizio _le);
        Scheda(int _ID_cliente, char sesso, int altezza, int peso, TipoObiettivo obiettivo); //da togliere id cliente perchè non serve a nulla;
        void stampa_esercizi();
        void modifica_esercizio();
        void salva_scheda();
        
};

#endif
