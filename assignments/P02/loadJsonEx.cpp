#include "./headers/json.hpp" // Make sure this points to the correct path of json.hpp
#include "./headers/timer.hpp"
#include <fstream>
#include <iostream>

using namespace std;

using json = nlohmann::json;

void saveWords(json j) {
    ofstream fout;
    fout.open("./data/words.txt");

    for (auto &element : j.items()) {
        std::string key = element.key();
        fout << key << "\n";
    }
}

json openJson(string filePath) {
    std::ifstream fileStream(filePath);
    json myJson;

    if (fileStream.is_open()) {
        fileStream >> myJson;
        fileStream.close();
    }
    return myJson;
}

vector<string> getMatches(json myJson, string partialKey) {
    vector<string> matches;

    // Iterate over all key-value pairs
    for (auto &element : myJson.items()) {
        std::string key = element.key();

        // Check if the key contains the partialKey substring
        if (key.substr(0, partialKey.size()).find(partialKey) != std::string::npos)
            matches.push_back(key);
    }

    return matches;
}

int main2(int argc, char **argv) {

    Timer T;   // create a timer
    T.start(); // start it

    // Load your JSON object as shown in previous examples
    std::string filePath = "./data/dictionary.json";
    json myJson = openJson(filePath);
    T.end(); // end the current timer

    if (myJson.size() == 0) {
        std::cerr << "Failed to open file: " << filePath << '\n';
        return 1;
    }

    printf("Nanoseconds: %.17f\n", (double)T.NanoSeconds() / 1000000000);

    std::string partialKey = " ";
    // The substring you are looking for in the keys
    if (argc == 1)
        partialKey = "axal";
    else
        partialKey = argv[1];

    vector<string> matches;

    // Iterate over all key-value pairs
    for (auto &element : myJson.items()) {
        std::string key = element.key();

        // Check if the key contains the partialKey substring
        if (key.substr(0, partialKey.size()).find(partialKey) != std::string::npos) {
            matches.push_back(key);
        }
    }

    return 0;
}