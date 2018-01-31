#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "cliente.h"
using namespace std;

Cliente::Cliente(string _nome, string _cognome, Data _data_nascita,char _sesso,
         int _peso, int _altezza, TipoObiettivo _obiettivo, string _telefono,
         int _ID_cliente, string _password, string _username)
         :Persona(_nome, _cognome, _data_nascita){
  sesso=_sesso;
  peso=_peso;
  altezza=_altezza;
  obiettivo=_obiettivo;
  telefono=_telefono;
  ID_cliente=_ID_cliente;
  password=_password;
  username=_username;
  Scheda tempS(ID_cliente, sesso, altezza, peso, obiettivo);
  myscheda=tempS; 
  // Valutazione IMC, consiglio sul fatto di cambiare obiettivo o meno!
  float IMC;
  float alt_m = (float)altezza /100;
  IMC = (float)((float)peso/(alt_m*alt_m));
  cout << "\nIMC: "<< IMC<< endl;
  
  if(IMC < 17.5){
    cout << "Sei sottopeso"<< endl<<endl;
    if(obiettivo == DIMAGRIMENTO){
      cout << "Consigliamo di cambiare l'obiettivo in aumento massa"<< endl<<endl;
    }
  }
  
  if(IMC >= 17.5 && IMC < 25){
    cout << "Hai un peso regolare"<< endl<<endl;
  }
  
  if(IMC >= 25 && IMC < 30){
    cout << "Sei sovrappeso"<< endl<<endl;
    if(obiettivo == AUMENTO_MASSA){
      cout << "Consigliamo di cambiare l'obiettivo in dimagrimento"<< endl<<endl;
    }  
  }
  
  if(IMC > 30){
    cout << "Sei obeso, ti consigliamo una visita dal dietologo"<< endl<<endl;
    if(obiettivo == AUMENTO_MASSA){
      cout << "Consigliamo di cambiare l'obiettivo in dimagrimento" << endl << endl;
    }
  }
  
  system("PAUSE");
}

//Costruttore Cliente letto da file
Cliente::Cliente(string _nome, string _cognome, Data _data_nascita,char _sesso,
         int _peso,int _altezza,TipoObiettivo _obiettivo, string _telefono,
         int _ID_cliente,string _password,string _username, Scheda s, Nota n)
         :Persona(_nome, _cognome, _data_nascita){
  sesso=_sesso;
  peso=_peso;
  altezza=_altezza;
  obiettivo=_obiettivo;
  telefono=_telefono;
  ID_cliente=_ID_cliente;
  password=_password;
  username=_username;
  myscheda=s;
  mynota=n;
}

void Cliente::modifica_cliente(){
  string scelta; //variabile per ciclo grande
  int scelta_obiettivo; //variabile per ciclo obiettivo
  int ctrl=0;
  int scelta_intero;
  int l, k;
  int flag=1;
  int flag_numero=1;
  do{
    do{    
      system("CLS");
      cout<<endl;
      cout<<"\t \t Quale campo vorresti modificare?"<<endl<<endl;
      cout<<"\t \t \t1 - modifica peso"<<endl;
      cout<<"\t \t \t2 - modifica altezza"<<endl;
      cout<<"\t \t \t3 - modifica obiettivo"<<endl;
      cout<<"\t \t \t4 - modifica telefono"<<endl;
      cout<<"\t \t \t5 - modifica username"<<endl;
      cout<<"\t \t \t6 - modifica password"<<endl;
      cout<<"\t \t \tE - torna al menu precedente"<<endl<<endl; //per uscire dal ciclo
      cout<<"\t \t \tScelta effettuata: ";                     
      cin>>scelta;
      cout<<endl;
    }while(scelta.size()!=1);
    scelta_intero=string_to_int(scelta);
    if((scelta[0]=='e')||(scelta[0]=='E')){ 
      flag=0; //metto flag 0 per uscire dal while
    }else{
      if(scelta_intero>0 && scelta_intero<7){
        string pes,alt,tobb; 
        switch(scelta_intero){
          case 1: 
            ctrl=0;
            do{
              cout<<"Inserisci il nuovo peso (Kg): ";
              cin>>pes;
              peso=string_to_int(pes);
                if((peso>29) && (peso<201)){ //secondo me deve essere un &&
                  ctrl=1;
                }else{
                  cout<<"ERRORE - PESO NON SUPPORTATO"<<endl;
                 }
            }while(ctrl!=1);
            cout<<endl<<"Modifica avvenuta con successo!"<<endl<<endl;
            system("PAUSE");
            break;
          case 2: 
            ctrl=0;
            do{
              cout<<"Inserisci la nuova altezza (cm): ";
              cin>>alt; 
              altezza=string_to_int(alt); 
                if((altezza>50) && (altezza<250)){
                  ctrl=1;
                }else{
                  cout<<"ERRORE - ALTEZZA NON SUPPORTATO"<<endl;
                 }
            }while(ctrl!=1);
            cout<<endl<<"Modifica avvenuta con successo!"<<endl<<endl;
            system("PAUSE");
            break;
          case 3: 
            do{
              cout<<"1 Riabilitazione"<<endl;
              cout<<"2 Dimagrimento"<<endl;
              cout<<"3 Aumento massa"<<endl;
              cin>>tobb;
              scelta_obiettivo=string_to_int(tobb);
              if((scelta_obiettivo<1) || (scelta_obiettivo>3)){
                cout<<"ERRORE - SCELTA NON SUPPORTATA"<<endl;
              }else{
                switch(scelta_obiettivo){
                  case 1:
                    obiettivo=RIABILITAZIONE;
                    break;
                  case 2: 
                    obiettivo=DIMAGRIMENTO;
                    break;
                  case 3:
                    obiettivo=AUMENTO_MASSA;
                    break;
                }
              }
            }while((scelta_obiettivo>3) || (scelta_obiettivo<1));
            myscheda=Scheda(ID_cliente, sesso, altezza, peso, obiettivo);
            break;
          case 4: 
            do{
              cout<<"Inserisci il nuovo numero di telefono: ";
              cin >> telefono;
              cout << endl;
              k=telefono.size();
              string::const_iterator it = telefono.begin(); //finchè non si arriva alla fine del numero di telefono continua 
              while(it != telefono.end() && isdigit(*it)) { ++it; } //isdigit constrolla che sia stato inserito un numero e non un char
              if(!telefono.empty() && it == telefono.end()){
                flag_numero=1;
                cout<<"ERRORE - NUMERO DI TELEFONO NON SUPPORTATO"<<endl;
              }else{
                 flag_numero=0;
               }
            }while(((k<10) || (k>10) || (flag_numero!=1)));
            cout<<"Modifica avvenuta con successo"<<endl<<endl;
            break;
          case 5: 
            ctrl=0;
            do{
              cout<<"Inserisci il nuovo username di min 6 e max 12 caratteri: ";
              cin>>username;
              if((username.length()>=6) && (username.length()<=12)){
                ctrl=1;
              }else{ 
                cout<<"ERRORE - USERNAME FUORI RANGE"<<endl;
              }
            }while(ctrl!=1);
            cout<<"Modifica avvenuta con successo!"<<endl<<endl;
            break;
          case 6:
            ctrl=0;
            do{
              cout<<"Inserisci la nuova password di min 6 e max 12 caratteri: ";
              cin>>password;
              if((password.length()>=6) && (password.length()<=12)){
                ctrl=1;
              }else{
                cout<<"ERRORE - PASSWORD FUORI RANGE"<<endl;
              }
            }while(ctrl!=1);
            cout<<"Modifica avvenuta con successo!"<<endl<<endl;
            break;
        }//chiuso switch scelta
      }//chiuso if
    }//chiudo else
  }while(flag==1);  
}

