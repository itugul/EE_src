#include "languageManager.h"
#include "preferenceManager.h"

std::unordered_map<string, string> LanguageManager::vocabulary;

string LanguageManager::get(string key)
{
    if (PreferencesManager::get("language") == "0")
        return key;
    if (vocabulary.find(key) == vocabulary.end())
        vocabulary[key] = key;
    return vocabulary[key];
}

void LanguageManager::load()
{
    char    filename[2][30] = {"resources/en.ini", "resources/ru.ini"};
    int     i = PreferencesManager::get("language").toInt();

    if (i == 0)
        return ;
    FILE* f = fopen(filename[i], "r");
    if (f)
    {
        char buffer[1024];
        while(fgets(buffer, sizeof(buffer), f))
        {
            string line = string(buffer).strip();
            if (line.find("=") > -1)
            {
                if(line.find("#") != 0) {
                    string key = line.substr(0, line.find("="));
                    string value = line.substr(line.find("=") + 1);
                    vocabulary[key] = value;
                }

            }
        }
        fclose(f);
    }
}