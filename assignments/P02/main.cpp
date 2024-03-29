/**
 * @short Json Linear Search
 * @author Jamil Bousquet | jcbousquet0923@my.msutexas.edu
 * @date 02/28/24
 * @details This program uses a "getch" function which means "get character".
 * However, getch does not print the character to the terminal, it
 * lets you decide what to do based on what character you are pressing.
 */

#include <fstream>
#include <utility>

#include "./headers/mygetch.hpp"
#include "./headers/preamble.h"


using namespace std;

enum Key {
    BACKSPACE = 127,
    SPACE = 32,
};

int main() {
    Logger<string> _logger;
    Timer _timer;

    json subDictionary;
    json dictionary;

    _timer.start();
    dictionary = loadData("./data/dictionary.json", _logger);
    _timer.end();
    subDictionary = dictionary;

    printLoadTime(_timer);

    vector<string> matches;
    string word = "";
    char typed_char;

    while ((typed_char = getch()) != 'Z') {
        _timer.start();

        string prevWord = word;
        bool errorOccurred = buildWord(typed_char, word);
        if (errorOccurred || word == prevWord)
            continue;

        if(prevWord.substr(0, 1) != word.substr(0, 1))
            cacheDictionary(dictionary, subDictionary, word);

        pair<vector<string>, int> queryResults = partialMatch(subDictionary, word);
        _timer.end();

        matches = queryResults.first;
        int numOfQueryResults = queryResults.second;

        if ((int)typed_char != Key::SPACE) {
            system("clear");
            printFormat("GETCH WORD LOOKUP");

            cout << termcolor::reset << termcolor::red
                 << word << termcolor::reset << "\n\n";

            printStats(numOfQueryResults, _timer.nanoSeconds());
            colorResults(matches, word);
        }
    }
}

json loadData(string pathName, Logger<string> & _logger) {
    ifstream fileStream(pathName);
    json dictionary;

    if (fileStream.is_open()) {
        fileStream >> dictionary;
        fileStream.close();
    } else
        _logger.log("provided `pathName` not found", LEVEL::DEBUG);

    return dictionary;
}

bool buildWord(char typed_char, string & word) {
    
    if ((int)typed_char == Key::BACKSPACE) {
        if (word.size() > 0)
            word.erase(word.end() - 1);
    } else {
        if (!isalpha(typed_char)) {
            cout << termcolor::on_bright_red << termcolor::bright_white
                    << "\nLetters only!" << termcolor::reset << '\n';
            return true;
        }

        if (isupper((int)typed_char))
            typed_char += 32;
        word += typed_char;
    }
    return false;
}

void cacheDictionary(json & dictionary, json & dictionaryCache, string word) {
    dictionaryCache.clear();

    char nextLetter = *(&word[0]) + 1;
    string nextLetterStr = "";
    nextLetterStr.push_back(nextLetter);

    auto start = dictionary.find(word.substr(0, 1));
    auto end = dictionary.find(nextLetterStr);
    dictionaryCache = json(start, end);
}

pair<vector<string>, int> partialMatch(json & dictionary, string substring) {
    vector<string> matches;
    size_t found_position;
    int substring_size = substring.size();

    vector<string> dictionaryMatches = getDictionaryMatches(dictionary, substring);
    int queryResultsSize = dictionaryMatches.size();
    int matchesSize = queryResultsSize < 10 ? queryResultsSize : 10;

    for (int i = 0; i < matchesSize; i++) {
        found_position
            = dictionaryMatches[i]
                .substr(0, substring_size)
                .find(substring);

        if (found_position != string::npos)
            matches.push_back(dictionaryMatches[i]);
    }

    return make_pair(matches, queryResultsSize);
}

vector<string> getDictionaryMatches(json & dictionary, string partialKey) {
    vector<string> matches;

    for (auto & element : dictionary.items()) {
        string key = element.key();

        if (key.substr(0, partialKey.size()) == partialKey)
            matches.push_back(key);
    }

    return matches;
}

void printStats(int numberOfQueryResults, int nanoseconds) {
    cout << termcolor::green;

    cout << termcolor::yellow << numberOfQueryResults << termcolor::reset
    << termcolor::green << termcolor::bold << " words found in "
    << termcolor::reset << termcolor::yellow
    << printf("%.3f", (double)nanoseconds / 1000000000)
    << termcolor::reset << " seconds"
    << termcolor::reset << "\n\n";

    cout << termcolor::reset << "\n\n";
}

void colorResults(vector<string> & matches, string word) {
    for (string match : matches) {
        cout << termcolor::bold << "\"";
        for (char letter : match.substr(0, word.size()))
            cout << termcolor::red << letter;
        for (char letter : match.substr(word.size(), match.size()))
            cout << termcolor::blue << letter;
        cout << termcolor::blue << "\"" << " ";
    }
}
