#include "Text.h"
#define _CRT_SECURE_NO_WARNINGS
int countWord(const char* sentence) {
	int wordCount = 0;
	bool word = false;

	for (const char* ptr = sentence; *ptr != '\0'; ptr++) {
		if (isspace(*ptr)) {
			word = false;
		}
		else if (!word) {
			word = true;
			wordCount++;
		}
	}
	return wordCount;
}

char** splitIntoSentences(const char* text, int& sentenceCount) {
    int capacity = 10; 
    char** sentences = new char* [capacity];
    sentenceCount = 0;

    const char* start = text;
    const char* current = text;
    while (*current != '\0') {
        if (*current == '.' || *current == '!' || *current == '?') {
            int length = current - start + 1;
            char* sentence = new char[length + 1];
            strncpy(sentence, start, length);
            sentence[length] = '\0';

            if (sentenceCount == capacity) {
                capacity *= 2;
                char** newSentences = new char* [capacity];
                for (int i = 0; i < sentenceCount; ++i) {
                    newSentences[i] = sentences[i];
                }
                delete[] sentences;
                sentences = newSentences;
            }

            sentences[sentenceCount++] = sentence;
            start = current + 1; // Начинаем новое предложение
        }
        ++current;
    }

    return sentences;
}

void freeSentences(char** sentences, int sentenceCount) {
    for (int i = 0; i < sentenceCount; ++i) {
        delete[] sentences[i];
    }
    delete[] sentences;
}