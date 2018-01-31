#include <iostream>
#include <cstdlib>
#include "funzioni.h"

using namespace std;

int random(int max, int min){
  return rand()%(max - min + 1 ) + min;
}

void stampa_obiettivo(TipoObiettivo obiettivo){
  
  if(obiettivo==RIABILITAZIONE){
    cout<<"Riabilitazione"<<endl;
  }
  if(obiettivo==DIMAGRIMENTO){
    cout<<"Dimagrimento"<<endl;
  }
  if(obiettivo==AUMENTO_MASSA){
    cout<<"Aumento massa"<<endl; 
  } 
}

void stampa_muscolo(Muscoli _muscolo){

  if(_muscolo==0){
    cout<<"Pettorali";
  }
  if(_muscolo==1){
    cout<<"Tricipiti";
  }
  if(_muscolo==2){
    cout<<"Dorsali"; 
  }
  if(_muscolo==3){
    cout<<"Bicipiti";
  }
  if(_muscolo==4){
    cout<<"Spalle";
  }
  if(_muscolo==5){
    cout<<"Addominali"; 
  }
  if(_muscolo==6){
    cout<<"Quadricipiti";
  }
  if(_muscolo==7){
    cout<<"Femorali";
  }
  if(_muscolo==8){
    cout<<"Polpacci"; 
  }if(_muscolo==9){
    cout<<"Cuore"; 
  }
}

int string_to_int(string s){ 
  string::const_iterator is=s.begin();
  while(is != s.end() && isdigit(*is)){ ++is; }
  if(!s.empty() && is == s.end()){
    return atoi(s.c_str());   
  }else{
    return -1; 
  } 
}
