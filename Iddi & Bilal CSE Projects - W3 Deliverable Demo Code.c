#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define MARQUEE_LENGTH 95

void Init() {
    printf("=== Welcome to the JDM Marquee Game ===\n");
    printf("Press 'a' to move the marquee left, press 'd' to move the marquee right, press any button to generate a new marquee line, and press 'e' to Exit.\n");
}

char getUserInput() { 
    return _kbhit() ? _getch() : '\0'; 
}

void printMarquee(const char* msg, int pos) {
    char buf[MARQUEE_LENGTH + 1];
    int len = strlen(msg);
    
       for (int i = 0; i < MARQUEE_LENGTH; i++) {
        buf[i] = msg[(pos + i) % len]; 
    }
    
    buf[MARQUEE_LENGTH] = '\0'; 
    printf("\r%s", buf); 
    fflush(stdout);
}

int main() {
    int pos = 0, dir = 1; // pos is the position of the marquee; dir is the direction
    const char* message = "Welcome to the JDM Marquee Game! ";
    Init();

    while (1) {
        // Update the position based on direction
        pos = (pos + dir) % strlen(message);
        if (pos < 0) pos += strlen(message); 
        printMarquee(message, pos); 
        
        char input = getUserInput(); 
        if (input) {
            if (input == 'e') break;   
            else if (input == 'a') dir = -1; 
            else if (input == 'd') dir = 1;  
            else printf("\nYou entered: '%c'\n", input); 
        }
        
        Sleep(100); 
    }

    printf("\nBUFFER OVERLOAD!!! YOU BROKE THE GAME\n");
    return 0;
}


