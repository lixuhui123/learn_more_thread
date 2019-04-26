#include <windows.h>
#include <iostream>
#include<stdlib.h>
using namespace std;
DWORD WINAPI Fun1Proc(
	LPVOID lpParameter   // thread data�����̺߳���
);

DWORD WINAPI Fun2Proc(
	LPVOID lpParameter   // thread data
);
int index = 0;
int tickets = 100;//ȫ�ֱ���Ʊ������
HANDLE hMutex;//������Ϊȫ�ֵĻ������
int main()
{
	HANDLE hThread1;//�̵߳ľ�����߳��������ڽ���CreateThread�����ķ���ֵ
	HANDLE hThread2;
	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);
	/*��һ����ָ��ṹ���һ��ָ�룬������null��ʾȱʡ�İ�ȫ��
	�ڶ���ָ����ʼ�ύ��ջ�Ĵ�С�����ֽ�Ϊ��λ��ϵͳ����������Ϊ�����ҳ���ֵ��ҳ����ϵͳ�ڹ����ڴ�ʱʹ�õ��ڴ浥λ��
	ָ��һ��LPTHREAD_ATART_ROUTINE������ָ�룬���Ǵ��̵߳���� 
	�������ǳ��̵߳���ں�����
	���ĸ��Ǹ��̴߳��ݵĲ���
	�����������ָ������̴߳����ĸ��ӱ�ǣ�������ֵ��0 ����ô����߳��ڴ���֮����������
	�����������������Ϊһ������ֵʹ�õģ����������̵߳ı�ʶ���������Ŵ����и��߳�ʱϵͳ��Ϊ���Ǵ���һ��ID��
	�����NULL����̲߳��᷵�أ�2000�������ϵİ汾�������ó�NULL��
	��������̳߳ɹ��᷵��һ���µ��̵߳ľ��*/
		CloseHandle(hThread1);//�ر��̵߳ľ�������߳�ִ�����֮���ͷ��̵߳��ں˶���
		CloseHandle(hThread2);
	//�ñ�֤�����߳�����Ʊ֮ǰ���̲߳����˳�	
	/*while(index++<1000)
		cout<<"main thread is running"<<endl;*/
	hMutex = CreateMutex(NULL, FALSE, NULL);
	//Mutex = CreateMutex(NULL, TRUE, "tickets");
	//��������Ǵ���һ��������������ǵ��߳�1ûִ�����ʱ���߳�2����ִ��
	//��һ����ָ��һ���ṹ��ָ�룬ʹ��Ĭ�ϵİ�ȫ��
	//������ǻ�õ����̵߳�����Ȩ����faues��ϵͳ�������ź�
	//�����������������һ�����֣�null��ʾ������
	Sleep(500);//�����̲߳��˳������̷߳�������ִ�е�Ȩ������ȴ�״̬����ʱ����ռ��CPUִ��ʱ�� 
		//Sleep(10);//���߳���ͣ���У������߳���ͣ���У���ʱ�������ȴ����߳��������У���λ�Ǻ���
	//���߳���ͣ���У������߳���ͣ���У���ʱ�������ȴ����߳��������У��߳�
	//ִ�е��ص��ǣ�һ���߳���ִ������һ���̲߳ŻῪʼִ�У�Ӧע�����߳�mainִ����ϻ���ֹ����
	system("pause");
	return 0;
}

DWORD WINAPI Fun1Proc(
	LPVOID lpParameter   // thread data
)//����һ��������Ϊ�̵߳���ں����������������ֿ����Լ�ȡ��
//�������Ͳ��ܱ伴���������ͣ�LPVOID���ͷ���ֵ������(DWORD)
{
	/*while(index++<1000)
		cout<<"thread1 is running"<<endl;*/
		//���Կ����������̺߳��߳�1��������һ��ʱ��
	//ʱ�䳤���Ǹ���ϵͳ�ṩ��ʱ��Ƭ�����ģ�ֱ�����߳�ִ�����

	while (TRUE)
	{
		
		WaitForSingleObject(hMutex, INFINITE);		//��fause�ǵõ�����ȴ�Ȼ��ϵͳ�������źţ�����ִ��
		//���󻥳���󣬷��ص�������1ָ���Ķ��������ź�״̬2��ʱ��ʱ����������
		//�������������ô�ͻ�һֱ�ȴ�������߳̾ͻ���ͣ����
		//INFINITE�ĺ�����������Զ�ȴ��������ǵȴ��Ķ��������ź�״̬ 
		if (tickets > 0)
		{ 
			Sleep(1);
			cout << "thread1 sell ticket : " << tickets-- << endl;
		}
		else

			break;
		ReleaseMutex(hMutex);//�ͷŻ���������������Ѿ�֪ͨ��״̬���������߳�ID��Ϊ0����Ϊ��֪ͨ״̬
	}

	
	return 0;
}

DWORD WINAPI Fun2Proc(
	LPVOID lpParameter   // thread data
)
{

	while (TRUE)
	{
		
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets > 0)
		{
			Sleep(1);
			cout << "thread2 sell ticket : " << tickets-- << endl;
		}
		else
			break;
		ReleaseMutex(hMutex);
	}
	
	return 0;
}