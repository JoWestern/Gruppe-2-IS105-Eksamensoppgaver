/*
* Modul 3
* Oppgave 3.21
*
* Med denne koden ønsker å få et input fra klienten i form av heltall (int),
* og bruke collatz conjecture algoritme for å regne det ut.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>


int main(int argc, char **argv){
   int num;
  
   //Sjekker om det har kommet argument i kommandolinjen - og gir beskjed
   if(argc==1){
        printf("\nNo extra command line argument passed other than program name.\n\n");
        exit(0);
    }
  

    // Konverterer char til integer
    num = atoi(argv[1]);
  
    //Sjekker om argumentet er et positivt heltall eller ikke
    if(num <= 0){
       printf("\nThe number should be a positive interger.\n\n");
        exit(0);
    }
  
    if(fork() == 0){
       //Child prosessen
       while(num > 1){
           printf("%d ", num);
           if(num %2 == 0)
               num = num / 2;
           else
               num = 3 * num + 1;      
       }
       printf("1\n\n");
    }
    else{
       //Parent prosessen - Venter for at child prosessen skal avslutte
       wait(NULL);
    }
  
    return 0;
}
