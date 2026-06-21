#include "beer_song.h"
#include <sstream>

using namespace std;

namespace beer_song {

    string verse(int number) {
        ostringstream ss;

        switch (number) {
            case 0:
            ss << "No more bottles of beer on the wall, no more bottles of beer.\n"
            << "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
            break;

            case 1:
            ss << "1 bottle of beer on the wall, 1 bottle of beer.\n"
            << "Take it down and pass it around, no more bottles of beer on the wall.\n";
            break;

            case 2:
            ss << "2 bottles of beer on the wall, 2 bottles of beer.\n"
            << "Take one down and pass it around, 1 bottle of beer on the wall.\n";
            break;

            default:
            ss << number << " bottles of beer on the wall, " << number << " bottles of beer.\n"
            << "Take one down and pass it around, " << (number - 1) << " bottles of beer on the wall.\n";
            break;
        }

        return ss.str();
    }

    string sing(int start, int end) {
        ostringstream ss;

        // La canción siempre va en cuenta regresiva
        for (int i = start; i >= end; --i) {
            ss << verse(i);
            // Salto de linea entre versos
            if (i > end) {
                ss << "\n";
            }
        }

        return ss.str();
    }

}