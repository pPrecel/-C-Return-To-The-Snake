#include "Menu.h"

// funkcja odpowiada za wyswietlanie wyniku po zakonczeniu gry
int EkranKoncowy(int *XMapy, int *YMapy)
{

	int klawisz = 0;

	CzyscEkran();

	//rysowane gornej krawedzi
	*XMapy = 47; *YMapy = 4; IdzDo(&XMapy, &YMapy);
	printf("ษอออออออออออออออออออออออป");

	//rysowanie srodka (z napisami)
	*YMapy = 5; IdzDo(&XMapy, &YMapy);
	printf("บ      Koniec Gry!      บ");

	*YMapy = 6; IdzDo(&XMapy, &YMapy);
	printf("บ      Wynik: %.3d       บ", wynik);

	*YMapy = 7; IdzDo(&XMapy, &YMapy);
	printf("บ   Gra dalej? ENTER   บ");

	*YMapy = 8; IdzDo(&XMapy, &YMapy);
	printf("บ Konczymy na dzi? ESC บ");

	//rysowanie dolnej krawedzi
	*YMapy = 9; IdzDo(&XMapy, &YMapy);
	printf("ศอออออออออออออออออออออออผ");

	*XMapy = 0; *YMapy = 0; IdzDo(&XMapy, &YMapy);

	while (klawisz != 27 && klawisz != 9)
	{
		klawisz = Pobierz();

		if (klawisz == 27) return 0; // ESC - zakoncz gre
		else if (klawisz == 13) return 1; //ENTER - od nowa
	}
}


// funkcja wyswietla opcje edytora map
void WyswietlOpcjeEdytora(int *XMenu, int *YMenu)
{
	//rysowane gornej krawedzi
	*XMenu = 47; *YMenu = 7; IdzDo(&XMenu, &YMenu);
	printf("ษอออออออออออออออออออออออป");

	//rysowanie srodka (z napisami)
	*YMenu = 8; IdzDo(&XMenu, &YMenu);
	printf("บ  esc- wyjdซ i zapisz  บ");

	*YMenu = 9; IdzDo(&XMenu, &YMenu);
	printf("บ  enter - postaw/usuไ  บ");

	*YMenu = 10; IdzDo(&XMenu, &YMenu);
	printf("บ       r - reset       บ");

	*YMenu = 11; IdzDo(&XMenu, &YMenu);
	printf("บ                       บ");

	*YMenu = 12; IdzDo(&XMenu, &YMenu);
	printf("บ     Nacinij  co     บ");

	//rysowanie dolnej krawedzi
	*YMenu = 13; IdzDo(&XMenu, &YMenu);
	printf("ศอออออออออออออออออออออออผ");
}

// funkcja odpowiada za rysowanie loga gry
void WyswietlLogo()
{
	int *X = malloc(sizeof(int));
	int *Y = malloc(sizeof(int));

	*X = 53;
	*Y = 1;
	IdzDo(&X, &Y);
	printf("Return to The");

	*Y = 2;
	IdzDo(&X, &Y);
	printf("ษออษปบษอปบษษอ");

	*Y = 3;
	IdzDo(&X, &Y);
	printf("ศอปบบบฬอนฬนฬอ");

	*Y = 4;
	IdzDo(&X, &Y);
	printf("ออผบศผบ บบศศอ");

	free(X);
	free(Y);
}

// funkcja odpowiada za wyswietlenie menu glownego
void WyswietlMenuGlowne(int *XMenu, int *YMenu)
{
	WyswietlLogo();

	//rysowane gornej krawedzi
	*XMenu = 47; *YMenu = 7; IdzDo(&XMenu, &YMenu);
	printf("ษอออออออออออออออออออออออป");

	//rysowanie srodka (z napisami)
	*YMenu = 8; IdzDo(&XMenu, &YMenu);
	printf("บ     Stwขrz Poziom     บ");

	*YMenu = 9; IdzDo(&XMenu, &YMenu);
	printf("บ     Gotowy Poziom     บ");

	*YMenu = 10; IdzDo(&XMenu, &YMenu);
	printf("บ         Wyjdซ         บ");

	//rysowanie dolnej krawedzi
	*YMenu = 11; IdzDo(&XMenu, &YMenu);
	printf("ศอออออออออออออออออออออออผ");
}

