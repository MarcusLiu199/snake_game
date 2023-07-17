#include <iostream>
#include <random>
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
}

void input() {

}

void logic() {

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
