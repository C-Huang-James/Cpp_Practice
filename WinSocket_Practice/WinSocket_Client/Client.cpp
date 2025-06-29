#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    sockaddr_in serverAddr;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed.\n";
        return 1;
    }

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed.\n";
        WSACleanup();
        return 1;
    }

    // Set to non-blocking mode
    u_long mode = 1;
    ioctlsocket(clientSocket, FIONBIO, &mode);

    // Server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(502);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    // Start connect (will likely return SOCKET_ERROR in non-blocking mode)
    int result = connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if (result == SOCKET_ERROR && WSAGetLastError() != WSAEWOULDBLOCK) {
        std::cerr << "Connect failed.\n";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Wait for connection to complete
    fd_set writeSet;
    FD_ZERO(&writeSet);
    FD_SET(clientSocket, &writeSet);
    timeval timeout = { 5, 0 }; // 5 seconds timeout

    result = select(0, nullptr, &writeSet, nullptr, &timeout);
    if (result <= 0) {
        std::cerr << "Connection timeout or error.\n";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Connected to server!\n";

    // Main loop
    char buffer[4096];
    std::string userInput;

    while (true) {
        std::cout << "Enter message: ";
        std::getline(std::cin, userInput);
        if (userInput.empty()) break;

        // Send data
        send(clientSocket, userInput.c_str(), userInput.size() + 1, 0);

        // Wait for response (read readiness)
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(clientSocket, &readSet);
        timeout.tv_sec = 5; timeout.tv_usec = 0;

        result = select(0, &readSet, nullptr, nullptr, &timeout);
        if (result > 0 && FD_ISSET(clientSocket, &readSet)) {
            int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
            if (bytesReceived > 0) {
                std::cout << "Server replied: " << std::string(buffer, 0, bytesReceived) << "\n";
            }
        }
        else {
            std::cout << "No response from server (timeout).\n";
        }
    }

    // Cleanup
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
