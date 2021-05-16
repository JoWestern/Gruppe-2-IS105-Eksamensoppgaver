import java.net.*;
import java.io.*;

public class EchoServer {
	public static void main(String[] args) throws IOException {
	
 	ServerSocket serverSock = null;

    // setter opp socket på port 8899
	try {
	serverSock = new ServerSocket(8899);
	}catch(IOException ie) {
	System.out.println("[-]Cant listen on port number 8899");
	System.exit(1);
	}

      // Venter på koblingen og bruker try catch for å finne IOExeptions, slik at programmer ikke krasjer hvis feil oppstår
	Socket clientSock = null;
	System.out.println("[+]Listening for connection...");
	try {
	clientSock = serverSock.accept();
	}catch(IOException ie) {
	System.out.println("[-]Accept failed");
	System.exit(1);
	}
  
      // Koblingen er riktig og venter på input fra klient
	System.out.println("[+]Connection successful");
	System.out.println("[+]Listening for input");

     // definerer input og output variabler 
	PrintWriter output = new PrintWriter(clientSock.getOutputStream(), true);
	BufferedReader input = new BufferedReader(new InputStreamReader(clientSock.getInputStream()));

	String inputLine;
    //bruker while loop for å vente på klientens tekst og skriver den på serveren og sender tilbake til klienten.
	while((inputLine = input.readLine()) != null){
	System.out.println("Server: " + inputLine);
	output.println(inputLine);

     // hvis meldingen er "bye" avsluttes programmet
	if(inputLine.equals("bye")){
		break;
	}
	}	
	
    // VIKTIG! lukke varablene i slutten av programmet
	output.close();
	input.close();
	clientSock.close();
	serverSock.close();
	
	}
}
