EXEBIN = test
SOURCES = $(EXEBIN).cpp
OBJECTS = $(EXEBIN).o

$(EXEBIN) : $(OBJECTS)
	g++ -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	g++ -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)