// funkja odpowiada za wyswietlenie menu Stworz Poziom
void WyswietlMenuStworzPoziom(int *XMenu, int *YMenu, int **szerokosc, int **wysokosc, int **przechodzenie)
{
	WyswietlLogo();

	//rysowane gornej krawedzi
	*XMenu = 47; *YMenu = 7; IdzDo(&XMenu, &YMenu);
	printf("ษอออออออออออออออออออออออป ษออป");

	//rysowanie srodka (z napisami)
	*XMenu = 47; *YMenu = 8; IdzDo(&XMenu, &YMenu);
	printf("บ     Szeroko Pola    บ บ  บ");

	*YMenu = 9; IdzDo(&XMenu, &YMenu);
	printf("บ     Wysoko  Pola    บ บ  บ");

	*YMenu = 10; IdzDo(&XMenu, &YMenu);
	printf("บ         Kolizje       บ บ  บ");

	*YMenu = 11; IdzDo(&XMenu, &YMenu);
	printf("บ      Edytor  Mapy     บ ศออผ");

	*YMenu = 12; IdzDo(&XMenu, &YMenu);
	printf("บ         Graj!         บ");

	*YMenu = 13; IdzDo(&XMenu, &YMenu);
	printf("บ         Wyjdซ         บ");

	//rysowanie dolnej krawedzi
	*YMenu = 14; IdzDo(&XMenu, &YMenu);
	printf("ศอออออออออออออออออออออออผ");


	//dopisywanie szerokosci, wysokosci i przechodzenie przez sciany
	*XMenu = 74; *YMenu = 8; IdzDo(&XMenu, &YMenu);
	printf("%.2d", **szerokosc);

	*YMenu = 9; IdzDo(&XMenu, &YMenu);
	printf("%.2d", **wysokosc);

	*YMenu = 10; IdzDo(&XMenu, &YMenu);

	if (**przechodzenie == 1)
		printf("t");
	else if (**przechodzenie == 0)
		printf("n");
}

// funkcja odpowiada za wyswietlenie menu gotowych poziomow
void WyswietlMenuGotowyPoziom(int *XMenu, int *YMenu)
{
	//rysowanie srodka (z napisami)
	*XMenu = 47; *YMenu = 8; IdzDo(&XMenu, &YMenu);
	printf("บ         25x25         บ");

	*YMenu = 9; IdzDo(&XMenu, &YMenu);
	printf("บ         58x28         บ");

	*YMenu = 10; IdzDo(&XMenu, &YMenu);
	printf("บ         Wyjdซ         บ");
}

// funkcja odpowiada za zwrocenie pozycji wybranego elementu przez uzytkownika
int ObsluzMenu(int *XMenu, int *YMenu, int * const wyborZMenuGlownego, int * DoIlu)
{

	// ฒ - ikonka glowy weza/celownik w menu
	int klawisz = 0, licznik = 0; // pobiera ascii klawisza wcisnietego przez uzytkownika | zlicza posuniecie w gore i dol
	int i;

	for (i = 0; i < 3; i++)
	{
		*XMenu = 49; *YMenu = 8 + i; IdzDo(&XMenu, &YMenu);
		printf(" ");
		*XMenu = 69; *YMenu = 8 + i; IdzDo(&XMenu, &YMenu);
		printf(" ");
	}


	// wyswietlanie poczatkowego stanu celownikow
	*XMenu = 49; *YMenu = 8; IdzDo(&XMenu, &YMenu);
	printf("ฒ");
	*XMenu = 69; *YMenu = 8; IdzDo(&XMenu, &YMenu);
	printf("ฒ");
	*XMenu = 0; *YMenu = 0; IdzDo(&XMenu, &YMenu);

	//petla komunikatow zbierajaca dane co wciska uzytkownik
	do
	{
		klawisz = 0;
		klawisz = Pobierz();

		switch (klawisz)
		{
		case 72: // w g๓r๊ -----------------------------------
			if (licznik != 0)
			{
				// usuwanie starego celownika
				*XMenu = 49; *YMenu = 8 + licznik; IdzDo(&XMenu, &YMenu);
				printf(" ");
				*XMenu = 69; *YMenu = 8 + licznik; IdzDo(&XMenu, &YMenu);
				printf(" ");

				licznik--;
				// dodawanie nowego celownika
				*XMenu = 49; *YMenu = 8 + licznik; IdzDo(&XMenu, &YMenu);
				printf("ฒ");
				*XMenu = 69; *YMenu = 8 + licznik; IdzDo(&XMenu, &YMenu);
				printf("ฒ");
				*XMenu = 0; *YMenu = 0; IdzDo(&XMenu, &YMenu);
			}
			break;


		case 80: //w dol -----------------------------------
			if (licznik != DoIlu)
			{
				// usuwanie starego celownika
				*XMenu = 49; *YMenu = 8 + licznik; IdzDo(&XMenu, &YMenu);
				printf(" ");
				*XMenu = 69; *YMenu = 8 + licznik; IdzDo(&XMenu, &YMenu);
				printf(" ");

				licznik++;
				// dodawanie nowego celownika
				*XMenu = 49; *YMenu = 8 + licznik; IdzDo(&XMenu, &YMenu);
				printf("ฒ");
				*XMenu = 69; *YMenu = 8 + licznik; IdzDo(&XMenu, &YMenu);
				printf("ฒ");
				*XMenu = 0; *YMenu = 0; IdzDo(&XMenu, &YMenu);
			}
			break;


		case 13:  // -----------------------------------
		{
			// usuwanie starego celownika
			*XMenu = 49; *YMenu = 8 + licznik; IdzDo(&XMenu, &YMenu);
			printf(" ");
			*XMenu = 69; *YMenu = 8 + licznik; IdzDo(&XMenu, &YMenu);
			printf(" ");

			return licznik;
		}

		}
	} while (1);

}

