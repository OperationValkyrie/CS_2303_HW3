/**
 * Jonathan Chang
 * CS 2303 C01 18
 * Assignment 3
 * ctext.c
 */

#include <stdio.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 * @author Jonathan Chang
 */

const int MAX_CHARS = 20; // Maximum number of characters in array

int main()
{
	char a1[MAX_CHARS + 1]; // Character array--initially empty
	char a2[] = "Hello"; // Character array--unsized but initialized
	char a3[MAX_CHARS + 1]; // Character array--we will underfill it
	char* p1 = "Hello"; // Pointer to constant string
	char* p2 = NULL;           // Will be a pointer to dynamically-allocated string
	char* p3 = "Hi"; // Pointer to another constant string
	// int copy_limit;     // Maximum characters to copy.

	strcpy(a3, "Hello, one more time."); // Initialize underfilled character array

	/* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
	 */
	printf("Initial state:\n");
	printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
	printf("          p1 = %p p2 = %p\n", p1, p2);

	strcpy(a1, p3); // Initialize character array

	printf("a1 = %s\n", a1);
	printf("a2 = %s\n", a2);
	printf("a3 = %s\n", a3);

	printf("\n");

	printf("Initial state:\n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	printf("  Pointer a3 = %p, Contents = %s\n", a3, a3);
	printf("  Pointer p1 = %p, Contents = %s\n", p1, p1);
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);


	printf("\n");
	printf("Section A Part 2\n");
	printf("\n");


	// Section A Part 2
	// Tesing for strlen1(), strlen()
	// Note that strlen() returns size_t, which is typedef'd to
	//   unsigned long, so we need to print it with %ld instead of just %d.
	printf("For string /%s/, strlen() returns %ld\n", a1, strlen(a1));

	printf("For string /%s/, strlen1() returns %ld\n", a2, strlen1(a2));

	printf("For string /%s/, strlen2() returns %ld\n", a3, strlen2(a3));

	printf("\n");

	// Section A Part 2
	// Testing for strdup1() and strdup2
	// Duplicate a string, using strdup(), then print
	printf("Before calling strdup()\n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);
	p2 = strdup(a1);
	printf("  Duplicated string: \n");
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);

	// Duplicate a string, using mystrup1(), then print
	printf("Before calling strdup1()\n");
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	p2 = mystrdup1(a2);
	printf("  Duplicated string: \n");
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);

	// Duplicate a string, using mystrdup2(), then print
	printf("Before calling strdup2()\n");
	printf("  Pointer a3 = %p, Contents = %s\n", a3, a3);
	p2 = mystrdup2(a3);
	printf("  Duplicated string: \n");
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);


	printf("\n");
	printf("Section A Part 3\n");
	printf("\n");


	// Section A Part 3
	// Testing for strcopy1()
	// Copy a string, using strcpy(), then print
	printf("Before calling strcpy()\n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);
	p2 = strcpy(p2, a1);
	printf("  Copied String: \n");
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);

	// Copy a string, using strcpy1(), then print
	printf("Before calling strcpy1()\n");
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	p2 = strcpy1(p2, a2);
	printf("  Copied String: \n");
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);

	// Reset Arrays
	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';
	strcpy(a1, p3); // Reset character array


	printf("\n");
	printf("Section A Part 4\n");
	printf("\n");


	// Section A Part 4
	// Testing for strcat1(), strncat1()
	// Concatenate two character arrays,using strcat(), then print.
	printf("Before calling strcat()\n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	p2 = strcat(a1, a2);
	printf("  Concatenated String: \n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);

	// Reset Arrays
	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';
	strcpy(a1, p3); // Reset character array
	printf("  Reset Arrays\n");

	// Concatenate two character arrays,using strcat1(), then print.
	printf("\nBefore calling strcat1()\n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	p2 = strcat1(a1, a2);
	printf("  Concatenated String: \n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);

	// Reset Arrays
	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';
	strcpy(a1, p3); // Reset character array
	printf("  Reset Arrays\n");

	// Concatenate two character arrays,using strncat1(), then print.
	printf("Before calling strncat1() with n = 4\n");
	printf("  Testing if n < length of string\n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	p2 = strncat1(a1, a2, 4);
	printf("  Concatenated String: \n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);

	// Reset Arrays
	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';
	strcpy(a1, p3); // Reset character array
	printf("  Reset Arrays\n");

	// Concatenate two character arrays,using strncat1(), then print.
	printf("Before calling strncat1() with n = 5\n");
	printf("  Testing if n = length of string\n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	p2 = strncat1(a1, a2, 5);
	printf("  Concatenated String: \n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);

	// Reset Arrays
	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';
	strcpy(a1, p3); // Reset character array
	printf("  Reset Arrays\n");

	// Concatenate two character arrays,using strncat1(), then print.
	printf("Before calling strncat1() with n = 7\n");
	printf("  Testing if n > length of string\n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	p2 = strncat1(a1, a2, 7);
	printf("  Concatenated String: \n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);

	// Reset Arrays
	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';
	strcpy(a1, p3); // Reset character array
	printf("  Reset Arrays\n");


	printf("\n");
	printf("Section A Part 5\n");
	printf("\n");


	// Section A Part 5
	// Testing for strncpy1(), strndup1()
	printf("Before calling strncpy() with n = 1()\n");
	printf("  Pointer a1 = %p, Contents = %s\n", a1, a1);
	p2 = strncpy(p2, a1, 1);
	printf("  Copied String: \n");
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);

	// Copy a string, using strcpy1(), then print
	printf("\nBefore calling strncpy1 with n = 4()\n");
	printf("  Testing if n < length of string\n");
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	p2 = strncpy1(p2, a2, 4);
	printf("  Copied String: \n");
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);
	printf("  String is wrong since string is not null-terminated\n");

	// Copy a string, using strcpy1(), then print
	printf("Before calling strncpy1 with n = 5()\n");
	printf("  Testing if n = length of string\n");
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	p2 = strncpy1(p2, a2, 5);
	printf("  Copied String: \n");
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);
	printf("  String is wrong since string is not null-terminated\n");

	// Copy a string, using strcpy1(), then print
	printf("Before calling strncpy1 with n = 6()\n");
	printf("  Testing if n > length of string\n");
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	p2 = strncpy1(p2, a2, 6);
	printf("  Copied String: \n");
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);

	// Copy a string, using strndup1(), then print
	printf("\nBefore calling strndup1 with n = 4()\n");
	printf("  Testing if n < length of string\n");
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	p2 = strndup1(a2, 4);
	printf("  Copied String: \n");
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);
	printf("  String is wrong since string is not null-terminated\n");

	// Copy a string, using strdnup1(), then print
	printf("Before calling strndup1 with n = 5()\n");
	printf("  Testing if n = length of string\n");
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	p2 = strndup1(a2, 5);
	printf("  Copied String: \n");
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);
	printf("  String is wrong since string is not null-terminated\n");

	// Copy a string, using strdup1(), then print
	printf("Before calling strndup1 with n = 6()\n");
	printf("  Testing if n > length of string\n");
	printf("  Pointer a2 = %p, Contents = %s\n", a2, a2);
	p2 = strndup1(a2, 6);
	printf("  Copied String: \n");
	printf("  Pointer p2 = %p, Contents = %s\n", p2, p2);


	return 0;
}
