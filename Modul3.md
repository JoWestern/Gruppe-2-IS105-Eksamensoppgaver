---Chapter 2 Modul 3, Oppgave 2.26---

In Section 2.3, we described a program that copies the contents of one file to a destination file. This program works by first prompting the user for the name of the source and destination files. Write this program using either the Windows or POSIX API. Be sure to include all necessary error checking, including ensuring that the source file exists. 

Once you have correctly designed and tested the program, if you used a system that supports it, run the program using a utility that traces system calls. Linux systems provide the strace utility, and Solaris and Mac OSX systems use the dtrace command. As Windows systems do not provide such features, you will have to trace through the Windows version of this program using a debugger. 

Hennviser til kildekode i repository fil: oppgave-2-26

<img width="1152" alt="Screen Shot 2021-04-27 at 11 59 03 AM" src="https://user-images.githubusercontent.com/79581649/116223635-02bb8c80-a750-11eb-9603-ca4d7e355a60.png">
(figur 1.1)

Først og fremst for å vite at alt skal fungere riktig når vi og andre skal bruke denne koden må vi sjekke hvilken versjon vi har.
Vi bruker kommandoen g++ --version for å få nødvendig informasjon, og som vi ser bruker vi i dette eksempelet clang versjon 12.0.0.


<img width="555" alt="Screen Shot 2021-04-27 at 11 52 59 AM" src="https://user-images.githubusercontent.com/79581649/116222787-2e8a4280-a74f-11eb-861d-1d973253e7ca.png">
(figur 1.2)

Vi begynte med å lage en C++ fil med navn oppgave2_26 som inneholder kildekoden. 
Deretter bruker vi kommandoen g++ for å kompilere koden, i C++ må vår .cpp kildefil bli kompilert til en a.out objektfil (vi kan også bruke -o for å gi den et eget navn) som er kjørbar. 
Kildefilen vår inneholder flere filer med #include kommandoen, disse er kalt filhoder eller header files ofte i form av .h, .hpp eller .hxx. 
Når vi kompilerer dette vil selve #include kommandoen bli byttet ut med alt innholdet til den inkluderte filen. 

Det første som skjer når kildefilen vår blir kompilert er at kompilatoren kjører forprosessor på den, dette skjer kun på kildefilen og ikke filhodene.
Forprosessoren vil bygge en oversettelsesenhet som den legger alt innhold den finner i #include og kildefilen.
Når den er ferdig vil selve kompileringensfasen starte og objektfilen blir produsert.

For å finne denne oversettelsesenheten kan man bruke g++ -E i terminalen, 
dette vil gi en fil med ekstremt mye innhold så den vil ikke bli referert til med bilde i denne oppagven.

Tilbake på figur 1.2 ser vi at etter kompileringen bruker vi ls kommandoen for å se at objektfilen vår har blitt generert, noe den har i form av a.out.
Deretter eksekverte vi filen ved å skrive ./a.out, og vi ser at koden fungerer siden vi får en prompt om skrive filnavnet vi vil kopiere. 
Etter å har gitt programmet filen den ønsker vil den begynne å overføre informasjonen fra txt-fra.txt til txt-til.txt, så får vi prompt om at filen er kopiert riktig, og programmet avslutter.

<img width="390" alt="Screen Shot 2021-04-27 at 12 38 02 PM" src="https://user-images.githubusercontent.com/79581649/116228341-757b3680-a755-11eb-891f-9295427e5d82.png">
(figur 1.3)

Til slutt åpnet vi filene for å se om oppgaven var fullført og som vi ser på figur 1.3 er teksten fra txt-fra overført til txt-til.


<img width="945" alt="Screen Shot 2021-04-27 at 1 36 46 PM" src="https://user-images.githubusercontent.com/79581649/116235032-a52e3c80-a75d-11eb-9bd6-0608a82ac02b.png">
(figur 1.4)

Her benytter vi DTrace for å se alle de forskjellige systemkallene programmet må be kernel utføre for å overføre informasjonen.


---Chapter 3, Modul 3, Oppgave 3.1---

Using the program shown in Figure 3.30, explain what the output will be at LINE A.

<img width="331" alt="Screen Shot 2021-04-27 at 2 45 18 PM" src="https://user-images.githubusercontent.com/79581649/116243422-36ee7780-a767-11eb-81b6-db0b0e9ac201.png">
(figur 2.1)

Dette er fork() programmet fra boken. Etter vi hadde lagd en fil med denne koden og skulle kompilere det i terminalen oppstod det en rekke feilmeldinger om pid og wait kommandoene. Dette skjønte vi ikke helt hvorfor oppstod siden programmet kommer fra læreboka, men til slutt fikk vi testet med å legge til #include <sys/wait.h> og da fungerte programmet slik det skulle.

Etter endringene ble kildekoden til oppgaven vist på figur 2.1.1:

