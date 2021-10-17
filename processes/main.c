#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>
#include <dos.h>

void printThreads(HANDLE snapshot, PROCESSENTRY32 processes) {
  THREADENTRY32 threads;
  threads.dwSize = sizeof(THREADENTRY32);
  unsigned thread_flag = Thread32First(snapshot, &threads);
  unsigned long count = processes.cntThreads;
  while (thread_flag && count) {
    if (threads.th32OwnerProcessID == processes.th32ProcessID) {
      --count;
      printf("\tID: %lu\tPriority: %lu\n", threads.th32ThreadID, threads.tpBasePri);
    }
    thread_flag = Thread32Next(snapshot, &threads);
  }
}
int main() {
  HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
  PROCESSENTRY32 processes;
  processes.dwSize = sizeof(PROCESSENTRY32);
  unsigned int process_flag = Process32First(snapshot, &processes);
  while (process_flag) {
    printf(
        "Process Name: %s\nPID: %lu\nParent PID: %lu\nPriorityClass: %lu\nThread count: %lu\nThread priority: %lu\nThread IDs:\n",
        processes.szExeFile,
        processes.th32ProcessID,
        processes.th32ParentProcessID,
        GetPriorityClass(GetCurrentProcess()),
        processes.cntThreads,
        processes.pcPriClassBase);
    printThreads(snapshot, processes);
    printf("Modules: \n");
    MODULEENTRY32 modules;
    modules.dwSize = sizeof(MODULEENTRY32);
    unsigned m_flag = Module32First(snapshot, &modules);
    int count = 0;
    while (m_flag) {
      if (modules.th32ProcessID == processes.th32ProcessID) {
        printf("\tModule Name: %s\n\tSize: %lu\n\tExecutable: %s\n",
               modules.szModule,
               modules.modBaseSize,
               modules.szExePath);
        ++count;
      }
      m_flag = Module32Next(snapshot, &modules);

    }
    printf(
        "Module count: %d\n-----------------------------------------------------------------------------------\n",
        count);
    process_flag = Process32Next(snapshot, &processes);
  }
  //printf("Hello, World!\n");
  return 0;
}
