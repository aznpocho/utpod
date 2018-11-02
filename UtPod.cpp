//
// Created by Ana Rodriguez on 10/30/18.
//

#include "UtPod.h"

using namespace std;

//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;

    // seeding the random number generator
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);  //seed the random number generator
}

//Constructor with size parameter
//The user of the class will pass in a size, an integer.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size){
    // checking if input size is less than 0 or greater than 512, the max memory
    if (size > 0 && size < MAX_MEMORY){
        memSize = size;
    }
    // setting memory size to default 512 MB
    else {
        memSize = MAX_MEMORY;
    }

    // pointer to linked list
    songs = NULL;

    // seeding the random number generator
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);  //seed the random number generator
}

/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song

 precondition: s is a valid Song

 input parms - song to be added

 output parms - -1 if unsuccessful or 0 if successful;
*/
int UtPod::addSong(Song const &s){
    // if there is enough memory and each song attribute is not blank then add song
    if ((s.getSize() <= getRemainingMemory()) && (s.getArtist()!="" && s.getTitle()!="" && s.getSize()!=0)){
        // add song to beginning of linked list
        SongNode* newSong = new SongNode;
        newSong -> s = s;
        newSong -> next = songs;
        songs = newSong;
        return(SUCCESS);
    }
    // insufficient memory to add song
    else{
        return(NO_MEMORY);
    }
}

/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
     o returns 0 if successful
     o returns -2 if nothing is removed


   input parms - song to be removed

   output parms - 0 if song successfully removed and -2 if song not found
*/
int UtPod::removeSong(Song const &s){
    SongNode* trail = NULL;
    SongNode* head = songs;
    // while not at null and not found song to remove keep traversing through linked list
    while ((head != NULL) && (!((head->s) == s))){
        trail = head;
        head = head -> next;
    }

    // checks if head is at null (meaning no song in linked list or reached end of linked list
    if (head != NULL){
        // getting song before song being deleted to point to the song that the being deleted song is pointing to
        if (trail != NULL){
            trail -> next = head -> next;
        }
        // means first song in linked list is the being deleted song
        else{
            songs = head -> next;
        }
        // delete song, freeing the memory ocoupied by the song
        delete(head);
        return (SUCCESS);
    }
    // song not found in linked list
    return(NOT_FOUND);
}


/* FUNCTION - void shuffle
 *  shuffles the songs into random order
    o will do nothing if there are less than two songs in the current list

   input parms - none

   output parms - none
*/
void UtPod::shuffle(){
    int idx1, idx2;

    // swapping songs through random number generator x2 the number of songs in linked list
    for (int i = 0; i < numberOfSongs()* 2; i++){
        idx1 = rand() % numberOfSongs();
        idx2 = rand() % numberOfSongs();
        // function being called to swap the contents of the songs located at the indexes randomly generated
        swap(idx1, idx2);
    }
}



/* FUNCTION - SongNode* findIdx(SongNode* head, int idx)
 * finds the pointer to wanted index

 input parms - pointer to songs and desired index

 output parms - pointer to desired index

 */
void UtPod::swap(const int &idx1, const int &idx2){
    SongNode *pt1 = NULL;
    SongNode *pt2 = NULL;
    int counter = 0;

    // traversing linked list and finding the songs at idx1 and idx2
    for (SongNode* head = songs; head != NULL; head = head -> next){
        if (counter == idx1){
            pt1 = head;
        }

        if (counter == idx2){
            pt2 = head;
        }
        counter ++;
    }

    // swapping song attributes between the two songs
    Song temp = pt1 -> s;
    pt1 -> s = pt2 -> s;
    pt2 -> s = temp;

}


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)

   input parms - none

   output parms - returns nothing, but prints all songs to screen
*/
void UtPod::showSongList() const{
    // if linked list is not empty
    if (songs != NULL) {
        cout << left << setw(30) << "Title" << left << setw(30) << "Artist" << left << setw(30) << "Size" << endl;
        // traverse linked list and print out each song
        for (SongNode *head = songs; head != NULL; head = head->next) {
            cout << head->s;
        }
    }
    // no song is in the linked list
    else{
        cout << "Playlist Empty :( \n";
    }
}


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    o will do nothing if there are less than two songs in the current list

   input parms - none

   output parms - none
*/
void UtPod::sortSongList(){
    // bubble sort, sorting songs by artist, then title, then size
    for (SongNode *head1 = songs; head1 != NULL; head1 = head1 -> next){
        SongNode* trail = songs;
        for (SongNode *head2 = trail -> next; head2 != NULL; head2 = head2 -> next){
            if (head2 -> s < trail -> s){
                Song temp = head2 -> s;
                head2 -> s = trail -> s;
                trail -> s = temp;
            }
            trail = head2;
        }
    }
}


/* FUNCTION - void clearMemory
 * clears all the songs from memory

   input parms - none

   output parms - none
*/
void UtPod::clearMemory(){
    // traverses linked list and deletes/frees allocated memory used by linked list
    for (SongNode* head = songs; head != NULL; head = songs){
        songs = head -> next;
        delete(head);
    }
}


/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs

   input parms - none

   output parms - int remaining memory
*/
int UtPod::getRemainingMemory() const{
    int total = 0;
    // traverses linked list and adds up each song's size
    for (SongNode *head = songs; head != NULL; head = head ->next){
        total += head -> s.getSize();
    }

    // returns the UtPod memory size minus size occupied by the songs
    return (memSize - total);
}


/* FUNCTION - int numberOfSongs()
 * counts the number of songs in UtPod

 input parms - none

 output parms - int number of songs

 */
int UtPod::numberOfSongs() const{
    int total = 0;

    // traverse linked list and counts the number of songs
    for(SongNode *head = songs; head != NULL; head = head -> next){
        total += 1;
    }

    return(total);
}

// Destructor, frees allocated memory whenever UtPod object goes out of scope
UtPod::~UtPod(){
    clearMemory();
}