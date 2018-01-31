#include <cstdlib>
#include <iostream>
#include <string>
#include "trainer.h"
using namespace std;

Trainer::Trainer(){
  //inizializzo gli attributi ereditati da Persona
  nome = "Luigi";
  cognome = "Franco";
  data_di_nascita.giorno = 10;    
  data_di_nascita.mese = 8;
  data_di_nascita.anno = 1961;
	username = "trainer";
	password = "mygym";						
}

bool Trainer::verifica_credenziali(string _user, string _pass){
  return (username==_user&&password==_pass);
}
