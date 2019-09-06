#!/bin/sh

cd ~/projects

# Please use the f option carefully... It will erase your work...

# If the user wants to force the creation of a new directory having the name of an existing one, he needs to put f to force the overwriting of the ancient one
if [ $# -eq 3 ] && [ $3 = "f" ]; then
	rm -rf $2
fi
mkdir $2

# If mkdir succeeded then we can continue (it's for protecting the user in case he didn't want erase the directory and mkdir display an error)
if [ $? -eq 0 ]; then
	cd $2

	if [ $1 = "library" ] || [ $1 = "class" ]; then
		# Basic specialization of the Makefile
		cp ~/.scripts/Makefile_libs.template ./Makefile
		sed -Ei "s|NAME(\t*)= |NAME\1= $LD_LIBRARY_PATH/lib$2.so|" Makefile
		sed -Ei "s|LIBS(\t*)= |LIBS\1= -l$2|" Makefile

		if [ $1 = "class" ]; then
			# Modify the Makefile to complete the specialization
			sed -Ei "s/SRCS(\t*)= /SRCS\1= $2.cpp access.cpp operators.cpp operations.cpp/g" Makefile
			sed -Ei "s/INCLUDE(\t*)= /INCLUDE\1= $2.h/g" Makefile
			
			# Creating all the beginning files
			touch ./$2.cpp ./access.cpp ./operators.cpp ./operations.cpp ./$2.h ./main.cpp

			# Putting in them the basics

			# Protection of the .h
			echo -n "#ifndef " > $2.h
			echo "$(echo $2 | tr '[:lower:]' '[:upper:]')_H" >> $2.h
			
			echo -n "#define " >> $2.h
			echo "$(echo $2 | tr '[:lower:]' '[:upper:]')_H\n" >> $2.h
			
			# Filling the main header, with the base of the future class and all the necessary to make it fully compatible with the templates
			NAME=$(echo $2 | sed -E "s/([[:lower:]])/\U\1/")
			echo "class $NAME\n{\npublic:\n\nprivate:\n\n};\n" >> $2.h
			echo "#include \"access.cpp\"" >> $2.h
			echo "#include \"$2.cpp\"" >> $2.h
			echo "#include \"operations.cpp\"" >> $2.h
			echo -n "#include \"operators.cpp\"" >> $2.h

			# Protecting the main .cpp files (not the main.cpp, because this file should not be included anywhere). I did it to take care of the template issue with the definition...
			echo "#ifndef ACCESS_CPP" > access.cpp
			echo "#ifndef OPERATORS_CPP" > operators.cpp
			echo "#ifndef OPERATIONS_CPP" > operations.cpp
			echo "#ifndef $(echo $2 | tr '[:lower:]' '[:upper:]')_CPP" > $2.cpp

			echo "#define ACCESS_CPP\n" >> access.cpp
			echo "#define OPERATORS_CPP\n" >> operators.cpp
			echo "#define OPERATIONS_CPP\n" >> operations.cpp
			echo "#define $(echo $2 | tr '[:lower:]' '[:upper:]')_CPP\n" >> $2.cpp

			# Include the main header
			(echo "#include \"$2.h\"\n" | tee -a *cpp) > /dev/null

			# Ending the protection of each file
			(echo -n "\n\n#endif" | tee -a $2.h access.cpp $2.cpp operators.cpp operations.cpp) > /dev/null

			# The following line is taking care of the main function
			echo -n "int main(int ac, char **av)\n{\n\t\n}" >> main.cpp
		fi
	fi
fi