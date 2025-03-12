#include <InvertedIndex.h>
#include <sstream>
#include <algorithm>

void InvertedIndex::CreateDocs(std::vector<std::string> path)
{
    // формируем коллекцию текстов документов docs
    for (size_t i = 0; i < path.size(); ++i)
    {
        std::ifstream file(path[i]);
        if (!file.is_open())
            throw std::runtime_error("input file is missing");
        else
        {
            std::string line;
            std::getline(file, line);
            file.close();
            docs.push_back(line);
        }
    }
}

void InvertedIndex::UpdateDocumentBase(std::vector<std::string> docs)
{
    freq_dictionary.clear();
    // Обрабатываем каждый документ
    for (size_t i = 0; i < docs.size(); ++i)
    {
        const auto document = docs[i];

        // Разбиваем строку на отдельные слова
        std::istringstream iss(document);
        std::string word;

        while (iss >> word)
        {
            // Если слово уже есть в индексе, увеличиваем счетчик для текущего документа
            if (freq_dictionary.find(word) != freq_dictionary.end())
            {
                bool found = false;
                for (auto &entry : freq_dictionary[word])
                {
                    if (entry.doc_id == i)
                    {
                        entry.count++;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    freq_dictionary[word].emplace_back(i, 1);
                }
            }
            else
            { // Иначе создаем новую запись для этого слова
                freq_dictionary[word].push_back({i, 1});
            }
        }
    }
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string &word)
{
    std::vector<Entry> result;
    if (freq_dictionary.find(word) != freq_dictionary.end())
    {
        result = freq_dictionary.at(word);
    }
    return result;
}



bool InvertedIndex :: findWord(const std::string &word)
{
    if (freq_dictionary.find(word) != freq_dictionary.end())
        return true;
    else
        return false;
}

int InvertedIndex :: getCountFromWord(const std::string &word)
{
    int count = 0;
    auto entry = freq_dictionary.at(word);
    for (auto &i : entry)
    {
        count += i.count;
    }
    return count;
}