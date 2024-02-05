#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> split(const string &inputString, char delimiter) {
    vector<string> splitString;
    splitString.clear();

    // define the staring position of the string and first delimiter's position
    size_t startPosition = 0;
    size_t delimiterPosition = inputString.find_first_of(delimiter);

    // while a delimiter is found...
    while(delimiterPosition != string::npos) {
        // push a component of `inputString` to the return vector
        // Note: `size_t endPosition = delimiterPosition - startPosition`
        splitString.push_back(
            inputString.substr(startPosition, delimiterPosition - startPosition)
        );

        // refresh the start position and delimiter position to next component's
        // start and end position
        startPosition = delimiterPosition + 1;
        delimiterPosition = inputString.find(delimiter, startPosition);
    }

    // Add the last component of `inputString` to the returned vector
    splitString.push_back(
        inputString.substr(
            startPosition,
            std::min(delimiterPosition, inputString.size()) - startPosition + 1
        )
    );
    return splitString;
}