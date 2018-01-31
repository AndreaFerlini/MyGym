#ifndef __ESERCIZIO_H__
#define __ESERCIZIO_H__
#include "funzioni.h"

using namespace std;



class Esercizio{
  private:
    string nome_esercizio;
    Muscoli gruppo_muscolare;
	  TipoObiettivo qualificatore;
      int carico;
	  int serie;
	  int ripetizioni;
	  int durata;
	  int velocita;
	  
  public:
    Esercizio(string _nome_esercizio, Muscoli _gruppo_muscolare, TipoObiettivo _qualificatore);
    TipoObiettivo ritorna_qualificatore();
    Muscoli ritorna_muscolo();
    void stampa();
    void modifica_attributi(int _carico, int _serie, int _ripetizioni, int _durata, int _velocita);
    void inizializza_attributi (char sessoS, int pesoS, int altezzaS, TipoObiettivo obiettivoS);
    void salva_esercizio(int ID_cliente);
    int* ritorna_attributi();
};

#endif
