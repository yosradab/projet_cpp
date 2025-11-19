#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <mysql/mysql.h>
#include <string>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Erreur de création du socket\n";
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cout << "Adresse invalide\n";
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Échec de connexion\n";
        return -1;
    }

    std::cout << "=== CLIENT CONNECTÉ AU SERVEUR ===\n";

    // Réception de T1
    int valread = read(sock, buffer, BUFFER_SIZE - 1);
    if (valread <= 0) {
        std::cout << "Erreur de réception des données\n";
        close(sock);
        return -1;
    }
    buffer[valread] = '\0';
    std::string received(buffer);

    std::cout << "Données reçues : " << received << "\n";

    // Connexion MySQL
    MYSQL* conn = mysql_init(NULL);
    if (conn == NULL) {
        std::cerr << "mysql_init() erreur\n";
        close(sock);
        return 1;
    }

    if (mysql_real_connect(conn, "188.165.236.167", "usercpp", "#usercpp!!", "testcpp", 0, NULL, 0) == NULL) {
        std::cerr << "Erreur de connexion MySQL : " << mysql_error(conn) << "\n";
        close(sock);
        mysql_close(conn);
        return 1;
    }

    // Insertion unique de toute la table T1
    std::string query = "INSERT INTO Data_CLIENT (ID_DB, reception) VALUES (NOW(), '" + received + "')";

    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Erreur insertion : " << mysql_error(conn) << "\n";
        send(sock, "Erreur insertion DB", 19, 0);
    } else {
        std::cout << "✓ Insertion réussie dans Data_CLIENT\n";
        const char* confirmation = "Code bien reçu";
        send(sock, confirmation, strlen(confirmation), 0);
    }

    mysql_close(conn);
    close(sock);
    return 0;
}