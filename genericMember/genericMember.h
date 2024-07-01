#pragma once
#include <winsock2.h>
#include <string>
#include <iostream>


class genericMember {

public:
	genericMember(const sockaddr addr);

	enum importanceLevel_t {
		LOW,
		MIDDLE,
		ASAP,
		HIGH,
		VERY_HIGH,
		EXTREMELY_HIGH
	};
	typedef struct {
		std::string text;
		importanceLevel_t importance;
		std::string destAddr;
	}message_t;
	virtual bool sendMessage(message_t msg) = 0;

private:
	SOCKET objSocket;
};

genericMember::genericMember(const sockaddr addr) : objSocket(socket(AF_INET, SOCK_STREAM, 0)) {
	LPWSADATA lpWSAData(0);
	if (WSAStartup(MAKEWORD(1, 1), lpWSAData)) {
		int attemptsCounter = 3;
		while (attemptsCounter--) {
			if (connect(objSocket, &addr, sizeof(addr))) {
				std::cout << "Socket succssesfully created\n";
				break;
			}
		}
	}
	else {
		std::cout << "Issue while creating socket\n";
	}
}
