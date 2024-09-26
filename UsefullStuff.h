//There I will place struct of time, some temporary things and almost all drawing tools
//that will be used in GUI
#ifndef USEFULLSTUFF_H 
#define USEFULLSTUFF_H

struct Time { int hours, minutes, seconds; };

enum Commands //Temporary used thing. I guess its won't be usefull in GUI
{
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

#endif