// funkcja odpowiada za odbieranie od uzytkownika wysokosci i szerokosci
int  PodajZmienna(int *XMenu, int *YMenu)
{
	int liczba[2] = { -1,-1 }; //tablica zawiera liczbe podawana przez gracza
	int klawisz = 0; //ascii wczytanego klawisza
	int iloscRuchow = 0; //okresla pozycje, ktora aktualnie wskazujemy (dziesiatki, jednosci)

	*XMenu = 59; *YMenu = 21; IdzDo(&XMenu, &YMenu);



	while (1)
	{
		OdkryjKursor();

		klawisz = Pobierz();

		if (klawisz == 27)//esc	
		{
			//czyszczenie pola bufora i pola bledu
			*XMenu = 47, *YMenu = 16, IdzDo(&XMenu, &YMenu);
			printf("                          ");
			*XMenu = 59; *YMenu = 21; IdzDo(&XMenu, &YMenu);
			printf("  ");

			//czyszczenie celownika
			*XMenu = 49; *YMenu = 8; IdzDo(&XMenu, &YMenu);
			printf(" ");
			*XMenu = 69; *YMenu = 8; IdzDo(&XMenu, &YMenu);
			printf(" ");
			*XMenu = 0; *YMenu = 0; IdzDo(&XMenu, &YMenu);

			UkryjKursor();

			return -88732; // "kod" ESC
		}
		else if (klawisz == 13)//enter
		{
			//czyszczenie pola bufora i pola bledu
			*XMenu = 47, *YMenu = 16, IdzDo(&XMenu, &YMenu);
			printf("                          ");
			*XMenu = 59; *YMenu = 21; IdzDo(&XMenu, &YMenu);
			printf("  ");


			UkryjKursor();

			if (liczba[1] == -1)
				return liczba[0];
			else
				return (10 * liczba[0]) + liczba[1];
		}
		else if (klawisz == 8) //backspace
		{
			if (iloscRuchow == 1)
			{
				*XMenu = 60, IdzDo(&XMenu, &YMenu);
				printf(" ");

				liczba[iloscRuchow] = -1;
				iloscRuchow--;

				*XMenu = 59, IdzDo(&XMenu, &YMenu);
			}
			else if (iloscRuchow == 0)
			{
				*XMenu = 59, IdzDo(&XMenu, &YMenu);
				printf(" ");

				liczba[iloscRuchow] = -1;
				*XMenu = 59, IdzDo(&XMenu, &YMenu);
			}
		}
		else if (klawisz >= 48 && klawisz <= 57)// 0-9
		{
			printf("%d", klawisz - 48);
			liczba[iloscRuchow] = klawisz - 48;

			if (iloscRuchow == 1)
				*XMenu = 60, IdzDo(&XMenu, &YMenu);
			else
				iloscRuchow++;
		}
	}
}

