#ifndef __PERSONA_H__
#define __PERSONA_H__
#include <string>

using namespace std;

typedef struct Data{
  int giorno;
  int mese;
  int anno;
};

class Persona{
  protected:
    string nome;
    string cognome;
    Data data_di_nascita;
  public:
    Persona();
    Persona(string _nome, string _cognome, Data _data_nascita);
    void stampa_persona() const;             
};

#endif
