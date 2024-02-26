#include <iostream>
#include <string>
#include <sstream>

using namespace std;


// FUNCTION PROTOTYPES
void parseCommand(stringstream& ss);
void parseToken(stringstream& ss);
void printCommand(string input);

//MAIN
int main() {
    string input;
    while (true) {
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        printCommand(input);
    }
    return 0;
}

// FUNCTION DEFINITIONS

// Print the command and its tokens
void printCommand(string input) {
    stringstream ss(input);
    parseCommand(ss);
}

// Parse the command and its tokens
void parseCommand(stringstream& ss) {
    string command;
    // Check if command is valid
    if (ss >> command) {
        cout << "Command: " << command << endl;
        // While the stream is not empty, parse the tokens
        while (!ss.eof()) {
            parseToken(ss);
        }
    }
    else {
        cout << "Command: " << "null" << endl;
        return;
    }
}

// Parse the tokens of the command
void parseToken(stringstream& ss) {
    string token;
    // Check if token is valid
    if (ss >> token) {
        // Check if it is an option
        if (token[0] == '-') {
            cout << "Options: " << token << endl;
        }
        // Check if it is io redirection
        else if (token == "<" || token == ">" || token == ">>") {
            cout << "File Redirection: " << token << endl;
            // Get the file name
            string file;
            if (ss >> file) {
                cout << "File: " << file << endl;
            } else {
                cout << "File: " << "null" << endl;
            }
        }
        // Check if it is a pipe
        else if (token == "|") {
            cout << "Pipe"<< endl;
            // The next is command, recurse
            parseCommand(ss);
        }
        // Otherwise it is an argument
        else {
            cout << "Arguments: " << token << endl;
        }
    } else {
        // Gave an empty stream, throw error
        throw "Invalid token";
    }
}