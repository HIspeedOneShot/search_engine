#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

struct Entry
{
    size_t doc_id, count;

    bool operator==(const Entry &other) const
    {
        return (doc_id == other.doc_id &&
                count == other.count);
    }

    Entry(size_t id_, size_t value_) : doc_id(id_), count(value_) {}
}; // структура для хранения частоты слов, встречаемых в тексте

class InvertedIndex
{
private:
    /* коллекция для хранения текстов документов, в которой номер элемента в векторе определяет
    doc_id для формирования результата запроса */
    std::vector<std::string> docs;
    /* это коллекция для хранения частоты слов, встречаемых в тексте. Entry представляет собой структуру */
    std::map<std::string, std::vector<Entry>> freq_dictionary;

public:
    InvertedIndex() = default;

    void CreateDocs(std::vector<std::string> GetTextFile);

    void UpdateDocumentBase(std::vector<std::string> input_docs);

    std::vector<Entry> GetWordCount(const std::string &word);

    bool findWord(const std::string &word);
    int getCountFromWord(const std::string &word);
    

};

