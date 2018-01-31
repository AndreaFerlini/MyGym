#ifndef __CLIENTE_H__
#define __CLIENTE_H__
#include "persona.h"
#include "scheda.h"
#include "nota.h"
#include "funzioni.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Cliente:public Persona{
  private:
    char sesso;
    int peso;
    int altezza;
    int ID_cliente;
    TipoObiettivo obiettivo;		 
    string telefono;
    string username;
    string password;      
    Scheda myscheda; //chiama il costruttore di def, non dovrebbe farlo!!
    Nota mynota;   
  public: 
    Cliente(string _nome, string _cognome, Data _data_nascita,const char _sesso,
         int _peso,int _altezza,TipoObiettivo _obiettivo, string _telefono,
         int _ID_cliente,string _password,string _username);  
    //Costruttore Cliente letto da file
    Cliente(string _nome, string _cognome, Data _data_nascita,const char _sesso,
         int _peso,int _altezza,TipoObiettivo _obiettivo, string _telefono,
         int _ID_cliente,string _password,string _username, Scheda s, Nota n);   
    void modifica_cliente();
    void stampa_cliente();
    void modifica_nota();
    void vedi_nota();
    bool get_letta();
    void crea_scheda();
    void apri_scheda();
    void stampa_scheda();
    bool verifica_credenziali(string _user, string _pass);  
    void salva_cliente();  
    friend ostream& operator<< (ostream& os, Data d); 
    string get_username();
    void letta();      
};

#endif
