#include "Gra.h"
#include "Konsola.h"

// funkcja odpowiada za czyszczene planszy przed rozpoczeciem rozgrywki
void CzyszczeniePlanszy(int **wysokosc, int **szerokosc)
{
	int i, j;
	for (i = 0; i < **szerokosc;i++)
		for (j = 0;j < **wysokosc;j++)
			pole[i][j] = '\0';
}

// funkcja odpowiada za usuwanie weza i jedzenia z talicy pole
void CzyszczenieWeza(int **wysokosc, int **szerokosc)
{
	int i, j;
	for (i = 0; i < **szerokosc;i++)
		for (j = 0;j < **wysokosc;j++)
			if (pole[i][j] == 'w' || pole[i][j] == 'j')
				pole[i][j] = '\0';

}

// funkcja odpowiada za wyswietlenie poczatkowego stanu planszy wraz z ramkami
void RysujPlansze(int szerokosc, int wysokosc)
{
	//czyszczenie konsoli pod wyswietlenie gry
	CzyscEkran();

	// rysowanie gornej krawedzi     
	//printf("É");
	for (int i = 0;i <= szerokosc;i++)
		printf("ÜÜ");
	printf("\n");

	// rysowanie bocznych krawedzi
	for (int i = 0; i < wysokosc;i++)
	{
		printf("Û");

		for (int j = 0;j < szerokosc;j++)
		{
			if (pole[j][i] == '\0') printf("  ");      // wyswietla puste pole
			else if (pole[j][i] == 'w') printf("²²"); // wyswietla ikonke weza
			else if (pole[j][i] == 'j') printf("°°"); // wyswietla ikonke jedzenia
			else if (pole[j][i] == 'b') printf("ÛÛ"); //rysowanie blokow przeszkod
			else                        printf("cc"); // wyswietla 'cc'. Ma to za zadanie pokazac bledy w wyswietlaniu tablicy


		}
		if (wysokosc > 15)
		{
			if (i == 1) printf("ÛS\n");
			else if (i == 2) printf("ÛN\n");
			else if (i == 3) printf("ÛA\n");
			else if (i == 4) printf("ÛK\n");
			else if (i == 5) printf("ÛE\n");

			else if (i == 7) printf("ÛB\n");
			else if (i == 8) printf("ÛY\n");

			else if (i == 10) printf("ÛF\n");
			else if (i == 11) printf("ÛI\n");
			else if (i == 12) printf("ÛL\n");
			else if (i == 13) printf("ÛI\n");
			else if (i == 14) printf("ÛP\n");
			else  printf("Û\n");
		}

		else if (wysokosc >= 5)
		{
			if (i == 0) printf("ÛS\n");
			else if (i == 1) printf("ÛN\n");
			else if (i == 2) printf("ÛA\n");
			else if (i == 3) printf("ÛK\n");
			else if (i == 4) printf("ÛE\n");
			else  printf("Û\n");
		}


	}

	// rysowanie dolej krawedzi
	//printf("È");
	for (int i = 0;i <= szerokosc;i++)
		printf("ßß");
	//printf("¼");
}

// funkcja wyswietla glowe weza, dodawanie jej do pola i historii
void WywietlGlowe(int *XWeza, int *YWeza, int *XMapy, int *YMapy, int *liczbaObrotowPetli, int *dlugoscWeza)
{
	*XMapy = *XWeza * 2 + 1;
	*YMapy = *YWeza + 1;
	IdzDo(&XMapy, &YMapy);
	printf("²²"); // wyswietlanie wyswietlanieglowy weza

	historiaX[*liczbaObrotowPetli] = *XWeza;
	historiaY[*liczbaObrotowPetli] = *YWeza;

}

// funkcja odpowiada za czyszczenie glowy weza 
void UsunOgon(int *XMapy, int *YMapy, int *liczbaObrotowPetli, int *dlugoscWeza)
{
	if (*dlugoscWeza >= 4) //warunek pozwala nie usuwac ogona, zanim nie zostanie wygenerowany caly
	{
		if (*liczbaObrotowPetli < *dlugoscWeza)
		{
			*XMapy = 2 * historiaX[abs(100 - (*dlugoscWeza - *liczbaObrotowPetli))] + 1;
			*YMapy = historiaY[abs(100 - (*dlugoscWeza - *liczbaObrotowPetli))] + 1;
		}
		else
		{
			*XMapy = 2 * historiaX[abs(*liczbaObrotowPetli - *dlugoscWeza)] + 1;
			*YMapy = historiaY[abs(*liczbaObrotowPetli - *dlugoscWeza)] + 1;
		}

		if (*dlugoscWeza >= 4)
		{
			if (*liczbaObrotowPetli < *dlugoscWeza)
			{
				pole[historiaX[abs(100 - (*dlugoscWeza - *liczbaObrotowPetli))]][historiaY[abs(100 - (*dlugoscWeza - *liczbaObrotowPetli))]] = '\0';
			}
			else
				pole[historiaX[abs(*liczbaObrotowPetli - *dlugoscWeza)]][historiaY[abs(*liczbaObrotowPetli - *dlugoscWeza)]] = '\0';

		}

		IdzDo(&XMapy, &YMapy);
		printf("  ");
	}
}

