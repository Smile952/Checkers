#include<iostream>﻿
#include <cmath>

using namespace std;

const int w = 1;
const int b = 2;

int amount_w = 12;
int amount_b = 12;

int map[8][8];

int player = 1;
bool isEaten = false;

int botStepsFrom_x[12];
int botStepsFrom_y[12];
int botStepsTo_x[12];
int botStepsTo_y[12];

int botAmountSteps = 0;

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
<<<<<<< HEAD
    if (inBorder(col + 2, row + 2) && map[col + 2][row + 2] == 0 && map[col + 1][row + 1] != player && map[col + 1][row + 1] != 0) {
        map[col + 1][row + 1] = 0;
        col += 2; row += 2;
        isEaten = true;
        checkForEat(col, row);
    }
    else if (inBorder(col - 2, row + 2) && map[col - 2][row + 2] == 0 && map[col - 1][row + 1] != player && map[col - 1][row + 1] != 0) {
        map[col - 1][row + 1] = 0;
        col -= 2; row += 2;
        isEaten = true;
        checkForEat(col, row);
    }
    else if (inBorder(col + 2, row - 2) && map[col + 2][row - 2] == 0 && map[col + 1][row - 1] != player && map[col + 1][row - 1] != 0) {
        map[col + 1][row - 1] = 0;
        col += 2; row -= 2;
        isEaten = true;
        checkForEat(col, row);
    }
    else if (inBorder(col - 2, row - 2) && map[col - 2][row - 2] == 0 && map[col - 1][row - 1] != player && map[col - 1][row - 1] != 0) {
        map[col - 1][row - 1] = 0;
        col -= 2; row -= 2;
        isEaten = true;
        checkForEat(col, row);
=======

<<<<<<< HEAD
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
=======
    if (inBorder(col + 2, row + 2) && map[col + 2][row + 2] == 0) {
        if (map[col + 1][row + 1] != player && map[col + 1][row + 1] != 0) {
            col += 2; row += 2;
            map[col - 1][row - 1] = 0;
            isEaten = true;
            checkForEat(col, row);
        }
    }
    else if (inBorder(col - 2, row + 2) && map[col - 2][row + 2] == 0) {
        if (map[col - 1][row + 1] != player && map[col - 1][row + 1] != 0) {
            col -= 2; row += 2;
            map[col + 1][row - 1] = 0;
            isEaten = true;
            checkForEat(col, row);
        }    }
    else if (inBorder(col + 2, row - 2) && map[col + 2][row - 2] == 0) {
        if (map[col + 1][row - 1] != player && map[col + 1][row - 1] != 0) {
            col += 2; row -= 2;
            map[col - 1][row + 1] = 0;
            isEaten = true;
            checkForEat(col, row);
        }
    }
    else if (inBorder(col - 2, row - 2) && map[col - 2][row - 2] == 0) {
        if (map[col - 1][row - 1] != player && map[col - 1][row - 1] != 0) {
            col -= 2; row -= 2;
            map[col + 1][row + 1] = 0;
            isEaten = true;
            checkForEat(col, row);
>>>>>>> 383d1cb8dce1f558f63536268579952076b1cde2
        }
>>>>>>> second
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
<<<<<<< HEAD
=======
<<<<<<< HEAD
            }
        }
=======
>>>>>>> second
                break;
            }
        }
        if (isEaten) {
            player = player == 1 ? 2 : 1;
            isEaten = false;
            FindToEat();
            break;
        }
<<<<<<< HEAD
=======
>>>>>>> 383d1cb8dce1f558f63536268579952076b1cde2
>>>>>>> second
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

bool step(int type, int& col, int& row) {
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
    return false;
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

<<<<<<< HEAD
void canBotStep(int col, int row) {
    if (inBorder(col + 1, row + 1) && map[col + 1][row + 1] == 0) {
        botStepsFrom_x[botAmountSteps] = col;
        botStepsFrom_y[botAmountSteps] = row;
        botStepsTo_x[botAmountSteps] = col + 1;
        botStepsTo_y[botAmountSteps] = row + 1;
        botAmountSteps++;
=======
<<<<<<< HEAD
>>>>>>> second

    }

    if (inBorder(col + 1, row + 1) && map[col + 1][row + 1] == 0) {
        botStepsFrom_x[botAmountSteps] = col;
        botStepsFrom_y[botAmountSteps] = row;
        botStepsTo_x[botAmountSteps] = col + 1;
        botStepsTo_y[botAmountSteps] = row + 1;
        botAmountSteps++;
    }

}

void createBotListSteps() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (map[i][j] == 2) {
                canBotStep(i, j);
            }
        }
    }
}
<<<<<<< HEAD
=======
=======
>>>>>>> 383d1cb8dce1f558f63536268579952076b1cde2
>>>>>>> second

int getRandomBotStep() {
    return rand() % botAmountSteps;
}

void botStep(int index) {
    map[botStepsFrom_x[index]][botStepsFrom_y[index]] = 0;
    map[botStepsTo_x[index]][botStepsTo_y[index]] = 2;
    cout << "Player 2 step from: " << botStepsFrom_x[index] << " " << botStepsFrom_y[index] << endl;
    cout << "Player 2 step to: " << botStepsTo_x[index] << " " << botStepsTo_y[index] << endl;
}

int main()
{
    int botStepIndex = 0;
    createMap();
    int col, row, col_past, row_past, step_type, temp_i, temp_j = 0;
    while (amount_b > 0 || amount_w > 0) {

        if (player == 1) {
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
            cout << "Player 1 step from : " << col_past << " " << row_past << endl;
            cout << "Player 2 step to: " << col << " " << row << endl;
        }
        else {
            createBotListSteps();
            botStepIndex = getRandomBotStep();
            botStep(botStepIndex);
            botAmountSteps = 0;
            outputMap();
        }
<<<<<<< HEAD
=======
        map[col][row] = player;
        map[col_past][row_past] = 0;
        switchPlayer();
<<<<<<< HEAD
        findToEat();
        if(isEaten) switchPlayer();
=======
>>>>>>> 383d1cb8dce1f558f63536268579952076b1cde2
>>>>>>> second
        isEaten = false;
        switchPlayer();
        cout << endl;
        cout << endl;
    }
}