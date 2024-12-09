#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

int countWord(const char* sentence);
char** splitIntoSentences(const char* text, int& sentenceCount);
void freeSentences(char** sentences, int sentenceCount);


