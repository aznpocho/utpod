//
// Created by Ana Rodriguez and Kevin Han on 10/30/18.
//

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On our honor, Analaura Rodriguez and Kevin Han, this programming project is our own work
 * and we have not provided this code to any other student.
 *
 * Name: Analaura Rodriguez, Kevin Han
 * email address: rodriguez.ana@utexas.edu, kevin.han@utexas.edu
 * UTEID: ar55665, kdh2789
 * Section 5 digit ID: 16230
 *
 */

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#endif //UTPOD_SONG_H
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Song{
    private:
        // declaring instance variables
        string title;
        string artist;
        int size;

    public:
        // Default constructor
        // set title to blank
        // set artist to blank
        // set size to 0
        Song();

        // Constructor with title parameter
        // User will pass in the song title, a string
        // set artist to blank
        // set size to 0
        Song(string title);

        // Constructor with title & artist parameter
        // User will pass in the song title & artist, both string
        // set size to 0
        Song(string title, string artist);

        // Constructor with title, artist, & size parameter
        // User will pass in the song title & artist, both string,
        // and song size, an int
        Song(string title, string artist, int size);

        /* FUNCTION - void setTitle
         * updates the song's title

         precondition: _title is a string

         input parms - a string

         output parms - none
        */
        void setTitle(string _title);

        /* FUNCTION - void setArtist
        * updates the song's artist

        precondition: _artist is a string

        input parms - a string

        output parms - none
        */
        void setArtist(string _artist);

        /* FUNCTION - void setSize
        * updates the song's size

        precondition: _size is an integer

        input parms - an int

        output parms - none
        */
        void setSize(int _size);

        /* FUNCTION - string getTitle
        * returns song's title

        precondition: none

        input parms - none

        output parms - song's title, a string
        */
        string getTitle() const;

        /* FUNCTION - string getArtist
        * returns song's artist

        precondition: none

        input parms - none

        output parms - song's artist, a string
        */
        string getArtist() const;

        /* FUNCTION - string getSize
        * returns song's size

        precondition: none

        input parms - none

        output parms - song's size, an integer
        */
        int getSize() const;


        /* FUNCTION - bool operator <
         * * Overrides operator <
         * 1st compares artists. Returns true if LHS alphabetically comes before RHS.
         * 2nd compares titles if artists are same. Returns true if LHS alphabetically comes before RHS.
         * 3rd compares size if artist and title are same. Returns true if LHS smaller than RHS.

         precondition: both LHS and RHS of operator are valid Song class

         input parms - objects of class Song

         output parms - boolean
        */
        bool operator <(const Song &rhs) const;

        /* FUNCTION - bool operator >
        * Overrides operator >
        * 1st compares artists. Returns true if LHS alphabetically comes after RHS.
        * 2nd compares titles if artists are same. Returns true if LHS alphabetically comes after RHS.
        * 3rd compares size if artist and title are same. Returns true if LHS greater than RHS.

        precondition: both LHS and RHS of operator are valid Song class

        input parms - objects of class Song

        output parms - boolean
        */
        bool operator >(const Song &rhs) const;

        /* FUNCTION - bool operator ==
        * Overrides operator ==
        * Returns true if LHS and RHS class Songs are identical, false otherwise
        * Identical = same artist, title, size

        precondition: both LHS and RHS of operator are valid Song class

        input parms - objects of class Song

        output parms - boolean
        */
        bool operator ==(const Song &rhs) const;

};

/* FUNCTION - ostream operator <<
 * Overrides ostream operator <<
 * Prints Song's artist, title, size, left formatted

 precondition: s is a valid object of class Song and called as following: "cout << s"

 input parms - ?? and object of class Song

 output parms - prints string
*/
ostream& operator << (ostream& out, const Song &s);