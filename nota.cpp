#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "nota.h"
using namespace std;

Nota::Nota(){
     testo = " ";
     letta = true;      
}

Nota::Nota(bool _letta, string _testo){
     testo = _testo;
     letta = _letta;      
}

void Nota::modifica(){
     cout <<endl<< "Inserisci cio' che vuoi comunicare al trainer:" << endl;
     char temp[256];
		 fflush (stdin);
     cin.getline(temp, sizeof(temp)); 
     testo = temp;
		 letta = false;
     cout <<endl<< "La nota e' stata inviata correttamente al trainer!" << endl <<endl;
     system ("PAUSE");    
}

void Nota::letta_si(){
  letta = true;
}

void Nota::stampa_nota(){
  cout << testo << endl;     
}

void Nota::salva_nota(int _ID_cliente){
  char IDchar[5]; //è stato creato per fare la conversione e quindi inserire _ID_cliente in un char
  itoa(_ID_cliente, IDchar, 10); //converte _ID_cliente in base 10 (il numero della funzione) in IDchar
  char* nomefile = strcat (IDchar, "[nota].csv"); 
  ofstream outfile;
  outfile.open(nomefile); // se il file non esiste lo crea, se esiste lo sovrascrive, anche se non specificato il metodo.
	 //controllo sull'apertura di file
  if(!outfile) {
	 	cout << "Errore nella creazione del file!";
	} else {
	    outfile << letta << ";" << testo<< ";" ; //è il formato del file
	    outfile.close();
    }
}

bool Nota::flag(){
     return letta;
}
