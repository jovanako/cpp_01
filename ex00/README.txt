----- ZOMBIE.HPP -----

					- This file declares the class.

						- private	-> data is hidden - 'name' is stored privately as a std::string
						- public	-> interface exposed to users
						- Functions are declared, not implemented
						- announce()	-> confirms that the Zombie was created correctly
										-> shows which Zombie is speaking
						- destructor	-> prints a message with a zombie's name
										-> shows when a zombie is destroyed
										-> shows where it is destroyed (end of scope vs manual deletion)

*** Why should the name variable be private?
	- it enforces ENCAPSULATION	-> the object controls its own data
								-> only the zombie class itself can access or modify it
								-> other code must go through public functions
		name is private to	-> protect the internal state of the object
							-> control how the name is accessed or changed
							-> enforce good object-oriented design habits
							-> OUTSIDE CODE SHOULD NOT FREELY MODIFY A ZOMBIE'S NAME

Rule of thumb:	all DATA MEMBERS should be PRIVATE unless you have a very good reason
				PUBLIC: functions (behavior)

----- ZOMBIE.CPP -----

					1. The constructor definition for the Zombie class

						Zombie::Zombie		-> scope resolution operator - tells the compiler this is the 'Zombie' class's constructor
						(std::string name)	-> constructor parameter - the caller must pass a string (e.g., "Brian") when creating a 'Zombie'
						: name(name)		-> member initializer list	- initializes the private member variable 'name' with the parameter 'name'
																		- tells C++: before running the constructor body: 
																			initialize these member variables with these values
						std::cout			-> standard output stream
						std::endl			-> ends the line with newline and flushes the output buffer
						
						Why we write here: helps debug the object lifetime and shows exactly when the constructor runs

					2. The destructor definition for the Zombie class

						-	It runs automatically when a Zombie object is destroyed
						-	Important points in C++98:	-	Called automatically for stack objects when they go out of scope
														-	Called manually for heap objects when you 'delete' them
						
						Why we write here: lets you see object lifetimes and helps distinguish stack vs heap objects in debugging

					3. A member function of the Zombie class

						Zombie::announce	-> scope resolution, this function belongs to Zombie


----- NEWZOMBIE.CPP -----

					This function creates a zombie, names it, and returns it so you can use it outside of the function scope
						- The function must return a pointer
						- The zombie must survive after the function ends -> must be allocated on the heap
						- The caller is responsible for deleting the zombie later to avoid memory leaks

						Zombie* z = new Zombie(name);	-> heap allocation
						
						- 'new' allocates Zombie on heap (dynamically)
						- initialization:	- you need to pass the name to the constructor when creating it
											- this ensures the member variable 'name' is set correctly
						- after creating the heap object, we return it, which lets the caller of newZombie use the zombie later
						- important: any object created with 'new' must eventually be destroyed with 'delete' to avoid a memory leak
						
						Memory:	- Heap	-> Zombie object lives here
								- Stack	-> pointer z point to it


----- RANDOMCHUMP.CPP -----

					This function creates a zombie, names it, and makes it announce itself immediately
						- the function does not return anything
						- the zombie only needs to exist inside the function
						- the zombie should announce itself before the function ends
						- after the function ends, the zombie is automatically destroyed

						- this zombie does not need to survive outside the function, 
							which means you can create it as a local variable on the stack
						
					Zombie z(name);	-> stack allocation
						
						- no 'new' is needed - the compiler automatically calls the destructor when the function ends


----- MAIN.CPP -----

					main.cpp should:		- test a heap zombie (from newZombie)
											- test a stack zombie (from randomChump)
											- show destructor timing to understand lifetime
					- Test 1: Heap allocation	->	create a zombie using newZombie
													->	call announce()
													->	delete it manually
													->	observe constructor and destructor messages
														(constructor message appears immediately after newZombie, 
															destructor message only after 'delete')
						
					- Test 2: Stack allocation	->	call randomChump with a name
													->	the zombie announces itself inside the function
													->	destructor runs automatically at the end of the function
						
					- Test 3: Multiple zombies	->	create multiple zombies with both methods
													->	observe order of destructor calls
