#include <stdio.h>
#include <conio.h>

int main() {
    char ch;

    // clrscr();              // clear screen (Turbo C / DOS)

    printf("Press any key: ");
    ch = getch();          // read a character (not echoed)

    printf("\nASCII value = %d", ch);   // display ASCII code

    getch();               // wait for another key before exit
    return 0;
}
