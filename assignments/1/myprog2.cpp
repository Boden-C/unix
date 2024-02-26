#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Print out everything before
    cout << "Before:" << endl;
    system("find");
    cout << endl;

    // Create myprog3.cpp
    ofstream file("myprog3.cpp");

    // Set code for myprog3.cpp using raw string literal
    file << R"(
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Unlink all links
    system("find . -type l ! -exec test -d {} \\; -exec rm {} +");

    // Remove all files and directories
    system("rm -rf ./*");

    // Print out everything after
    cout << "After:" << endl;
    system("find");
}
    )";
    
    // Close file
    file.close();

    // Compile
    if (system("g++ myprog3.cpp -o myprog3") != 0) {
        cerr << "Compilation failed!";
        return 1;
    }

    // Execute
    system("./myprog3");

    return 0;
}