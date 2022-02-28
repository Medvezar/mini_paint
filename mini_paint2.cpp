#include "mini_paint.h"


void setColor(int color) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)(0) | (color));
}


void drawField(vector <vector <string>> field) {
    for (int n1 = 0; n1 < field.size(); n1++) {
        vector <string> test = field[n1];
        for (int n2 = 0; n2 < test.size(); n2++)
            cout << test[n2];
        cout << "\n";
    }
}


void abs(int& num) {
    if (num < 0)
        num *= -1;
}


void swap(int &num1, int &num2) {
    int num3 = num1;
    num1 = num2;
    num2 = num3;
}