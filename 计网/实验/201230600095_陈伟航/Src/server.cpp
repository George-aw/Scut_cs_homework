#include <stdio.h>
#include <tchar.h>
#include <exception> 
// socketTest.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <iostream>
#include <winsock.h>


#pragma  comment (lib,"ws2_32.lib")
#define  MAXBUFLEN 256
#define  PORT 44965

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA Data;
	SOCKADDR_IN serverSockAddr;
	//SOCKADDR_IN clientSockAddr;
	SOCKET serversocket;  //��ʵ����һ��unsig int���ͣ�������¼�Ѿ�����������δ�������׽��ֺ�
	SOCKET clientsocket;
	int addrlen = sizeof(SOCKADDR_IN);   //16
	int status;
	int numrcv;
	char buffer[MAXBUFLEN];

	//��ʼ��windows Socket Dll
	status = WSAStartup(MAKEWORD(1,1),&Data);
	if (0!=status)
	{
		cout<<"��ʼ��ʧ��"<<endl;
		return 0;
	}

	//��0
	memset(&serverSockAddr,0,sizeof(serverSockAddr));
	//��ʼ��
	serverSockAddr.sin_port = htons(PORT);
	serverSockAddr.sin_family = AF_INET;    //ָ����ַЭ����
	serverSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);  //��ʼ��ip��ַ0,0,0,0 �κ�ip����������

	//�����׽���
	serversocket = socket(AF_INET,SOCK_STREAM/*�׽�������*/,0/*�׽���ʹ�õ��ض�Э��*/);
	if (INVALID_SOCKET == serversocket)
	{
		cout<<"����socketʧ��"<<endl;
		return 1;
	}

	//��socket���ض���ַ(�ṹ���ַ)
	status = bind(serversocket,(LPSOCKADDR)&serverSockAddr,sizeof(serverSockAddr));
	if (SOCKET_ERROR==status)
	{
		cout<<"�󶨵�ַʧ��"<<endl;
		return 1;
	}

	//�������������������󣬻���˵���Ǽ���
	status = listen(serversocket/*�׽��ֺ�*/,2/*����������ӵ��׽��ָ���*/);
	if (SOCKET_ERROR == status)
	{
		cout<<"����ʧ��"<<endl;
		return 1;
	}
	cout<<"���Ӵ����ɹ��������Ƿ��пͻ��˽��롭��\n";
	clientsocket = accept(serversocket,(LPSOCKADDR)&clientsocket,&addrlen);
	
	//�������������Ǿͽ�����������
	while(1)
	{
		try
		{
			if (SOCKET_ERROR==clientsocket)
			{
				cout<<"�ͻ��˽���ʧ��"<<endl;
				return 1;
			}
			numrcv = recv(clientsocket/*�Ѿ��������׽���*/,buffer/*�����������ݻ�������ָ��*/,MAXBUFLEN/*���ܻ�������С*/,0/*������Ʒ�ʽ*/);
			if (0==numrcv||numrcv==SOCKET_ERROR)
			{
				cout<<"�����ܵ�����"<<endl;

				status = closesocket(clientsocket);
				if (SOCKET_ERROR==status)
					cout<<"�Ͽ�����ʧ��"<<endl;

				status = WSACleanup();
				if (SOCKET_ERROR==status)
					cout<<"��������ʧ��"<<endl;
				return(1);
			}

			cout<<"���ܵ��ͻ��˷���������Ϣ�����ǣ�"<<buffer<<endl;
			if (!strcmp(buffer,"closeClient"))
			{
				cout << "Connection terminated" << endl;

				status=closesocket(clientsocket);
				if (status == SOCKET_ERROR)
					cout<< "ERROR: closesocket unsuccessful" << endl;
				status=WSACleanup();
				if (status == SOCKET_ERROR)
					cout<< "ERROR: WSACleanup unsuccessful" << endl;
				return(1);
				
			}
			cout<<"������Ҫ���͸��ͻ��˷��͵���Ϣ���ݲ����س�����"<<endl;

			int numsnt;
			char toSendtxt[256];
			cin.getline(toSendtxt,256,'\n');

			numsnt=send(clientsocket, toSendtxt, strlen(toSendtxt) + 1, 0);
			if (numsnt != (int)strlen(toSendtxt) + 1)
			{
				cout << "Connection terminated" << endl;

				status=closesocket(clientsocket);
				if (status == SOCKET_ERROR)
					cout<< "ERROR: closesocket unsuccessful" << endl;
				status=WSACleanup();
				if (status == SOCKET_ERROR)
					cout<< "ERROR: WSACleanup unsuccessful" << endl;
				return(1);
			}
			cout<<"�ȴ��������ܿͻ��˷�������Ϣ.........."<<endl;

		}
		catch (exception& e)
		{
			cout<<e.what()<<endl;
			return 1;
		}		
	}

	return 0;
}

/*�ܽ�ͨ�ŷ������ˣ�����һ��socketͨ�ţ�        socket()
�����socket����ַ�ṹ�壬bind()
�����������뽨����������,   listen() 
���������������������,     accept()
���ܿͻ��˷�������Ϣ���ݣ�  recv()
��ͻ��˷�����Ϣ��          send()
*/