// funckja odpwiada za odebranie od uzytkownika znaku 
int PodajZnak(int *XMenu, int *YMenu)
{
	int znak = 0; // przzechowuje ASCII 
	int klawisz = 0; //ascii wczytanego klawisza


	OdkryjKursor();


	while (1)
	{
		*XMenu = 59; *YMenu = 21; IdzDo(&XMenu, &YMenu);

		klawisz = Pobierz();

		if (klawisz == 27)//esc	
		{
			//czyszczenie pola bufora i pola bledu
			*XMenu = 47, *YMenu = 16, IdzDo(&XMenu, &YMenu);
			printf("                          ");
			*XMenu = 59; *YMenu = 21; IdzDo(&XMenu, &YMenu);
			printf("  ");

			//czyszczenie celownika
			*XMenu = 49; *YMenu = 6; IdzDo(&XMenu, &YMenu);
			printf(" ");
			*XMenu = 69; *YMenu = 6; IdzDo(&XMenu, &YMenu);
			printf(" ");
			*XMenu = 0; *YMenu = 0; IdzDo(&XMenu, &YMenu);

			UkryjKursor();

			return -88732; // "kod" ESC
		}

		else if (klawisz == 13)//enter
		{
			//czyszczenie pola bufora i pola bledu
			*XMenu = 47, *YMenu = 16, IdzDo(&XMenu, &YMenu);
			printf("                          ");
			*XMenu = 59; *YMenu = 21; IdzDo(&XMenu, &YMenu);
			printf("  ");


			UkryjKursor();

			return znak;
		}

		else if (klawisz == 8) //backspace
		{
			znak = 0;
			printf(" ");
		}

		else if (klawisz >= 32 && klawisz <= 126)
		{
			znak = klawisz;
			printf("%c", klawisz);
		}
	}
}

// funkcja odpowiada za wyswietlanie aktualnej wysokosci i szerokosci, podczas tworzenia wlasnej planszy
void WyswietlZmienna(int *XMenu, int *YMenu, int **zmienna, int YWyswietlania)
{
	*XMenu = 74; *YMenu = 7 + YWyswietlania; IdzDo(&XMenu, &YMenu);

	printf("%.2d", **zmienna);
}

// funcka odpowiada za wyswietlanie znaku w wybranym miejscu
void WysiwetlZnak(int *XMenu, int *YMenu, int **znak)
{
	IdzDo(&XMenu, &YMenu);

	printf("%c", **znak);
}

// funkcja odpowiada za wyswietlanie komuniatu bledu
void WyswieltKomunikat(int *XMenu, int *YMenu, char komunikat[])
{
	int i = 0;
	IdzDo(&XMenu, &YMenu);
	for(i ; komunikat[i] != '\0' ; i++)
		printf("%c", komunikat[i]);
}

