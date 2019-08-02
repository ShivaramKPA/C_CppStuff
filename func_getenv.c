/*
  C library function - getenv()
=================================
  Description

  The C library function char *getenv(const char *name) searches for the environment string pointed to by name and returns the associated value to the string.
  Declaration

  Following is the declaration for getenv() function.

  char *getenv(const char *name)

  Parameters

  name − This is the C string containing the name of the requested variable.

  Return Value

  This function returns a null-terminated string with the value of the requested environment variable, or NULL if that environment variable does not exist.
  Example

  The following example shows the usage of getenv() function.
 */
#include <stdio.h>
#include <stdlib.h>

int main () {
  printf("PATH : %s\n", getenv("PATH"));
  printf("HOME : %s\n", getenv("HOME"));
  printf("ROOT : %s\n", getenv("ROOT"));

  return(0);
}

/*
  Let us compile and run the above program that will produce the following result −

  PATH : /sbin:/usr/sbin:/bin:/usr/bin:/usr/local/bin
  HOME : /
  ROOT : (null)

 */
