#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

struct Entry
{
    size_t doc_id, count;
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
    /**
     * Обновить или заполнить базу документов, по которой будем совершать поиск
     * @param texts_input содержимое документов
     */

    void UpdateDocumentBase(std::vector<std::string> input_docs);
    /**
    * Метод определяет количество вхождений слова word в загруженной базе
    документов
    * @param word слово, частоту вхождений которого необходимо определить
    * @return возвращает подготовленный список с частотой слов
    */
    std::vector<Entry> GetWordCount(const std::string &word);
};
