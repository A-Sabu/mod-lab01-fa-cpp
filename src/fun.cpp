// Copyright 2022 UNN-IASR
#include "fun.h"
#include "ctype.h"
#include "cmath"

unsigned int faStr1(const char *str) {
    int count = 0;
    bool inWord = false;
    bool findDigitInWord = false;
    while (*str) {
        if (*str != ' ' && !inWord) {
            inWord = true;
        }
        else if (*str == ' ' && inWord) {
            inWord = false;
            if (findDigitInWord == true) findDigitInWord = false;
            else count++;
        }
        else if (std::isdigit(*str) && inWord) {
            findDigitInWord = true;
        }
        *str++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    return 0;
}

unsigned int faStr3(const char *str) {
    return 0;
}
