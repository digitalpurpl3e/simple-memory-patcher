#include <Windows.h>
#include <iostream>

int main()
{
	BYTE jump[] = { 0xEB, 0x00 }; 
	DWORD adres = 0x7FF68679132F; //00007FF68679132F
	DWORD pid;

	std::cout << "pid:";
	std::cin >> pid;

	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, true, pid);

	if (!phandle)
	{
		std::cout << "error_!phandle" << std::endl;
	}
	else
	{
		std::cout << "access" << std::endl;

		if (!WriteProcessMemory(phandle, LPVOID(adres), &jump, sizeof(jump), 0))
		{
				std::cout << "error_WriteProcessMemory" << std::endl;
		}
		else
		{
			std::cout << "success" << std::endl;
		}
	}
	system("pause");
}