#ifndef FILE_H
#define FILE_H

#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

enum Mode
{
	IO = O_RDWR,
	O = O_WRONLY,
	I = O_RDONLY
};

enum WRMode
{	
	LINE,
	CHARACTER,
	SEPARATOR
};

class File
{
public:
	// defined in file.cpp
							File();
							File(char *path, Mode mode = IO);
							File(const File& other);
							File(Mode mode);

	// defined in operations.cpp
	bool					open(mode_t mode = 0644);
	bool					close();
	bool					seek();
	bool					copy(const File& other);
	char					read();

	// defined in access.cpp
	char					*getline();
	char					*getfile();
	int						size(WRMode mode);
	char					*path();

	int						setpath(char *path);
	int						setmode(Mode mode);
	int						setmode(WRMode mode);
	void					setsep(char *sep);

	// defined in operators.cpp
	friend std::ostream&	operator<<(std::ostream& os, const char* src);
	friend std::istream&	operator>>(std::istream& is, const char* dest);
	File&					operator=(const File& other);

private:
	Mode		_mode;
	WRMode		_read;
	int			_fd;
	char		*_path;
	char		*_sep;

	void __init__(Mode mode, WRMode read, int fd, char *path, char *sep);
};

#endif