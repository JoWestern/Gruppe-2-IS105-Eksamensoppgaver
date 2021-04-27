Chapter 2 Modul 3

Oppgave 2.26

In Section 2.3, we described a program that copies the contents of one file to a destination file. This program works by first prompting the user for the name of the source and destination files. Write this program using either the Windows or POSIX API. Be sure to include all necessary error checking, including ensuring that the source file exists. 

Once you have correctly designed and tested the program, if you used a system that supports it, run the program using a utility that traces system calls. Linux systems provide the strace utility, and Solaris and Mac OSX systems use the dtrace command. As Windows systems do not provide such features, you will have to trace through the Windows version of this program using a debugger. 

Hennviser til kildekode i repository fil: oppgave-2-26

<img width="1152" alt="Screen Shot 2021-04-27 at 11 59 03 AM" src="https://user-images.githubusercontent.com/79581649/116223635-02bb8c80-a750-11eb-9603-ca4d7e355a60.png">
Figur 1.1

Først og fremst for å vite at alt skal fungere riktig når vi og andre skal bruke denne koden må vi sjekke hvilken versjon vi har.
Vi bruker kommandoen g++ --version for å få nødvendig informasjon, og som vi ser bruker vi i dette eksempelet clang versjon 12.0.0.


<img width="555" alt="Screen Shot 2021-04-27 at 11 52 59 AM" src="https://user-images.githubusercontent.com/79581649/116222787-2e8a4280-a74f-11eb-861d-1d973253e7ca.png">
Figur 1.2

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
Figur 1.3

Til slutt åpnet vi filene for å se om oppgaven var fullført og som vi ser på figur 1.3 er teksten fra txt-fra overført til txt-til.


<img width="945" alt="Screen Shot 2021-04-27 at 1 36 46 PM" src="https://user-images.githubusercontent.com/79581649/116235032-a52e3c80-a75d-11eb-9bd6-0608a82ac02b.png">
Figur 1.4

Her benytter vi DTrace for å se hvordan kjøringen av programmet blir utført.


Chapter 3, Modul 3

Oppgave 3.1

Using the program shown in Figure 3.30, explain what the output will be at LINE A.

<img width="331" alt="Screen Shot 2021-04-27 at 2 45 18 PM" src="https://user-images.githubusercontent.com/79581649/116243422-36ee7780-a767-11eb-81b6-db0b0e9ac201.png">
Figur 2.1
Dette er fork() programmet fra boken. Etter vi hadde lagd en fil med denne koden og skulle kompilere det i terminalen oppstod det en rekke feilmeldinger om pid og wait kommandoene. Dette skjønte vi ikke helt hvorfor oppstod siden programmet kommer fra læreboka, men til slutt fikk vi testet med å legge til #include <sys/wait.h> og da fungerte programmet slik det skulle.

Etter endringene ble kildekoden til oppgaven seende slik ut:

<img width="267" alt="Screen Shot 2021-04-27 at 2 58 23 PM" src="https://user-images.githubusercontent.com/79581649/116245291-1cb59900-a769-11eb-8478-d4aad19dba0b.png">

Figur 2.1.2



<img width="431" alt="Screen Shot 2021-04-27 at 2 41 11 PM" src="https://user-images.githubusercontent.com/79581649/116242906-ae6fd700-a766-11eb-81df-26e1f5250cfc.png">

Figur 2.2








