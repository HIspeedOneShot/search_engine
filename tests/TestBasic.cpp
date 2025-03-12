#include "gtest/gtest.h"


void TestInvertedIndexFunctionality(const vector<string> &docs,
                                    const vector<string> &requests,
                                    const std::vector<vector<Entry>> &expected)
{
    std::vector<std::vector<Entry>> result;
    InvertedIndex idx;
    idx.UpdateDocumentBase(docs);
    for (auto &request : requests)
    {
        std::vector<Entry> word_count = idx.GetWordCount(request);
        result.push_back(word_count);
    }
    ASSERT_EQ(result, expected);
}

TEST(TestCaseInvertedIndex, TestBasic)
{
    const vector<string> docs = {
        "london is the capital of great britain",
        "big ben is the nickname for the Great bell of the striking clock"};
    const vector<string> requests = {"london", "the"};
    const vector<vector<Entry>> expected = {
        {{0, 1}}, {{0, 1}, {1, 3}}};
    TestInvertedIndexFunctionality(docs, requests, expected);
}

int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}