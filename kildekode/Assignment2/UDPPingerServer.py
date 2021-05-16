# Modul 4
# Assignment 2

# Dette er UDP Serverprogrammet
# Den sender en melding i KAPITALISERTE bokstaver til klienten.
# Lager et rand (tilfeldig) nummer
# Hvis rand er mindre enn 4 vil ikke responsen bli sendt
# Hvis rand er større eller lik 4 er responsen sendt.

import random
from socket import *

# Lager en UDP socket
# Her brukes SOCK_DGRAM for UDP pakkene, SOCK_STREAM brukes til TCP.
serverSocket = socket(AF_INET, SOCK_DGRAM)

# Angir IP adresse og port nummer til socket.
serverSocket.bind(('', 12000))

while True:

	# genererer et tilfeldig tall mellom 0 og 10
	rand = random.randint(0, 10)

	# Tar imot klienpakken sammen med adressen den kommer fra
	message, address = serverSocket.recvfrom(1024)

	# Omgjør bokstavene til caps
	message = message.upper()

	# hvis rand er mindre enn 4 anser vi pakken som tapt
	if rand < 4:
		continue

	# Eller så vil serveren sende meldingen
	serverSocket.sendto(message, address)
