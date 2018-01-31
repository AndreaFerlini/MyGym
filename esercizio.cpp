#include <cstdlib>
#include <iostream>
#include <string>
#include "esercizio.h"
#include "funzioni.h"
#include <fstream>
using namespace std;

Esercizio::Esercizio(string _nome_esercizio, Muscoli _gruppo_muscolare, TipoObiettivo _qualificatore){
  nome_esercizio = _nome_esercizio; 
  gruppo_muscolare = _gruppo_muscolare;
  qualificatore = _qualificatore;
  carico=0;
  serie=0;
  ripetizioni=0;
  durata=0;
  velocita=0;
}

void Esercizio::stampa(){   
  cout <<"\t"<<nome_esercizio <<"  (";
  stampa_muscolo(gruppo_muscolare);
  cout<<")"<<endl<<endl;
  if(carico!=0){
    cout << "\t\t carico: " << carico;
  }
  if(serie!=0){
    cout << " \tserie: " << serie;
  }
  if(ripetizioni!=0){
    cout << " \tripetizioni: " << ripetizioni << endl;
  }
  if(durata!=0){
    cout << " \t\t durata: " << durata;
  }
  if(velocita!=0){
  cout << " \tvelocita: " << velocita << endl;
  }
  cout << endl<<endl<<endl;
}

void Esercizio::modifica_attributi (int _carico, int _serie, int _ripetizioni, int _durata, int _velocita){
  carico = _carico;
  serie = _serie;
  ripetizioni = _ripetizioni;
  durata = _durata;
  velocita = _velocita;
}

void Esercizio::inizializza_attributi (char sessoS, int pesoS, int altezzaS, TipoObiettivo obiettivoS){
    //Parte di scelta del carico, serie, ripetizioni, durata e velocità
    // funzione random che è presente nella libreria funzioni
    if( nome_esercizio == "panca_piana"){
        carico = random(160,10);
        serie = random(5,1);
        ripetizioni = random(20,6);
        durata = 0;
        velocita = 0;
    }
    if( nome_esercizio == "croci_manubri"){
      carico = random(40,5);
      serie = random(5,1);
      ripetizioni = random(20,6);
      durata = 0;
      velocita = 0;
    }
    if( nome_esercizio == "spinte_manubri"){
      carico = random(36,4);
      serie = random(5,1);
      ripetizioni = random(20,6);
      durata = 0;
      velocita = 0;
    }
    if( nome_esercizio == "french_press"){
      carico = random(30,4);
      serie = random(5,1);
      ripetizioni = random(20,6);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "pulldown_braccia_tese"){
      carico = random(60,5);
      serie = random(5,1);
      ripetizioni = random(20,6);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "dip"){
      carico = pesoS;
      serie = random(5,1);
      ripetizioni = random(20,6);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "lat_machine"){
      carico = random(130,5);
      serie = random(5,1);
      ripetizioni = random(20,6);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "low_row"){
      carico = random(130,5);
      serie = random(5,1);
      ripetizioni = random(20,6);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "pulley"){
      carico = random(150,5);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "curl_bilanciere"){
      carico = random(70,10);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "curl_martello"){
      carico = random(30,4);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "panca_scott"){
      carico = random(50,10);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "shoulder_press"){
      carico = random(130,5);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "military_press"){
      carico = random(160,10);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "tirate_mento"){
      carico = random(100,10);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "crunch"){
      carico = pesoS;
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "crunch_obliqui"){
      carico = pesoS;
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "sit_up"){
      carico = pesoS;
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "squat"){
      carico = random(160,10);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "leg_extension"){
      carico = random(130,5);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "leg_press"){
      carico = random(130,5);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "leg_curl"){
      carico = random(130,5);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "stacchi_gambe_tese"){
      carico = random(160,10);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "leg_curl_a_terra"){
      carico = random(130,5);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "calf_pressa"){
      carico = random(160,5);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "calf_in_piedi"){
      carico = random(160,5);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "calf_rise_con_manubrio"){
      carico = random(50,5);
      serie = random(5,1);
      ripetizioni = random(20,3);
      durata = 0;
      velocita = 0;
    }
    if(nome_esercizio == "tapis_roulant"){
      carico = 0;
      serie = 0;
      ripetizioni = 0;
      durata = random(30,5);
      velocita = random(12,1);
    }
    if(nome_esercizio == "cyclette"){
      carico = 0;
      serie = 0;
      ripetizioni = 0;
      durata = random(30,5);
      velocita = random(12,1);
    }
    if(nome_esercizio == "stepper"){
      carico = 0;
      serie = 0;
      ripetizioni = 0;
      durata = random(30,5);
      velocita = random(12,1);
    }
  //controllo sul sesso, e conseguente impostazione degli attributi
  if(sessoS == 'F' || sessoS == 'f'){
    carico = (int)(carico*0.6);
  }
  
  switch(obiettivoS){
    case RIABILITAZIONE: if(carico > 20){carico -= 20;} break;
    case DIMAGRIMENTO: if(carico > 10){carico -= 10;} break; 
  }
}

void Esercizio::salva_esercizio(int ID_cliente){
 
    char IDchar[5]; 
     itoa(ID_cliente, IDchar, 10);
     char* nomefile = strcat (IDchar, "[scheda].csv");
     ofstream outfile;
     outfile.open(nomefile, ios::app);  
                             
	 if(!outfile) {
		cout << "Errore nella creazione del file!";
	 }else{
	    outfile << nome_esercizio << ";" << gruppo_muscolare << ";" << qualificatore << ";" << carico << ";"
	    << serie << ";" << ripetizioni << ";" << durata << ";" << velocita<< ";" << endl; 
	    outfile.close();
      }
}

TipoObiettivo Esercizio::ritorna_qualificatore(){
  return qualificatore;
}
  
Muscoli Esercizio::ritorna_muscolo(){
  return gruppo_muscolare;
}

int* Esercizio::ritorna_attributi(){
  int* p;
  p=new int[5]; //verrà deallocato in modifica_esercizio() di Scheda
  p[0]=carico;
  p[1]=serie;
  p[2]=ripetizioni;
  p[3]=durata;
  p[4]=velocita;
  return p;                   
}
