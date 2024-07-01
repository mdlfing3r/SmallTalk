#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#include <string>
#include <iostream>
#include <vector>


int main() {
	// Declare variables
	SOCKET ListenSocket;
	struct sockaddr_in saServer;
	hostent* localHost;
	char* localIP;

	// Create a listening socket
	ListenSocket = socket(AF_INET, SOCK_STREAM, 0);

	// Get the local host information
	localHost = gethostbyname("");
	//localIP = inet_ntoa(*(struct in_addr*)*localHost->h_addr_list);

	// Set up the sockaddr structure
	saServer.sin_family = AF_INET;
	saServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	saServer.sin_port = htons(20041);

	// Bind the listening socket using the
	// information in the sockaddr structure
	bind(ListenSocket, (SOCKADDR*)&saServer, sizeof(saServer));

	sockaddr_in name;
	int n_l = sizeof(name);
	ZeroMemory(&name, sizeof(name));

	getsockname(ListenSocket, (sockaddr*)&name, &n_l);



	std::vector<char> buf[10] = {};    // адрес буфера для приёма данных
	int len = 10;          // длинна буфера для приёма данных
	int flags = 0;
	bool isConnected = false;
	while(!isConnected){

	}
	while (true) {
		recv(ListenSocket, (char*)&buf, len, flags);
		if (buf->size()) {
			std::cout << std::string(*(buf->begin()), len) << std::endl;
			buf->clear();
		}
		Sleep(400);
	}
	return 0;
}