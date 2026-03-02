--- std::stringstream buffer; ---

-	Think of std::stringstream as a temporary holding tank (a buffer) in your
	program's memory. It allows you to treat a regular std::string exactly 
	like you would an input/output stream (like std::cin, std::cout, or a 
	file stream).

-	Three most common use cases:
	
	(1)	Reading an entire file into a string
		When you open a file with std::ifstream, reading it line-by-line using
		std::getline can be tedious if you just want to grab all the text at once.
		std::stringstream makes this incredibly easy using the file stream's buffer
		(rdbuf()).
	
	(2)	Extracting data (parsing strings)
		If you have a string with formatted data (like "User 42 99.5"), you can
		use stringstream to extract that data into the correct variable types,
		exactly like you would use std::cin.

				std::string data = "John 42 99.5";
				std::stringstream ss(data); // Initialize the stream with the string

				std::string name;
				int age;
				float score;

				// Extract the data into variables
				ss >> name >> age >> score;

				std::cout << "Name: " << name << ", Age: " << age << std::endl;
	
	(3) Building strings (formatting)
		You can also use it in reverse. If you have various data types and want to 
		stitch them together into a single string (similar to sprintf in C), you 
		push them into the stream using <<.

				int score = 100;
				std::string player = "Alice";

				std::stringstream ss;

				// Build the string piece by piece
				ss << "Player " << player << " scored " << score << " points.";

				// Get the final string
				std::string finalString = ss.str();

				std::cout << finalString << std::endl;

(1) Automatic memory management
	
	In C++, standard library classes like std::stringstream (and std::string,
	std::vector, etc.) manage their own memory under the hood.

	When you declare std::stringstream buffer;, the C++ compiler creates the
	object on the stack. Inside that object is a pointer to a chunk of memory
	on the heap.

(2) It grows automatically

	When you pipe the file contents into the buffer 
	(buffer << inputFile.rdbuf();),
	the stringstream looks at the size of the incoming data. If its current
	internal memory block isn't big enough, it automatically calls the
	equivalent of realloc() behind the scenes, asks the OS for more memory,
	and copies the data in. You don't have to calculate sizes or worry about
	buffer overflows.

(3) It cleans up after itself

	Just as you dont' use malloc, you also don't use free.
	When the buffer variable goes out of scope (for example, when your main
	function hits return 0;), C++ automatically calls a special function
	called a destructor. The stringstream destructor looks at the heap memory
	it allocated, frees it, and cleanly destroys the object. No leaks!

--- In C++, you let the objects do the heavy lifting. You just declare the
	object,	use it, and let it clean itself up when it's done. ---

--- main.cpp ---

line:	Replacer replacer(argv[1], argv[2], argv[3]);
	->	The C++ compiler does the following:
		1. It sees argv[1] is a char *
		2. It looks at your Replacer constructor and sees it requires
			a std::string
		3. It realizes that std::string knows how to build itself
			from a char *
		4. It automatically calls the std::string constructor, creates
			a temporary string object using the text from argv[1], and
			passes that fully-formed std::string into your Replacer class
	
	-> You could also write:
		Replacer replacer(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]);)
