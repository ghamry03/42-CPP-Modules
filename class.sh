#!/bin/bash

# check number of arguments
if [ $# -ne 1 ]; then
    echo "Wrong number of arguments, try ./script className"
    exit 1
fi


# class name from the first argument
className=$1

# check if incs directory exists in the home directory
if [ -d "$PWD/incs" ]; then
    hppPath="$PWD/incs/$className.hpp"
else
    hppPath="$PWD/$className.hpp"
fi

# check if srcs directory exists in the home directory
if [ -d "$PWD/srcs" ]; then
    cppPath="$PWD/inc/$className.cpp"
else
    cppPath="$PWD/$className.cpp"
fi

# make sure that class files don't exist already
if [ -f "$cppPath" ]; then
    echo "$className cpp file already exists"
    exit 1
fi
if [ -f "$hppPath" ]; then
    echo "$className hpp file already exists"
    exit 1
fi

classNameUpper=$(echo $className | awk '{print toupper($0)}')
### HPP FILE
echo "#ifndef ${classNameUpper}_HPP
# define ${classNameUpper}_HPP

# include <iostream>

class $className {
    private:

    public:
        $className( void );
        ~$className( void );
        $className( const $className & copy );
        $className & operator=( const $className & copy );

};

#endif
" >> $hppPath

### CPP FILE
echo "#include \"$className.hpp\"

$className::$className( void ) {
}

$className::~$className( void ) {
}

$className::$className( const $className & copy ) {
    *this = copy;
}

$className & $className::operator=( const $className & copy ) {
    return ( *this );
}
" >> $cppPath

