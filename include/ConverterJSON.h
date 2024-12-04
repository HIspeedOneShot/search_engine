#pragma once
#include <string>
#include <vector>

class ConverterJSON
{
private:
    std::string name;
    int responses;
    std::vector<std::string> GetTextFile;
    std::vector<std::string> path;
    void putAnswers(std::vector<std::vector<std::pair<int, float>>>
answers);

public:
    ConverterJSON() = default; // конструктор по умолчанию

    void readConfig();   // функция считывания конфигурационного файла config.json
    void readRequests(); // преобразование запросов в формате json (requests.json)
    void writeAnswer();  // формирование ответов в формате json (answers.json)
    /* std::string getName;
    int getResponses;
    std::vector<std::string> getGetTextFile;
    std::vector<std::string> getPath; */
};