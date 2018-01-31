#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "listaesercizio.h"
using namespace std;

ListaEsercizio::ListaEsercizio(){
 ifstream iss;
  iss.open("esercizi.csv",ios::in); //ios::in è la modalità di apertura 
  char linea[100];
  if(!iss) {
    cout<<"ERRORE - IL FILE [esercizi.csv] NON ESISTE"<<endl;
  }else{
    char* pch;   
    while(!iss.getline(linea,100).eof()){ //cicla fino a quando non trova la fine del file, permette di cambiare la linea  
      Muscoli m;
      TipoObiettivo obiettivo;      
      pch = strtok(linea,";");//leggi fino al primo ";"
      string nome_es(pch); //va a chiamare il costruttore dei tipi std, è come fare "nome_es=pch;"
      pch = strtok(NULL,";"); //permette di partire dalla posiione raggiunta precedentemente
      
      if(strcmp(pch,"pettorali")==0){  
        m=PETTORALI; 
      }
      if (strcmp(pch,"tricipiti")==0){
        m=TRICIPITI;
      }
      if (strcmp(pch,"dorsali")==0){
        m=DORSALI;
      }
      if (strcmp(pch,"bicipiti")==0){
        m=BICIPITI;
      }
      if (strcmp(pch,"spalle")==0){
         m=SPALLE;
      }
      if (strcmp(pch,"addominali")==0){
         m=ADDOMINALI;
      }
      if (strcmp(pch,"quadricipiti")==0){
        m=QUADRICIPITI;
      }
      if (strcmp(pch,"femorali")==0){
        m=FEMORALI;
      }
      if (strcmp(pch,"polpacci")==0){
        m=POLPACCI;
      }
      if (strcmp(pch,"cuore")==0){
         m=CUORE;                       
      }
      pch = strtok(NULL,";");
      if(strcmp(pch,"riabilitazione")==0){
        obiettivo=RIABILITAZIONE;
      }
      if(strcmp(pch,"dimagrimento")==0){
        obiettivo=DIMAGRIMENTO;
      }
      if(strcmp(pch,"aumento_massa")==0){
        obiettivo=AUMENTO_MASSA;
      }
      Esercizio es(nome_es, m , obiettivo);
      elenco_esercizi.push_back(es);
    }//chiusura ciclo while
    iss.close(); //chiude il file	
  }//chiusura else
}

void ListaEsercizio::estrai(TipoObiettivo obiettivoS){ 
  list <Esercizio> temp;
  temp.clear();
  
  list <Esercizio>::iterator lei;
  list <Esercizio>::iterator tlei;
  
  vector <Esercizio> v_pettorali;
  v_pettorali.clear();
  vector <Esercizio> v_tricipiti;
  v_tricipiti.clear();
  vector <Esercizio> v_dorsali;
  v_dorsali.clear();
  vector <Esercizio> v_bicipiti;
  v_bicipiti.clear();
  vector <Esercizio> v_spalle;
  v_spalle.clear();
  vector <Esercizio> v_addominali;
  v_addominali.clear();
  vector <Esercizio> v_quadricipiti;
  v_quadricipiti.clear();
  vector <Esercizio> v_femorali;
  v_femorali.clear();
  vector <Esercizio> v_polpacci;
  v_polpacci.clear();
  vector <Esercizio> v_cuore;
  v_cuore.clear();
 
  TipoObiettivo ok;
  for(lei=elenco_esercizi.begin(); lei!=elenco_esercizi.end(); lei++){
    ok = lei->ritorna_qualificatore();
    if(ok==obiettivoS){  
      temp.push_back(*lei);
      
    }
  }
 elenco_esercizi.clear();
    //ciclo temp per suddividere gli esercizi nei vari gruppi muscolari
    for (tlei=temp.begin(); tlei!=temp.end(); tlei++){
      Muscoli muscolo_ritornato;
      muscolo_ritornato=tlei->ritorna_muscolo();
      switch (muscolo_ritornato){
        case PETTORALI:
          v_pettorali.push_back(*tlei);
          break;   
          
        case TRICIPITI:
          v_tricipiti.push_back(*tlei);
          break;
        
        case DORSALI:
          v_dorsali.push_back(*tlei);
          break; 
          
        case BICIPITI:
          v_bicipiti.push_back(*tlei);
          break;
          
        case SPALLE:
          v_spalle.push_back(*tlei);
          break;
          
        case ADDOMINALI:
          v_addominali.push_back(*tlei);
          break;
        
        case QUADRICIPITI:
          v_quadricipiti.push_back(*tlei);
          break;
        
        case FEMORALI:
          v_femorali.push_back(*tlei);
          break;
          
        case POLPACCI:
          v_polpacci.push_back(*tlei);
          break;      
      
        case CUORE:
          v_cuore.push_back(*tlei);
          break;
      }//chiusura switch
    }//chiusura ciclo su temp 
    
    int j;
    for(int i=0; i<2; i++){
      j=random((v_pettorali.size()-1), 0);
      elenco_esercizi.push_back(v_pettorali[j]);
      v_pettorali.erase(v_pettorali.begin()+j);
    }
    
    for(int i=0; i<2; i++){
      j=random((v_tricipiti.size())-1, 0);
      elenco_esercizi.push_back(v_tricipiti[j]);
      v_tricipiti.erase(v_tricipiti.begin()+j);
    }
    
    for(int i=0; i<2; i++){
      j=random((v_dorsali.size())-1, 0);
      elenco_esercizi.push_back(v_dorsali[j]);
      v_dorsali.erase(v_dorsali.begin()+j);
    }
    
    for(int i=0; i<2; i++){
      j=random((v_bicipiti.size())-1, 0);
      elenco_esercizi.push_back(v_bicipiti[j]);
      v_bicipiti.erase(v_bicipiti.begin()+j);
    }
    
    for(int i=0; i<2; i++){
      j=random((v_spalle.size())-1, 0);
      elenco_esercizi.push_back(v_spalle[j]);
      v_spalle.erase(v_spalle.begin()+j);
    }
    
    for(int i=0; i<2; i++){
      j=random((v_addominali.size())-1, 0);
      elenco_esercizi.push_back(v_addominali[j]);
      v_addominali.erase(v_addominali.begin()+j);
    }
    
    for(int i=0; i<2; i++){
      j=random((v_quadricipiti.size())-1, 0);
      elenco_esercizi.push_back(v_quadricipiti[j]);
      v_quadricipiti.erase(v_quadricipiti.begin()+j);
    }
    
    for(int i=0; i<2; i++){
      j=random((v_femorali.size())-1, 0);
      elenco_esercizi.push_back(v_femorali[j]);
      v_femorali.erase(v_femorali.begin()+j);
    }
    
    for(int i=0; i<2; i++){
      j=random((v_polpacci.size())-1, 0);
      elenco_esercizi.push_back(v_polpacci[j]);
      v_polpacci.erase(v_polpacci.begin()+j);
    }
    
    for(int i=0; i<2; i++){
      j=random((v_cuore.size())-1, 0);
      elenco_esercizi.push_back(v_cuore[j]);
      v_cuore.erase(v_cuore.begin()+j);
    }
}