// funkcja odpowiada za wyswietlanie planszy wyniku
void WyswietlWynik(int *XMapy, int *YMapy, int *wynik)
{
	*XMapy = 0;
	*YMapy = 0;
	IdzDo(&XMapy, &YMapy);
	printf("Zjadles: %d", *wynik);
}

// funkcja odpowiada za losowanie startowej pozycji weza
void LosujGlowe(int **wysokosc, int **szerokosc, int *XWeza, int *YWeza)
{
	srand(time(NULL));
	do
	{
		*XWeza = rand() % (**szerokosc - 2);
		*YWeza = rand() % **wysokosc;
	} while (pole[*XWeza][*YWeza] == 'b' || pole[*XWeza+1][*YWeza] == 'b');
	pole[*XWeza][*YWeza] = 'w';
}

// funkcja odpowiada za losowanie pokarmu dla weza
void LosujPokarm(int ** wysokosc, int ** szerokosc, int * XMapy, int *YMapy, int * XJedzenia, int * YJedzenia, int * dlugoscWeza)
{
	srand(time(NULL));
	do
	{
		*YJedzenia = rand() % **wysokosc;
		*XJedzenia = rand() % **szerokosc;
	} while (pole[*XJedzenia][*YJedzenia] == 'w' || pole[*XJedzenia][*YJedzenia] == 'b');

	pole[*XJedzenia][*YJedzenia] = 'j';
	*XMapy = 2 * (*XJedzenia) + 1;
	*YMapy = *YJedzenia + 1;
	IdzDo(&XMapy, &YMapy);
	printf("°°");
}

// funkcja odpowiada za "przechodzenie przez sciany" lub zgon przy zderzeniu sie z nimi
int KolizjaZeScianami(int *XWeza, int *YWeza, int **szerokosc, int **wysokosc, int przechodzeniePrzezSciany)
{
	if (przechodzeniePrzezSciany != 1)
	{
		if (*XWeza == **szerokosc) *XWeza = 0;
		else if (*XWeza == -1)   *XWeza = **szerokosc - 1;
		if (*YWeza == **wysokosc) *YWeza = 0;
		else if (*YWeza == -1) *YWeza = **wysokosc - 1;
	}
	else if (przechodzeniePrzezSciany == 1)
	{
		if (*XWeza == **szerokosc) return 0;
		else if (*XWeza == -1)   return 0;
		if (*YWeza == **wysokosc) return 0;
		else if (*YWeza == -1) return 0;
	}

	return 1;
}

// funkcja odpowiada za rysowanie ramki na ekranie
int Main_UruchomSnake                  // elementy remki: É-lewy gorny, Í-gorny, »-prawy gorny, º-bok, È-lewy dolny, Í-dolny, ¼-rawy dolny
(int *const szerokosc, int *const wysokosc, int *przechodzeniePrzezSciany) //szerokosc i wysokosc pola, po ktorym rusza sie waz + przechodzenie przez sciany
{
	//********************ZMIENNE********************************************************

	int klawisz;
	int XMapy, YMapy; //wspolrzedne mapy
	int liczbaObrotowPetli = 0; //liczba obrocen petli gry
	int dlugoscWeza = 0; // dlugosc aktualna weza
	float szybkosc = 1.0; // szybkosc weza
	char kierunek = 'p'; // okresla kierunek, w ktorym m sie poruszac waz
	int XWeza, YWeza; // polozenie glowy
	int XJedzenia, YJedzenia; // polozenie jedzenia

	//***********************************************************************************

	wynik = 0;

	//Losuj pozycje, a ktorej zacznie grac gracz
	LosujGlowe(&wysokosc, &szerokosc, &XWeza, &YWeza);


	//Wyswietlenie pokarmy
	LosujPokarm(&wysokosc, &szerokosc, &XMapy, &YMapy, &XJedzenia, &YJedzenia, &dlugoscWeza);

	//Rysowanie poczatkowego stanu gry
	RysujPlansze(*szerokosc, *wysokosc);


	do // rozpoczecie wlasciwych mechanizmow gry
	{

		//Zerowanie tablicy hisotorii w celu zwiekszenia ilosci wykonanych ruchow i zaoszczedzenia pamieci
		if ((liczbaObrotowPetli + 1) >= 100)
			liczbaObrotowPetli = 0;
		else
			liczbaObrotowPetli++;

		//Wyswietlanie glowy weza, dodawanie go do pola i historii
		WywietlGlowe(&XWeza, &YWeza, &XMapy, &YMapy, &liczbaObrotowPetli, &dlugoscWeza);
		pole[XWeza][YWeza] = 'w';

		// czyszczenie ogona weza (nadpisywanie)
		UsunOgon(&XMapy, &YMapy, &liczbaObrotowPetli, &dlugoscWeza);

		// wyswietlanie planszy wyniku
		WyswietlWynik(&XMapy, &YMapy, &wynik);

		// "szybkosc" poruszania weza
		Czekaj(&szybkosc);

		// pobiera uderzenie przez uzytkownika
		PobierzJesliIstnieje(&klawisz, &kierunek);

		// okreslenie kierunku rochu weza
		if (kierunek == 'g')      YWeza--;
		else if (kierunek == 'd') YWeza++;
		else if (kierunek == 'p') XWeza++;
		else if (kierunek == 'l') XWeza--;

		// zjadanie "samego siebie" lub przeszkody
		if (pole[XWeza][YWeza] == 'w' || pole[XWeza][YWeza] == 'b')
		{
			CzyszczenieWeza(&wysokosc, &szerokosc);
			return 1;
		}

		// zjadanie pokarmu
		if (YWeza == YJedzenia && XWeza == XJedzenia)
		{
			LosujPokarm(&wysokosc, &szerokosc, &XMapy, &YMapy, &XJedzenia, &YJedzenia, &dlugoscWeza);
			szybkosc += 0.2;
			dlugoscWeza++;
			wynik += 1;
		}

		// przechodzenie od scian lub klizja
		if (!KolizjaZeScianami(&XWeza, &YWeza, &szerokosc, &wysokosc, *przechodzeniePrzezSciany))
		{
			CzyszczenieWeza(&wysokosc, &szerokosc);
			return 1;
		}

		// poczarkowe generowanie dlugosci ogona	
		if (dlugoscWeza < 4)
			dlugoscWeza++;

		// warunki wyjscia z gry
		if (wynik == 100 || kierunek == 0)
		{
			CzyszczenieWeza(&wysokosc, &szerokosc);
			return 1;
		}

	} while (wynik != 100);
}



