#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <future>
#include <ctime>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y);
int16_t y=0;
struct version
{
    string VERSION="1.101RG15wer45";
};
bool switch_while=true,switch_NEW_algorithm=false;
int8_t random_Student_ID=0;
int arr_Student_ID[10000];
int getTime()
{
    long int time_int;
    time_t timep;
    time (&timep); 
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep));
    string time=tmp;
    for (int i = 0; i < time.length(); i++)
    {
        if (time[i]>='0'&&time[i]<='9')
        {
            time_int+=(time[i]-'0')*i;
        }
    }
    return time_int;
}
void SetFont(int size = 30) {
	CONSOLE_FONT_INFOEX cfi; 
	cfi.cbSize = sizeof cfi; 
	cfi.nFont = 0; 
	cfi.dwFontSize.X = 0; 
	cfi.dwFontSize.Y = size;  
	cfi.FontFamily = FF_DONTCARE; 
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFO consoleCurrentFont;
	GetCurrentConsoleFont(handle, FALSE, &consoleCurrentFont);
}
void set_cursor(bool hide) { 
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo); 
	CursorInfo.bVisible = hide;				   
	SetConsoleCursorInfo(handle, &CursorInfo); 
}
void gotoxy(int x, int y) { // ???娼???
	COORD c = {(SHORT)x, (SHORT)y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setmode() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE; 
	// mode &= ~ENABLE_INSERT_MODE;	 
	// mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, mode);
}
void Loading()
{
    const char* title="随机抽取学号";
    SetConsoleTitle(TEXT("随机抽取学号"));
    system("mode con cols=35 lines=12");
    SetFont(50);
    set_cursor(false);
    setmode();
    gotoxy(4,5);
}
int main(int argc, char const *argv[])
{
    Loading();
    switch_while=true;
    int64_t i;
    srand(getTime());
_1_:i=rand();
    srand(i);
    y=rand()%100;
    thread while_([&]{
        srand(getTime());
        gotoxy(9,7);
        cout<<"按下任意键以停止";
        gotoxy(4,5);
        while (1)
        {
            if (switch_while==true)
            {
                    y=rand()%100;
                    if (y>=1&&y<=60)
                    {
                        if (y>=1&&y<=9)
                        {
                            cout<<"请学号为 "<<y<<"号的同学起立发言";
                            gotoxy(4,5);
                        }
                        else
                        {
                            cout<<"请学号为"<<y<<"号的同学起立发言";
                            gotoxy(4,5);
                        }
                    }   
            }
            else if (switch_while==false)
            {
                break;
            }
        }
        system("cls");
        gotoxy(9,7);
        cout<<"按下任意键以开始";
        gotoxy(4,5);
        if (y>=0&&y<=9)
        {
            cout<<"请学号为 "<<y<<"号的同学起立发言";
            gotoxy(4,5);
        }
        else
        {
            cout<<"请学号为"<<y<<"号的同学起立发言";
            gotoxy(4,5);
        }
        return 0;
    });
    while_.detach();
    int ch=_getwch();
    gotoxy(4,5);
    switch_while=false;
    ch=_getwch();
    switch_while=true;
    goto _1_;
    return 0;
}