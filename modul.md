Hei 
Kildekode til hvert eksempel ligger i form av oppgavex-x. i repository.
   
   ---Chapter 2 Modul 3, Oppgave 2.26---

In Section 2.3, we described a program that copies the contents of one file to a destination file. This program works by first prompting the user for the name of the source and destination files. Write this program using either the Windows or POSIX API. Be sure to include all necessary error checking, including ensuring that the source file exists. 

Once you have correctly designed and tested the program, if you used a system that supports it, run the program using a utility that traces system calls. Linux systems provide the strace utility, and Solaris and Mac OSX systems use the dtrace command. As Windows systems do not provide such features, you will have to trace through the Windows version of this program using a debugger. 

Hennviser til kildekode i repository fil: oppgave2-26

<img width="1152" alt="Screen Shot 2021-04-27 at 11 59 03 AM" src="https://user-images.githubusercontent.com/79581649/116223635-02bb8c80-a750-11eb-9603-ca4d7e355a60.png">
(figur 1.1)

Først og fremst for å vite at alt skal fungere riktig når vi og andre skal bruke denne koden må vi sjekke hvilken versjon vi har.
Vi bruker kommandoen g++ --version for å få nødvendig informasjon, og som vi ser bruker vi i alle eksempelene clang versjon 12.0.0.


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
dette vil gi et output med ekstremt mye innhold så den vil ikke bli referert til med bilde i denne oppgaven.

Tilbake på figur 1.2 ser vi at etter kompileringen bruker vi ls kommandoen for å se at objektfilen vår har blitt generert, noe den har i form av a.out.
Deretter eksekverte vi filen ved å skrive ./a.out, og vi ser at koden fungerer siden vi får en prompt om skrive filnavnet vi vil kopiere. 
Etter å har gitt programmet filen den ønsker vil den begynne og overføre informasjonen fra txt-fra.txt til txt-til.txt, så får vi prompt om at filen er kopiert riktig, og programmet avslutter.

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

For å teste om programmet fungerer la vi inn kildekoden i en fil i .cpp format, og kompilerte det med gcc kommandoen som lagde et a.out objekt som vi kjørte med ./a.out. 
Spørsmålet spør om hvilke output det er på linje A, noe vi vet skal bli at verdien skal være lik 5. Vi ser dette på figur 2.2 hvor utfallet når koden har gjennomført er value = 5, som bekrefter at output på linje A er 5.


    ---Chapter 3 Modul 3, Oppgave 3.2---

Including the initial parent process, how many processes are created by the program shown in Figure 3.31 (referert til som figur 3.1 her)?


<img width="317" alt="Screen Shot 2021-04-27 at 3 19 46 PM" src="https://user-images.githubusercontent.com/79581649/116248286-05c47600-a76c-11eb-8a18-db91025ed779.png">

(figur 3.1)

På figuren ser vi at tre fork()-kommandoer blir utført, dette har vi forklart at skal ende opp med å bli 8 prosesser til sammen. For å finne ut om dette skjer må vi sjekke status på alle prosessene når programmet kjøres. På figur 3.1.2 ser vi at under kolonnen S og cmd har akkuratt 8 fork prosesser blitt utført etter hverandre. 


<img width="794" alt="bilde" src="https://user-images.githubusercontent.com/79581649/116384200-ebe06d00-a817-11eb-99bd-b71d0e8a151c.png">

(figur 3.1.2)


    ---Chapter 3 Modul 3, Oppgave 3.19---

Using either a UNIX or a Linux system, write a C program that forks a child process that ultimately becomes a zombie process. This zombie process must remain in the system for at least 10 seconds. Process states can be obtained from the command ps −l The process states are shown below the S column; processes with a state of Z are zombies. The process identifier (pid) of the child process is listed in the PID column, and that of the parent is listed in the PPID column. Perhaps the easiest way to determine that the child process is indeed a zombie is to run the program that you have written in the background (using the &) and then run the command ps −l to determine whether the child is a zombie process. Because you do not want too many zombie processes existing in the system, you will need to remove the one that you have created. The easiest way to do that is to terminate the parent process using the kill command. For example, if the process id of the parent is 4884, you would enter kill −9 4884.

