#include "ConverterJSON.h"
#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

void ConverterJSON::readConfig() // функция считывания конфигурационного файла
{
    std::ifstream file("config.json");
    if (!file.is_open())
        throw std::runtime_error("config file is missing");
    else
    {
        nlohmann::json readFile;
        file >> readFile;
        // необходимо раскрыть дальнейшую логику работы с файлом
        if (readFile["config"] == nullptr) // если поле пустое
            throw std::runtime_error("config file is empty");
        else
        {
            name = readFile["config"]["name"]; // получаем имя приложения
        }

        if (readFile["config"]["max_responses"] == nullptr) // если поле пустое
            responses = 5;
        else
            responses = readFile["config"]["max_responses"]; // возможно добавить перевод типа

        for (auto i = 0; i < readFile["files"].size(); i++) // выделение путей к файлам
        {
            GetTextFile.push_back(readFile["files"][i]);
        }
        // в будущем добавить проверку версии программы
    }
    file.close();
}

void ConverterJSON::readRequests() // функция преобразования запросов JSON
{
    std::ifstream file("requests.json");
    if (!file.is_open())
        throw std::runtime_error("config file is missing");
    else
    {
        nlohmann::json readRequest;
        file >> readRequest;
        for (auto i = 0; i < readRequest["requests"].size(); i++)
        {
            GetTextFile.push_back(readRequest["requests"][i]);
        }
    }

    file.close();
}

void ConverterJSON::writeAnswer()
{
    std::ofstream file("answers.json");
    //необходимо расписать запись данных в файл
    file.close();
}