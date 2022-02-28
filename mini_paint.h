#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <Windows.h>

using namespace std;


int pow(int num1, int num2);
int to_intStr(string text);
void strStrip(string text, vector <string>& res);
int testLen(string fileName);
int testFile(string fileName);
void drawField(vector <vector <string>> field);
void setColor(int color);
void abs(int& num);
void swap(int &num1, int &num2);