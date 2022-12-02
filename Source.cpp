#include <Windows.h> //memory
#include <iostream> //cout, cin


// - http://www.club155.ru/x86cmd/Jcc
int main()
{
	BYTE jump[] = { 0xEB, 0x00 }; //jne - 0xEB, jmp - 0x00, nop - 0x90 
	DWORD address = 0x0; 
	DWORD pid; //processid

	std::cout << "pid:";
	std::cin >> pid;
		
	
	//https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, true, pid); 

	if (!phandle)
	{
		std::cout << "error_!phandle" << std::endl;
	}
	
	//https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-writeprocessmemory
	if (WriteProcessMemory(phandle, LPVOID(address), &jump, sizeof(jump), 0))
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "error_WriteProcessMemory" << std::endl;
	}
	system("pause"); //getch
}