<img width="497" alt="Screen Shot 2021-04-28 at 10 41 22 AM" src="https://user-images.githubusercontent.com/79581649/116374146-4f659d00-a80e-11eb-8979-931ce9499508.png">

(figur 3.2)

Kildekoden på figur 3.2 viser framgangsmåten for hvordan en zombie prosess blir dannet. For at zombien skal bli dannet i vår kode så må child prosessen avsluttes uten at parent prosessen har utløst en wait() kommando. Her vil child prosessen utløse en exit() som sender et signal til parent prosessen som ikke blir oppfattet så child prosessen skal bli en zombie prosess, men dette må vi sjekke i terminalen for å være sikre. 

<img width="801" alt="Screen Shot 2021-04-28 at 11 12 36 AM" src="https://user-images.githubusercontent.com/79581649/116379544-65299100-a813-11eb-89cc-bd48236f1e47.png">

(figur 3.3)

Etter å ha kompilert koden og lagd et objekt, så skal vi kjøre koden ./zombie.o&. Koden kjører med tegnet "&" bak som betyr at den skal kjøre i bakgrunnen, så vi kan skrive kommandoen ps -l samtiding for å se prosesstatus. Etter ps -l kommandoen er utført får vi en liste over prosessene som kjører, hvor vi må lete under "S" kolonnen. Der ser vi en prosess som har status "zn", som er zombien vi ser etter. Til slutt får vi en prompt om at parent prosessen er ferdig og statusen viser at prosessene er avsluttet. 



    ---Chapter 3 Modul 3, Oppgave 3.21---

The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm: The conjecture states that when this algorithm is continually applied, all positive integers will eventually reach 1. For example, if n = 35, the sequence is 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1. Write a C program using the fork() system call that generates this sequence in the child process. The starting number will be provided from the command line. For example, if 8 is passed as a parameter on the com-mand line, the child process will output 8, 4, 2, 1. Because the parent and child processes have their own copies of the data, it will be necessary for the child to output the sequence. Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. Per-form necessary error checking to ensure that a positive integer is passed on the command line. 

<img width="509" alt="bilde" src="https://user-images.githubusercontent.com/79581649/116386857-7aee8480-a81a-11eb-9a53-84304474631f.png">

(figur 3.4)

For at koden skal kjøre trenger den et argument i form av heltall som den skal regne ut med collatz conjecture. Hvis vi ikke gir den noe tall vil den gi beskjed om at den trenger et argument. Etter vi har gitt den tallet vil den begynne å regne ut ved å bruke teorien bak the collatz conjecture. I eksempelet på figur 3.4 ga vi programmet tallet 10. Programmet begynner da med å sjekke om det er et partall, hvis det er sant vil neste tall være halvparten, hvis tallet nå er et oddetall vil det bli tredoblet og addert med 1, og dette fortsetter fram til tallet blir 1. Prinsippet bak denne formelen er at uansett hvilket positivt heltall n man putter inn vil svaret alltid bli 1. 

