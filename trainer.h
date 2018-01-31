#ifndef __TRAINER_H__
#define __TRAINER_H__


#include "persona.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Trainer:public Persona{
  private:
    string username;
    string password;
  public:
    Trainer();
    bool verifica_credenziali(string _user, string _pass);
};

#endif
