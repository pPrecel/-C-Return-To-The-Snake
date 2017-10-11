#include "Main.h"
#include "Konsola.h"

//Glowwna funkcja rozruchowa
main()
{
	//********************ZMIENNE*************************************

	int ZwrotWGore, ZwrotWDol, ZwrotWLewo, ZwrotWPrawo; // zwrot weza
	int szerokosc = 25, wysokosc = 25; // szerokosc i wysokosc planszy
	int przechodzeniePrzezSciany = 1;
	int XMapy = 0, YMapy = 0; // X i Y polozenia kursora konsoli

	//****************************************************************


	//ustawiamy odpowiednia wielkosc okna
	UstawWielkoscOkna();

	//ukrywanie kursora
	UkryjKursor();

	//petla komunikatow gry, menu i ekranu koncowego
	while (Main_Menu(&szerokosc, &wysokosc, &przechodzeniePrzezSciany))
	{
		do
		{
			if (!Main_UruchomSnake(&szerokosc, &wysokosc, &przechodzeniePrzezSciany)) // main gry
				return 0;
		} while (EkranKoncowy(&XMapy, &YMapy));
	}

	return 0;
}