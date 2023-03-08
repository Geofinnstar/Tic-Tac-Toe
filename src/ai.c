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

	int possiblePlaceLocations[9] = {0};
	int count = 0;

	for (int i = 0; i < 9; i++) {
		if (tempBoard.boardState[i] == SPACE) {
			possiblePlaceLocations[count] = i;
			count++;
		}
	}

	int randomNumber = random(sizeof(possiblePlaceLocations) / sizeof(possiblePlaceLocations[0]));

	board->boardState[possiblePlaceLocations[randomNumber]] = P2;
	return 0;
}