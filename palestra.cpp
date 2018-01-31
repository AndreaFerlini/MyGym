#include "palestra.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include "funzioni.h"
using namespace std;

Palestra::Palestra(string _nome){
  nome = _nome; 
	//lettura del file consiglio
  ifstream is("consiglio.txt"); 
  string s;
  if(!is) {
    cout<<"ERRORE - IL FILE [consiglio.txt] NON ESISTE"<<endl;
  }else{
    while(!is.eof()){
      getline(is, s); 
    }
      is.close(); //chiude il file	
      consiglio=s;
  }
  //lettura e caricamento dei clienti
  ifstream isss;
  isss.open("clienti.csv",ios::in); 
  if(!isss) {
    cout<<"ERRORE - IL FILE [clienti.csv] NON ESISTE"<<endl;
  }else{
    char linea2[200];
    int id,pe,al;
    TipoObiettivo ob;
    char se;
    Data da;
    int j;
    char* pch;
    while(!isss.getline(linea2,200).eof()){
      pch = strtok(linea2,";");//leggi fino al primo ";"
      id=atoi(pch);
      pch = strtok(NULL,";");
      string us(pch); //converte l'array di char in string
      pch = strtok(NULL,";");
      string pa(pch);
      //qui leggo l'obiettivo che è salvato sottoforma numerica e non 
	  pch = strtok(NULL,";");
      j=atoi(pch);
      if(j==0){
        ob=RIABILITAZIONE;
      }
			if(j==1){
        ob=DIMAGRIMENTO;
			}
      if(j==2){
        ob=AUMENTO_MASSA;
      }
 
      pch = strtok(NULL,";");
      string no(pch);
      pch = strtok(NULL,";");
      string co(pch);
      pch = strtok(NULL,";");
      se=pch[0];
      pch = strtok(NULL,";");
      pe=atoi(pch);
      pch = strtok(NULL,";");
      al=atoi(pch);
      //ora per la data taglio l'array di caratteri in 3 diverse stringhe e 
      //riconvertendole in char* per poter fare la "atoi"     
      pch = strtok(NULL,";");
      string datas(pch);
      string gg=datas.substr(0,2); //substr legge lo 0 (posizione nella stringa) 
                                   //e il 2 (numero di caratteri), la stringa è gg/mm/aaaa
      const char* day;
      day = gg.c_str(); //converte gg da string a char* (il "c_str();")
      da.giorno=atoi(day);
      string mm=datas.substr(3,2);
      const char* month;
      month = mm.c_str(); //converte mm da string a char* (il "c_str();")
      da.mese=atoi(month);
      string aa=datas.substr(6,4);
      const char* year;
      year = aa.c_str();
      da.anno=atoi(year);
      pch = strtok(NULL,";");
      string tel(pch);
      //LETTURA NOTA
      ifstream in; //Stream per la lettura della nota 
      Nota n;
      char id_char[5]; //serve per convertire l'id intero in caratteri
      itoa(id, id_char, 10);
      char* nomefile = strcat (id_char, "[nota].csv");
      in.open(nomefile, ios::in);
      if(!in) {
      cout<<"ERRORE - IL FILE " << id << "[nota].csv NON ESISTE"<<endl;
      }else{
        char linea3[500];
        in.getline(linea3,500);
        bool l;
        int f;
        pch = strtok(linea3, ";");
        f=atoi(pch);
        if (f == 1){
          l=true;
        } else{
            l=false;
          }
        pch = strtok (NULL, ";");
        string t(pch);
        Nota nota_temp(l,t);
        n = nota_temp;
        in.close(); //chiusura del file di nota
      }
      //LETTURA SCHEDA
      ifstream isc; //Stream per la lettura della scheda 
      itoa(id, id_char, 10);
      nomefile = strcat (id_char, "[scheda].csv");
      isc.open(nomefile, ios::in);
      if(!isc) {
      cout<<"ERRORE - IL FILE " << id << "[scheda].csv NON ESISTE"<<endl;
      }else{
        char linea4[300];
        ListaEsercizio _esercizi; //creo una nuova lista
        _esercizi.svuota_listaes(); //la svuoto
        while(!isc.getline(linea4, 300).eof()){
          int carico, serie, ripetizioni, durata, velocita,i,j;
          Muscoli m;
          TipoObiettivo obiettivo;
          pch = strtok(linea4,";");//leggi fino al primo ";"
          string nome_es(pch);
          //legge il numero corrispondente al gruppo muscolare
	      pch = strtok(NULL,";");
	      i=atoi(pch);
          //caricamento gruppi muscolari
          //serie di if perchè lo switch non funziona con le string
          if(i==0){  
            m=PETTORALI; 
          }
          if(i==1){
            m=TRICIPITI;
          }
          if(i==2){
            m=DORSALI;
          }
          if(i==3){
            m=BICIPITI;
          }
          if(i==4){
            m=SPALLE;
          }
	      if(i==5){
            m=ADDOMINALI;
          }
          if(i==6){
            m=QUADRICIPITI;
          }
          if(i==7){
            m=FEMORALI;
          }
          if(i==8){
            m=POLPACCI;
          }
          if(i==9){
            m=CUORE;                          
          }
          pch = strtok(NULL,";");
          j=atoi(pch);
          //caricamento dei qualificatori
          if(j==0){
            obiettivo=RIABILITAZIONE;
          }
					if(j==1){
            obiettivo=DIMAGRIMENTO;
          }
          if(j==2){
            obiettivo=AUMENTO_MASSA;
          }
          //Ora leggiamo gli interi Carico, serie, ripetizioni, durata, velocità.
          pch = strtok(NULL,";");
          carico=atoi(pch); 
          pch = strtok(NULL,";");
          serie=atoi(pch); 
          pch = strtok(NULL,";");
          ripetizioni=atoi(pch); 
          pch = strtok(NULL,";");
          durata=atoi(pch); 
          pch = strtok(NULL,";");
          velocita=atoi(pch); 
          Esercizio es(nome_es, m, obiettivo); //creo un esercizio  (quello letto)
          es.modifica_attributi(carico, serie, ripetizioni, durata, velocita); //lo modifico con gli attributi salvati
          _esercizi.aggiungi_es(es); //lo aggiungo alla lista
      }   
        Scheda sc(id, _esercizi);
        isc.close(); //chiusura del file di scheda
        //inizializzo il cliente appena letto
        Cliente c (no, co, da, se, pe, al, ob, tel, id, pa, us, sc, n); //chiamo il costruttore specifico di cliente
                                                                        // sc ed n sono scheda e nota del cliente 
                                                                        //che sono appena state lette dal file
        clienti.push_back(c);
      }
    }//chiusura while dei clienti -> scorre tutti i clienti e li carica tutti con le relative schede-note
  } //chiusura else !isss
  isss.close(); //chiude il file          
}                        
//MENU SCELTA
void Palestra::menu_scelta(){
  char scelta[2]; //DUE perchè atoi non prende un solo char (scelta+finestring)
  bool flag =false;
  int l,scelta_intero;
  do{ //inizio ciclo principale di chiusura. esce con scelta == 4
    do{ //inizio ciclo di richiesta scelta 1-2-3-4
      system ("CLS");
      printf("\t \t \t BENVENUTO IN MYGYM \n \n\n");     
      printf("\t \t \t Login - Registrazione \n\n");
      printf("\t \t \t 1. Login Cliente \n");
      printf("\t \t \t 2. Login Trainer \n");
      printf("\t \t \t 3. Registrati \n");
      printf("\t \t \t E. Chiusura del Programma \n\n");
      printf("\t \t \t SCELTA EFFETTUATA: ");
      cin >> scelta;      
      l=strlen(scelta);
    }while(l<1||l>2);
    scelta_intero=atoi(scelta);
    if((*scelta=='e')||(*scelta=='E')){
      flag=this->chiudi_programma();
    }else{
      if(scelta_intero>0 && scelta_intero<4){
        switch(scelta_intero){
          case 1: this->login_cliente();
            break;                                                   
          case 2: this->login_trainer();
            break;
          case 3: this->registrazione_cliente();
            break;
        }
      }
    }  
  }while(flag==false);
}
//MENU CLIENTE
void Palestra::menu_cliente(Cliente &p_cliente){
  string scelta_str;
	int scelta = 0;
	bool esci=false;
  do{ //inizio ciclo principale di chiusura. esce con scelta == 4
	  do{ //inizio ciclo di richiesta scelta 1-2-3-4
      system("CLS");
	    printf("\t \t \t MENU' CLIENTE \n");
		  printf("\n \t \t \t 1. Modifica i tuoi dati \n");
			printf("\t \t \t 2. Allenamento odierno \n");
			printf("\t \t \t 3. I miei dati \n");
			printf("\t \t \t 4. Contatta il personal trainer \n");
			printf("\t \t \t 5. Consiglio della settimana \n");
			printf("\t \t \t 6. Logout \n\n");
			printf("\t \t \t SCELTA EFFETTUATA: ");
	  	cin >> scelta_str; //prendo la stringa 
	  	scelta = string_to_int(scelta_str); //e controllo che sia un numero
			}while(scelta<1||scelta>6);
			switch(scelta) {
			  case 1: p_cliente.modifica_cliente();
 	 		          break;							 
			  case 2: p_cliente.stampa_scheda(); 
			          break;
			  case 3: system("CLS");
                      p_cliente.stampa_cliente(); 
			          break;
			  case 4: system("CLS");
                      p_cliente.modifica_nota();
			    	  break;							 
			  case 5: system("CLS");
                      consiglio.stampa_consiglio();  
			          break;
			  case 6: esci=true;
			          break;
			}	
  }while(esci==false);		 	 
}
//REGISTRAZIONE CLIENTE
void Palestra::registrazione_cliente(){
  system("CLS");
  string nome,cognome,numero,username,password;
  Data d;
	char sesso;
  int scelta_obiettivo, altezza, peso, ID_cliente;
  TipoObiettivo obiettivo;
  int check = 1;
  
  do{
      cout << "Nome: "; cin >> nome; cout << endl;
      string::const_iterator is = nome.begin();
      while(is != nome.end() && (isalpha(*is))){++is;}
      if (!nome.empty() && is == nome.end()){ check = 1;}
      else{check = 0;}
    }while(check!=1);
  fflush(stdin);
  check=1; //ripristino il valore del check e controllo il cognome
  do{
    cout << "Cognome: "; cin >> cognome; cout << endl;
    string::const_iterator is = cognome.begin();
    while(is != cognome.end() && (isalpha(*is))){++is;}
    if (!cognome.empty() && is == cognome.end()){ check = 1;}
    else{check = 0;}
  }while(check!=1);
  fflush(stdin);  
	int g,m,a;
	string gg,mm,aa; //stringhe di supporto per controllare l'inserimento della data
	do{
    cout << "Giorno di nascita (gg): ";
    cin >> gg;    
    cout << endl;
    g = string_to_int(gg); 
    if(!(g >0 && g < 32)){
        cout<<"ERRORE - GIORNO INSERITO SBAGLIATO"<<endl<<endl;
      }
  }while ( !(g >0 && g < 32));  
  d.giorno = g;
  do{
    do{
      cout << "Mese di nascita (mm): ";
      cin >> mm;    
      cout << endl;
      m = string_to_int(mm);
      if(!(m >0 && m < 13)){
        cout<<"ERRORE - MESE INSERITO SBAGLIATO"<<endl<<endl;
      }
    }while( (m == 2 && d.giorno > 28) ||(m==4 && d.giorno > 30) 
            ||(m==6 && d.giorno > 30) ||( m==9 && d.giorno > 30) || (m==11 && d.giorno > 30));
    
  }while ( !(m >0 && m < 13))   ;        
  d.mese = m;
  do{
    cout << "Anno di nascita (aaaa): ";
    cin >> aa;  
    cout << endl;
    a=string_to_int(aa);
      if(!(a >1899 && a < 2100)){
        cout<<"ERRORE - ANNO INSERITO SBAGLIATO"<<endl<<endl;
      }
  }while ( !(a >1899 && a < 2100));        
  d.anno = a;
	string se;
	bool controllo=true;
    do{ 
      cout << "Sesso (M/F): "; 
  	  cin >> se;
      cout << endl;
      if((se[0]=='M' || se[0]=='m') && (se.size()==1)){
        sesso='m';
        controllo=false;
      }else{
        if((se[0]=='F' || se[0]=='f')&&(se.size()==1)){
          sesso='f';
          controllo=false;
        }else{
         cout<<"ERRORE - SESSO SCONOSCIUTO"<<endl<<endl;
         }
        }
    }while(controllo);
  fflush(stdin); 
  //controllo inserimento altezza
  string alt; //variabile per il controllo dell'altezza
  do{
    cout << "Altezza (cm): ";
    cin >> alt;
    cout << endl;
    altezza=string_to_int(alt);
    if(altezza<50 || altezza>250){
        cout<<"ERRORE - ALTEZZA INSERITA NON SUPPORTATA"<<endl<<endl;   
      }   
  }while(altezza<50 || altezza>250);
  //controllo inserimento peso
  string pes;
  do{
    cout << "Peso (kg): ";
    cin >> pes;
    cout << endl;
    peso=string_to_int(pes);
      if(peso<30 || peso>200){
        cout<<"ERRORE - PESO INSERITO NON SUPPORTATO"<<endl<<endl;
      }
  }while(peso<30 || peso>200);
  //controllo inserimento obiettivo
  string tobb;
  do{ 
    cout << "Obiettivo (0: riabilitazione, 1: dimagrimento, 2: aumento massa): "; 
		cin>>tobb;
		cout<<endl;
	  scelta_obiettivo=string_to_int(tobb);
    if((scelta_obiettivo<0) || (scelta_obiettivo>2)){
      cout<<"ERRORE - SCELTA NON SUPPORTATA"<<endl;
    } else {
		switch(scelta_obiettivo){
      case 0:
   				 	  obiettivo=RIABILITAZIONE;
              cout<<"Obiettivo scelto: RIABILITAZIONE"<<endl;
              cout<<endl;
              break;
      case 1: 
       		 	  obiettivo=DIMAGRIMENTO;
              cout<<"Obiettivo scelto: DIMAGRIMENTO"<<endl;
              cout<<endl;
              break;
      case 2:
              obiettivo=AUMENTO_MASSA;
              cout<<"Obiettivo scelto: AUMENTO MASSA"<<endl;
              cout<<endl;
              break;
    }//fine switch
		}//fine else
   }while((scelta_obiettivo>2) || (scelta_obiettivo<0));
  //robustezza sul numero telefonoico
  int k;
  int flag_numero=1;
  do{
    cout << "Numero di telefono: ";
    cin >> numero;
    cout << endl;
    k=numero.size();
    string::const_iterator it = numero.begin(); //finchè non si arriva alla fine del numero di telefono continua 
    while(it != numero.end() && isdigit(*it)) { ++it; } //isdigit constrolla che sia stato inserito un numero e non un char
    if(!numero.empty() && it == numero.end()){
      flag_numero=1;
    }else{
      flag_numero=0;
      cout<<"ERRORE - NUMERO DI TELEFONO NON SUPPORTATO"<<endl;
    }
  }while(((k<10) || (k>10) || (flag_numero!=1)));
  fflush(stdin);
  //controllo username e password
  int flag_user=0;
  do{
    cout << "Username: ";
    cin >> username;
    cout << endl;
    if((username.length()<6) || (username.length()>12)){
      cout << "ERRORE - La lunghezza dell'username deve essere almeno di 6 e massimo di 12"<< endl;
    }else{
       list<Cliente>::iterator itc=clienti.begin();
       while(itc!=clienti.end() && itc->get_username()!=username){++itc;}
         if(itc->get_username()==username){
           cout << "ERRORE - USERNAME GIA' PRESENTE"<< endl;
           flag_user=1;  
         }else{
            flag_user=0;
          }
     }
  }while((username.length()<6) || (username.length()>12) || flag_user!=0);
  cout << "Username accettato"<< endl<<endl;
  fflush(stdin);
  do{
    cout << "Password: ";
    cin >> password;
    cout << endl;
    if((password.length()<6) || (password.length()>12)){
      cout << " ERRORE - La lunghezza della password deve essere almeno di 6 e massimo di 12" << endl;
    }
  }while((password.length()<6) || (password.length()>12));
  cout << "Password accettata" << endl<<endl;
	ID_cliente = clienti.size();
  Cliente c(nome, cognome, d, sesso, peso, altezza,obiettivo,numero,ID_cliente,password,username);
  clienti.push_back(c);
  cout << "REGISTRAZIONE COMPLETATA."<<endl;
  cout << "PREMERE INVIO PER CONTINUARE." << endl;
}
//LOGIN CLIENTE
void Palestra::login_cliente(){
	string username, password;
	int trovato = 0; //variabile sentinella
  Cliente *p_cliente=NULL;
  system("CLS");
  if(clienti.size()==0){
    cout<<endl<<"Non sono presenti clienti!"<<endl<<endl; 
    system("Pause");
  }else{
    printf ("\t \t \t \t LOGIN CLIENTE: \n \n");
    cout << "\t \tusername: "; 
    cin >> username; 
    cout << endl;
    cout << "\t \tpassword: ";
    cin >> password;
    list<Cliente>::iterator iter;
    for(iter=clienti.begin();iter!=clienti.end()&&trovato==0;iter++){
      if(iter->verifica_credenziali(username,password)){
        p_cliente = &(*iter);
        trovato = 1;
        }else{
           string cre;
           cout<<endl<<"ERRORE, CREDENZIALI ERRATE, LOGIN NON EFFETTUATO!"<<endl;
           do{
             system("CLS");
             printf ("\t \t \t \t LOGIN CLIENTE: \n \n");                 
             cout<<endl<<"E - torna al menu precedente"<<endl;
             cout<<"R - reinserisci le credenziali"<<endl<<endl;
             cin>>cre;
           }while((cre.size()!=1)&&((cre[0]!='E')||(cre[0]!='R')||(cre[0]!='e')||(cre[0]!='r')));
           if((cre[0]=='e')||(cre[0]=='E')){
             this->menu_scelta();
           }
           if((cre[0]=='r')||(cre[0]=='R')){
             this->login_cliente();
           }
         }
      if(p_cliente!=NULL) {
        this->menu_cliente(*p_cliente);
      }   										  
    }
  }
}
//MENU TRAINER
void Palestra::menu_trainer(){
  int scelta = 0;
  string sce;
  bool esci=false;
  char temp [256];
  string cons;
	do{ //inizio ciclo principale di chiusura. esce con scelta == 3
	  do{ //inizio ciclo di richiesta scelta 1-2-3
      system("CLS");
	    printf("\t \t BENVENUTO E BUON LAVORO LUIGI FRANCO \n \n  ");
      printf("\t \t 1. Leggi le nuove note e modifica le schede \n");
      printf("\t \t 2. Crea il consiglio della settimana \n");
      printf("\t \t 3. Logout \n\n");
      printf("\t\t\t SCELTA EFFETTUATA: ");
	  	cin >> sce;
	  	cout << endl;
	  	scelta=string_to_int(sce);
    }while(scelta<1 && scelta>3);
			switch(scelta) {
			  case 1: this->scorri_note(); 
 	 					   break;							 
			  case 2: cout << "Inserisci il consiglio della settimana: ";
			  		 		fflush (stdin);
			  		 		cin.getline(temp, sizeof(temp)); //permette di prendere un insieme di char che verranno messe nel temp 
                                                 
                cons = temp;
			  		 		consiglio = cons; //ridefinito operatore = 
			  		 		cout<<"Consiglio Settimanale inserito con successo!"<<endl<<endl;
			          break;
			  case 3: //esce dal ciclo e ritorna al menu_scelta (passando da login)
			          esci=true;
                break;
			}	
  }while(esci==false);		 
}
//LOGIN TRAINER
void Palestra::login_trainer(){
  string username, password;
  system("CLS");
  printf ("\t \t \t \t LOGIN TRAINER: \n \n");
	cout << "\t \tusername: "; cin >> username; cout << endl;
	cout << "\t \tpassword: ";	cin >> password; cout<<endl;
	if(allenatore.verifica_credenziali(username,password)){
	this->menu_trainer();
  } else {
    cout<<"ERRORE, CREDENZIALI ERRATE, LOGIN NON EFFETTUATO!"<<endl<<endl;
    system ("PAUSE");
	}	
}

