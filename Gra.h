#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

//********************ZMIENNE********************************************************

char pole[58][28]; // \0-pole puste, w-pole weza, j-jedzenie , b-blok przeszkody
int wynik = 0; //okrela ile pokarmu zjedlimy, zanim przegralismy
int historiaX[100], historiaY[100]; // zmienne przechowujace historie ruchow weza

//***********************************************************************************

void CzyszczeniePlanszy(int **wysokosc, int **szerokosc);

void CzyszczenieWeza(int **wysokosc, int **szerokosc);

void RysujPlansze(int **szerokosc, int **wysokosc);

void WywietlGlowe(int *XWeza, int *YWeza, int *XMapy, int *YMapy, int *liczbaObrotowPetli, int *dlugoscWeza);

void UsunOgon(int *XMapy, int *YMapy, int *liczbaObrotowPetli, int *dlugoscWeza);

void WyswietlWynik(int *XMapy, int *YMapy, int *wynik);

void LosujGlowe(int **wysokosc, int **szerokosc, int *XWeza, int *YWeza);

void LosujPokarm(int ** wysokosc, int ** szerokosc, int * XMapy, int *YMapy, int * XJedzenia, int * YJedzenia, int * dlugoscWeza);

int KolizjaZeScianami(int *XWeza, int *YWeza, int **szerokosc, int **wysokosc, int *przechodzeniePrzezSciany);

int Main_UruchomSnake(int *const szerokosc, int *const wysokosc);