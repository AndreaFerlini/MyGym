#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "consigliosettimanale.h"
using namespace std;

ConsiglioSettimanale::ConsiglioSettimanale(){
  testo = " ";                       
}

ConsiglioSettimanale::ConsiglioSettimanale(string _testo){
  testo = _testo;                                            
}

void ConsiglioSettimanale::stampa_consiglio() const{
  cout<<endl;
  cout << testo<< endl;
  cout<<endl;
  system("PAUSE");
}

void ConsiglioSettimanale::salva_consiglio(){
  ofstream outfile;
  outfile.open("consiglio.txt"); // se il file non esiste lo crea, se esiste lo sovrascrive.
  if(!outfile) {
    cout << "Errore nella creazione del file consiglio.txt!";
  } else {
	    outfile << testo; 
	    outfile.close();
    }
}

ConsiglioSettimanale& ConsiglioSettimanale::operator=(string _testo){
 this->testo = _testo;
 return *this;
}
