#include <iostream>
#include <random>
#include <curses.h>
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void draw() {
    system("clear");
    for (int i = 0; i < width; i++) {
        std::cout << "# ";
    }
    std::cout << "\n";

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                std::cout << "# ";
            } else if (i == y && j == x) {
                std::cout << "O";
            } else if (i == fruitY && j == fruitX) {
                std::cout << "F";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << "\n";
    }

    for (int i = 0; i < width; i++) {
        std::cout << "# ";
    }
    std::cout << "\n";

    std::cout << "Score: " << score << "\n";
}

int khbit() {
    int ch;
    nodelay(stdscr, TRUE);
    ch = getch();
    if (ch != ERR) {
        ungetch(ch);
        return 1;
    }
    return 0;
}

void input() {
    if (khbit()) {
        switch (getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void logic() {
    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;

    }

    if (x > width || x < 0 || y > height || y < 0) {
        gameOver = true;
    }
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX  = rand() % width;
        fruitY = rand() % height;
    }
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
    }

    return 0;
}
