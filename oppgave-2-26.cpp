                                                       /* --Kildekode til Prgogramming Problems-- */
//Modul 3

//Oppgave 2.26

/**
 * Demonstrasjonsprogram som kopeierer innhold fra en fil til en annen fil, som i eksempelet i modul3.md filen heter txt-fra.txt og txt-til.txt
 **/
 
 
//#include importerer de nødvendige hodefilene
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
// importerer biblioteket til input/output tjenester
#include <iostream>

// både cout og cin er definert inni std (standardbiblioteket) for å brukes i koden
using namespace std;

/*definerere main funskjonen
siden vi vil returnere et nummer som sjekker
om alt fungerer som det skal
så definerer vi en int main() funksjon*/
int main(int argc, char *argv[]) {
	
   //definerer variablene for filnavn
   
   string inputFile, outputFile;
   int inputFD, outputFD;     
    ssize_t bytesRd, bytesWr; //samler bytes til read og written
    int bufferSize = 32768;  //definerer buffersize 2^15
    char buffer[bufferSize];  
    char filenameOut[256], filenameIn[256];
 

   //Passer på at filen som blir brukt for input er tilstede i det gjeldene arbeidskatalogen (working directory)
   //Anskaffer inputfilens navn, skriver en prompt til skjermen og aksepterer inputen
   
   cout << "First we need a file to copy from (ex: input.txt)" << endl;
   cout << "Enter the name of the input file" << endl;
   cin >> inputFile;
   
   //Anskaffer outputfilens navn og skriver en prompt til skjermen, akspeterer input
   
   cout << "Then we need another file as destination of copied data (ex: output.txt)" << endl; 
   cout << "Enter the name of the input file" << endl;
   cin >> outputFile;
   
   //konverterer string til char 
   
   strcpy(filenameIn, inputFile.c_str());
   strcpy (filenameOut, outputFile.c_str());
	
    
    /* Åpner inputfilen, hvis filen ikke eksisterer avbrytes det*/
    
    inputFD = open (filenameIn, O_RDONLY);    
    if (inputFD == -1) {
        perror ("Error while opening Input File");
        return 2;

    }
    //Lager outputfil kun hvis den ikke eksisterer
    
    outputFD = open(filenameOut, O_WRONLY | O_CREAT, 0644);
    if(outputFD == -1){
        perror("Error while opening Output File");
        return 3;
    }

    //Leser fra inputfilen og skriver det til outputfilen helt fram til read-kommandoen feiler
    
    while((bytesRd = read (inputFD, &buffer, bufferSize)) > 0){
        bytesWr = write (outputFD, &buffer, (ssize_t) bytesRd);
        if(bytesWr != bytesRd){
            perror("Error in writing");
            return 4;

        }else {
        
          //Skriver fullført beskjed til skjermen
          
          cout<<"File copied correctly";
		} 
    }

     /* Lukker filbeskrivelsen. */
    close (inputFD);
    close (outputFD);
    
    //vanlig avslutning
    return 0;

}
