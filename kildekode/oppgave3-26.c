/*
* Modul 3
* Oppgave 3.26
*
* Denne koden skal ta imot en melding og bytte om slik at upper case bokstaver blir lower case og omvendt.
*/


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// Metode for å bytte uppercase til lowercase og motsatt. 
//Denne metoden vil loope gjennom en array og bytte størrelsen på chars, dette forgår i child prosessen.
void switchCases(char* message) {
    int i = 0;
    while(message[i] != '\0') {
        if(message[i] > 64 && message[i] < 91) {
            message[i]+=32;
        }
        else if(message[i] > 96 && message[i] < 123) {
            message[i]-=32;
        }
        i++;
    }
}
 
//Main metoden begynner med å lage to pipes, så vil den lage en fork.
//Child prosessen vil lukke pipen og lese meldingen og skrive det til pipen. 
//Så vil parent prosessen lukke pipen og lese den og gi et output av svaret.
int main(int argc, char** argv){
    int fd[2];
    char message[10] = "Hi there!";
    if (pipe(fd) == -1) {
        printf("There was an error in pipe creation. Program will now exit.\n");
        return -1;
    }
    pid_t child;
    child = fork();
    if(child < 0) {
        printf("Forking failed.");
        return -1;
    }
    if(child == 0) {
        close(fd[0]);
        switchCases(message);
        write(fd[1],message,10);
    }
    else if(child > 0) {
        close(fd[1]);
        char read_buffer[10];
        read(fd[0],read_buffer,10);
        printf("%s",read_buffer);
    }
    return 0;
}
