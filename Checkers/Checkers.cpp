#include <iostream>
#include <cmath>

using namespace std;

const int w = 1;
const int b = 2;
const int W = 3;
const int B = 4;

int amount_w = 12;
int amount_b = 12;

int coord_x[12];
int coord_y[12];

int map[8][8];

int player = 1;
bool isEaten = false;

void createMap() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    map[i][j] = b;
                }
                else if (i > 4) {
                    map[i][j] = w;
                }
                else map[i][j] = 0;
            }
            else map[i][j] = 0;
        }
    }
}

bool inBorder(int x, int y) {
    if (x < 8 && x > 0 && y < 8 && y > 0) {
        return true;
    }
    return false;
}

void checkForEat(int& col, int& row) {

    if (inBorder(col + 2, row + 2)) {
        if (map[col + 2][row + 2] == 0) {
            if (map[col + 1][row + 1] != player && map[col + 1][row + 1] != 0) {
                col += 2; row += 2;
                map[col - 1][row - 1] = 0;
                isEaten = true;
                checkForEat(col, row);
            }
        }
    }
    else if (inBorder(col - 2, row + 2)) {
        if (map[col - 2][row + 2] == 0) {
            if (map[col - 1][row + 1] != player && map[col - 1][row + 1] != 0) {
                col -= 2; row += 2;
                map[col + 1][row - 1] = 0;
                isEaten = true;
                checkForEat(col, row);
            }
        }
    }
    else if (inBorder(col + 2, row - 2)) {
        if (map[col + 2][row - 2] != 0) {
            if (map[col + 1][row - 1] != player && map[col + 1][row - 1] != 0) {
                col += 2; row -= 2;
                map[col - 1][row + 1] = 0;
                isEaten = true;
                checkForEat(col, row);
            }
        }
    }
    else if (inBorder(col - 2, row - 2)) {
        if (map[col - 2][row - 2] != 0) {
            if (map[col - 1][row - 1] != player && map[col - 1][row - 1] != 0) {
                col -= 2; row -= 2;
                map[col + 1][row + 1] = 0;
                isEaten = true;
                checkForEat(col, row);
            }
        }
    }
}

void FindToEat() {
    int temp_i, temp_j = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            temp_i = i;
            temp_j = j;
            if (map[i][j] == player) {
                checkForEat(i, j);
            }
            if (isEaten) {
                map[i][j] = player;
                map[temp_i][temp_j] = 0;
            }
        }
    }
}

void switchPlayer() {
    player = player == 1 ? 2 : 1;
    FindToEat();
}

bool isCorrectStep(int col, int row) {
    if (map[col][row] == 0) return true;
    return false;
}

bool step(int type, int &col, int &row) {
    int x = col; int y = row;
    switch (type) {
    case(0):
        if (isCorrectStep(x + 1, y - 1) && player == 2) {
            col += 1; row -= 1;
            return true;
        }
        else cout << "Uncorrect step" << "\n";
        return false;
        break;
    case(1):
        if (isCorrectStep(x + 1, y + 1) && player == 2) {
            col += 1; row += 1;
            return true;
        }
        else cout << "Uncorrect step" << "\n";
        return false;
        break;
    case(2):
        if (isCorrectStep(x - 1, y + 1) && player == 1) {
            col -= 1; row += 1;
            return true;
        }
        else cout << "Uncorrect step" << "\n";
        return false;
        break;
    case(3):
        if (isCorrectStep(x - 1, y - 1) && player == 1) {
            col -= 1; row -= 1;
            return true;
        }
        else cout << "Uncorrect step" << "\n";
        return false;
        break;
    
    }
}

bool isCorrectCoord(int col, int row) {
    if (map[col][row] != 0 && (map[col][row] == player || map[col][row] == player + 2)) {
        return true;
    }
    return false;
}

bool isCorrectInput(int x, int y) {
    if ((x < 8 && x >= 0) && (y >= 0 && y < 8)) return true;
    return false;
}

void outputMap() {
    cout << "Current player: " << player << "\n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << "\n";
    }
}


void findToEat() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (map[i][j] == player) {
                checkForEat(i, j);
            }
        }
    }
}

//добавить два массива с коодинатами фишек для бота среди которых он выберет случайные и которыми он сможет сходить
int main()
{
    createMap();
    int col, row, col_past, row_past, step_type, temp_i, temp_j = 0;
    while (amount_b > 0 || amount_w > 0) {
        outputMap();
        cin >> col >> row;
        while (!isCorrectCoord(col, row)) {
            cout << "Uncorrect coord for figure" << "\n";
            cin >> col >> row;
        }
        col_past = col; 
        row_past = row;
        cin >> step_type;
        while (!step(step_type, col, row)) {
            cin >> step_type;
        }
        map[col][row] = player;
        map[col_past][row_past] = 0;
        switchPlayer();
        findToEat();
        if(isEaten) switchPlayer();
        isEaten = false;
    }
}
