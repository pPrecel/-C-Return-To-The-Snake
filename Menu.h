#pragma once

#include <stdio.h>
#include <stdlib.h>

extern wynik; //wynik externowany z Gra.c

int EkranKoncowy(int *XMapy, int *YMapy);

void WyswietlOpcjeEdytora(int *Xmenu, int *Ymenu);

void WyswietlLogo();

int Main_Menu(int * const szerokosc, int * const wysokosc);

void WyswietlMenuGlowne(int *XMenu, int *YMenu);

void WyswietlMenuStworzPoziom(int *XMenu, int *YMenu);

void WyswietlMenuGotowyPoziom(int *XMenu, int *YMenu);

int ObsluzMenu(int *XMenu, int *YMenu, int * const wyborZMenuGlownego, int DoIlu);

int  PodajZmienna(int *XMenu, int *YMenu, int *DoIlu);

int PodajZnak(int *XMenu, int *YMenu);

void WyswieltKomunikat(int *XMenu, int *YMenu, char komunikat[]);

void WyswietlZmienna(int *XMenu, int *YMenu, int **zmienna, int YWyswietlania);



