#include <SearchServer.h>
#include <sstream>
#include <unordered_set>
#include <map>
#include <algorithm>

std::vector<std::vector<RelativeIndex>> SearchServer ::search(const std::vector<std::string> &requests_input)
{
    std::vector<std::vector<RelativeIndex>> results;
    for (auto &words : requests_input)
    {
        std::istringstream iss(words);
        std::string word;

        // разделение строки на отдельные слова и помещение в контейнер уникальных слов
        std::unordered_set<std::string> words_set;
        while (iss >> word)
        {
            words_set.insert(word); // добавление слова в словарь
        }

        // сортировка слов по возрастанию из найденых документов
        std::multimap<int, std::string> words_sorted;
        for (auto &word : words_set)
        {
            auto count = _index.getCountFromWord(word);
            words_sorted.insert({count, word});
        }

        // для каждого документа считаем абсолютную релевантность
        std::map<std::string, bool> words_found; // мапа для хранения слова
        std::map<size_t, size_t> relative_id;    // мапа для хранения id документа и суммарного вхождения в него слов
        for (auto &word : words_sorted)          // формируем документ для подсчета данных
        {
            auto range = words_sorted.equal_range(word.first);

            std::vector<Entry> wordCount = _index.GetWordCount(word.second);
            if (wordCount.size() != 0) // проверяем размер
            {
                words_found.insert({word.second, true}); // если есть добавляем и формируем данные
                for (auto &entry : wordCount)
                {
                    if (relative_id.find(entry.doc_id) != relative_id.end())
                    {
                        relative_id[entry.doc_id] += entry.count;
                    }
                    else
                        relative_id.insert({entry.doc_id, entry.count});
                }
            }
            else
                words_found.insert({word.second, false}); // если нет то пишем false
        }

        // подсчитываем относительную релевантность
        auto maxCount = relative_id.find(0)->second;
        for (auto &entry : relative_id)
        {
            if (entry.second > maxCount)
                maxCount = entry.second;
        }
        std::vector<RelativeIndex> relativeOut;
        for (auto &entry : relative_id)
        {
            RelativeIndex relative;
            relative.doc_id = entry.first;
            relative.rank = float(entry.second) / float(maxCount);
            relativeOut.push_back(relative);
        }

        // добавляем в конечный вектор релевантности (до этого необходимо отсортировать от большего к меньшему)
        std::sort(relativeOut.begin(), relativeOut.end(), [](const RelativeIndex &first, const RelativeIndex &second)
                  { return first.rank > second.rank; });

        results.push_back(relativeOut);
    }
    std::cout <<"" << std::endl;

    return results;
}