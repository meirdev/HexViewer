CPP = g++
CXXFLAGS = -ansi -pedantic -Wall -Werror -Wconversion -std=c++0x -O3
CPPFLAGS = -I.

PROGRAM = HexViewer

SOURCES = Main.cpp \
		 ./StringBuffer/StringBuffer.cpp \
		 ./Style/ABCStyle.cpp \
		 ./Style/HexDump/HexDump.cpp \
		 ./Style/Hexyl/Hexyl.cpp \
		 ./FileStream/ABCFile.cpp \
		 ./FileStream/LocalFile/LocalFile.cpp \
		 ./Printer/ABCPrinter.cpp \
		 ./Printer/DefaultPrinter/DefaultPrinter.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(PROGRAM): $(OBJECTS)
	$(CPP) $(CXXFLAGS) $(CPPFLAGS) $(OBJECTS) -o $(PROGRAM)

include depends

depends:
	$(CPP) $(CXXFLAGS) $(CPPFLAGS) -MM $(SOURCES) > depends

run:
	@./$(PROGRAM)

gdb:
	@gdb ./$(PROGRAM) -q

clean:
	rm *.o depends $(PROGRAM)
	find . -name '*.o' -type f -delete

# head -c 100MB < /dev/urandom > $(file_name)
# time ./$(PROGRAM) $(file_name) > /dev/null