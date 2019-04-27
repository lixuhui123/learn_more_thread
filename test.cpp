//#include<stdlib.h>
//#include<iostream>
//#include<windows.h>
//using namespace std;
//DWORD WINAPI Fun1Proc(
//	LPVOID lpParameter   // thread data
//);
//DWORD WINAPI Fun2Proc(
//	LPVOID lpParameter   // thread data
//);
//int tickets = 100;
//HANDLE hMutex;//声明它为全局的互斥对象
//int main()
//{
//	HANDLE hThread1;
//	HANDLE hThread2;
//	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
//	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);
//	CloseHandle(hThread1);//关闭线程的句柄，在线程执行完毕之后释放线程的内核对象，
//	CloseHandle(hThread2);
//	hMutex = CreateMutex(NULL,FALSE, NULL);//互斥对象处于已通知状态，拿到钥匙
//	Sleep(2000);
//	system("pause");
//	return 0;
//}
//DWORD WINAPI Fun1Proc(
//	LPVOID lpParameter   // thread data
//)
//{
//	while (TRUE)
//	{
//		WaitForSingleObject(hMutex, INFINITE);
//		if (tickets > 0)
//		{
//			Sleep(1);
//			cout << "thread1 sell tickets:" << tickets-- << endl;
//		
//		}
//		else
//		
//			break;
//
//		ReleaseMutex(hMutex);
//	}
//	return 0;
//}
//DWORD WINAPI Fun2Proc(
//	LPVOID lpParameter   // thread data
//)
//
//{
//	while (TRUE)
//	{
//		WaitForSingleObject(hMutex, INFINITE);
//		if (tickets > 0)
//		{
//			Sleep(1);
//			cout << "thread2 sell tickets:" << tickets-- << endl;
//			
//		}
//		else
//		
//			break;
//		ReleaseMutex(hMutex);
//	}
//	return 0;
//}//ticket--和--ticket就会产生区别