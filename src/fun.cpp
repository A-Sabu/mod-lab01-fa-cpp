// Copyright 2022 UNN-IASR
#include "fun.h"
#include <ctype.h>
#include <cmath>

unsigned int faStr1(const char *str) {
    int count = 0;
    bool inWord = false;
    bool findDigitInWord = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && !inWord) {
            inWord = true;
        } else if (str[i] == ' ' && inWord) {
            inWord = false;
            if (findDigitInWord == true) findDigitInWord = false;
            else count++;
        } else if (isdigit(str[i]) && inWord) {
            findDigitInWord = true;
        }
    }
    return count;
}

unsigned int faStr2(const char *str) {
    int count = 0;
    bool inWord = false;
    bool isCorrectWord = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && !inWord) {
            inWord = true;
            if (isupper(str[i])) isCorrectWord = true;
        } else if (str[i] == ' ' && inWord) {
            inWord = false;
            if (isCorrectWord) {
                isCorrectWord = false;
                count++;
            }
        } else if (!islower(str[i])) isCorrectWord = false;
    }
    return count;
}

unsigned int faStr3(const char *str) {
    int count = 0;
    int sum = 0;
    int i;
    bool inWord = false;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && !inWord) {
            sum++;
            inWord = true;
        } else if (str[i] == ' ' && inWord) {
            count++;
            inWord = false;
        } else if (inWord) sum++;
    }
    if (str[i] != ' ') count++;
    return round(sum/count);
}
