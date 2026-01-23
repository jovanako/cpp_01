This exercise focuses on:
	(1) Encapsulation (private members + getters/setters)
	(2) References vs pointers
	(3) Object ownership vs object usage
	(4) When an object must exist vs may exist

The key concept:
	->	HumanA always has a weapon			-> use a reference
	->	HumanB may or may not have a weapon	-> use a pointer

The Weapon class acts as a shared object.

- getType(): const std::string& getType() const;

Why const reference?	->	avoids copying the string
						->	prevents modification of 'type' from outside
						->	guarantees safe read-only access

- setType()	->	allows changing the weapon after it has been given to a human

- Important: If you change the weapon's type, all humans using that weapon see the change,
				because they don't own copies - they reference the same object

- HumanA vs HumanB:	-> both have a name, a weapon and an attack() function

- HumanA is always armed	-> key rule: HumanA will always have a weapon
							-> this means:	- the weapon must exist at construction
											- it can never be null
											- it can never be changed to "no weapon"

							- Constructor: HumanA(std::string name, Weapon& weapon);

							Why a reference?	->	a reference must be initialized
												->	a reference cannot be null
												->	a reference cannot be reseated
							This enforces the rule that HumanA is always armed

- HumanB may be unarmed		->	HumanB may not always have a weapon
							->	this means:	- they can be created without a weapon
											- a weapon can be assigned later
											- they might attack while unarmed
							
							- Constructor: HumanB(std::string name);
							- Weapon starts at: weapon = null
							- Setter: void setWeapon(Weapon& weapon)
							- This allows arming the human later

							- attack() must handle both cases:	-> weapon exists
																-> weapon does not exist
							- Example:	if (weapon)
											Bob attacks with their club
										else
											Bob attacks with their bare hands

Reference vs Pointer:	(1) What they are:	-> Reference is an alias for an existing object
											-> another name for the same thing
											-> no separate identity, cannot exist without an object

											-> Pointer is a variable that stores an address
											-> a thing that points to something else
											-> has its own identity, can point to different objects or to nothing
						
						(2) Initialization:	-> Reference	- must be initialized at declaration
															- cannot be left uninitialized
															 int a = 5
															 int& r = a

											-> Pointer		- can be uninitialized (but unsafe)
															- can be NULL/nullptr
									
						(3) Rebinding / reseating	-> Reference (cannot be reseated):	int a = 1;
																						int b = 2;
																						int& r = a;
																						r = b; -> assigns b's value to a, NOT rebinding

																						after this:
																						a == 2
																						b == 2
																						-> r stil refers to a
																		
													-> Pointer (can be reseated):		int a = 1;
																						int b = 2;
																						int* p = &a;
																						p = &b; -> now points to b
																
						(4) Memory representation:	-> Reference	- usually implemented as a pointer internally
																	- but you cannot:	(1) change what it refers to
																						(2) access its address meaningfully
																	- conceptually not an object
														
													-> Pointer		- is a real object
																	- has its own address
																	- can be passed, copied, reassigned
						
						(5) When to use which:	- use a reference when	- the object must exist
																		- you do not want to change what it refers to
																		- you want safer, cleaner syntax

												- use a pointer when	- the object may not exist
																		- you need to change what it points to
																		- NULL is a valid state
						
						REFERENCES - must exist and never change
						POINTERS - may exist and may change

Why does Weapon constructor have type parameter?
	->	The constructor parameter enforces that every Weapon is valid from the moment it exists
			->	because a Weapon should never exist without a valid type
			->	the constructor forces the object to be fully initialized
			->	with the constructor parameter 'Weapon club("crude spiked club"),
				- the weapon is valid immediately
				- 'type' is set at creation
				- no invalid state is possible
	Why not set the type later? -> because the object exists in invalid state until setType() is called
								-> nothing forces the user to call it
	This practice is called enforcing a <class invariant>
	-> objects should be created in a valid state

Why it is important in this exercise:
	->	humans do not own weapons
	->	weapons must already exist
	->	humans only reference them

--- Important concept: <invariants> ---

An invariant is a condition that must ALWAYS be true for an object while it exists.

- Weapon invariant -
	What is a weapon?	- a weapon must have a type
						- a weapon with no type is meaningless
	
	Invariant for Weapon:
			Weapon::type is always a valid, non-empty string

- Constructors enforce invariants -
	-> The constructor's job is to establish the invariant
	That's why you:	-> initialize references in constructors
					-> validate parameters in constructors
					-> prevent invalid states early

	Invariants in HumanA and HumanB:
		-> HumanA always has a weapon:	-> Weapon& weapon; (cannot be NULL)
										-> HumanA(name, weapon);
		-> HumanB may or may not have a weapon:	-> Weapon* weapon; (can be NULL)

Golden rules of invariants:
		(1)	Constructors establish invariants
		(2) Public methods preserve invariants
		(3) Private members exist to protect invariants
		(4) Stronger invariants = simpler code
		(5) If an invariant can be broken, it will be

*** An invariant is the truth your class promises to always uphold
	- and good C++ design makes it impossible to break.


* HumanB constructor signature:
		HumanB(const std::string& name);
* HumanB constructor definition:
		HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {}
		
*** Inside the constructor definition, we initialize weapon to NULL
	because this is where we initialize member variables
	regardless of the fact whether they are also a constructor's parameter or not