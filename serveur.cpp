#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Table exactement comme dans le sujet (espaces simples)
    const std::string T1 = "KIU5m LK52 Fgb2 ZSt4 Mu8c Mh8h CT3S jiTr";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    std::cout << "=== SERVEUR DÉMARRÉ ===\nEn attente de connexion sur le port " << PORT << "...\n";

    new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);

    std::cout << "Client connecté!\n";

    // Envoi de T1 avec espaces
    send(new_socket, T1.c_str(), T1.length(), 0);
    std::cout << "Table T1 envoyée au client: " << T1 << "\n\n";

    // Réception confirmation
    int bytes = read(new_socket, buffer, BUFFER_SIZE-1);
    buffer[bytes] = '\0';

    std::cout << "=== NOTIFICATION ===\n" << buffer << std::endl;

    close(new_socket);
    close(server_fd);
    return 0;
}