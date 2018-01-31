#include <cstdlib>
#include <iostream>
#include <string>
#include "persona.h"
using namespace std;

Persona::Persona(){
  nome = "";
  cognome = "";
  data_di_nascita.giorno = 1;    
  data_di_nascita.mese = 1;
  data_di_nascita.anno = 1900;
}

Persona::Persona(string _nome, string _cognome, Data _data_nascita){
  nome = _nome;
  cognome = _cognome; 
  data_di_nascita.giorno = _data_nascita.giorno;    
  data_di_nascita.mese = _data_nascita.mese;
  data_di_nascita.anno = _data_nascita.anno;             
}       

void Persona::stampa_persona() const{
  cout << "Nome:  " << nome << endl;
  cout << "Cognome:  " << cognome << endl;
  cout << "Data di Nascita:  " ;
  cout<<data_di_nascita.giorno<<"/"<<data_di_nascita.mese<<"/"<<data_di_nascita.anno << endl;
  }
