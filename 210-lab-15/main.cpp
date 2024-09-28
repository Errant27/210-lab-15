#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const int FILE_SIZE = 4;

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
    vector<Movie> movieVector;
    string s;
    string t;
    Movie m;
    
    int n;
    
    
    reader.open(fileName);
    
    if (!reader) {
        cout << "ERROR. File not opened" << endl;
    }
    else while (reader) {
        for (int i = 0; i < FILE_SIZE; i++) {
            getline(reader, s);
            cout << s << endl;
//            m.setScreenWriter(s);
            reader >> n;
            cout << n << endl;
//            m.setReleaseYear(n);
            reader >> t;
            cout << t << endl;
//            m.setTitle(t);
//            movieVector.push_back(m);
        }
    }
    reader.close();
    
//    for (int i = 0; i < FILE_SIZE; i++) {
//        movieVector[i].print_Movie();
//        cout << "---" << endl;
//    }
//
    
    return 0;
}
