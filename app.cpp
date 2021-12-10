#include <iostream>

using namespace std;

#ifdef _WIN32
  #include <Windows.h>
#else
  #include <unistd.h>
  string colors[] = { "31", "32", "33", "34", "35", "36" };
#endif

char grid[10][100];

int x = 0, oldx;
void colorGrid(bool changeColor) {
    if (changeColor) do {
        oldx = x;
        x = rand()%6;
    } while (x == oldx);

    #ifdef _WIN32
      
    #else
      cout << "\033[" + colors[x] + "m";
    #endif
}

void colorGridDefault() {
    #ifdef _WIN32
      system("color 07");
    #else
      cout << "\033[37m";
    #endif
}

void clearGrid() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 100; j++)
            grid[i][j] = ' ';
}

void printGrid(bool changeColor) {
    #ifdef _WIN32
      system("cls");
    #else
      system("clear");
    #endif

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

        #ifdef _WIN32
          Sleep(40);
        #else
          usleep(40000);
        #endif
    }
}