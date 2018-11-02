//
// Created by Ana Rodriguez on 10/30/18.
//

#include "song.h"

using namespace std;

// Default constructor
// set title to blank
// set artist to blank
// set size to 0
Song::Song(){
    // setting attributes to default values
    title = "";
    artist = "";
    size = 0;
}

// Constructor with title parameter
// User will pass in the song title, a string
// set artist to blank
// set size to 0
Song::Song(string title){
    // setting song title to user input
    this -> title = title;
    artist = "";
    size = 0;
}

// Constructor with title & artist parameter
// User will pass in the song title & artist, both string
// set size to 0
Song::Song(string title, string artist){
    // setting song title and artist to user input
    this -> title = title;
    this -> artist = artist;
    size = 0;
}

// Constructor with title, artist, & size parameter
// User will pass in the song title & artist, both string,
// and song size, an int
Song::Song(string title, string artist, int size){
    this -> title = title;
    this -> artist = artist;
    // checking input, if size is less than 0 then default to 0
    if (size < 0){
        this -> size = 0;
    }
    else{
        this -> size = size;
    }
}

/* FUNCTION - void setTitle
 * updates the song's title

 precondition: _title is a string

 input parms - a string

 output parms - none
*/
void Song::setTitle(string _title){
    title = _title;
}

/* FUNCTION - void setArtist
 * updates the song's artist

 precondition: _artist is a string

 input parms - a string

 output parms - none
*/
void Song::setArtist(string _artist){
    artist = _artist;
}

/* FUNCTION - void setSize
 * updates the song's size

 precondition: _size is an integer

 input parms - an int

 output parms - none
*/
void Song::setSize(int _size){
    size = _size;
}

/* FUNCTION - string getTitle
 * returns song's title

 precondition: none

 input parms - none

 output parms - song's title, a string
*/
string Song::getTitle() const{
    return(title);
}

/* FUNCTION - string getArtist
 * returns song's artist

 precondition: none

 input parms - none

 output parms - song's artist, a string
*/
string Song::getArtist() const{
    return(artist);
}

/* FUNCTION - string getSize
 * returns song's size

 precondition: none

 input parms - none

 output parms - song's size, an integer
*/
int Song::getSize() const{
    return(size);
}


/* FUNCTION - bool operator <
 * * Overrides operator <
 * 1st compares artists. Returns true if LHS alphabetically comes before RHS.
 * 2nd compares titles if artists are same. Returns true if LHS alphabetically comes before RHS.
 * 3rd compares size if artist and title are same. Returns true if LHS smaller than RHS.

 precondition: both LHS and RHS of operator are valid Song class

 input parms - objects of class Song

 output parms - boolean
*/
bool Song::operator <(const Song &rhs) const{
    // check if LHS and RHS artists are equivalent
    if (artist != rhs.artist){
        // returns True if LHS artist comes before RHS artist
        return(artist < rhs.artist);
    }
    // checks if LHS and RHS titles are equivalent
    if (title != rhs.title) {
        // returns True if LHS title comes before RHS artist
        return (title < rhs.title);
    }
    // checks if LHS and RHS sizes are equivalent
    if (size != rhs.size){
        // returns TRUE if LHS size is less than RHS size
        return (size < rhs.size);
    }
    // returns false if RHS is less than LHS
    return(false);

}

/* FUNCTION - bool operator >
 * Overrides operator >
 * 1st compares artists. Returns true if LHS alphabetically comes after RHS.
 * 2nd compares titles if artists are same. Returns true if LHS alphabetically comes after RHS.
 * 3rd compares size if artist and title are same. Returns true if LHS greater than RHS.

 precondition: both LHS and RHS of operator are valid Song class

 input parms - objects of class Song

 output parms - boolean
*/
bool Song::operator >(const Song &rhs) const{
    // check if LHS and RHS artists are equivalent
    if (artist != rhs.artist){
        // returns True if LHS artist comes after RHS artist
        return(artist > rhs.artist);
    }
    // checks if LHS and RHS titles are equivalent
    if (title != rhs.title) {
        // returns True if LHS title comes after RHS artist
        return (title > rhs.title);
    }
    // checks if LHS and RHS sizes are equivalent
    if (size != rhs.size){
        // returns TRUE if LHS size is less than RHS size
        return (size > rhs.size);
    }
    // returns false if LHS is less than RHS
    return(false);

}

/* FUNCTION - bool operator ==
 * Overrides operator ==
 * Returns true if LHS and RHS class Songs are identical, false otherwise
 * Identical = same artist, title, size

 precondition: both LHS and RHS of operator are valid Song class

 input parms - objects of class Song

 output parms - boolean
*/
bool Song::operator ==(const Song &rhs) const{
    // returns true if title, artist, and size are all equivalent
    return(title == rhs.title &&
            artist == rhs.artist &&
            size == rhs.size);
}

/* FUNCTION - ostream operator <<
 * Overrides ostream operator <<
 * Prints Song's artist, title, size, left formatted

 precondition: s is a valid object of class Song and called as following: "cout << s"

 input parms - ?? and object of class Song

 output parms - prints string
*/
ostream& operator << (ostream& out, const Song &s){
    // overrides << operator, prints out song attributes left justified
    out << left << setw(30) << s.getTitle() << left << setw(30) << s.getArtist() << left << setw(30) << s.getSize() << endl;
    return(out);
}