#include <stdio.h>   
#include <conio.h>  
#include <windows.h> 
#include <stdlib.h>  
#include <time.h>   

#define BOARD_SIZE 30
#define EMPTY_CHAR ' '
#define EDGE_CHAR '#'
#define SNAKE_CHAR '*'
#define FOOD_CHAR '^'

char board[BOARD_SIZE][BOARD_SIZE];
int snakeBodyRow[BOARD_SIZE * BOARD_SIZE], snakeBodyCol[BOARD_SIZE * BOARD_SIZE];
int snakeLength = 1, directionX = 0, directionY = 0, foodRow, foodCol;


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
}


void getUserInput() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w': directionX = 0; directionY = -1; break; 
            case 's': directionX = 0; directionY = 1; break; 
            case 'a': directionX = -1; directionY = 0; break; 
            case 'd': directionX = 1; directionY = 0; break; 
            case 'x': snakeLength++; break; 
            case 'e':
                printf("Better luck next time!\n"); 
                Sleep(2000); 
                exit(0); 
        }
    }
}


void moveSnake() {
    int oldHeadRow = snakeBodyRow[0], oldHeadCol = snakeBodyCol[0];
    
    
    snakeBodyRow[0] += directionY;
    snakeBodyCol[0] += directionX;

   
    if (snakeBodyRow[0] >= BOARD_SIZE - 1) snakeBodyRow[0] = 1;
    if (snakeBodyRow[0] < 1) snakeBodyRow[0] = BOARD_SIZE - 2;
    if (snakeBodyCol[0] >= BOARD_SIZE - 1) snakeBodyCol[0] = 1;
    if (snakeBodyCol[0] < 1) snakeBodyCol[0] = BOARD_SIZE - 2;

   
    int grew = (snakeBodyRow[0] == foodRow && snakeBodyCol[0] == foodCol);
    if (grew) snakeLength++;

   
    for (int i = snakeLength; i > 0; --i) {
        snakeBodyRow[i] = snakeBodyRow[i - 1];
        snakeBodyCol[i] = snakeBodyCol[i - 1];
    }

    board[oldHeadRow][oldHeadCol] = EMPTY_CHAR; 
    for (int i = 0; i < snakeLength; i++) {
        board[snakeBodyRow[i]][snakeBodyCol[i]] = SNAKE_CHAR; 
    }
    if (grew) spawnFood(); 
}


void showLobby() {
    system("cls");
    printf("========================================\n");
    printf("  Welcome to Iddi and Bilal's Snake Game!\n");
    printf("========================================\n");
    printf("Controls:\n");
    printf("W - Move Up\n");
    printf("A - Move Left\n");
    printf("S - Move Down\n");
    printf("D - Move Right\n");
    printf("X - Grow Snake\n");
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
    spawnFood(); 

    while (1) {
        getUserInput();
        moveSnake(); 
        draw(); 
        Sleep(100);
    }

    return 0;
}