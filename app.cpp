#include <iostream>
#include <Windows.h>

using namespace std;

char grid[10][100];

int x = 0, oldx;
void colorGrid(bool changeColor) {
    if (changeColor) do {
        oldx = x;
        x = rand()%6;
    } while (x == oldx);
    
    switch (x) {
    	case 0: system("color 01"); break;
    	case 1: system("color 02"); break;
    	case 2: system("color 03"); break;
    	case 3: system("color 04"); break;
    	case 4: system("color 05"); break;
    	case 5: system("color 06"); break;
	}
}

void colorGridDefault() {
    system("color 07");
}

void clearGrid() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 100; j++)
            grid[i][j] = ' ';
}

void printGrid(bool changeColor) {
    system("cls");

    colorGrid(changeColor);
    cout << '+';
    for (int i = 0; i < 100; i++) cout << '-';
    cout << '+' << endl;

    for (int i = 0; i < 10; i++) {
        cout << '|';

        colorGridDefault();
        for (int j = 0; j < 100; j++)
            cout << grid[i][j];

        colorGrid(false);
        cout << '|' << endl;
    }

    cout << '+';
    for (int i = 0; i < 100; i++) cout << '-';
    cout << '+' << endl;

    cout.flush();
}


int main() {
    unsigned int row = 0, column = 0;
    bool up = false, left = false;

    while (true) {
        clearGrid();

        grid[column][row] = 'o';

        if (column == 9) up = true;
        else if (column == 0) up = false;

        if (row == 99) left = true;
        else if (row == 0) left = false;

        if (up) column--;
        else column++;

        if (left) row -= 3;
        else row += 3;

        if (column == 0 || column == 9 || row == 0 || row == 99) {
            printGrid(true);
            cout << '\a';
        } else printGrid(false);

        Sleep(40);
    }
}