//*********************Funkcje z Menu.c, ktore wymagaja dostepu do tablicy pole[][]*********************



// funckja pozwala edytowa, rysowac wlasna mape
int EdytorMapy(int ** szerokosc, int ** wysokosc)
{
	RysujPlansze(**szerokosc, **wysokosc);
	int klawisz = 13;
	int x = 2, y = 0;
	int *XMapy, *YMapy;

	XMapy = malloc(sizeof(int));
	YMapy = malloc(sizeof(int));

	x = 0;

	*XMapy = x * 2 + 1;
	*YMapy = y + 1;

	IdzDo(&XMapy, &YMapy);
	printf("°°");

	while (1)
	{

		if (klawisz != 13)
		{
			if (pole[(*XMapy - 1) / 2][*YMapy - 1] == 'b')
			{
				IdzDo(&XMapy, &YMapy);
				printf("ÛÛ");
			}
			else
			{
				IdzDo(&XMapy, &YMapy);
				printf("  ");
			}


			*XMapy = x * 2 + 1;
			*YMapy = y + 1;

			IdzDo(&XMapy, &YMapy);
			printf("°°");
		}


		klawisz = Pobierz();


		//obsluga strzalem i f1...f12
		if (klawisz == 224)    klawisz += Pobierz();
		else if (klawisz == 0) klawisz -= Pobierz();


		//warunki klawiszy
		if (klawisz == 224 + 72 && y != 0)				   	  y--; // gora
		else if (klawisz == 224 + 80 && y != **wysokosc - 1)    y++; // dol
		else if (klawisz == 224 + 77 && x != **szerokosc - 1)   x++; // prawo
		else if (klawisz == 224 + 75 && x != 0)				  x--; // lewo
		else if (klawisz == 27) // esc
		{
			if (PoprawnoscPlanszy(**szerokosc, **wysokosc))
			{
				CzyscEkran();
				free(XMapy);
				free(YMapy);
				return 1;
			}
			else
			{
				int i = 2, j =0;
				CzyscEkran();
				RysujPlansze(**szerokosc, **wysokosc);
				WyswieltKomunikat(&i, &j, "Musisz zostawic miejsce dla weza i jedzenia !");
			}
				
		}
		else if (klawisz == 13) // enter
		{
			if (pole[x][y] == 'b')
				pole[x][y] = '\0';

			else if (pole[x][y] == '\0')
				pole[x][y] = 'b';
		}
		else if (klawisz == 'r') // r
		{
			int *tX = malloc(sizeof(int)), *tY = malloc(sizeof(int));
			*tX = **szerokosc, *tY = **wysokosc;
			CzyszczeniePlanszy(&tX, &tY);
			RysujPlansze(**szerokosc, **wysokosc);
			x = 2, y = 0;
			
			
			WyswieltKomunikat(&x, &y, "r - reset,  esc - zapisz i wyjdz,  enter - postaw/usun,  z - ukryj podpowiedzi");
			x = 0;

			*XMapy = x * 2 + 1;
			*YMapy = y + 1;
			free (tX);
			free (tY);
		}
	}
	free(XMapy);
	free(YMapy);
}

int PoprawnoscPlanszy(int szerokosc, int wysokosc)
{
	int licznikW = 0; // licznik mozliwych pozycji generowania weza
	int i = 0, j = 0;

	for(i = 0 ; i < szerokosc - 1 ; i++)
		for (j = 0; j < wysokosc; j++)
		{
			if (pole[i][j] == '\0' && pole[i+1][j] == '\0')
				licznikW++;
			if (licznikW >= 1)
				return 1;
		}

	return 0;
}