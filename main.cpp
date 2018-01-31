#include <cstdlib>
#include <iostream>
#include "palestra.h"
#include "funzioni.h"

using namespace std;

int main(int argc, char *argv[])
{
  srand (time(0)); //così viene chiamato una sola volta e il random è veramente casuale
  Palestra p("myGym");
  p.menu_scelta();
  system("PAUSE");
  return EXIT_SUCCESS;
}