void ListaEsercizio::set_attributi(char sessoS, int pesoS, int altezzaS, TipoObiettivo obiettivoS){    
  list<Esercizio>::iterator lei; 
  for (lei=elenco_esercizi.begin(); lei!=elenco_esercizi.end(); lei++){
    lei->inizializza_attributi (sessoS, pesoS, altezzaS, obiettivoS);
  }
}

void ListaEsercizio::salva_lista(int ID_cliente){    
  list <Esercizio>::iterator lei; 
  for (lei=elenco_esercizi.begin(); lei!=elenco_esercizi.end(); lei++){
    lei->salva_esercizio(ID_cliente);
  }
}

void ListaEsercizio::scorri_esercizi(){
  list<Esercizio> :: iterator lei; 
  int i=1;
  for (lei = elenco_esercizi.begin(); lei != elenco_esercizi.end(); lei++){
    cout<<"\t\t"<<i<<": ";
    lei->stampa();
    cout<<endl;
    i++;
  }
}

void ListaEsercizio::scorri_modifica(int _scelta, int _carico, int _serie, int _ripetizioni, int _durata, int _velocita){
  list<Esercizio> :: iterator lei; 
  lei=elenco_esercizi.begin();
  for (int i=0; i< (_scelta-1); i++){
    lei++;   
  }
  lei->modifica_attributi( _carico, _serie, _ripetizioni, _durata, _velocita); //modifica l'esercizio corrisp. a scelta
}

void ListaEsercizio::stampa_scelta(int _scelta){
  cout << endl << " Scelta: "<< _scelta<< endl;
  list<Esercizio> :: iterator lei; 
  lei=elenco_esercizi.begin();
  for (int i=0; i<(_scelta - 1); i++){
    lei++;
  }
  lei->stampa(); //stampa l'esercizio da modificare
}

Muscoli ListaEsercizio::ottieni_muscolo(int _scelta){
  list<Esercizio> :: iterator lei; 
  lei=elenco_esercizi.begin();
  for (int i=0; i<(_scelta - 1); i++){
    lei++;
  }
  return lei->ritorna_muscolo();  
}

void ListaEsercizio::svuota_listaes(){
  elenco_esercizi.clear();     
}

void ListaEsercizio::aggiungi_es(Esercizio _es){
  elenco_esercizi.push_back(_es);
}

int* ListaEsercizio::ritorna_attributi_es(int _scelta){
  list<Esercizio> :: iterator lei; 
  lei=elenco_esercizi.begin();
  for (int i=0; i< (_scelta-1); i++){
    lei++;   
  }
  return lei->ritorna_attributi(); //chiama il metodo di Esercizio per poter avere il ptr agli attributi di Esercizio
}
