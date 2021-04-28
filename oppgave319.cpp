#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {

        pid_t pid;

        //lager en child prosess og lagrer PID som skal returneres
        pid = fork();

        if (pid > 0)
        {
                printf("Dette er parent prosessen");
                sleep(10);
        }
        else if (pid == 0)
        //denne koden blir utført av child prosessen
        {
                printf("Dette er child prosessen");
                //avslutter child prosessen
                exit(0);
        }

        return 0;
}
