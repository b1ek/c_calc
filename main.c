#include <stdio.h>
#include <conio.h>

#define bool int
#define false 0
#define true 1

int main() {
    printf("Welcome to my simple calculator! Print a digit, then opperand(one of /, *, - and +)\nand one more digit. The calculator will print the value on enter press.\n\nTo exit, press ESC, Del or Ctrl+C\n======\n");
    char c;
    bool n = 0;
    int a = 0; int b = 0;
    char op;
    while (1) {
        if (_kbhit()) {
            c = _getch();
            if (c >= 48 && c <= 57) {
                if (n == 0) {
                    a = (a * 10) + (c - 48);
                    putch(c);
                } else if (n == 1) {
                    b = (b * 10) + (c - 48);
                    putch(c);
                }
        } if (c == 13 && n == 1) {
                printf(" = ");
                switch (op) {
                    case '+':
                        printf("%d", a + b);
                        break;
                    case '-':
                        printf("%d", a - b);
                        break;
                    case '*':
                        printf("%d", a * b);
                        break;
                    case '/':
                        printf("%0.2f", (float) a / (float)b);
                        break;
                    default:
                        putch('?');
                        break;
                }
                putch('\n');
                n = 0;
                a = 0;
                b = 0;
                op = 0;
            }
        } if (c >= 42 && c <= 47 && c != 46 && n != 1) {
            if (n == 0) {
                n = 1;
            }
            op = c;
            printf(" %c ", c);
        }

        if (c == 3 || c == 27 || c == 83) {
            puts("^C");
            return 0;
        }
    }
}
