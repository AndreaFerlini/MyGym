#include <cstdlib>
#include <iostream>
#include <string>
#include "scheda.h"
using namespace std;

Scheda::Scheda(){}

Scheda::Scheda(int _ID_cliente,char sesso, int altezza, int peso, TipoObiettivo obiettivo){
  ID_cliente = _ID_cliente;
  esercizi.estrai(obiettivo); //chiamata ad estrai
  esercizi.set_attributi(sesso,peso,altezza,obiettivo);
  cout<<"Scheda creata con successo!"<<endl;
}

Scheda::Scheda(int _ID_cliente, ListaEsercizio _le){
  ID_cliente = _ID_cliente;
  esercizi = _le;
}

void Scheda::stampa_esercizi(){
  esercizi.scorri_esercizi();
}

void Scheda::modifica_esercizio(){
  int l;
  char scelta[2]; 
  int scelta_intero;
  int flag=1;
  do{
    this->stampa_esercizi();
    do{
      cout<<endl<<"Che esercizio vuoi modificare?  Digita 'e' se non vuoi modificarne nessuno"<<endl;
      cout<<"(Il numero degli esercizi va da 1 a 20)"<<endl<<endl;
      cin>>scelta;
      l=strlen(scelta);//restituisce lunghezza di scelta
    }while((l>2)|| (l<1));
    scelta_intero=atoi(scelta);
    if((*scelta=='e')||(*scelta=='E')){ 
      flag=0; //metto flag 0 per uscire dal while degli esercizi
    }else{
      if(scelta_intero>0 && scelta_intero<21){
        int scelta_parametro;
        int flag2=1;
        int* p;
        //mi faccio ritornare gli attributi attuali dell'esercizio per non 
        //perderli, dato che prima li azzeravamo.
        p = esercizi.ritorna_attributi_es(scelta_intero);
        int _carico=p[0];
        int _serie=p[1];
        int _ripetizioni=p[2];
        int _durata=p[3];
        int _velocita=p[4];
        delete p; //delete perchè l'indirizzo di p è nell' heap, e quindi lo deallochiamo
        system("CLS");  
        string scel;
        do {      
          esercizi.stampa_scelta(scelta_intero);
          cout<<endl<<"Quale parametro vuoi modificare?"<<endl;
          cout<<"1 - carico"<<endl;
          cout<<"2 - serie"<<endl;
          cout<<"3 - ripetizioni"<<endl;
          cout<<"4 - durata"<<endl;
          cout<<"5 - velocita"<<endl;
          cout<<"0 - Exit"<<endl<<endl;
          cout<<"SCELTA EFFETTUATA: ";
          cin>>scel;
          cout<<endl; 
          scelta_parametro=string_to_int(scel);
          if((scelta_parametro<0)||(scelta_parametro>5)){//controllo su correttezza parametri
            cout<<"ERRORE - SCELTA NON SUPPORTATA"<<endl;
          }else{
            Muscoli m = esercizi.ottieni_muscolo(scelta_intero);  
            string _car,_ser,_rip,_dur,_vel;
            switch(scelta_parametro){
              case 0:
                flag2=0;   //metto flag a 0 per uscire dal while dei parametri
                cout<<"Uscita avvenuta con successo:"<<endl;
                break;
              case 1:
                if(m != CUORE){   
                  cout<<"Inserisci il nuovo carico con valore compreso tra 5 e 160:"<<endl;  
                  do{ 
                    cin>>_car;
                    _carico=string_to_int(_car);
                      if((_carico<5)||(_carico>160)){//controllo inserimento valori nel range dato
                        cout<<"ERRORE - CARICO NON SUPPORTATO"<<endl;  
                        cout<<"Reinserisci il nuovo carico:"<<endl;
                      }
                  }while((_carico<5)||(_carico>160));
                  system("CLS");
                  cout<<"Modifica avvenuta con successo"<<endl;
                }else{
                  system("CLS");
                  cout << "ERRORE - gli esercizi cardio non hanno il CARICO" << endl;
                 }
                break;
              case 2:
                if(m != CUORE){    
                  cout<<"Inserisci le nuove serie con valore compreso tra 1 e 5:"<<endl;
                  do{
                    cin>>_ser;
                    _serie=string_to_int(_ser);
                    if((_serie<1)||(_serie>5)){
                      cout<<"ERRORE - CARICO NON SUPPORTATO"<<endl;  
                      cout<<"Reinserisci le nuove serie:"<<endl;
                    }
                  }while((_serie<1)||(_serie>5));
                  system("CLS");
                  cout<<"Modifica avvenuta con successo"<<endl;
                }else{
                  system("CLS");
                  cout << "ERRORE - gli esercizi cardio non hanno le SERIE" << endl;
                 }
                break;
              case 3:
                if(m != CUORE){ 
                  cout<<"Inserisci le nuove ripetizioni con valore compreso tra 6 e 20:"<<endl;
                  do{
                    cin>>_rip;
                    _ripetizioni=string_to_int(_rip);
                    if((_ripetizioni<6)||(_ripetizioni>20)){
                      cout<<"ERRORE - RIPETIZIONI NON SUPPORTATE"<<endl;  
                      cout<<"Reinserisci le nuove ripetizioni:"<<endl;
                    }
                  }while((_ripetizioni<6)||(_ripetizioni>20));
                  system("CLS");
                  cout<<"Modifica avvenuta con successo"<<endl;
                }else{
                  system("CLS");
                  cout << "ERRORE - gli esercizi cardio non hanno le RIPETIZIONI" << endl;
                 }
                break;
              case 4:
                if(m == CUORE){    
                  cout<<"Inserisci la nuova durata con valore compreso tra 5 e 30:"<<endl<<endl;
                  do{
                    cin>>_dur;
                    _durata=string_to_int(_dur);
                    if((_durata<5)||(_durata>30)){
                      cout<<"ERRORE - DURATA NON SUPPORTATA"<<endl;  
                      cout<<"Reinserisci la nuova durata:"<<endl;
                    }
                  }while((_durata<5)||(_durata>30));
                  system("CLS");
                  cout<<"Modifica avvenuta con successo"<<endl;
                }else{
                  system("CLS");
                  cout << "ERRORE - solo gli esercizi cardio hanno la DURATA" << endl;
                 }
                break;
              case 5:
                if(m == CUORE){   
                  cout<<"Inserisci la nuova velocita con valore compreso tra 1 e 12:"<<endl;
                  do{
                    cin>>_vel;
                    _velocita=string_to_int(_vel);
                    if((_velocita<1)||(_velocita>12)){
                      cout<<"ERRORE - VELOCITA' NON SUPPORTATA"<<endl;  
                      cout<<"Reinserisci le nuova velocita:"<<endl;
                    }
                  }while((_velocita<1)||(_velocita>12));
                  system("CLS");
                  cout<<"Modifica avvenuta con successo"<<endl;
                }else{
                  system("CLS");
                  cout << "ERRORE - solo gli esercizi cardio hanno la VELOCITA'" << endl;
                 }
                break;
            }//fine switch
          }//fine else
          esercizi.scorri_modifica(scelta_intero, _carico, _serie, _ripetizioni, _durata, _velocita);
        }while(flag2==1); //Fine do while
      }//fine if
    }//fine else
  }while(flag==1);//Fine do while
}

void Scheda::salva_scheda(){
       esercizi.salva_lista(ID_cliente);
}
