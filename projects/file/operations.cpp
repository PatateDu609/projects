#ifndef OPERATIONS_CPP
#define OPERATIONS_CPP

#include "file.h"

bool	File::open(mode_t mode)
{
	if (!_path)
		return (false);
	_fd = ::open(_path, _mode);
	if (errno == 2)
		_fd = ::open(_path, _mode | O_CREAT, mode);
	if (_fd == -1)
	{
		std::cout << "Error no " << errno << ": " << strerror(errno) << std::endl;
		return (false);
	}
	return (true);
}

bool	File::close()
{
	if (::close(_fd) == -1)
	{
		std::cout << "Error no " << errno << ": " << strerror(errno) << std::endl;
		return (false);
	}
	_fd = -1;
	return (true);
}

#endif