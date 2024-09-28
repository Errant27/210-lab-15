#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


class Movie
{
private:
    string screenWriter;
    int releaseYear;
    string title;
    
public:
    void setScreenWriter(string s) {
        screenWriter = s;
    }
    
    void setReleaseYear(int r) {
        releaseYear = r;
    }
    
    void setTitle(string t) {
        title = t;
    }
    
    string getScreenWriter() {
        return screenWriter;
    }
    
    int getReleaseYear() {
        return releaseYear;
    }
    
    string getTitle() {
        return title;
    }
    
    void print_Movie() {
        cout << screenWriter << endl;
        cout << releaseYear << endl;
        cout << title << endl;
    }
}; // End of class

int main()
{
    ifstream reader;
    string fileName = ("TopMovies.txt");
    Movie movie1;
    string s;
    int n;
    
    reader.open(fileName);
    
    if (!reader) {
        cout << "ERROR. File not opened" << endl;
    }
    else {
        reader >> s;
        movie1.setScreenWriter(s);
        reader >> n;
        movie1.setReleaseYear(n);
        reader >> s;
        movie1.setTitle(s);
    }
    
    movie1.print_Movie();
    
    return 0;
}
