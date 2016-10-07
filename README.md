# BOOKS
Repository containing solutions to practice problems from various programming books.

# BUILD
The default Makefile target builds all programs in src directory. All binaries
are created in the build directory. To build one specific file, the makefile
target should be the path of the file without the file-suffix. For eg:
```
# If executing for the first time, do setup.
make setup
make src/book1/progr1
```
