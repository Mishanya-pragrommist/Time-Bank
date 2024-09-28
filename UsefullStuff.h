//There I will place struct of time, some temporary things and almost all drawing tools
//that will be used in GUI
#ifndef USEFULLSTUFF_H 
#define USEFULLSTUFF_H

struct Time { int hours, minutes, seconds; };

enum Commands //Temporary used thing. I guess its won't be usefull in GUI. But who knows...
{
	UPDATE = 1,
	ADD, //= 2
	GETTIME, // 3
	RETURNTIME, // 4
	STARTTIMER, // 5
	PRINTALLACCOUNTS, // 6
	CREATEACCOUNT, // 7
	RENAMECURRENTACC, // 8
	GOTO, // 9
	DELETEACC, // 10
	STOP // 11
};

#endif
