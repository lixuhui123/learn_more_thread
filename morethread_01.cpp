//#include<process.h>
//#include<windows.h>
//#include<iostream>
//using namespace std;
//
//void ThreadFun1(void * p);
//void ThreadFun2(void * p);
//int tickets = 0;
//
//int main()
//{
//	cout << "��Ʊ��ʼ��" << endl;
//	HANDLE hThread1 = (HANDLE)_beginthread(ThreadFun1, 0, (void*)"A");
//	HANDLE hThread2 = (HANDLE)_beginthread(ThreadFun2, 0, (void*)"B");
//
//	HANDLE hThreadarry[] = { hThread1 ,hThread2 };
//
//	WaitForMultipleObjects(2, hThreadarry, true, INFINITE);
//	cout << "��Ʊ������" << endl;
//	system("pause");
//	return 0;
//}
//
//void ThreadFun1(void * p)
//{
//	char * name = (char*)p;
//	while (tickets++ <= 100)
//	{
//		printf("%s�۳���%d��\n", name, tickets);
//	}
//}
//
//void ThreadFun2(void * p)
//{
//	char * name = (char*)p;
//	while (tickets++ <= 100)
//	{
//		printf("%s�۳���%d��\n", name, tickets);
//	}
//}
