--- What this exercise is testing ---
	-> command-line argument handling
	-> C++ file streams
	-> manual string manipulation
	-> edge-case handling
	-> clean, readable code
	-> following constraints precisely

--- THE GOAL ---
->	You are recreating a very simplified version of the Unix command:

sed -i 's/s1/s2/g' filename

->	Your program needs to read a file, find every instance of string s1,
	change it to string s2, and save the result in a new file named <filename>.replace

->	You must use the C++ standard library streams:	->	std::ifstream (Input File Stream) to read
													->	std::ofstream (Output File Stream) to write

(1) GOAL OF THE EXERCISE:
	-> write a C++ program that:	1. takes 3 command-line arguments: ./program filename s1 s2
									2. reads the contents of 'filename'
									3. creates a new file named: 'filename.replace'
									4. writes the file's content into a new file, but:
										- every occurence of 's1' is replaced by 's2'

(2) PROGRAM INPUTS(VERY IMPORTANT):
	-> Command-line arguments	- error cases to handle:	- wrong number of arguments (argc != 4)
															- file cannot be opened
															- empty 's1' (this is critical)

(3) FILE HANDLING RULES (STRICT):	X FORBIDDEN:	FILE*, fopen, fread, fwrite, fprintf, etc.
									REQUIRED:		use C++ file streams:
													->	std::ifstream (Input File Stream) for reading
													->	std::ofstream (Output File Stream) for writing

(4) STRING MANIPULATION RULES:	X FORBIDDEN:	std::string::replace
								ALLOWED:		all other std::string member functions:
												- find, substr, append, erase, insert, length, size, operator +, etc.

(5) EMPTY STRING EDGE CASES (VERY IMPORTANT):
		- If 's1' is empty	- detect that 's1' is empty
							- print an error or exit safely

7. How you’re expected to think about the solution

			(1)Read the file		- Either line by line (std::getline)
									- Or whole file into a string

			(2) Process the text	- Search for s1
									- Copy text into a result string
									- When s1 is found, append s2 instead
									- Move forward manually

			(3) Write the result	- Output to <filename>.replace

		You are essentially implementing your own string replacement algorithm.