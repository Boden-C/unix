#include <cstdlib>

using namespace std;

int main() {

    // Create dir1 and file10 first
    system("mkdir dir1");
    system("touch dir1/file10");

    // Then create dir2 and file20
    system("mkdir dir2");
    system("touch dir2/file20");

    // Then create file 1
    system("touch file1");

    // Create symbolic link to file20
    system("ln -s dir2/file20 link1");

    return 0;
}
