/*
* Modul 3
* Oppgave 3.1
*
* Med dette programmet tester vi hva som skjer når vi utløser en fork og hvilke output vi får på variabelen vi har definert. 
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int value = 5;

int main()
{
  pid_t pid;
  
  //utløser en fork
  pid = fork();
  
  //Sjekker om det er child prosessen
  if (pid == 0) { 
    
    //Legger til 15 på verdien
    value += 15;
    return 0;
  }
  
  //Sjekker om det er parent prosessen
  else if (pid > 0) { 
    //Verdien fra child prosessen vil ikke bli oppdatert i parent prosessen
    wait(NULL);
    //Siden verdien ikke er endret vil output bli 5.
    printf("PARENT: value = %d",value); 
    return 0;
  }
}
