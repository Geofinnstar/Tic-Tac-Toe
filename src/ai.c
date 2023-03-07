int random(int max) {
    srand((unsigned) time(NULL));
    return (rand() % max) + 1;
}

int makeAIMove(Board *board) {
	Board tempBoard;
	int win = 0;

	for (int i = 0; i < 9; i++) {
		tempBoard.boardState[i] = board->boardState[i];
	}

	for (int i = 0; i < 9; i++) {
		if (tempBoard.boardState[i] == SPACE) {
			tempBoard.boardState[i] = P2;

			win = isGameWon(tempBoard);

			if (win == 2) {
				board->boardState[i] = P2;
				return 0;
			}

			tempBoard.boardState[i] = SPACE;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (tempBoard.boardState[i] == SPACE) {
			tempBoard.boardState[i] = P1;

			win = isGameWon(tempBoard);

			if (win == 1) {
				board->boardState[i] = P2;
				return 0;
			}

			tempBoard.boardState[i] = SPACE;
		}
	}

	int randomNumber = random(9) - 1;

	while (tempBoard.boardState[randomNumber] != SPACE) {
		randomNumber = random(9) - 1;
	}

	board->boardState[randomNumber] = P2;
	return 0;
}