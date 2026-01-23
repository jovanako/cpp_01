--- zombieHorde() ---

This function should:
	1. Allocate N Zombie objects in one single allocation
	2. Give each Zombie the same name
	3. Return a pointer to the first Zombie
	4. Allow the caller to later call announce() on each Zombie
	5. Be properly cleaned up with delete[]

	"Single allocation" - what this really means 
						(the most important concept of the exercise)
	Zombie* horde = new Zombie[N];
	This:	-	Allocates one block of memory
			-	Holds N Zombies contiguously
			-	Must be freed using: delete[] horde;
	
	Initializing each Zombie:
	- After allocating the array, the Zombies exist but may not have names yet
	- You must loop through them and use setName()
	- Why?	->	Constructors with parameters cannot be easily used with 'new'
			->	So you create them first, then assign values
	
	Returning the pointer:
	- When you return 'return horde;' you are returning:
			->	A pointer to the first Zombie
			->	The caller can access others using indexing: 
							horde[0], horde[1], horde[2]...

--- main.cpp ---

main.cpp should prove that:	- all Zombies exist
							- all Zombies have the correct name
							- announce() works for each one
	
	- Test 1 verifies:	(1) Multiple Zombies
						(2) Correct name assignment
						(3) Loop access

	- Test 2 verifies:	(1) Works with smallest valid size
						(2) No array logic bugs
	
	- Test 3 verifies:	(1) No shared state
						(2) Separate allocations

	- Test 4 verifies:	(1) No crash
						(2) Proper cleanup

	- Test 5 verifies:	(1) Performance
						(2) No segmentation faults
						(3) Proper loop logic