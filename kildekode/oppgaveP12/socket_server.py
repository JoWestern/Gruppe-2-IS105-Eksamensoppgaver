
import socket


def server_program():
    # får tak i hosten sitt navn
    host = socket.gethostname()
    port = 5000  # initialiserer en port med nummer høyere enn 1024

    server_socket = socket.socket()  # får en instans av server_socket
    
    server_socket.bind((host, port))  # binder hostadressen og porten sammen

    # konfigurerer hvor mange klienter servere kan lytte etter samtidig, som i dette tilfellet er 2
    server_socket.listen(2)
    conn, address = server_socket.accept()  # aksepterer den nye koblingen
    print("Connection from: " + str(address))
    while True:
        # Tar imot en datastrøm, den vil ikke akseptere datapakker større enn 1024 bytes.
        data = conn.recv(1024).decode()
        if not data:
            # hvis den ikke får tatt imot data vil den avlsute med en break.
            break
        print("from connected user: " + str(data))
        data = input(' -> ')
        conn.send(data.encode())  # sender data til klienten

    conn.close()  # Lukker koblingen


    #Dette er kjent som "boilerplate" kode som beskytter mot feil under importering og kjøring av flere programmer.
if __name__ == '__main__':
    server_program()
