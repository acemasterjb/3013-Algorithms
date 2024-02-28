#include "./json.hpp"
#include "./logging.h"

using namespace std;
using json = nlohmann::json;

void colorResults(vector<string> & matches, string word);
void printStats(int numberOfQueryResults, int nanoseconds);
vector<string> getDictionaryMatches(json dictionary, string partialKey);
pair<vector<string>, int> partialMatch(json dictionary, string substring);
void cacheDictionary(json & dictionary, json & dictionaryCache, string word);
bool buildWord(char typed_char, string & word);
json loadData(string pathName, Logger<string> & _logger);
