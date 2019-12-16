EXEBIN = fractionTest
SOURCES = $(EXEBIN).cpp
OBJECTS = $(EXEBIN).o

$(EXEBIN) : $(OBJECTS)
	g++ -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES) fraction.hpp
	g++ -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)