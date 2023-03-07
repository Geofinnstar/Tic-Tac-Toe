struct Board {
	char boardState[9];
	int playerTurn;
} typedef Board;

char decideBoardCharacter(int x, int y, char value) {
	if (x % 4 == 0 && y % 2 == 0) {
		return '+';
	}

	if (y % 2 == 0) {
		return '-';
	}

	if (x % 4 == 0 && y % 2 == 1) {
		return '|';
	}

	if ((x + 2) % 4 == 0 && y % 2 == 1) {
		return value;
	}

	return SPACE;

}

Board createNewBoard(int turn, char *boardState) {
	Board board;

	for (int i = 0; i < 9; i++) {
		board.boardState[i] = boardState[i];
	}

	board.playerTurn = turn;

	return board;
}

void drawBoard(Board board) {
	char printBoard[256];
	int count = 0;
	int currentValue = -1;

	for (int y = 0; y < BOARD_VERTICAL_SIZE; y++) {
		for (int x = 0; x < BOARD_HORIZONTAL_SIZE; x++) {
			if ((x + 2) % 4 == 0 && y % 2 == 1) { currentValue++; }
			printBoard[count] = decideBoardCharacter(x, y, board.boardState[currentValue]);

			count++;
		}

		printBoard[count] = '\n';
		count++;
	}

	printBoard[count] = '\0';

	system("cls");
	printf("%s", printBoard);
}

int placeBoardValue(Board *board, int place, char value) {
	if (board->boardState[place] == SPACE && place < 9 && place > -1) {
		board->boardState[place] = value;
		return 0;
	}

	return 1;
}

int isGameWon(Board board) {
	char playerValue = SPACE;

	if (board.boardState[2] != SPACE) {
		playerValue = board.boardState[2];

		// 1 2 3
		if (board.boardState[5] == playerValue && board.boardState[8] == playerValue) {
			if (playerValue == P1)
				return 1;
			return 2;
		}

		// 3 6 9
		if (board.boardState[0] == playerValue && board.boardState[1] == playerValue) {
			if (playerValue == P1)
				return 1;
			return 2;
		}
	}

	if (board.boardState[4] != SPACE) {
		playerValue = board.boardState[4];

		// 1 5 9
		if (board.boardState[0] == playerValue && board.boardState[8] == playerValue) {
			if (playerValue == P1)
				return 1;
			return 2;
		}

		// 3 5 7
		if (board.boardState[2] == playerValue && board.boardState[6] == playerValue) {
			if (playerValue == P1)
				return 1;
			return 2;
		}

		// 2 5 8
		if (board.boardState[1] == playerValue && board.boardState[7] == playerValue) {
			if (playerValue == P1)
				return 1;
			return 2;
		}

		// 4 5 6
		if (board.boardState[3] == playerValue && board.boardState[5] == playerValue) {
			if (playerValue == P1)
				return 1;
			return 2;
		}
	}

	if (board.boardState[6] != SPACE) {
		playerValue = board.boardState[6];

		// 7 8 9
		if (board.boardState[7] == playerValue && board.boardState[8] == playerValue) {
			if (playerValue == P1)
				return 1;
			return 2;
		}

		// 1 4 7
		if (board.boardState[0] == playerValue && board.boardState[3] == playerValue) {
			if (playerValue == P1)
				return 1;
			return 2;
		}
	}

	return 0;
}

void clearBoard(Board *board) {
	for (int i = 0; i < 9; i++) {
		board->boardState[i] = SPACE;
	}

	if (board->playerTurn == 1) {
		board->playerTurn = 2;
	} else {
		board->playerTurn = 1;
	}

	drawBoard(*board);
}