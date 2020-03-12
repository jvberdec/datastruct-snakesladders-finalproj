#include "Board.h"

Board::Board() {
     boardState = new int[101];
     int temp[] = {-1, 1, 2, 20, 4, 5, 14, 7, 4, 9, 10, 28, 12, 13,
                    14, 34, 16, 74, 1, 19, 20, 21, 37, 23, 24, 25,
                    10, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
                    59, 5, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
                    50, 6, 52, 53, 36, 55, 1, 76, 58, 59, 23, 78,
                    62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 86,
                    74, 28, 76, 77, 78, 79, 80, 98, 82, 45, 84, 59,
                    86, 87, 91, 89, 48, 91, 25, 93, 94, 95, 96, 87,
                    98, 99, 100}; // SNAKES AND LADDERS PRE-ENTERED

     for (int i = 0; i < 101; i++) {
       boardState[i] = temp[i];
     }
}
Board::~Board(){
	delete boardState;
}

/*

if placeNumber < originalPlaceOrder it is a SNAKE
if placeNumber > originalPlaceOrder it is a LADDER

SNAKES: landing on the left position will lead the player downward to the right position
8  -> 4
18 -> 1
26 -> 10
39 -> 5
51 -> 6
54 -> 36
56 -> 1
60 -> 23
75 -> 28
83 -> 45
85 -> 59
90 -> 48
92 -> 25
97 -> 87

LADDERS: landing on the left position will lead the player upward to the left position
3  -> 20
6  -> 14
11 -> 28
15 -> 34
17 -> 74
22 -> 37
38 -> 59
57 -> 76
61 -> 78
73 -> 86
88 -> 91
81 -> 98

*/
