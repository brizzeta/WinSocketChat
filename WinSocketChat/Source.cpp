//Main.cpp
#include <iostream>
#include "Socket.h"

using namespace std;

int main()
{
	int nChoice;
	int port = 24242;  //âûáèðàåì ïîðò
	bool Status = false;
	float quan;
	string ipAddress = "127.0.0.1"; //Àäðåñ ñåðâåðà

	char receiveMessage[MAXSTRLEN];
	char sendMessage[MAXSTRLEN];

	cout << "1) Start server" << endl;
	cout << "2) Connect to server" << endl;
	cout << "3) Exit" << endl;
	cin >> nChoice;
	if (nChoice == 1) {
		ServerSocket server;
		cout << "Starting server..." << endl;
		//Çàïóñêàåì ñåðâåð
		server.StartHosting(port);
		while (true)
		{
			cout << "\tWaiting..." << endl;
			//Ïîëó÷àåì äàííûå îò êëèåíòà
			//è ñîõðàíÿåì â ïåðåìåííîé receiveMessage
			server.ReceiveData(receiveMessage, MAXSTRLEN);
			cout << "Received: " << receiveMessage << endl;
			//Îòïðàâëÿåì äàííûå êëèåíòó
			server.SendDataMessage();
			//Åñëè åñòü ñîîáùåíèå "end", çàâåðøàåì ðàáîòó
			if (strcmp(receiveMessage, "end") == 0 ||
				strcmp(sendMessage, "end") == 0) {
				break;
			}
			else if (strcmp(sendMessage, "end") == 0) {

			}
		}
	}
	else if (nChoice == 2) {
		ClientSocket client;
		//ïîäêëþ÷àåìñÿ ê ñåðâåðó
		client.ConnectToServer(ipAddress.c_str(), port);
		while (true) {
			//îòïðàâëÿåì ñîîáùåíèå
			client.SendDataMessage();
			cout << "\tWaiting" << endl;
			//ïîëó÷àåì îòâåò
			client.ReceiveData(receiveMessage, MAXSTRLEN);
			cout << "Received: " << receiveMessage << endl;
			if (strcmp(receiveMessage, "end") == 0 ||
				strcmp(sendMessage, "end") == 0) {
				break;
			}
			else if (strcmp(receiveMessage, "start") == 0) {
				Status = true;
				cout << "\n1)Telephone - 7800 uan" << endl;
				cout << "2)Laptop - 26000 uan" << endl;
				cout << "3)Tablet - 9000 uan" << endl;
				cout << "Select option(1 - tel, 2 - lap, 3 - tab):\n";
			}
			else if (strcmp(receiveMessage, "1") == 0 && Status == true) {
				cout << "Enter quantity of this point:";
				cin >> quan;
				quan *= 7800;
				cout << "Price:" << quan << endl;
				Status = false;
			}
			else if (strcmp(receiveMessage, "2") == 0 && Status == true) {
				cout << "Enter quantity of this point:";
				cin >> quan;
				quan *= 26000;
				cout << "Price:" << quan << endl;
				Status = false;
			}
			else if (strcmp(receiveMessage, "3") == 0 && Status == true) {
				cout << "Enter quantity of this point:";
				cin >> quan;
				quan *= 9000;
				cout << "Price:" << quan << endl;
				Status = false;
			}
		}
		//Çàêðûâàåì ñîåäèíåíèå
		client.CloseConnection();
	}
	else if (nChoice == 3)
		return 0;
}










