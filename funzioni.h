#ifndef __FUNZIONI_H__
#define __FUNZIONI_H__
#include <string.h>

using namespace std;

typedef enum TipoObiettivo {RIABILITAZIONE, DIMAGRIMENTO, AUMENTO_MASSA};
typedef enum Muscoli {PETTORALI,TRICIPITI,DORSALI,BICIPITI,SPALLE,ADDOMINALI,QUADRICIPITI,FEMORALI,POLPACCI,CUORE};
int random(int max, int min);
void stampa_obiettivo(TipoObiettivo obiettivo);
void stampa_muscolo(Muscoli _muscolo);
int string_to_int(string s);

#endif

