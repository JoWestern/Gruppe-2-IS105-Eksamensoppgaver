
import socket


def client_program():
    host = socket.gethostname()  # Får tak i hosten sitt navn igjen
    port = 5000  # bruker socket_server sin port nummer

    client_socket = socket.socket()  
    client_socket.connect((host, port))  # kobler til sereren

    message = input(" -> ")  # tar imot input

    while message.lower().strip() != 'bye':
        client_socket.send(message.encode())  # sender meldinger
        data = client_socket.recv(1024).decode()  # tar imot melding

        print('Received from server: ' + data)  # viser i terminal

        message = input(" -> ")  # tar imot neste input

    client_socket.close()  # lukker koblingen


if __name__ == '__main__':
    client_program()