void Palestra::scorri_note(){
  list<Cliente>::iterator iter; //iteratore per scorrere la lista (clienti)
  string s; //variabile che serve per l'acquisizione del carattere
  for(iter=clienti.begin();iter!=clienti.end();iter++ ){
		if(!(iter->get_letta())) {  //entra nell'if solo se il valore è false
		  do{
            system("CLS");
            cout<< "Cliente: " << iter->get_username() << endl;
            iter->vedi_nota();
            cout<<endl<<endl<<endl;                 
		    cout << " M - modifica scheda cliente "<<endl;
		    cout << " C - cancella la nota "<<endl;
		    cout << " E - passare alla nuova nota senza cancellare questa "<<endl; 
			  cin >> s;
			  cout << endl;
			  if((s[0]=='m'||s[0]=='M')&&(s.size()==1)) {
					iter->apri_scheda();
                    iter->letta();		 
              }				 
              if((s[0]=='c'||s[0]=='C')&&(s.size()==1)) {
                    iter->letta();		 
              }				 
			}while((s[0]!='m' && s[0]!='M' && s[0]!='e' && s[0]!='E' && s[0]!='c' && s[0]!='C') || s.size()!=1); //esce solo se il carattere non è e,m,E,M	    	
    }//fine if !(iter->get_letta)
  }//fine for
  system("CLS");
  cout<<endl<<endl<<"\t \t \t Non sono presenti altre note!"<<endl<<endl;
  system("PAUSE");
}

bool Palestra::chiudi_programma(){
	string username, password;
	system("CLS");
    cout<<"\t \t Per terminare inserire le credenziali del Trainer:"<<endl<<endl;
	cout << "\t \t \t username: "; cin >> username; cout << endl;
	cout << "\t \t \t password: ";	cin >> password;
	if(allenatore.verifica_credenziali(username,password)){
		//procedi al salvataggio
		consiglio.salva_consiglio(); //del consiglio della settimana
		list<Cliente>::iterator iter;
		if(remove("clienti.csv")!=0){
	    //perror( "Error deleting file" );
		}
		for(iter=clienti.begin();iter!=clienti.end();iter++ ){
		  iter->salva_cliente();
		}
		cout<<endl<<endl<<" \t \t Salvataggio completato, arrivederci!"<<endl<<endl<<endl;
    return true;																										 
  }else {
		 return false;
   }
}
