/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    // initial class Song Testing
    cout << "_____Initial class Song Testing_____" << endl;

    // test Song constructor, 0 input
    cout << "*** Test Song constructor, 0 input ***" << endl;
    cout << left << setw(30) << "Title" << left << setw(30) << "Artist" << left << setw(30) << "Size" << endl;
    Song test1;
    cout << test1 << endl;

    // test Song constructor, 1 input
    cout << "*** Test Song constructor, 1 input ***" << endl;
    cout << left << setw(30) << "Title" << left << setw(30) << "Artist" << left << setw(30) << "Size" << endl;
    Song test2("Sicko Mode");
    cout << test2 << endl;

    // test Song constructor, 2 input
    cout << "*** Test Song constructor, 2 input ***" << endl;
    cout << left << setw(30) << "Title" << left << setw(30) << "Artist" << left << setw(30) << "Size" << endl;
    Song test3("Sicko Mode","Travis Scott");
    cout << test3 << endl;

    // test Song constructor, 3 input
    cout << "*** Test Song constructor, 3 input ***" << endl;
    cout << left << setw(30) << "Title" << left << setw(30) << "Artist" << left << setw(30) << "Size" << endl;
    Song test4("Sicko Mode","Travis Scott",50);
    cout << test4 << endl;

    // test Song constructor, 3 input
    cout << "*** Test Song constructor, 3 input, setting size less than or equal to 0 ***" << endl;
    cout << left << setw(30) << "Title" << left << setw(30) << "Artist" << left << setw(30) << "Size" << endl;
    Song test5("Sicko Mode","Travis Scott",0);
    Song test6("Sicko Mode","Travis Scott",-1);
    cout << test5;
    cout << test6 << endl;

    // testing get functions
    cout << "*** Testing get functions of class Song ***" << endl;
    cout << "Title: " << test6.getTitle() << endl;
    cout << "Artist: " << test6.getArtist() << endl;
    cout << "Size: " << test6.getSize() << endl << endl;

    // testing set functions
    cout << "*** Testing set functions of class Song ***" << endl;
    cout << "Original Song: ";
    Song test7;
    cout << test7;
    cout << "Updated Song: ";
    test7.setTitle("Astro Thunder");
    test7.setArtist("John Mayer");
    test7.setSize(50);
    cout << test7 << endl;

    // testing boolean operators <, >, ==
    Song test8("It's Raining", "Elmo", 25);
    cout << "*** Testing boolean operators of class Song ***" << endl;
    cout << "LHS: " << test8 << "RHS: " << test6;
    cout << "Testing LHS < RHS songs: ";
    if (test8 < test6){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "Testing LHS > RHS songs: ";
    if (test8 > test6){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "Testing LHS == RHS songs: ";
    if (test8 == test6){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "Testing RHS == RHS songs: ";
    if (test6 == test6){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
    // creating class UtPod object t and class Song object s's
    UtPod t;
    UtPod t2(300);
    UtPod t3(5000);
    UtPod t4(-123);
    Song s1("Sicko Mode", "Travis Scott", 50);
    Song s2("Astrothunder", "Travis Scott", 34);
    Song s3("The Prayer", "Kid Cudi", 0);
    Song s4("", "Kevin Han", 50);
    Song s5("Nights", "Frank Ocean", 513);
    Song s6("Notice Me", "Migos", 140);
    Song s7("Finesse", "Drake", 100);
    Song s8("Blue Tint", "Drake", 100);
    Song s9("4 Your Eyez Only", "J. Cole", 5);
    Song s10("Kevin's Heart", "J. Cole", 2);
    Song s11("Element", "Kendrick Lamar", 65);
    Song s12("Shot Clock", "Ella Mai", 500);
    Song s13("Pizza Time");


    // testing class UtPod
    cout << endl << "__________UtPod testing__________" << endl;

    // testing UtPod constructor, testing getTotalMemory Function
    cout << "*** Testing UtPod Constructor ***" << endl;
    cout << "Default UtPod Constructor: " <<  endl;
    cout << "- Total Size: " << t.getTotalMemory() << endl;
    cout << "- Song list: ";
    t.showSongList();
    cout << endl << "UtPod Constructor, size input: " << endl;
    cout << "- Total Size: " << t2.getTotalMemory() << endl;
    cout << "- Song list: ";
    t2.showSongList();
    cout << endl << "UtPod Constructor, size input greater than 512 MB: " << endl;
    cout << "- Total Size: " << t3.getTotalMemory() << endl;
    cout << "- Song list: ";
    t3.showSongList();
    cout << endl << "UtPod Constructor, size input less than 0: " << endl;
    cout << "- Total Size: " << t4.getTotalMemory() << endl;
    cout << "- Song list: ";
    t4.showSongList();


    // testing add song function
    cout << endl << "*** Testing add song ***" << endl;
    cout << "- Will only add songs if they meet requirements and/or if there is enough memory space" << endl;
    cout << "Songs to be added:" << endl;
    cout << left << setw(30) << "Title" << left << setw(30) << "Artist" << left << setw(30) << "Size" << endl;
    cout << s1 << s2 << s3 << s4 << s5 << s6 << s7 << s8 << s9 << s10 << s11 << s12 << s13 << endl << endl << "Actual Songs added: \n";

    t2.addSong(s1);     // should add
    t2.addSong(s2);     // should add
    t2.addSong(s3);     // shouldn't add: missing song size
    t2.addSong(s4);     // shouldn't add: missing song title
    t2.addSong(s5);     // shouldn't add: not enough memory
    t2.addSong(s6);     // should add
    t2.addSong(s7);     // shouldn't add: not enough memory
    t2.addSong(s8);     // shouldn't add: not enough memory
    t2.addSong(s9);     // should add
    t2.addSong(s10);    // should add
    t2.addSong(s11);    // should add
    t2.addSong(s12);    // shouldn't add: not enough memory
    t2.addSong(s13);    // shouldn't add: missing song artist and size
    t2.showSongList();

    // testing remove song function
    cout << endl << "*** Testing remove song ***" << endl;
    cout << "- Removing song that does exist:  " << s1;
    t2.removeSong(s1);
    t2.showSongList();
    cout << endl << "- Removing song that doesn't exist:  " << s7;
    t2.removeSong(s7);
    t2.showSongList();

    // testing shuffling song function
    cout << endl << "*** Testing shuffle ***" << endl;
    cout << "- Original:" << endl;
    t2.addSong(s1);
    t2.showSongList();
    cout << endl << "- Shuffled:" << endl;
    t2.shuffle();
    t2.showSongList();

    // testing sort song function
    cout << endl << "*** Testing sort ***" << endl;
    cout << "- Original:" << endl;
    t2.showSongList();
    cout << endl << "- Sorted:" << endl;
    t2.sortSongList();
    t2.showSongList();

    // testing RemainingMemory function
    cout << endl << "*** Testing remaining memory ***" << endl;
    cout << "- Total Memory: " << t2.getTotalMemory() << endl;
    cout << "- Remaining Memory: " << t2.getRemainingMemory() << endl;

    // testing clearMemory function
    cout << endl << "*** Testing clearing memory ***" << endl;
    t2.clearMemory();
    cout << "- Total Memory: " << t2.getTotalMemory() << endl;
    cout << "- Remaining Memory: " << t2.getRemainingMemory() << endl;
    cout << "- Song list: ";
    t2.showSongList();
}