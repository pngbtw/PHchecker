/* Proc.c */
/* this is a troll project i made to check if your friends watch ph and some more troll shit just read the code and see what it does :) */
#include <windows.h>
#include <stdio.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")


int main(int argc, char *argv[])
{
 HANDLE hFile;
 DWORD dwBytesWritten;
 LPCSTR data = "Please Help I Didnt Want To Hack You\n";
 const char *url = "https://wallpapersok.com/images/file/shrek-making-a-funny-face-1lawv7i17eeg10xw.jpg";
 SetConsoleTitle("ransomware");
 STARTUPINFO si;
 PROCESS_INFORMATION pi;
 
 ZeroMemory(&si, sizeof(si));
 si.cb = sizeof(si);
 ZeroMemory(&pi, sizeof(pi));

 if (argc > 1)
 {

  printf("Usage: %s\n", argv[0]);
  return 1;

 }

 char pcusername[256];
 DWORD username_len = sizeof(pcusername);
 char message[300];
 if (GetUserName(pcusername, &username_len))
 {
  sprintf(message," %s\n  Is This Your Pc Name ?", pcusername);
  char path[MAX_PATH];
  snprintf(path, sizeof(path),  "C:\\Users\\%s\\Documents\\shrek.jpg", pcusername);
  int result = MessageBox(NULL, message, "Hacked by PNG", MB_YESNO | MB_APPLMODAL); 
  if (result == IDYES)
  {

   CreateProcess(NULL, "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe https://myactivity.google.com/product/search?utm_medium=mavatar&utm_source=web_search&hl=en&q=porn&product=11%2C19%2C25",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
   Sleep(4000);
   MessageBox(NULL,"Nice P0rn Bro","Leaked",MB_OK);
   Sleep(2000);
   TerminateProcess(pi.hProcess,0);

  }

  else if (result == IDNO)
  {
   printf("Nigger its your pc name stfu and enjoy malwar3 donkey\n\n");
   Sleep(2500);
   CreateProcess(NULL,"cmd.exe /c color 4 & ipconfig /all",NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
   Sleep(6000);
   printf("\n You Think Its All?");
   HRESULT result = URLDownloadToFile(NULL, url, path, 0, NULL);
   Sleep(2000);
   int background = SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void *)path, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
   if (background)
   {
    hFile = CreateFile("pleasehelpthehacker.txt", GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    WriteFile(hFile, data, strlen(data), &dwBytesWritten, NULL);
   }
   TerminateProcess(pi.hProcess, 0);
   return 0;
  }
 }

 else
 {
  printf("Failed to get your user name lucky boy (%d).\n", GetLastError());
 }


 CloseHandle(pi.hProcess);
 CloseHandle(pi.hThread);

 return 0;

}
