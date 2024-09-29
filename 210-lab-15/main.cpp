#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const int FILE_SIZE = 4;

class Movie
{
private:    // Private member variables for the title, release year, and screen writer
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
    ifstream reader; // ifstream variable to read the file
    string fileName = ("TopMovies.txt"); // Name of file initialized as string
    vector<Movie> movieVector; // Movie class vector
    string t; // String variable to store the title
    int n; // int varaible to store the release year
    string s; // string varable to store the screen writer
    Movie movie; // Movie object to fill and populate the vector
    
    
    reader.open(fileName);    // File opened, with error message if unsuccessful
    if (!reader) {
        cout << "ERROR. File not opened" << endl;
    }
    else {    // When file is successfully opened, a movie object is populated and put in the vector on each loop iteration
        for (int i = 0; i < FILE_SIZE; i++) {
            getline(reader, t);
            movie.setTitle(t);
            reader >> n;
            movie.setReleaseYear(n);
            reader >> s;
            movie.setScreenWriter(s);
            
            reader.ignore();    // Xcode seems to require file reader object be cleared through subsequent loop runs in order to store new values
            reader.clear();     // (Ex: Loop run 1, store ifstream, store in vector, clear ifstream > Loop run 2, store ifstream, store in vector, clear ifstream. etc)
            
            movieVector.push_back(movie);
        }
    }
    reader.close();    // File closed
    
    for (int i = 0; i < FILE_SIZE; i++) {    // Elements of Movie vector printed out via calls to the print_Movie member function
        movieVector[i].print_Movie();
        cout << "---" << endl;
    }
    
    return 0;
}
