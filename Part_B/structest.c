/**
 * Jonathan Chang
 * CS 2303 C01 18
 * Assignment 3
 * structest.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {
	srand(time(0));
	employee *e1, *e2, *e3;

	e1 = makeEmployee(1952, 1999, "Mike Ciaraldi");
	e2 = makeEmployee(1989, 2015, "Annette Durand");
	e3 = generateEmployee();

	printf("Section B Part 2 and Part 3\n");
	printf("\n");


	// Section B Part 2 and Part 3
	// Testing for makeEmployee() and generateEmployee()
	printf("Print out employees and single generated employee\n");
	printEmployee(e1);
	printEmployee(e2);
	printEmployee(e3);
	printf("\n");


	printf("\n");
	printf("Section B Part 4 and Part 5\n");
	printf("\n");


	// Section B Part 4 and 5
	// Testing for generateEmployees(), createShallowEmployees()
	printf("Print out 5 randomly generated employees\n");
	employee** emps = generateEmployees(5);
	printEmployees(emps, 5);
	employee** empsShallow = createShallowEmployees(emps, 5);
	printf("  Created shallow copy\n");
	emps[1]->start_year = 500;
	printf("\n  Changed start year of second employee to 500\n");
	printf("\n  Original Array:\n");
	printEmployees(emps, 5);
	printf("\n  Shallow Copy:\n");
	printEmployees(empsShallow, 5);


	printf("\n");
	printf("Section B Part 4 and Part 5\n");
	printf("\n");


	// Section B Part 6 and Part 7
	// Testing for freeEmployees()
	printf("Create deep copy of employees\n");
	employee** empsDeep = createDeepEmployees(emps, 5);
	printf("\n  Changed start year of first employee to 1000\n");
	emps[0]-> start_year = 1000;
	printf("\n  Original Array:\n");
	printEmployees(emps, 5);
	printf("\n  Deep Copy:\n");
	printEmployees(empsDeep, 5);
	printf("\n  Freeing all arrays");
	freeEmployees(empsDeep, 5);
	freeEmployees(empsShallow, 5);
	freeEmployees(emps, 5);
	printf("\n  All employees freed.\n");
	return 0;
}
