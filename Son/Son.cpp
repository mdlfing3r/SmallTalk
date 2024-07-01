#include "../genericMember/genericMember.h"

class Son : protected genericMember {
	Son(sockaddr sock);
	virtual bool sendMessage(message_t msg) override;

};

Son::Son(sockaddr sock) : genericMember(sock){

}

bool Son::sendMessage(genericMember::message_t msg)
{
	//send to msg.destAddr
	//msg.text
	//	with
	//msg.importance
	return false; //send status
}

int main() {
	sockaddr socket(TCP/IP, inet_addr("193.108.128.226"));
	Son service = new Son()
	connect()
}
// тип адреса (TCP/IP)
s_addr.sin_family = AF_INET;
//адрес сервера. Т.к. TCP/IP представляет адреса в числовом виде, то для перевода
// адреса используем функцию inet_addr.
s_addr.sin_addr.S_un.S_addr = inet_addr("193.108.128.226");
// Порт. Используем функцию htons для перевода номера порта из обычного в //TCP/IP представление.
s_addr.sin_port = htons(1234);
