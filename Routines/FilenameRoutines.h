/*  Created 20-May-2007: Thomas Mulgrew (tmulgrew@slingshot.co.nz)

    General purpose filename routines.
*/

#ifndef FilenameRoutinesH
#define FilenameRoutinesH

#include <string>

// Prepares a file path for comparison with another.
// Converts all characters to lowercase and exchanges any '/' symbols with '\'
void PrepPathForComp (char *string);

// Process a path (and filename) for string matching
// Returns the path relative to the current directory, cast to lowercase.
std::string ProcessPath (std::string filename); 

#endif
