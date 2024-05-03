#ifndef LOGGING_H
#define LOGGING_H

#include <string>
#include <vector>

#include "./termcolor.hpp"
#include "./timer.hpp"

using std::cout;
using std::string;
using std::vector;


enum LEVEL {
    OFF,
    INFO,
    DEBUG
};

template <typename MessageType>
class Logger {
    private:
        unsigned short int _level;
        vector<unsigned short int> index;
    public:
        Logger();
        Logger(unsigned short int _level);
        ~Logger();

        void log(MessageType msg, unsigned short int level);
        void _log(MessageType msg, string end, unsigned short int level);
};


template <typename MessageType>
Logger<MessageType>::Logger()
{
    this->_level = 0;
    this->index = {0, 0, 0};
}

template <typename MessageType>
inline Logger<MessageType>::Logger(unsigned short int _level) {
    this->_level = _level;
    this->index = {0, 0, 0};
}

template <typename MessageType>
inline void Logger<MessageType>::log(MessageType msg, unsigned short int level) {
    this->_log(msg, "\n", level);
}

template <typename MessageType>
inline void Logger<MessageType>::_log(MessageType msg, string end, unsigned short int level) {
    if (this->_level < level)
        return;
    
    string level_str = level > 1 ? "[Debug " : "[Info ";
    
    cout << level_str << index[level]++ << "]: " << msg << end;
}

template <typename MessageType>
Logger<MessageType>::~Logger() {
}

#endif

void printFormat(string title="", string line="") {
    cout
        << termcolor::underline << termcolor::bold << termcolor::bright_cyan
        << title << line << termcolor::reset << "\n\n";
}

void printLoadTime(Timer & _timer) {
    printFormat("GETCH WORD LOOKUP");

    vector<pair<string, int>> times = {
        make_pair("  ", _timer.seconds()),
        make_pair("  Milli", _timer.milliSeconds()),
        make_pair("  Nano", _timer.nanoSeconds()),
    };

    // print out how long it took to load the animals file
    cout << termcolor::underline << termcolor::cyan
         << "Load Time for data file:" << termcolor::reset << '\n';
    for (pair<string, int> timeUnit : times) {
        cout << termcolor::bold << termcolor::green
             << timeUnit.second << termcolor::yellow << timeUnit.first
             << "seconds" << termcolor::reset << "\n\n";
    }

    printFormat("Type a word to begin...");
}
