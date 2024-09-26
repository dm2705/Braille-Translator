// braille_translator.h
#ifndef BRAILLE_TRANSLATOR_H
#define BRAILLE_TRANSLATOR_H

#include <string>

std::string braille_to_english(const std::string& input);
std::string english_to_braille(const std::string& input);
bool is_braille(const std::string& input);

#endif