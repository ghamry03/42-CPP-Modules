#ifndef FILE_H
# define FILE_H

# include <iostream>
# include <fstream>

class	File {
	private:
		int				_isError;
		std::string		_inFilePath;
		std::string		_outFilePath;
		std::ifstream	_inFile;
		std::ofstream	_outFile;
		std::string		_inFileText;
		std::string		_replacedText;

	public:
		File( void );
		~File( void );

		void	setInFilePath ( std::string filePath );
		void	setOutFilePath ( std::string filePath );
		int		openInFile( void );
		void	readInFile( void );
		void	replaceText( std::string findWord, std::string replaceWord );
		int		openOutFile( void );
		void	writeToOutFile( void );
		int		sed( std::string fileName, std::string findWord, std::string replaceWord );
};

#endif
