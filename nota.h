#ifndef __NOTA_H__
#define __NOTA_H__
#include <string>

using namespace std;
class Nota{
  private:
    string testo;
    bool letta;
  public:   
    Nota(); 
    Nota(bool letta, string testo);
    void modifica();   
    void letta_si();
    void stampa_nota(); 
    void salva_nota(int _ID_cliente);
    bool flag();
};

#endif
