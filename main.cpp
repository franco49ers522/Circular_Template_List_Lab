// Jareth Franco - Circular Template List Lab
#include <iostream>
#include <sstream>
#include <string>
#include "LinkedList.h"
#include "Podcast.h"
#include "Song.h"

bool readLine(const std::string& prompt, std::string& value) {
    std::cout << prompt;
    return static_cast<bool>(std::getline(std::cin, value));
}

bool readNumber(const std::string& prompt, int& value) {
    std::string line;
    while (readLine(prompt, line)) {
        std::istringstream input(line);
        char extra;
        if ((input >> value) && !(input >> extra) && value >= 0) return true;
        std::cout << "Please enter a nonnegative whole number.\n";
    }
    return false;
}

int main(int argc, char* argv[]) {
    if (argc == 2 && std::string(argv[1]) == "--songs") {
        LinkedList<Song*> myPlaylist;
        myPlaylist.insert(new Song("Bohemian Rhapsody", "Queen", 355));
        myPlaylist.insert(new Song("Stairway to Heaven", "Led Zeppelin", 482));
        myPlaylist.displayList();
        myPlaylist.playCurrent();
        myPlaylist.playNext();
        myPlaylist.playNext();
        return 0;
    }

    LinkedList<Media*> playlist;
    playlist.insert(new Song("Bohemian Rhapsody", "Queen", 355));
    playlist.insert(new Podcast("The Daily: AI Ethics", "Michael Barbiero", 145));
    playlist.insert(new Song("Stairway to Heaven", "Led Zeppelin", 482));

    int choice;
    while (true) {
        std::cout << "\n1. Add song\n2. Add podcast\n3. Display playlist\n"
                     "4. Play current item\n5. Exit\n6. Play next item\n";
        if (!readNumber("Choice: ", choice) || choice == 5) break;

        std::string title, creator;
        int number;
        switch (choice) {
            case 1:
                if (!readLine("Song title: ", title) ||
                    !readLine("Artist: ", creator) ||
                    !readNumber("Duration in seconds: ", number)) return 0;
                playlist.insert(new Song(title, creator, number));
                std::cout << "Song added.\n";
                break;
            case 2:
                if (!readLine("Episode title: ", title) ||
                    !readLine("Host: ", creator) ||
                    !readNumber("Episode number: ", number)) return 0;
                playlist.insert(new Podcast(title, creator, number));
                std::cout << "Podcast added.\n";
                break;
            case 3: playlist.displayList(); break;
            case 4: playlist.playCurrent(); break;
            case 6: playlist.playNext(); break;
            default: std::cout << "Choose a number from 1 to 6.\n";
        }
    }
}