<img width="267" alt="Screen Shot 2021-04-27 at 2 58 23 PM" src="https://user-images.githubusercontent.com/79581649/116245291-1cb59900-a769-11eb-8478-d4aad19dba0b.png">

(figur 2.1.1)

Beskrivelse av hvordan koden utføres er beskrevet og forklart i innleveringsdokumentet. 


<img width="431" alt="Screen Shot 2021-04-27 at 2 41 11 PM" src="https://user-images.githubusercontent.com/79581649/116242906-ae6fd700-a766-11eb-81df-26e1f5250cfc.png">

(figur 2.2)

For å teste om programmet fungerer så la vi inn kildekoden i en fil i .cpp format, og kompilerte det med gcc kommandoen som lagde et a.out objekt som vi kjørte med ./a.out. 
Spørsmålet spør om hvilke output det er på linje A, noe vi vet skal bli at verdien skal være lik 5. som vi ser på figur 2.2 er utfallet etter koden har gjennomført er value = 5, som bekrefter at teorien vår er riktig. 



---Chapter 3 Modul 3, Oppgave 3.2---

Including the initial parent process, how many processes are created by the program shown in Figure 3.31 (referert til som figur 3.1 her)?


<img width="317" alt="Screen Shot 2021-04-27 at 3 19 46 PM" src="https://user-images.githubusercontent.com/79581649/116248286-05c47600-a76c-11eb-8a18-db91025ed779.png">

(figur 3.1)

På figuren ser vi at tre fork() kommandoer blir utført, dette har vi forklart at skal ende opp med å bli 8 prosesser til sammen. For å finne ut om dette skjer må vi sjekke status på alle prosessene når programmet kjøres. På figur 3.1.2 ser vi at under kolonnen S ser vi at akkuratt 8 fork prosesser har blitt utført etter hverandre. 


<img width="794" alt="bilde" src="https://user-images.githubusercontent.com/79581649/116384200-ebe06d00-a817-11eb-99bd-b71d0e8a151c.png">

(figur 3.1.2)


---Chapter 3 Modul 3, Oppgave 3.19---

Using either a UNIX or a Linux system, write a C program that forks a child process that ultimately becomes a zombie process. This zombie process must remain in the system for at least 10 seconds. Process states can be obtained from the command ps −l The process states are shown below the S column; processes with a state of Z are zombies. The process identifier (pid) of the child process is listed in the PID column, and that of the parent is listed in the PPID column. Perhaps the easiest way to determine that the child process is indeed a zombie is to run the program that you have written in the background (using the &) and then run the command ps −l to determine whether the child is a zombie process. Because you do not want too many zombie processes existing in the system, you will need to remove the one that you have created. The easiest way to do that is to terminate the parent process using the kill command. For example, if the process id of the parent is 4884, you would enter kill −9 4884.

<img width="497" alt="Screen Shot 2021-04-28 at 10 41 22 AM" src="https://user-images.githubusercontent.com/79581649/116374146-4f659d00-a80e-11eb-8979-931ce9499508.png">

(figur 3.2)

Kildekoden på figur 3.2 viser framgangsmåten for hvordan en zombie prosess blir dannet. For at zombien skal bli dannet i vår kode så må child prosessen avsluttes uten at parent prosessen har utløst en wait() kommando. Her vil child prosessen utløse en exit() som sender et signal til parent prosessen som ikke blir oppfattet så child prosessen skal bli en zombie prosess, men dette må vi sjekke i terminalen for å være sikre. 

<img width="801" alt="Screen Shot 2021-04-28 at 11 12 36 AM" src="https://user-images.githubusercontent.com/79581649/116379544-65299100-a813-11eb-89cc-bd48236f1e47.png">

(figur 3.3)

Etter å ha kompilert koden og lagd et objekt, så skal vi kjøre koden ./zombie.o&. Koden kjører med tegnet "&" bak som betyr at den skal kjøre i bakgrunnen, så vi kan skrive kommandoen ps -l samtiding for å se prosesstatus. Etter ps -l kommandoen er utført får vi en liste over prosessen som kjører, hvor vi må lete under "S" kolonnen. Der ser vi en prosess som har status "zn", som er zombien vi ser etter. Så får vi en prompt om at parent prosessen er ferdig og statusen viser at prosessene er avsluttet. 



---Chapter 3 Modul 3, Oppgave 3.21---

The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm: The conjecture states that when this algorithm is continually applied, all positive integers will eventually reach 1. For example, if n = 35, the sequence is35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1. Write a C program using the fork() system call that generates this sequence in the child process. The starting number will be provided from the command line. For example, if 8 is passed as a parameter on the com-mand line, the child process will output 8, 4, 2, 1. Because the parent and child processes have their own copies of the data, it will be necessary for the child to output the sequence. Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. Per-form necessary error checking to ensure that a positive integer is passed on the command line. 

<img width="509" alt="bilde" src="https://user-images.githubusercontent.com/79581649/116386857-7aee8480-a81a-11eb-9a53-84304474631f.png">

(figur 3.4)











