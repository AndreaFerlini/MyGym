#ifndef __LISTAESERCIZIO_H__
#define __LISTAESERCIZIO_H__

#include "esercizio.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "funzioni.h"

using namespace std;

class ListaEsercizio{
  private:
    list<Esercizio> elenco_esercizi;
  public:
    ListaEsercizio();
    void estrai(TipoObiettivo obiettivoS);
    void set_attributi(char sessoS, int pesoS, int altezzaS, TipoObiettivo obiettivoS);
    void salva_lista(int ID_cliente);
    void scorri_esercizi();
    void scorri_modifica(int _scelta, int _carico, int _serie, int _ripetizioni, int _durata, int _velocita);
    void stampa_scelta(int _scelta);
    Muscoli ottieni_muscolo(int _scelta);
    void svuota_listaes();
    void aggiungi_es(Esercizio _es);
    int* ritorna_attributi_es(int _scelta);
};
#endif
