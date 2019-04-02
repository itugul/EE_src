#ifndef LANGUAGE_MANAGER_H
#define LANGUAGE_MANAGER_H

#include "engine.h"

class LanguageManager
{
private:
    static std::unordered_map<string, string> vocabulary;
public:
    static string get(string key);
    static void load();
};

#endif//LANGUAGE_MANAGER_H