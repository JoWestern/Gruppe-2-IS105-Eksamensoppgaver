# Modul 3
# Assignment 2

# Dette er UDP klientprogrammet
# Dette sender melding til serveren,
# og kalkulerer RTT-tiden til de forskjellige meldingene.
# Så printer den RTT til hver melding
# Hvis ventetiden er mer enn ett sekund vil pakken bli ansett som mistet og det blir utløst en timeout

# Importerer socket module
# Importerer time og ctime for å få tiden
# Importerer sys for å få argumentene
from socket import *
from time import time, ctime
import sys

# Denne inputer tre argumenter

if (len(sys.argv) != 3):
    print(len(sys.argv))
    print("Wrong number of arguments.")
    print("Use: UDPPingClient.py <server_host> <server_port>")
    sys.exit()

# klargjør nettverkssocketen
serverHost, serverPort = sys.argv[1:]
clientSocket = socket(AF_INET, SOCK_DGRAM)
clientSocket.settimeout(1)

# Sender og tar imot de 10 forespørselene
for i in range(10):
    startTime = time() # Bruker den nåværende tiden
    message = "Ping " + str(i+1) + " " + ctime(startTime)[11:19]

    try:

        # Dette sender meldingen og venter på svar.
        clientSocket.sendto(message.encode(),(serverHost, int(serverPort)))
        encodedModified, serverAddress = clientSocket.recvfrom(1024)

        # Sjekker om den nåværende tiden og om serveren svarer
        endTime = time()

        # Den modifiserte meldingen blir dekodet.
        modifiedMessage = encodedModified.decode()
        print(modifiedMessage)

        # Printer RTT
        print("Round Trip Time: %.3f ms\n" % ((endTime - startTime)*1000))
    except:
        print("PING %i Request timed out\n" % (i+1))

clientSocket.close()
