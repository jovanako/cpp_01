-> How to declare and initialize an array of pointers to member functions in C++98:

void (Harl::*complaints[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
};

-	In C++98, you are allowed to initialize an array using an INITIALIZER LIST
	(the "{}" syntax) as long as the data is known at the time of declaration.

-	Why this works in C++98:
	-	INITIALIZATION: You are providing the addresses of functions 
		("&Harl::debug", etc.) immediately upon creating the array.
	-	TYPE COMPATIBILITY: The syntax "void (Harl::*complaints[])(void)"
		correctly tells the C++98 compiler that "complaints" is an array
		of pointers to functions that belong to the "Harl" scope, return
		"void", and take no arguments.

-	Important not on "where" to declare it:
	
	While the syntax is correct, WHERE you put this line in your code matters
	for C++98 compliance and the rules of this specific exercise:
	
	1.	INSIDE THE "complain" FUNCTION:
		This is the most common approach. Every time "complain" is called, 
		the array is created on the stack.
	
	2.	USING THE "static" KEYWORD: 
		If you write "static void (Harl::*complaints[])(void) = ..." inside your
		"complain" function, the array is initialized only ONCE when the program
		starts. This is more efficient and perfectly valid in C++98.
	
	3.	NOT IN THE CLASS DECLARATION:
		You cannot initialize an array like this directly inside the class definition
		in the ".hpp" file in C++98.

-	When you use this array later in your loop, make sure to use the C++98
	pointer-to-member operator:

	(this->*complaints[i])();

	The parentheses around "this->*complaints[i]" are MANDATORY because the function
	call operator "()" has higher precedence than the pointer-to-member operator "->*".