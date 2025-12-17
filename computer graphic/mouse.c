#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int x = 320, y = 240;   // initial position of circle center
    int ch;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    circle(x, y, 20);

    while (1) {
        ch = getch();   // read a key immediately (no Enter needed)

        // for extended keys (like arrows), first getch() returns 0 or 224
        if (ch == 0 || ch == 224) {
            ch = getch();      // real code of arrow key
            switch (ch) {
                case 75:       // left arrow
                    cleardevice();
                    x -= 10;
                    circle(x, y, 20);
                    break;
                case 77:       // right arrow
                    cleardevice();
                    x += 10;
                    circle(x, y, 20);
                    break;
            }
        } else if (ch == 27) { // Esc key ASCII
            break;
        }
    }

    closegraph();
    return 0;
}
