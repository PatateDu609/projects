#ifndef FILE_CPP
#define FILE_CPP

#include "file.h"

void	File::__init__(Mode mode, WRMode read, int fd, char *path, char *sep)
{
	umask(0);
	_mode	= mode;
	_read	= read;
	_fd		= fd;
	_path	= path;
	_sep	= sep;
}


File::File()
{
	__init__(IO, CHARACTER, 0, NULL, NULL);
}


File::File(char *path, Mode mode)
{
	__init__(mode, CHARACTER, 0, path, NULL);
}

File::File(const File& other)
{
	__init__(other._mode, other._read, other._fd, other._path, other._sep);
}

File::File(Mode mode)
{
	__init__(mode, CHARACTER, 0, NULL, NULL);
}

#endif