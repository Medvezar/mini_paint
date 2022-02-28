#include "mini_paint.h"


int pow(int num1, int num2) {
    int num3 = num1;
    for (int n1 = 1; n1 < num2; n1++)
        num3 *= num1;
    if (num2 > 0)
        return num3;
    return 1;
}


int to_intStr(string text) {
    int numRes = 0;
    int times = 0, len = 0;
    while (text[len] != '\0')
        len++;
    while (text[times] != '\0') {
        numRes += (text[times] - 48) * pow(10, len - times);
        times++;
    }
    return numRes / 10;
}


void strStrip(string text, vector <string>& res) {
    string textTest = "";
    for (auto n1 : text) {
        if (n1 == ' ') {
            res.push_back(textTest);
            textTest = "";
        }
        else
            textTest += n1;
    }
    res.push_back(textTest);
}


int testLen(string fileName) {
    for (auto n1 : fileName)
        if (n1 == ' ')
            return 3;
    return 0;
}


int testFile(string fileName) {
    string file = "";
    string file1 = "";
    bool dotTest = false;
    for (auto n1 : fileName) {
        if (n1 == '.')
            dotTest = true;
        if (dotTest)
            file1 += n1;
        else
            file += n1;
    }
    if (file1 != ".it")
        return 1;
    ifstream fileRead(fileName);
    if (fileRead.is_open() == false)
        return 2;
    fileRead.close();
    return 0;
}