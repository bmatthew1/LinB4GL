#include "FilenameRoutines.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void PrepPathForComp (char *string) {

	// Prepare file path for comparison by converting to lowercase, and swapping '/' with '\'
	for (char *ptr = string; *ptr != 0; ptr++)
		if (*ptr >= 'A' && *ptr <= 'Z')
			*ptr = *ptr - 'A' + 'a';
		else if (*ptr == '/')
			*ptr = '\\';
}
std::string ProcessPath (std::string filename) {

	// Find full pathname
	char fullPath[1024];
	char *fileBit;
	int r = GetFullPathName (filename.c_str (), 1024, fullPath, &fileBit);
	if (r == 0 || r > 1024)
		return filename;
	PrepPathForComp (fullPath);

	// Find current directory, convert to lowercase
	char currentDir[1024];
	r = GetCurrentDirectory (1024, currentDir);
	if (r == 0 || r > 1024)
		return (std::string) fullPath;
	PrepPathForComp (currentDir);
	int curDirLen = strlen (currentDir);
	if (currentDir [curDirLen - 1] != '\\') {
		currentDir [curDirLen] = '\\';
		currentDir [curDirLen + 1] = 0;
	}

	// Compare strings for matching directories
	bool relative = false, matches = true;
	int offset = 0;
	while (matches) {
		char	*p1 = strchr (fullPath + offset, '\\'),
				*p2 = strchr (currentDir + offset, '\\');
		matches =	p1 != NULL && p2 != NULL														// Found dir separators
				&&	p1 - (fullPath + offset) == p2 - (currentDir + offset)							// Same # of characters
				&&	memcmp (fullPath + offset, currentDir + offset, p1 - (fullPath + offset)) == 0;	// Directories match
		if (matches) {
			relative = true;
			offset = p1 - fullPath + 1;
		}
	}

	if (!relative)
		return (std::string) fullPath;
	else {
		std::string result = "";
		
		// Look for remaining directories in currentDir that didn't match 
		// For each of these, we need to back out one directory.
		char *cursor = currentDir + offset;
		char *p;
		while ((p = strchr (cursor, '\\')) != NULL) {
			result += "..\\";
			cursor = p + 1;
		}
		
		// Append remaining bit of full path
		result += (fullPath + offset);

		return result;
	}
}