![bilde](https://user-images.githubusercontent.com/79581649/117549931-735e8500-b03d-11eb-9fd2-d3e614828075.png)

Her har kodet blitt kjørt i WSL på Windows. Det var ikke noe merkbar forskjell på utførelse av koden på Windows i forhold til MacOS, det var heller ingen komplikasjoner eller feilmeldinger med koden etter den var tatt fra repository med git pull. Siden WSL er Windows Subsystem for Linux skal kodene fungere selv om de er overført mellom operativsystemene. Derimot har Linuxkode noen systemkall og #include mapper i C-språkene som ikke alltid er kompitable på Windows, noe som har gjort at det oppstått problemer i andre oppgaver. Her var koden plettfri mest sannsynlig fordi det er en enkel utregningsalgoritme uten krevende og dype systemkall.


    ---Chapter 3 Modul 3, Oppgave 3.22---

In Exercise 3.21, the child process must output the sequence of numbers generated from the algorithm specified by the Collatz conjecture because the parent and child have their own copies of the data. Another approach to designing this program is to establish a shared-memory object between the parent and child processes. This technique allows the child to write the contents of the sequence to the shared-memory object. The parent can then output the sequence when the child completes. Because the memory is shared, any changes the child makes will be reflected in the parent process as well. This program will be structured using POSIX shared memory as described in Section 3.5. 

1. The parent process will progress through the following steps: Create the child process and wait for it to terminate. 

3. Output the contents of shared memory. 

4. Remove the shared-memory object.  

One area of concern with cooperating processes involves synchronization issues. In this exercise, the parent and child processes must be coordinated so that the parent does not output the sequence until the child finishes execution. These two processes will be synchronized using the wait() system call: the parent process will invoke wait(), which will suspend it until the child process exits. 

<img width="552" alt="Screen Shot 2021-04-28 at 2 01 29 PM" src="https://user-images.githubusercontent.com/79581649/116400467-5bf7ee80-a82a-11eb-83e3-4eb01dd90a56.png">

(figur 3.5)

Denne koden skal også utføre collatz conjecture men denne gangen bruker vi Posix shared memory. Dette er et rammeverk for inter-prosess kommunikasjon (IPC). Her kan to eller flere jobber lese og skrive i et delt område av minne. Posix skiller seg ut ifra andre IPC-strukturer som socket og pipe, siden den ikke alltid krever kopi av overhead. Essensen med shared memory er at det blir skapt et shared memory objekt med kommandoen shm_open(), så vil størrelsen bli bestemt av ftruncate(). Deretter må objektet bli kartlagt mmap() og MAP_SHARED, så kan man lese og skrive i dette objektet. Programmet vil så kjøre en fork() som skaper child prosessen som utfører selve collatz conjecture. 


    ---Chapter 3 Modul 3, Oppgave 3.23---

Section 3.6.1 describes port numbers below 1024 as being well known—that is, they provide standard services. Port 17 is known as the quote-of-the-day service. When a client connects to port 17 on a server, the server responds with a quote for that day. Modify the date server shown in Figure 3.21 so that it delivers a quote of the day rather than the current date. The quotes should be printable ASCII characters and should contain fewer than 512 characters, although multiple lines are allowed. Since port 17 is well known and therefore un-available, have your server listen to port 6017. The date client shown in Figure 3.22 can be used to read the quotes returned by your server. 

<img width="342" alt="Screen Shot 2021-04-28 at 5 38 55 PM" src="https://user-images.githubusercontent.com/79581649/116432165-b56f1600-a848-11eb-86b8-05d864bef29a.png">

<img width="384" alt="Screen Shot 2021-04-28 at 5 42 10 PM" src="https://user-images.githubusercontent.com/79581649/116432711-1991da00-a849-11eb-82b0-b2a6c124454c.png">

(figur 3.6)

Denne koden baserer seg på regnemaskinens port 17, også kjent som Qoute of the Day (QOTD) protokollen. Denne tjenesten er en del av TCP/IP protokollene. En host kan via port 17 koble seg til en server som støtter QOTD-protokollen og få output av dagens qoute. På figur 3.6 ser vi at når programmet er startet vil den vente på en kobling på denne porten. Portene fra 0-1023 er kjent som systemportene,  de blir brukt av systemprosesser som gir ofte brukte netverkstjenester. På de fleste Unixlignende operativsystemene må man ha administrativ tilgang for å koble seg til en av disse systemportene. Får å gi vårt program et signal på port 17, bruker vi Netcat kommandoen nc localhost 17. Netcat er et redskap for å lese og skrive data over nettverkskoblinger. Den har mange funksjoner hvor en av de viktigste er debugging, siden den kan lage nesten hvilken som helst kobling man trenger for å teste et program. Det er også det vi gjør i koden for å sende signalet. Siden vi sender dette singalet, trenger vi ikke høre på port 6017. Etter vi bruker kommandoen vil programmet kjøre og må lese av tekstdokumentet qotd.txt for å plukke ut en tilefldig qoute, som den da sender som et output til brukeren.

   
    ---Chapter 3 Modul 3, Oppgave 3.25---
 
An echo server echoes back whatever it receives from a client. For example, if a client sends the server the string “Hello there!”, the server will respond with Hello there! Write an echo server using the Java networking API described in Section 3.6.1. This server will wait for a client connection using the accept() method. When a client connection is received, the server will loop, per-forming the following steps: Read data from the socket into a buffer. Write the contents of the buffer back to the client. The server will break out of the loop only when it has determined that the client has closed the connection. The date server shown in Figure 3.21 uses the java.io.BufferedReader class. Buffered Reader extends the java.io. Reader class, which is used for reading character streams. However, the echo server cannot guarantee that it will read characters from clients; it may receive binary data as well. The class java.io.InputStream deals with data at the byte level rather than the character level. Thus, your echo server must use an object that extends java.io.InputStream. The read() method in the java.io.InputStream class returns −1 when the client has closed its end of the socket connection. 

 
<img width="978" alt="bilde" src="https://user-images.githubusercontent.com/79581649/117145829-de952680-adb3-11eb-8bae-0fecc8a4143d.png">
 
Dette programmer benytter seg av Java sin BufferedReader og InputStream for å lese informasjon som en klien sender til en echo server. I programmet vårt kan vi sende en string eller data til serveren, som vil godkjenne at den har mottat meldingen, og outputte dette tilbake til klienten. I programmet setter vi opp en ServerSocket som skal lytte på port 8899. Her vil den begynne med en Try - Catch for å se på porten den skal kobles på. Noe vi gir den med kommandoen "nc localhost 8899". Så vil den koble seg på og vente til neste Try - Catch som venter på at klienten skal koble seg på porten. Så bruker vi PrintWriter sammen med OutputStream. Den vil da koble seg til klienten mens den feilsøker med Try - Catch kommandoen etter problemer. Når koblingen er satt opp vil en while loop forsørge at serveren konstant hører etter input fra klienten, helt fram til klienten skriver "bye", hvor den da utløser en break og stopper programmet.
  
   
   
    ---Chapter 3 Modul 3, Oppgave 3.26---
    
3.26 Design a program using ordinary pipes in which one process sends a string message to a second process, and the second process reverses the case of each character in the message and sends it back to the first process. For example, if the first process sends the message Hi There, the second process will return hI tHERE. This will require using two pipes, one for sending the original message from the first to the second process and the other for sending the modified message from the second to the first process. You can write this program using either UNIX or Windows pipes. 

<img width="437" alt="bilde" src="https://user-images.githubusercontent.com/79581649/116992153-e5e60280-acd5-11eb-9fc4-0494daca05a3.png">

Dette programmet tar meldingen "Hello There" og skal endre hver bokstav fra uppercase til lowercase og omvendt. For å gjøre dette vil programmet loope teksten gjennom en array med chars for å gjøre endringen. Så vil main metoden lage to pipes og kaller en fork. En pipe er en form for enveis kommunikasjon i UNIX OS. En pipe vil sende informasjon fra en program prosess til en annen, men i motsetning til andre IPC, er pipes enveiskommunikasjon. Child prosessen vil lukke pipen, lese av meldingen og omstrukturere meldingen ved å kjøre switchCase metoden. Deretter vil parent prosessen lukke pipen, lese meldingen og printe det til brukeren. Outputet vi får her vil være "hI THERE!".


![bilde](https://user-images.githubusercontent.com/79581649/117549344-3218a600-b03a-11eb-90ef-d1277a6e670c.png)

Her er den samme koden kjørt på Windows OS. Koden er kjørt fra WSL og det var forventet at det skulle oppstå problemer med feilmeldinger, men programmet funket rett ut av github. Dette var overaskende fordi det er mye komplikasjoner med å bytte fra Mac som er mer Unix/Linux lignende, noe Windows kan slite med å være kompatibel med. Koden her oppnådde akkurat det samme som på Mac-eksempelet.



    ---Chapter 2 Modul 4, Oppgave P12---
    
Write a simple TCP program for a server that accepts lines of input from a client and prints the lines onto the server’s standard output. (You can do this by modifying the TCPServer.py program in the text.) Compile and execute your program. On any other machine that contains a Web browser, set the proxy server in the browser to the host that is running your server program; also configure the port number appropriately. Your browser should now send its GET request messages to your server, and your server should display the messages on its standard output. Use this platform to determine whether your browser generates conditional GET messages for objects that are locally cached.

<img width="1057" alt="bilde" src="https://user-images.githubusercontent.com/79581649/117005331-66f9c580-ace7-11eb-9369-dc1f1251db32.png">

Dette programmet består av to filer, en socket_server og en socket_client. Først må vi sette opp serveren ved å kjøre socket_server. Den setter opp en server som lytter på port 5000. Så må vi bruke socket_client som skal koble seg til den samme porten. Ved å kjøre klientprogrammet vil den automatisk koble seg på porten siden det er satt opp i kildekoden. Når koblingen er akseptert kan klienten skrive input til serveren som mottar et output, hvor serveren kan svare med sitt eget input som klienten tar imot som output. 


    ---Chapter 2 Modul 4, Assignment 2---

In this programming assignment, you will write a client ping program in Python. Your client will send a simple ping message to a server, receive a corresponding pong message back from the server, and determine the delay between when the client sent the ping message and received the pong message. This delay is called the Round Trip Time (RTT). The functionality provided by the client and server is similar to the functionality provided by standard ping program available in modern operating systems. However, standard ping programs use the Internet Control Message Protocol (ICMP) (which we will study in Chapter 4). Here we will create a nonstandard (but simple!) UDP-based ping program. Your ping program is to send 10 ping messages to the target server over UDP. For each message, your client is to determine and print the RTT when the corresponding pong message is returned. Because UDP is an unreliable protocol, a packet sent by the client or server may be lost. For this reason, the client cannot wait indefinitely for a reply to a ping message. You should have the client wait up to one second for a reply from the server; if no reply is received, the client should assume that the packet was lost and print a message accordingly. In this assignment, you will be given the complete code for the server (available in the companion Web site). Your job is to write the client code, which will be very similar to the server code. It is recommended that you first study carefully the server code. You can then write your client code, liberally cutting and pasting lines from the server code.    
    
    
<img width="634" alt="bilde" src="https://user-images.githubusercontent.com/79581649/117011415-1b96e580-acee-11eb-9c0b-d99ce71b805a.png">
  
Dette er også et program hvor man først må sette opp og starte en server, noe vi satt opp i terminalen. Når vi kjører klientprogrammet og gir den riktig argumenter i form av hosten sitt navn og porten serveren kjører på kan vi oppnå en kobling. Når vi kjøren den koden med Python3 kommandoen vi den begynne å pinge serveren. Pinging fungerer litt på samme måte som sonar, hvor du sender ut et signal og sjekker hvor lang tid det tar før den returnerer. I vår kode skal vi pinge serveren 10 ganger og finne ut hvor lang tid det tar å kontakte serveren. For hvert ping vil serveren genere et tilfeldig nummer mellom 0 og 10, hvis dette nummeret er mindre enn 4 vil serveren sende en timeout melding. Hvis det er større enn 4 vil den sende tilbakemelding med round trip tiden (RRT) til klienten.  RTT er hvor lang tid det tar for et signal å bli sendt pluss tiden det tar å få godkjenning at signalet er mottat. Til slutt får vi se alle pingsene serveren mottok som et output i terminalen.
