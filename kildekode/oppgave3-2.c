/*
* Modul 3
* Oppgave 3.2
*
* Med denne koden vil vi se hva som skjer når vi utløser 3 fork() systemkall etter hverandre,
* vi er nysgjerrige på hvor mange parent og child prosesser vi får til sammen.
*/

// Importerer fra biblioteket
#include <stdio.h>
#include <unistd.h>

int main() {
  fork(); // kaller første fork()
  
  fork(); // kaller andre fork()
  
  fork(); // kaller tredje fork()
  
  /*
  * Her kunne vi også hatt et output for å se hvor mange prosesser som
  * kjører men siden dette er et eksempel fra pensumsboka valgte vi
  * ikke å ta det med.
  */
  
  return 0;
}
