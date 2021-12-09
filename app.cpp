#include <iostream>

using namespace std;

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
    int colors[] = { 40, 41, 42, 43, 44, 45, 46, 47, 100, 101, 102, 103, 104, 105, 106, 107 };
#endif



char grid[10][100];

void clearGrid() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 100; j++)
            grid[i][j] = ' ';
}

void printGrid() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    cout << "\033[102;41m";

    cout << '+';
    for (int i = 0; i < 100; i++) cout << '-';
    cout << '+' << endl;
    for (int i = 0; i < 10; i++) {
        cout << '|';
        for (int j = 0; j < 100; j++)
            cout << grid[i][j];
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

        if (column == 0 || column == 9 || row == 0 || row == 99) cout << '\a';

        if (column == 9) up = true;
        else if (column == 0) up = false;

        if (row == 99) left = true;
        else if (row == 0) left = false;

        if (up) column--;
        else column++;

        if (left) row -= 3;
        else row += 3;

        printGrid();

        #ifdef _WIN32
        Sleep(40);
        #else
        usleep(40000);
        #endif
    }
}
