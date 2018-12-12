#include <sstream>

using namespace std;

struct Book {
    string title;
    string author;
    string genre;
};

void Parse (string line, Book &b)
{
    stringstream lineStream(line);   // transforms the line into a string stream
    
    // get fields from the string stream to the struct fields; data is separated by comma
    getline(lineStream, b.title, ',');
    getline(lineStream, b.author, ',');
    getline(lineStream, b.genre, ',');
    
}
