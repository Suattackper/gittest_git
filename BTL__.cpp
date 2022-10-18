#include <stdio.h>
#include <Windows.h>
#include <time.h> // dung trong ham random
#include <stdlib.h> // dung de random so cho AI
#include <string.h> //dung cho strcmp, strcpy
#include <ctype.h> //dung cho toupper
#include <stdbool.h> //dung cho True - False
#include "MyGraphic.h" //thu vien lap trinh vien tu dinh nghia
int DiemPlayer = 0;
int DiemAI = 0;
char Choilai;
char PlayerName[20];

int main() {
	int k{};
	AnhNen();
	do {
		system("cls");
		DiemPlayer = 
	textcolor(116);
	gotoxy(45, 15);
	printf("THANKS FOR PLAYING. SEE YOU AGAIN !!!");
	textcolor(0);
	_getch();
	return 0;
}

void VeTuong() {
	for (int x = 5; x <= 115; x++) {
		gotoxy(x, 2);
		printf("_");
		gotoxy(x, 28);
		printf("_");
	}
	for (int y = 2; y <= 28; y++) {
		if (y == 2) {
			printf(".");
		}
		else {
			gotoxy(4, y);
			printf("|");
			gotoxy(116, y);
			printf("|");
		}
	}
}
void AnhNen() {
	VeTuong();
	VeBua(47, 9);
	VeKeo(19, 8);
	VeBao(80, 8);
	for (int i = 1; i <= 15; i++) {
		textcolor(i);
		gotoxy(40, 4);
		printf("WELCOME TO ROCK - PAPER - SCISSORS GAME");
		Sleep(200);
	}
	gotoxy(40, 20);
	textcolor(15);
	printf("Enter your name: ");
	fflush(stdin);
	gets(PlayerName);
	gotoxy(55, 22);
	printf("Loadding...\n");
	int dc = 10;
	for (int i = 1; i <= 100; i++) {
		textcolor(8);
		gotoxy(dc, 24);
		printf("#");
		Sleep(50);
		dc += 1;
		gotoxy(58, 25);
		printf("%d %%", i);
	}
	XoaManHinh();
}
void NewGame() {
	do {
		system("cls");
		VeTuong();
		VeBua(47, 11);
		VeKeo(19, 10);
		VeBao(80, 10);
		textcolor(11);
		gotoxy(51, 4);
		printf("%s score: %d", PlayerName, DiemPlayer);
		gotoxy(51, 5);
		printf("AI score: %d", DiemAI);
		gotoxy(28, 20);
		textcolor(250);
		printf(" 1 ");
		gotoxy(59, 20);
		textcolor(246);
		printf(" 2 ");
		gotoxy(90, 20);
		textcolor(252);
		printf(" 3 ");
		gotoxy(49, 24);
		textcolor(11);
		printf("Nhan phim so de chon: ");
		scanf("%d", &ipPlayer);
	} while (ipPlayer != 1 && ipPlayer != 2 && ipPlayer != 3);
	system("cls");
	VeTuong();
	switch (ipPlayer)
	{
	case 1:
		strcpy(Player, "KEO");
		VeKeo(19, 11);
		break;
	case 2:
		strcpy(Player, "BUA");
		VeBua(16, 11);
		break;
	default:
		strcpy(Player, "BAO");
		VeBao(19, 11);
		break;
	}
	srand(time(0));
	int AI_brain;
	AI_brain = (rand() % 3) + 1;
	switch (AI_brain) {
	case 1:
		strcpy(AI, "BUA");
		VeBua(80, 11);
		break;
	case 2:
		strcpy(AI, "KEO");
		VeKeo(80, 11);
		break;
	default:
		strcpy(AI, "BAO");
		VeBao(80, 11);
		break;
	}
	Display_Score(AI, Player);
}
void Display_Score(char AI[], char Player[]) {
	if (strcmp(Player, AI) == 0) {
		VeDraw(50, 7);
	}
	else {
		if (strcmp(Player, "BUA") == 0) {
			if (strcmp(AI, "KEO") == 0) {
				VeWin(50, 10);
				DiemPlayer++;
			}
			else {
				VeLoss(52, 7);
				DiemAI++;
			}
		}
		else if (strcmp(Player, "KEO") == 0) {
			if (strcmp(AI, "BUA") == 0) {
				VeLoss(52, 7);
				DiemAI++;
			}
			else {
				VeWin(50, 10);
				DiemPlayer++;
			}
		}
		else {
			if (strcmp(AI, "BUA") == 0) {
				VeWin(50, 10);
				DiemPlayer++;
			}
			else {
				VeLoss(52, 7);
				DiemAI++;
			}
		}
	}
}
void Vong(int k) {
	do {
		system("cls");
		VeTuong();
		VeBua(47, 9);
		VeKeo(19, 8);
		VeBao(80, 8);
		textcolor(116);
		gotoxy(40, 4);
		printf("WELCOME TO ROCK - PAPER - SCISSORS GAME");
		gotoxy(40, 20);
		textcolor(15);
		printf("Ban muon choi bao nhieu hiep: ");
		scanf("%d", &k);
	} while (k <= 0);
	system("cls");
	for (int i = 0; i < k; i++) {
		NewGame();
		Sleep(1000);
		system("cls");
	}
}
bool PlayAgain(char Choilai) {
	do {
		system("cls");
		VeTuong();
		if (DiemPlayer > DiemAI) {
			VeWin(50, 10);
		}
		else if (DiemPlayer < DiemAI) {
			VeLoss(52, 7);
		}
		else {
			VeDraw(50, 7);
		}
		gotoxy(20, 14);
		printf("%s score: %d", PlayerName, DiemPlayer);
		gotoxy(20, 16);
		printf("AI score: %d", DiemAI);
		gotoxy(85, 15);
		printf("Ban co muon choi lai(Y/N): ");
		fflush(stdin);
		scanf("%c", &Choilai);
		Choilai = toupper(Choilai);
	} while (Choilai != 'Y' && Choilai != 'N');
	if (Choilai == 'Y') {
		return true;
	}
	else {
		return false;
	}
}
