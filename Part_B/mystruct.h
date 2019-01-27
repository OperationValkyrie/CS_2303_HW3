/**
 * Jonathan Chang
 * CS 2303 C01 18
 * Assignment 3
 * mystruct.h
 */
/** mystruct.h
 * @author Mike Ciaraldi
 * Sample structs
 * @author Jonathan Chang
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
};

typedef struct Employee employee;

// Function prototype(s):
employee *makeEmployee(int birth, int start, const char* name);
void printEmployee(employee *e);
employee* generateEmployee();
int getRandomYear();
char* getRandomString();
char getRandomCharacter();
employee** generateEmployees(int count);
void printEmployees(employee** emps, int count);
employee** createShallowEmployees(employee** emps, int count);
void freeEmployees(employee** emps, int count);
employee** createDeepEmployees(employee** emps, int count);
