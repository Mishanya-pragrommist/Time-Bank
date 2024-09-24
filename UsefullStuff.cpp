#include "UsefullStuff.h"

enum Commands { //Temporary used thing. I guess it won't be usefull in GUI
    UPDATE = 1,
    ADD, //= 2
    GETTIME, // 3
    PRINT, // 4
    PRINTALLACCOUNTS, // 5
    CREATEACCOUNT, // 6
    RENAMECURRENTACC, //7
    GOTO, //8
    DELETE, // 9
    STOP // 10
};

struct Time { int hours, minutes, seconds; };
