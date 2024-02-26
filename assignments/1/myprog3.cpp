
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
    