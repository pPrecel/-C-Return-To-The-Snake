#include "Konsola.h"

// funkcja odpowiada za podmiane poszczegolnych elementow wyswetlacza w konsoli bez potrzeby wyswietlania calej tablicy od nowa
void IdzDo(int ** const XMapy, int ** const YMapy)
{
	COORD dwPos;

	dwPos.X = **XMapy;
	dwPos.Y = **YMapy;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwPos);
}

// funkcja odpowiada za ukrywanie kursora konsoli
void UkryjKursor()
{
	HANDLE hKonsola = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO daneKonsli;
	GetConsoleCursorInfo(hKonsola, &daneKonsli);
	daneKonsli.bVisible = FALSE;
	SetConsoleCursorInfo(hKonsola, &daneKonsli);
}

// funkcja odpowiada za odkrywanie kursora konsoli
void OdkryjKursor()
{
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO hCCI;
	GetConsoleCursorInfo(hConsoleOut, &hCCI);
	if (hCCI.bVisible != TRUE)
	{
		hCCI.bVisible = TRUE;
		SetConsoleCursorInfo(hConsoleOut, &hCCI);
	}
}

// funkcja odpowiada za ustawianie odpowiedniego rozmiaru konsoli   -   nie skonczona!
void UstawWielkoscOkna()
{
	//funkcja MoveWindow zostala ponizej uzyta, pniewaz zle dziala skalowanie konsoli z malego okna do duzego, a dobrze z duzego do maleg
	//stad zeby zapobiec ewentualnym problemom, postanowilem ja maksymanie powiekszyc

	//**************************************************************

	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE); // uchwyt do okna konsoli
	SMALL_RECT windowSize = { 0, 0,119, 29 }; // strunktura przechowujaca koordynaty lewego gornego rogu i prawego dolnego, konsoli
	COORD  dwSize = { 120, 30 }; // struktura przechowuje wielkosc bufora
	HWND uchwytKonsoli = GetConsoleWindow(); // zmienna przechowuje uchwyt do okna konsoli
	CONSOLE_FONT_INFOEX font = { sizeof(font) }; //struktura przechowyj¹ca informacje na temat czcionki

	//**************************************************************

	//ustawia wielkosc czcionki
	font.dwFontSize.X = 10;  
	font.dwFontSize.Y = 18;
	SetCurrentConsoleFontEx(wHnd, 0, &font);

	//zmiana wielkosci okna konsoli
	SetConsoleWindowInfo(wHnd, 1, &windowSize);

	//zmiana wielkosci bufora konsoli
	SetConsoleScreenBufferSize(wHnd, dwSize);

	//ustawia maxymalny rozmiar konsoli
	MoveWindow(uchwytKonsoli, 0, 0, 5000, 5000, FALSE);

	//zmiana wielkosci okna konsoli
	SetConsoleWindowInfo(wHnd, 1, &windowSize);

	//zmiana wielkosci bufora konsoli
	SetConsoleScreenBufferSize(wHnd, dwSize);
	
}

//funkcja odpowiada za uspienie aplikacji
int Czekaj(float *szybkosc)
{
	Sleep(250.0 / *szybkosc);
	return 1;
}

// funkcja odpowiada za funkcje kbhit, czyli pobieranie wystapienia z bufora konsoli
void PobierzJesliIstnieje(int *klawisz, char *kierunek)
{
	if (kbhit())
	{

		*klawisz = Pobierz();

		if (*klawisz == 224)    *klawisz += Pobierz();
		else if (*klawisz == 0) *klawisz -= Pobierz();

		if (*klawisz == 224 + 72 && *kierunek != 'd')       *kierunek = 'g';
		else if (*klawisz == 224 + 80 && *kierunek != 'g')   *kierunek = 'd';
		else if (*klawisz == 224 + 77 && *kierunek != 'l') *kierunek = 'p';
		else if (*klawisz == 224 + 75 && *kierunek != 'p')  *kierunek = 'l';
		else if (*klawisz == 27) *kierunek = 0;
	}
}

// funkcja zawiera getch()
int Pobierz()
{
	return getch();
}

// funkcja odpowiada za system("CLS");
void CzyscEkran()
{
	system("CLS");
}