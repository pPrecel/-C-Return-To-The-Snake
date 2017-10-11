#pragma once

#include <Windows.h>
#include <conio.h>

void IdzDo(int ** const XMapy, int ** const YMapy);

void UkryjKursor();

void OdkryjKursor();

void UstawWielkoscOkna();

int Czekaj(int *szybkosc);

void PobierzJesliIstnieje(int *klawisz, int *kierunek);

int Pobierz();