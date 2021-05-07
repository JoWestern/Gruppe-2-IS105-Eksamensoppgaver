#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int value = 5;

int main()
{
  pid t pid;
  
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
