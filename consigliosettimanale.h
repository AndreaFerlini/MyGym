#ifndef __CONSIGLIOSETTIMANALE_H__
#define __CONSIGLIOSETTIMANALE_H__

#include <string>
using namespace std;

class ConsiglioSettimanale{
  private:
    string testo;
  public:
    ConsiglioSettimanale();       
    ConsiglioSettimanale(string _testo);
    void stampa_consiglio() const;
    void salva_consiglio();
    
    ConsiglioSettimanale& operator=(string _testo);
};

#endif
