/**
 * Jonathan Chang
 * CS 2303 C01 18
 * Assignment 3
 * mystruct.c
 */
/** mystruct.c
 * @author Mike Ciaraldi
 * @author Jonathan Chang
*/


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mystruct.h"

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the emploee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 *
 * If unable to allocate memory, will return NULL pointer
 */
employee* makeEmployee(int birth, int start, const char *name) {
	employee* emp = malloc(sizeof(employee)); // Allocate memory for struct

	// Test if unable to allocate memory
	if(!emp) {
		// If unable to allocate memory
		return NULL;
	}

	strcpy(emp->name, name);

	emp->birth_year = birth;
	emp->start_year = start;

	return emp;
}

/**
 * Prints out the given Employee
 * @param e The pointer to the employee to print
 * @return void
 */
void printEmployee(employee *e) {
	printf("%20s: %4d -> %4d\n", e->name, e->birth_year, e->start_year);
}

/**
 * Creates a random employee
 * @return The randomly created employee
 */
employee* generateEmployee() {
	int birth_year = getRandomYear();
	int start_year = getRandomYear();
	char* name = getRandomString();

	return makeEmployee(birth_year, start_year, name);
}

/**
 * Creates a random year between 0 and 2000
 * @return The random year
 */
int getRandomYear() {
	return rand() % 2000;
}

/**
 * Creates a random string of max length of 20
 * @return The random string
 */
char* getRandomString() {
	int length = 5 + (rand() & 15);
	char* str = malloc(sizeof(char) * length);

	// Pre-conditions: string not created
	for(int i = 0; i < length; i++) {
		// Loop Invariant: 0 < i < length
		str[i] = getRandomCharacter();
	}
	// Post-conditions: string is created
	str[length] = '\0';
	return str;
}

/**
 * Creates a random printable character (32 - 126)
 * @return The random character
 */
char getRandomCharacter() {
	int ascii = 32 + rand() % (126 - 32);
	return (char) ascii;
}

/**
 * Creates a array of the given length of randomized employees
 * @param count The number of random employees to generate
 * @return The array of the randomized employees
 */
employee** generateEmployees(int count) {
	employee** emps = malloc(sizeof(employee*) * count);
	// Pre-conditions: no employees generated yet
	for(int i = 0; i < count; i++) {
		// Loop Invariant: 0 < i < count
		emps[i] = generateEmployee();
	}
	// Post-conditions: all employees generated
	return emps;
}

/**
 * Prints out the given array of employees
 * @param emps The array of employees
 * @param count The number of employees in the array
 */
void printEmployees(employee** emps, int count) {
	// Pre-conditions: no employees printed
	for(int i = 0; i < count; i++) {
		// Loop Invariant: 0 < i < count
		printEmployee(emps[i]);
	}
	// Post-conditions: all employees printed
}

/**
 * Creates a shallow copy of the array of employees
 * @param emps The array of employees to copy
 * @param count The number of employees in the array
 * @param A shallow copy of the array of employees
 */
employee** createShallowEmployees(employee** emps, int count) {
	employee** empsShallow = malloc((sizeof(employee*) * count));
	// Pre-conditions: no employees shallowed copied
	for(int i = 0; i < count; i++) {
		// Loop Invariant: 0 < i < count
		empsShallow[i] = emps[i];
	}
	// Pre-conditios: all employees shallowed copied
	return empsShallow;
}

/**
 * Frees up the given employee array
 * @param emps The employee array to free
 * @param count The number of employees in the array
 */
void freeEmployees(employee** emps, int count) {
	// Pre-conditions: no employees freed
	for(int i = 0; i < count; i++) {
		// Loop Invariant: 0 < i < count
		free(emps[i]);
	}
	free(emps);
	// All employees freed
}

/**
 * Creates a deep copy of the given employee array
 * @param emps The employee arrays to copy
 * @param count The number of employees in the array
 * @return The deep copy of the array
 */
employee** createDeepEmployees(employee** emps, int count) {
	employee** empsDeep = malloc(sizeof(employee*) * count);
	// Pre-conditions: no deep employees created
	for(int i = 0; i < count; i++) {
		// Loop Invariant: 0 < i < count
		empsDeep[i] = makeEmployee(emps[i]->birth_year,
						emps[i]->start_year, emps[i]->name);
	}
	// Post-condiitons: all deep employees created
	return empsDeep;
}
