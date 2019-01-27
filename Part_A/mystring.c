/**
 * Jonathan Chang
 * CS 2303 C01 18
 * Assignment 3
 * mystring.c
 */
/** mystring.c
 * @author Mike Ciaraldi
 * @author Jonathan Chang
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/**
 * Duplicates a C-style string.
 * @param src Pointer to string to be copied
 * @return Pointer to freshly-allocated string containing a duplicate of src
 *       or null if no memory is available
*/
char* mystrdup1(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = strlen1(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/**
 * Duplicates a C-style string.
 * @param src Pointer to string to be copied
 * @return Pointer to freshly-allocated string containing a duplicate of src
 *       or null if no memory is available
*/
char* mystrdup2(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = strlen2(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/**
 * Calculates the length of the given C-style string
 * @param str A pointer to the constant array to count the length of
 * @return The length of the string
 *
 * C-style string must be null-terminated
 * 		Will count unallocated space - Throws Segmentation Fault
 */
size_t strlen1(const char *str) {
	size_t length = 0; // Holds the counter for the length
	// Pre-condition: str has not been counted yet
	while(str[length] != '\0') {
		// Loop Invariant: str is within the original string
		length++;
	}
	// Post-conditions: The length of src has been counted
	return length;
}

/**
 * Calculates the length of the given C-style string
 * @param str The character array to count the length of
 * @return The length of the string
 *
 * C-style string must be null-terminated
 * 		Will count unallocated space - Throws Segmentation Fault
 */
size_t strlen2(const char *str) {
	size_t length = 0; // Holds the counter for the length
	// Pre-condition: str has not been counted yet
	while(str[0] != '\0') {
		// Loop Invariant: str is within the original string
		str++;
		length++;
	}
	// Post-conditions: The length of src has been counted
	return length;
}

/**
 * Copies over a string from a given C-style string to a given C-style string
 * @param dest The destination C-style string to copy to
 * @param src The C-style string to copy from
 * @return A pointer to the destination source
 *
 * C-style string at source must null-terminated
 * 		Will count unallocated space - Throws Segmentation Fault
 * C-style string at destination must be large enough to fit the source string
 * 		Will overwrite unallocated space - Throws Segmentation Fault
 */
char* strcpy1(char* dest, const char* src) {
	char *destpointer = dest; // Holds pointer to destination to return
	// Pre-conditions: src has not been copied over to dest
	while(src[0] != '\0') {
		// Loop Invariant: src is within the source string
		dest[0] = src[0];
		dest++;
		src++;
	}
	// Post conditions: src has been copied over to dest
	dest[0] = '\0';
	return destpointer;
}

/**
 * Appends the C-style string from the given C-style string to the end
 * 		of the given C-style string
 * @param dest The C-style string to append to the end of
 * @param src The C-style string to append to the end of dest
 * @return A pointer to the beginning of dest with src appended over
 *
 * C-style strings in src and dest must null-terminate
 * 		Will read into unallocated space - Throws Segmentation Fault
 * C-style string in dest must been large enough
 * 		Will overwrite unallocated space - Throws Segmentation Fault
 */
char* strcat1(char* dest, const char* src) {
	char* destpointer = dest; // Holds the pointer to the original destination
	// Pre-conditions: dest points to beginning of the C-style string
	while(dest[0] != '\0') {
		// Loop Invariant: dest is within the original string
		dest++;
	}
	// Post-conditions: dest points the null-terminator of the original string
	// Pre-condtiions: dest points to the null-terminator of the destination
	//		string, src points to beginning of its C-style string
	while(src[0] != '\0') {
		// Loop Invariant: src is within the original string
		dest[0] = src[0];
		dest++;
		src++;
	}
	// Post-conditions: src appended to the end of dest
	dest[0] = '\0';
	return destpointer;
}

/**
 * Appends the C-style string from the given C-style string to the end of the
 * 		given C-style string up to the given number of characters
 * @param dest The string to append to the end of
 * @param src The string to append to the end of dest
 * @param n The maximum number of characters to append
 * @return A pointer to the beginning of dest with src appended
 *
 * C-style strings in dest and src must nul-terminate
 * 		Will read into unallocated space - Throws Segmentation Fault
 * C-style string in dest must be large enough
 * 		Will overwrite unallocated space - Throws Segmentation Fault
 *
 * If the length of src is < n
 * 		Then the array is padded with null-terminates
 * If the length of src is >= n
 * 		Then only n characters will be copied over
 * 		Will null-terminate the (n+1)th character
 */
char* strncat1(char* dest, const char* src, size_t n) {
	char* destpointer = dest; // Holds the pointer to the original destination
	// Pre-conditions: dest points to the beginning of the origiinal string
	while(dest[0] != '\0') {
		// Loop-Invariant: dest is within the original string
		dest++;
	}
	// Post-conditions: dest is pointing to the null-terminator
	int counter = 0; // Holds the number of characters copied
	int flag = 0; // If the src string has ended
	// Pre-conditions: No characters copied over yet
	while(counter < n) {
		// Loop Invariant: counter < n && src is within the original string
		// Test if src string has ended
		if(flag) {
			// If src string has ended
			dest[0] = '\0';
		} else {
			// If still more of src to copy
			dest[0] = src[0];
			src++;
			// Test if src string will ended
			if(src[0] == '\0') {\
				// If src string will ended
				flag = 1;
			}
		}
		dest++;
		counter++;
	}
	// Post-conditions: n characters copied over
	dest[0] = '\0';
	return destpointer;
}

/**
 * Copies over a string from a given C-style sting to a given C-style string
 * 		Copies a maximum of n characters
 * @param dest The destination string to copy to
 * @param src The sources tring to copy from
 * @param n The maxmimum of characters to copy
 * @return The pointer to the beginning of dest with src copied over
 *
 * C-style string in src must null-terminate
 * 		Will read into unallocated space - Throws Segmentation Fault
 * Length of C-style string src must be less than n
 * 		Will copy over but will not null-terminate - Throws Segmentation Fault
 *
 * If the length of src is < n
 * 		The arays is padded with null-terminates
 * If the length of src is >= n
 * 		Then only n characters will be copied over
 * 		Does not null-terminate
 */
char* strncpy1(char* dest, const char* src, size_t n) {
	char* destpointer = dest; // Holds a pointer to the beginning of dest
	int counter = 0; // Holds the number of characters copied
	int flag  = 0; // Holds if src string has ended
	// Pre-condition: No characters copied over
	while(counter < n) {
		// Loop Invariant: counter < n && src is within the original string
		// Tests if src string has ended
		if(flag) {
			// If src string has ended
			dest[0] = '\0';
		} else {
			// If src string still has characters
			dest[0] = src[0];
			src++;
			// Test if src string will end
			if(src[0] == '\0') {
				// if src string will end
				flag = 1;
			}
		}
		dest++;
		counter++;
	}
	return destpointer;
}

/**
 * Duplicates a C-style string up to the given amount of characters
 * @param src The string to copy
 * @return A pointer to the duplicated string, null if errors
 *
 * If length of src is > n
 * 		Only n characters will be copied
 * 		Will be null-terminated
 * If length of src is <= n
 * 		Will be padded with null-terminates
 */
char* strndup1(const char* src, size_t n) {
	  int length; // Length to copy over or allocate
	  char* newstr; // Pointer to memory which will hold new string

	  length = n + 1;  // Leave space for the terminator
	  newstr = (char*) malloc(length); // Must cast!

	  // If no memory was available, return null pointer immediately
	  if (newstr == 0) return (char *) 0;

	  // Otherwise, copy the string and return pointer to new string
	  strncpy1(newstr, src, n);
	  return newstr;
}
