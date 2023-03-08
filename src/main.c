#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int random(int max) {
    srand((unsigned) time(NULL));
    return rand() % max;
}

#include "board.c"
#include "ai.c"

int main() {
	char boardState[9] = {SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE};
	Board board = createNewBoard(1, boardState);
	int putPlace = 0;
	bool running = true;
	int win = 0;
	int temp = 0;

	drawBoard(board);
	while (running) {
		printf("Place at: ");
		scanf("%d", &putPlace);
		temp = placeBoardValue(&board, putPlace - 1, P1);

		while (temp == 1) {
			printf("Cannot place there!\n");
			getch();
			drawBoard(board);
			scanf("%d", &putPlace);
			temp = placeBoardValue(&board, putPlace - 1, P1);
		}
		temp = 0;

		drawBoard(board);
		win = isGameWon(board);

		if (win == 1) {
			printf("You win!\n");
			getch();
			clearBoard(&board);
		}
		if (win == 2) {
			printf("You lose!\n");
			getch();
			clearBoard(&board);
		}

		bool boardFull = true;
		for (int i = 0; i < 9; i++) {
			if (board.boardState[i] == SPACE) {
				boardFull = false;
			}
		}

		if (boardFull) {
			win = isGameWon(board);

			if (win == 0) {
				printf("It's a tie!\n");
				getch();
				clearBoard(&board);
			}
		}

		makeAIMove(&board);
		drawBoard(board);
		win = isGameWon(board);

		if (win == 1) {
			printf("You win!\n");
			getch();
			clearBoard(&board);
		}
		if (win == 2) {
			printf("You lose!\n");
			getch();
			clearBoard(&board);
		}

		boardFull = true;
		for (int i = 0; i < 9; i++) {
			if (board.boardState[i] == SPACE) {
				boardFull = false;
			}
		}

		if (boardFull) {
			win = isGameWon(board);

			if (win == 0) {
				printf("It's a tie!\n");
				getch();
				clearBoard(&board);
			}
		}
	}

	return 0;
}