#include <cstdlib>
#include <iostream>
#include "palestra.h"
#include "funzioni.h"

using namespace std;

int main(int argc, char *argv[])
{
  srand (time(0)); //cos� viene chiamato una sola volta e il random � veramente casuale
  Palestra p("myGym");
  p.menu_scelta();
  system("PAUSE");
  return EXIT_SUCCESS;
}
