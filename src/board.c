const int BOARD_HORIZONTAL_SIZE = 13;
const int BOARD_VERTICAL_SIZE = 7;
const char P1 = 'X';
const char P2 = 'O';
const char SPACE  = ' ';

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
	// Rows
	for (int i = 0; i < 9; i += 3) {
		if (board.boardState[i] != SPACE && board.boardState[i] == board.boardState[i+1] && board.boardState[i] == board.boardState[i+2]) {
			return (board.boardState[i] == P1) ? 1 : 2;
		}
	}

	// Columns
	for (int i = 0; i < 3; i++) {
		if (board.boardState[i] != SPACE && board.boardState[i] == board.boardState[i+3] && board.boardState[i] == board.boardState[i+6]) {
			return (board.boardState[i] == P1) ? 1 : 2;
		}
	}

	// Diagonals
	if (board.boardState[0] != SPACE && board.boardState[0] == board.boardState[4] && board.boardState[0] == board.boardState[8]) {
		return (board.boardState[0] == P1) ? 1 : 2;
	}

	if (board.boardState[2] != SPACE && board.boardState[2] == board.boardState[4] && board.boardState[2] == board.boardState[6]) {
		return (board.boardState[2] == P1) ? 1 : 2;
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