#include <windows.h>
#include <iostream>
#include<stdlib.h>
using namespace std;
DWORD WINAPI Fun1Proc(
	LPVOID lpParameter   // thread data声明线程函数
);

DWORD WINAPI Fun2Proc(
	LPVOID lpParameter   // thread data
);
int index = 0;
int tickets = 100;//全局变量票的张数
HANDLE hMutex;//声明它为全局的互斥对象
int main()
{
	HANDLE hThread1;//线程的句柄和线程名，用于接收CreateThread函数的返回值
	HANDLE hThread2;
	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);
	/*第一个是指向结构体的一个指针，我们用null表示缺省的安全性
	第二个指定初始提交的栈的大小，以字节为单位，系统会四舍五入为最近的页面的值，页面是系统在管理内存时使用的内存单位。
	指向一个LPTHREAD_ATART_ROUTINE函数的指针，就是次线程的入口 
	第三个是吃线程的入口函数名
	第四个是给线程传递的参数
	第五个是用来指定这个线程创建的附加标记，如果这个值是0 ，那么这个线程在创建之后被立即运行
	第六个，这个参数作为一个返回值使用的，用来接收线程的标识符，当我门创建有个线程时系统会为我们创建一个ID号
	如果是NULL这个线程不会返回（2000及其以上的版本可以设置成NULL）
	如果创建线程成功会返回一个新的线程的句柄*/
		CloseHandle(hThread1);//关闭线程的句柄，在线程执行完毕之后释放线程的内核对象，
		CloseHandle(hThread2);
	//得保证两个线程卖完票之前主线程不能退出	
	/*while(index++<1000)
		cout<<"main thread is running"<<endl;*/
	hMutex = CreateMutex(NULL, FALSE, NULL);
	//Mutex = CreateMutex(NULL, TRUE, "tickets");
	//这个函数是创建一个互斥对象，作用是当线程1没执行完的时候线程2不能执行
	//第一个是指向一个结构的指针，使用默认的安全性
	//是真就是获得调用线程的所有权，是faues是系统给他有信号
	//第三个给互斥对象起一个名字，null表示匿名的
	Sleep(500);//让主线程不退出，主线程放弃了他执行的权利进入等待状态，这时他不占用CPU执行时间 
		//Sleep(10);//让线程暂停运行，让主线程暂停运行，把时间留给等待的线程让他运行，单位是毫秒
	//让线程暂停运行，让主线程暂停运行，把时间留给等待的线程让他运行，线程
	//执行的特点是，一个线程先执行完另一个线程才会开始执行，应注意主线程main执行完毕会终止进程
	system("pause");
	return 0;
}

DWORD WINAPI Fun1Proc(
	LPVOID lpParameter   // thread data
)//定义一个函数作为线程的入口函数，函数数的名字可以自己取，
//但是类型不能变即参数的类型（LPVOID）和返回值的类型(DWORD)
{
	/*while(index++<1000)
		cout<<"thread1 is running"<<endl;*/
		//可以看到的是主线程和线程1交替运行一段时间
	//时间长短是根据系统提供的时间片决定的，直到主线程执行完毕

	while (TRUE)
	{
		
		WaitForSingleObject(hMutex, INFINITE);		//是fause是得到解除等待然后系统给到无信号，往下执行
		//请求互斥对象，返回的条件是1指定的对象处于有信号状态2超时的时间间隔流逝了
		//他如果不返回那么就会一直等待，这个线程就会暂停运行
		//INFINITE的含义是让它永远等待除非我们等待的对象处于有信号状态 
		if (tickets > 0)
		{ 
			Sleep(1);
			cout << "thread1 sell ticket : " << tickets-- << endl;
		}
		else

			break;
		ReleaseMutex(hMutex);//释放互斥对象让它处于已经通知的状态，将对象线程ID设为0，且为已通知状态
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