void Cliente::stampa_cliente(){
  this->stampa_persona(); //perchè stampiamo quell'elemento della persona
  cout<<endl;
  cout<<"obiettivo= ";
  stampa_obiettivo(obiettivo); //chiama la stampa dell'obiettivo di tale istanza 
  cout<<"peso= "<<peso<<endl;
  cout<<"altezza= "<<altezza<<endl;
  cout<<"numero di telefono= "<<telefono<<endl;
  cout<<"username= "<<username<<endl;
  cout<<"password= "<<password<<endl<<endl;
  system("PAUSE");
}

void Cliente::modifica_nota(){
  mynota.modifica();
}

void Cliente::vedi_nota(){
  mynota.stampa_nota();
}

void Cliente::letta(){
  mynota.letta_si();
}

bool Cliente::get_letta(){
  return mynota.flag();
}

void Cliente::crea_scheda(){
  Scheda nuovascheda (ID_cliente, sesso, altezza, peso, obiettivo);
  myscheda=nuovascheda;
}

void Cliente::apri_scheda(){
  myscheda.modifica_esercizio(); 
}

void Cliente::stampa_scheda(){
  system("CLS");   
  cout<<"\t \t Scheda odierna di  "<<nome<<" "<<cognome<<endl<<endl;
  myscheda.stampa_esercizi();
  system("PAUSE");
}

bool Cliente::verifica_credenziali(string _user, string _pass){
  if(username==_user){
    if(password==_pass){
      return true;
    } else { 
        return false;
      }
  } else { 
      return false; 
    }
}   

void Cliente::salva_cliente(){
  //SALVA NOTA
  char IDchar[5];
  itoa(ID_cliente, IDchar, 10);
  char* nomenota = strcat(IDchar, "[nota].csv");
  mynota.salva_nota(ID_cliente);
  //SALVA SCHEDA
  itoa(ID_cliente, IDchar, 10);
  char* nomefile = strcat (IDchar, "[scheda].csv");
    if(remove(nomefile)!=0){
	    //perror( "Error deleting file" );
		}
  myscheda.salva_scheda();
  //SALVA CLIENTE
  ofstream outfile;
  outfile.open("clienti.csv",ios::app);
  if(!outfile) {
    cout << "ERRORE NELLA CREAZIONE DEL FILE [clienti.csv]"<<endl;
  }else{
    outfile<<ID_cliente<<";"<<username<<";"<<password<<";"<<obiettivo<<";"<<nome
    <<";"<<cognome<<";"<<sesso<<";"<<peso<<";"<<altezza<<";"<<data_di_nascita
    <<";"<<telefono<<";"<<endl; 
    outfile.close();
  }
}

string Cliente::get_username(){
  return username;
}  

ostream& operator<< (ostream& os, Data d){
  if (d.giorno<10){
    os<<"0"<<d.giorno<<"/";
  }else{
     os<<d.giorno<<"/";  
   }
  if (d.mese<10){
    os<<"0"<<d.mese<<"/";
  }else{
     os<<d.mese<<"/";
   } 
  os<<d.anno;
  return os;
}
