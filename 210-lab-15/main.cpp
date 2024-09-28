#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const int FILE_SIZE = 4;

class Movie
{
private:
    string title;
    int releaseYear;
    string screenWriter;
    
public:
    void setTitle(string t) { title = t; }    // Setter Functions
    void setReleaseYear(int r) { releaseYear = r; }
    void setScreenWriter(string s) { screenWriter = s; }
    
    string getTitle() { return title; }    // Getter Functions
    int getReleaseYear() { return releaseYear; }
    string getScreenWriter() { return screenWriter; }
    
    void print_Movie() {    // Print Function
        cout << "Title: " << title << endl;
        cout << "Release year: " << releaseYear << endl;
        cout << "Screenwriter: " << screenWriter << endl;
    }
};     // End of class

int main()
{
    ifstream reader;
    string fileName = ("TopMovies.txt");
    vector<Movie> movieVector;
    string t;
    int n;
    string s;
    Movie m;
    
    
    reader.open(fileName);
    if (!reader) {
        cout << "ERROR. File not opened" << endl;
    }
    else {
        for (int i = 0; i < FILE_SIZE; i++) {
            getline(reader, t);
            m.setTitle(t);
            reader >> n;
            m.setReleaseYear(n);
            reader >> s;
            m.setScreenWriter(s);
           
            reader.ignore();    // Xcode seems to require file reader object be cleared through subsequent loop runs in order to store new values
            reader.clear();     // (Ex: Loop run 1, store ifstream, store in vector, clear ifstream > Loop run 2, store ifstream, store in vector, clear ifstream. etc)
            
            movieVector.push_back(m);
        }
    }
    reader.close();
    
    for (int i = 0; i < FILE_SIZE; i++) {
        movieVector[i].print_Movie();
        cout << "---" << endl;
    }
    
    return 0;
}
