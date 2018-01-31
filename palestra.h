#ifndef __PALESTRA_H__
#define __PALESTRA_H__

#include <list>
#include <string>
#include "cliente.h"
#include "trainer.h"
#include "consigliosettimanale.h"
#include "funzioni.h"

using namespace std;


class Palestra{
  private:
    string nome;
    list<Cliente> clienti;
    Trainer allenatore;
    ListaEsercizio esercizi_palestra; 
    ConsiglioSettimanale consiglio;   
  public:
    Palestra(string _nome);
    void menu_scelta();
    void menu_cliente(Cliente &p_cliente);
    void registrazione_cliente();
    void login_cliente();
    void menu_trainer();
    void login_trainer();
    void scorri_note();
    bool chiudi_programma();
};

#endif
