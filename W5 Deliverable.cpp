#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 30
#define EMPTY_CHAR ' '
#define EDGE_CHAR '#'
#define SNAKE_CHAR '$'
#define FOOD_CHAR '^'

char board[BOARD_SIZE][BOARD_SIZE];
int snakeBodyRow[BOARD_SIZE * BOARD_SIZE], snakeBodyCol[BOARD_SIZE * BOARD_SIZE];
int snakeLength = 1, directionX = 1, directionY = 0, foodRow, foodCol;

void resetBoard() {
    for (int y = 0; y < BOARD_SIZE; ++y)
        for (int x = 0; x < BOARD_SIZE; ++x)
            board[y][x] = (x == 0 || x == BOARD_SIZE - 1 || y == 0 || y == BOARD_SIZE - 1) ? EDGE_CHAR : EMPTY_CHAR;
}

void spawnFood() {
    do {
        foodRow = rand() % (BOARD_SIZE - 2) + 1;
        foodCol = rand() % (BOARD_SIZE - 2) + 1;
    } while (board[foodRow][foodCol] != EMPTY_CHAR);
    board[foodRow][foodCol] = FOOD_CHAR;
}

void draw() {
    system("cls");
    for (int y = 0; y < BOARD_SIZE; ++y) {
        for (int x = 0; x < BOARD_SIZE; ++x) {
            printf("%c", board[y][x]);
        }
        printf("\n");
    }
    printf("Score: %d\n", snakeLength - 1);
}

void getUserInput() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w': if (directionY != 1) { directionX = 0; directionY = -1; } break;
            case 's': if (directionY != -1) { directionX = 0; directionY = 1; } break;
            case 'a': if (directionX != 1) { directionX = -1; directionY = 0; } break;
            case 'd': if (directionX != -1) { directionX = 1; directionY = 0; } break;
            case 'g':
                snakeLength++;
                printf("\a"); 
                break;
            case 'e':
                printf("Game Over! Your score: %d\n", snakeLength - 1);
                Sleep(2000);
                exit(0);
        }
    }
}

int moveSnake() {
    int newHeadRow = snakeBodyRow[0] + directionY;
    int newHeadCol = snakeBodyCol[0] + directionX;

    if (board[newHeadRow][newHeadCol] == EDGE_CHAR) {
        return 0;  
    }

    for (int i = 0; i < snakeLength; i++) {
        if (newHeadRow == snakeBodyRow[i] && newHeadCol == snakeBodyCol[i]) {
            return 0;  
        }
    }

    int grew = (newHeadRow == foodRow && newHeadCol == foodCol);
    if (grew) {
        snakeLength++;
        spawnFood();
    } else {
        board[snakeBodyRow[snakeLength-1]][snakeBodyCol[snakeLength-1]] = EMPTY_CHAR;
    }

    for (int i = snakeLength - 1; i > 0; i--) {
        snakeBodyRow[i] = snakeBodyRow[i-1];
        snakeBodyCol[i] = snakeBodyCol[i-1];
    }

    snakeBodyRow[0] = newHeadRow;
    snakeBodyCol[0] = newHeadCol;

    board[newHeadRow][newHeadCol] = SNAKE_CHAR;

    return 1;  
}

void showLobby() {
    system("cls");
    printf("========================================\n");
    printf(" Welcome to Iddi and Bilal's Snake Game!\n");
    printf("========================================\n");
    printf("Controls:\n");
    printf("W - Move Up\n");
    printf("A - Move Left\n");
    printf("S - Move Down\n");
    printf("D - Move Right\n");
    printf("G - Grow Snake\n");
    printf("E - Exit Game\n");
    printf("Press any key to start...\n");
    _getch();
}

int main() {
    srand((unsigned int)time(0));
    showLobby();
    resetBoard();

    snakeBodyRow[0] = rand() % (BOARD_SIZE - 2) + 1;
    snakeBodyCol[0] = rand() % (BOARD_SIZE - 2) + 1;
    board[snakeBodyRow[0]][snakeBodyCol[0]] = SNAKE_CHAR;

    spawnFood();

    while (1) {
        draw();
        getUserInput();
        if (!moveSnake()) {
            printf("Game Over! Your score: %d\n", snakeLength - 1);
            break;
        }
        Sleep(100);
    }

    return 0;
}