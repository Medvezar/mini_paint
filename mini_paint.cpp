#include "mini_paint.h"


void drawRectFill(int x, int y, vector<vector <string> >& field, vector <string> resStr) {
    int height = to_intStr(resStr[4]);
    int width = to_intStr(resStr[3]);
    if ((y < 0 or x < 0) or (height < 0 or width < 0)) throw 1;
        for (int i = y; i < y + height; i++) {
            if (i < field.size()) {
                for (int a = x; a < x + width; a++) {
                    if (a < field[0].size())
                        field[i][a] = resStr[5];
                }
            }
    }
}


void drawRect(int x, int y, vector<vector <string> >& field, vector <string> resStr) {
    int height = to_intStr(resStr[4]);
    int width = to_intStr(resStr[3]);
    for (int i = y; i < y + height; i++) {
        if (i < field.size()) {
            field[i][x] = resStr[5];
            field[i][x + width - 1] = resStr[5];
        if (i == y or i == y + height - 1) {
            for (int a = x; a < x + width; a++) {
                if (a < field[0].size())
                    field[i][a] = resStr[5];
                }
            }
        }
    }
}


void drawCicle(int x, int y, int radius, vector <vector <string>> &field, string text) {
        int x1 = radius;
        int y1 = 0;
        int radiusError = 1 - x1;
        while (x1 >= y1) {
            field[y1 + y][x1 + x] = text;
            field[y1 + x][x1 + y] = text;
            field[ - x1 + x][y1 + y] = text;
            field[- y1 + x1][x1 + y] = text;
            field[ - x1 + x][-y1 + y] = text;
            field[ - y1 + x][ - x1 + y] = text;
            field[x1 + x][ - y1 + y] = text;
            field[y1 + x][ - x1 + y] = text;
            y1++;
            if (radiusError < 0) {
                radiusError += 2 * y1 + 1;
            }
            else {
                x1--;
                radiusError += 2 * (y1 - x1 + 1);
            }
        }
}


void drawCicleFill() {

}


void drawLine(int x1, int y1, int x2, int y2, vector<vector<string>>& field, string txt) {
    int x, y;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = (dy * 2) - dx;
    int d1 = dy * 2;
    int d2 = (dy - dx) * 4;
    x = x1;
    y = y1;
    if (x1 < field[0].size() and y1 < field.size()) field[x1][y1] = txt;
    if (x2 < field[0].size() and y2 < field.size()) field[x2][y2] = txt;
    if (y1 == y2) {
        for (int n1 = x1; n1 < x2 + 1; n1++)
            field[y][n1] = txt;
    }
    else if (x1 == x2) {
        for (int n1 = y1; n1 < y2 + 1; n1++)
            field[n1][x] = txt;
    }
    else {
        while (x < x2) {
            x++;
            if (d < 0) d += d1;
            else {
                y++;
                d += d2;
            }
            if (x < field[0].size() and field.size() > y) field[y][x] = txt;
        }
    }
}



int main() {
    string fileName;
    vector <string> commands;
    vector <string> resStr;
    vector <vector <string>> field;
    string line;
    try {
        getline(cin, fileName);
        if (testLen(fileName))
            throw testLen(fileName);
        if (testFile(fileName))
            throw testFile(fileName);
    }
    catch (int n1){
        if (n1 == 1) cout << "Error: operation file has not correct extension\n";
        else if (n1 == 2) cout << "Error: name file\n";
        else if (n1 == 3) cout << "Error: a lot of arguments\n";
        return 0;
    }
    ifstream fileRead(fileName);
    while (getline(fileRead, line))
        commands.push_back(line);
    try {
        for (int n1 = 0; n1 < commands.size(); n1++) {
            string commandStr = commands[n1];
            strStrip(commandStr, resStr);
            if (n1 == 0) {
                if ((to_intStr(resStr[1]) > 300 or to_intStr(resStr[1]) < 0) or (to_intStr(resStr[0]) > 300 or to_intStr(resStr[0]) < 0)) throw 1;
                for (int nV = 0; nV < to_intStr(resStr[1]); nV++) {
                    vector <string> test = {};
                    for (int nH = 0; nH < to_intStr(resStr[0]); nH++) {
                        test.push_back(resStr[2]);
                    }
                    field.push_back(test);
                }
            }
            int x = to_intStr(resStr[1]);
            int y = to_intStr(resStr[2]);
            if ((x < 0 or x > field[0].size()) or (y < 0 or y > field.size())) throw 1;
            if (resStr[0] == "r") {
                if ((y < 0 or x < 0) or (to_intStr(resStr[4]) < 0 or to_intStr(resStr[3]) < 0)) throw 1;
                drawRect(x, y, field, resStr);
            }
            else if (resStr[0] == "R") {
                if ((y < 0 or x < 0) or (to_intStr(resStr[4]) < 0 or to_intStr(resStr[3]) < 0)) throw 1;
                drawRectFill(x, y, field, resStr);
            }
            else if (resStr[0] == "c") {
                int radius = to_intStr(resStr[3]);
                if ((y < 0 or x < 0) or radius < 0) throw 1;
                drawCicle(x, y, radius, field, resStr[4]);
            }
            else if (resStr[0] == "C") {
                int radius = to_intStr(resStr[3]);
                if ((y < 0 or x < 0) or radius < 0) throw 1;
            }
            else if (resStr[0] == "L") {
                int x2 = to_intStr(resStr[3]);
                int y2 = to_intStr(resStr[4]);
                if ((x2 < 0 or x2 >= field[0].size()) or (y2 < 0 or y2 >= field.swdize())) throw 1;
                drawLine(x, y, x2, y2, field, resStr[5]);
            }
            resStr = {};
        }
    }
    catch (int n1) {
        cout << "Error: operation file corrupted" << "\n";
        fileRead.close();
        return 0;
    }
    drawField(field);
    fileRead.close();
    return 0;
}