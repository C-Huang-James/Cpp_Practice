#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    SOCKET serverSocket;
    sockaddr_in serverAddr;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed.\n";
        return 1;
    }

    // Create server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed.\n";
        WSACleanup();
        return 1;
    }

    // Set server socket to non-blocking mode
    u_long mode = 1;
    ioctlsocket(serverSocket, FIONBIO, &mode);

    // Bind
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(502); // Use a port above 1024 for testing
    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

    // Listen
    listen(serverSocket, SOMAXCONN);
    std::cout << "Server listening on port 502...\n";

    // Track client sockets
    std::vector<SOCKET> clientSockets;

    // Main loop
    while (true) {
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(serverSocket, &readSet); // Watch server socket
        SOCKET maxSock = serverSocket;

        // Add client sockets to the read set
        for (SOCKET client : clientSockets) {
            FD_SET(client, &readSet);
            if (client > maxSock) maxSock = client;
        }

        // Set timeout
        timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        // Wait for activity
        int activity = select(0, &readSet, nullptr, nullptr, &timeout);
        if (activity == SOCKET_ERROR) {
            std::cerr << "select() failed.\n";
            break;
        }

        // Incoming connection?
        if (FD_ISSET(serverSocket, &readSet)) {
            sockaddr_in clientAddr;
            int clientSize = sizeof(clientAddr);
            SOCKET newClient = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
            if (newClient != INVALID_SOCKET) {
                std::cout << "New client connected.\n";
                clientSockets.push_back(newClient);
            }
        }

        // Check each client for incoming data
        char buffer[4096];
        for (size_t i = 0; i < clientSockets.size(); ) {
            SOCKET client = clientSockets[i];

            if (FD_ISSET(client, &readSet)) {
                int bytesReceived = recv(client, buffer, sizeof(buffer), 0);
                if (bytesReceived <= 0) {
                    std::cout << "Client disconnected.\n";
                    closesocket(client);
                    clientSockets.erase(clientSockets.begin() + i);
                    continue; // Don't increment index since we erased
                }
                else {
                    std::string msg(buffer, bytesReceived);
                    std::cout << "Received: " << msg << "\n";
                    send(client, buffer, bytesReceived, 0); // Echo back
                }
            }
            ++i;
        }
    }

    // Cleanup
    for (SOCKET client : clientSockets) {
        closesocket(client);
    }
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
