#include "./json.hpp"
#include "./logging.h"

using namespace std;
using json = nlohmann::json;

/// @brief color format top 10 query results
/// @param matches all matches from current query
/// @param word word criteria of current query
void colorResults(vector<string> & matches, string word);

/// @brief print stats on the number of matches and duration of a query
/// @param numberOfQueryResults number of matches from current query
/// @param nanoseconds time duration for getting current query
void printStats(int numberOfQueryResults, int nanoseconds);

/// @brief Get a vector of matches from a given dictionary based on a key
/// @param dictionary dictionary containing possible matches
/// @param partialKey key criteria for retrieving matches
/// @return all dictionary entries which fit the given key criteria
vector<string> getDictionaryMatches(json & dictionary, string partialKey);

/// @brief Finds partial matches in an array of strings
/// @param words array to search
/// @param substring substring to search for in each word
/// @return all the matched words from substring
pair<vector<string>, int> partialMatch(json & dictionary, string substring);

/// @brief cache a portion of a given `dictionary` to the given cache
/// @details cache is built from the first letter of the given `word`
/// @param dictionary full dictionary `json` object
/// @param dictionaryCache container for cached dictionary
/// @param word word whose first letter is used as caching criteria
void cacheDictionary(json & dictionary, json & dictionaryCache, string word);

/// @brief Append `typed_char` or pop last letter in `word`
/// @param typed_char either a alphanum or a backspace key
/// @param word word currently in buffer
/// @return boolean of whether or not an error occured
bool buildWord(char typed_char, string & word);

/// @brief Load .json data from a given file at `pathName`
/// @param pathName absolute location of .json file
/// @param _logger `Logger` object to log errors
/// @return nlohmann `json` deserialization of `pathName`
json loadData(string pathName, Logger<string> & _logger);