// elementy remki: ษ-lewy gorny, อ-gorny, ป-prawy gorny, บ-bok, ศ-lewy dolny, อ-dolny, ผ-rawy dolny
int Main_Menu(int * const szerokosc, int * const wysokosc, int *przechodzeniePrzezSciany)
{
	//********************ZMIENNE*************************************

	int XMenu = 0, YMenu = 0;
	int wyborZMenu = 0;
	const int kodWyjscia = -88732; // kod, ktory zwraca funkcja, a ktory ma swiatczyc o wyjsciu z funkcji

	//****************************************************************


	
	while (1)
	{
		CzyscEkran();
		WyswietlMenuGlowne(&XMenu, &YMenu);
		wyborZMenu = ObsluzMenu(&XMenu, &YMenu, &wyborZMenu, 2);

		switch (wyborZMenu)
		{
		case 0: // wybran Stworz Poziom  -------------------------------------------------------------

			WyswietlMenuStworzPoziom(&XMenu, &YMenu, &szerokosc, &wysokosc, &przechodzeniePrzezSciany);
			do
			{
				wyborZMenu = ObsluzMenu(&XMenu, &YMenu, &wyborZMenu, 5);

				if (wyborZMenu == 0) // podawanie szerokosci
				{
					int historiaSzerokosci = *szerokosc;
					do
					{
						*szerokosc = PodajZmienna(&XMenu, &YMenu);

						// wszystko ok
						if (*szerokosc >= 5 && *szerokosc <= 58)
						{
							WyswietlZmienna(&XMenu, &YMenu, &szerokosc, 1);
							break;
						}

						// jesli klikniemy esc
						if (*szerokosc == kodWyjscia)
						{
							*szerokosc = historiaSzerokosci;
							break;
						}	

						// wypisywanie komunikatu bledu
						XMenu = 47; YMenu = 16;
						WyswieltKomunikat(&XMenu, &YMenu, "Zakres dozwolony to 5 - 58");						
					} while (1);
				}
					

				else if (wyborZMenu == 1)
				{
					int historiaWysokosci = *wysokosc;
					do
					{

						*wysokosc = PodajZmienna(&XMenu, &YMenu);

						// wszystko ok
						if (*wysokosc >= 5 && *wysokosc <= 28)
						{
							WyswietlZmienna(&XMenu, &YMenu, &wysokosc, 2);
							break;
						}

						// jesli klikniemy esc
						if (*wysokosc == kodWyjscia)
						{
							*wysokosc = historiaWysokosci;
							break;
						}

						// wypisywanie komunikatu bledu
						XMenu = 47; YMenu = 16;
						WyswieltKomunikat(&XMenu, &YMenu, "Zakres dozwolony to 5 - 28");					
					} while (1);
				}
					
				
				else if (wyborZMenu == 2) // przechodzeni przez sciany(t/n)
				{
					int historiaPrzechodzenia = *przechodzeniePrzezSciany;
					while (1)
					{
						*przechodzeniePrzezSciany = PodajZnak(&XMenu, &YMenu);

						// jesli wszystko jest ok
						if (*przechodzeniePrzezSciany == '0' || *przechodzeniePrzezSciany == 'n' || *przechodzeniePrzezSciany == 'N'
							|| *przechodzeniePrzezSciany == '1' || *przechodzeniePrzezSciany == 't' || *przechodzeniePrzezSciany == 'T')
						{
							XMenu = 74; YMenu = 10;
							WysiwetlZnak(&XMenu, &YMenu, &przechodzeniePrzezSciany);

							if (*przechodzeniePrzezSciany == '0' || *przechodzeniePrzezSciany == 'n' || *przechodzeniePrzezSciany == 'N')
								*przechodzeniePrzezSciany = 0;
							if (*przechodzeniePrzezSciany == '1' || *przechodzeniePrzezSciany == 't' || *przechodzeniePrzezSciany == 'T')
								*przechodzeniePrzezSciany = 1;

							break;
						}

						// jesli klikniemy esc
						if (*przechodzeniePrzezSciany == kodWyjscia)
						{
							*przechodzeniePrzezSciany = historiaPrzechodzenia;
							break;
						}

						// wypisywanie komunikatu bledu
						XMenu = 47; YMenu = 16;
						WyswieltKomunikat(&XMenu, &YMenu, "Mozesz podac: t,n,T,N,1,0");					
					}
				}           

				else if (wyborZMenu == 3) // edytor mapy
				{
					CzyscEkran();
					WyswietlLogo();

					WyswietlOpcjeEdytora(&XMenu, &YMenu);
					Pobierz();

					EdytorMapy(&szerokosc, &wysokosc);

					CzyscEkran;
					WyswietlMenuStworzPoziom(&XMenu, &YMenu, &szerokosc, &wysokosc, &przechodzeniePrzezSciany);

					continue;
				}

				else if (wyborZMenu == 4)	// graj		
					return 1;
				
				else if (wyborZMenu == 5)   // wyjdz
					break;

			} while (1);
			break;


		case 1: // wybrano Gotowy Poziom -------------------------------------------------------------
			WyswietlMenuGotowyPoziom(&XMenu, &YMenu);
			wyborZMenu = ObsluzMenu(&XMenu, &YMenu, &wyborZMenu, 2);
			
			if (wyborZMenu == 0)
			{
				//Czysc plansze
				CzyszczeniePlanszy(&wysokosc, &szerokosc);

				*przechodzeniePrzezSciany = 0;
				*szerokosc = 25;
				*wysokosc = 25;
				return 1;
			}
			else if (wyborZMenu == 1)
			{
				//Czysc plansze
				CzyszczeniePlanszy(&wysokosc, &szerokosc);

				*przechodzeniePrzezSciany = 0;
				*szerokosc = 58;
				*wysokosc = 28;
				return 1;
			}
			else if (wyborZMenu == 2)
				continue;
			break;


		case 2: // wybrano Wyjscie       -------------------------------------------------------------
			return 0;
			break;
		}
	}
}