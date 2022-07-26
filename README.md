## Program for copying files

### Analogue of cp(1)

This program copies bytes from the source file skipping the bytes with values of 0.

Create a copy of the source file without 0.

#### To run this program in command line run:

`g++ main.cpp -o 'compiledFileName'` - to compile a file

`./'compiledFileName'' < fileToRead > fileToWrite` - to run 

Note: `fileToRead` must be created and filled beforehand, `fileToWrite` will be created (copy of `fileToRead` without 0)

You can use `file.hole` to test the program
