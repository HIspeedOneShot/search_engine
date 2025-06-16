#include <SearchServer.h>
#include <sstream>
#include <unordered_set>
#include <map>
#include <algorithm>

std::vector<std::vector<RelativeIndex>> SearchServer ::search(const std::vector<std::string> &requests_input)
{
    std::vector<std::vector<RelativeIndex>> results;
        
        for (const auto& request : requests_input) {
            std::istringstream iss(request);
            std::string word;
            
            // Разделение строки на уникальные слова
            std::unordered_set<std::string> unique_words;
            while (iss >> word) {
                unique_words.insert(word);
            }
            
            // Подсчет частот встречаемости слов в документах
            std::map<size_t, size_t> document_frequencies;
            for (const auto& w : unique_words) {
                auto entries = _index.GetWordCount(w);
                
                for (const auto& entry : entries) {
                    document_frequencies[entry.doc_id] += entry.count;
                }
            }
            
            // Нормализация рангов и создание финального списка
            std::vector<RelativeIndex> ranked_results;
            size_t max_count = 0;
            
            for (const auto& pair : document_frequencies) {
                max_count = std::max(max_count, pair.second);
            }
            
            if (max_count > 0) {
                for (const auto& pair : document_frequencies) {
                    RelativeIndex ri;
                    ri.doc_id = pair.first;
                    ri.rank = static_cast<float>(pair.second) / max_count;
                    
                    ranked_results.emplace_back(std::move(ri));
                }
                
                // Сортируем результаты по убыванию ранга
                std::sort(ranked_results.begin(), ranked_results.end(),
                          [](const RelativeIndex& a, const RelativeIndex& b) {
                              return a.rank > b.rank || (a.rank == b.rank && a.doc_id < b.doc_id);
                          });
            }
            
            results.push_back(ranked_results);
        }
        
        return results;
   }
