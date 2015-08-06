PROJECT= resume
SOURCES= src/cheapgmp.cpp src/accessories.cpp
MAINSRC= src/main.cpp
TESTSOURCES= tests/test_cheapgmp.cpp
LDFLAGS=
TESTLDFLAGS= -laeryn_tests -laeryn_core
CFLAGS= -c -Wall -std=c++11
CPLUSPLUS= g++
BINARY=cheapgmp
TESTBINARY=testrunner

OBJECTS=$(SOURCES:.cpp=.o)
TESTOBJECTS=$(TESTSOURCES:.cpp=.o)
MAINOBJECTS=$(MAINSRC:.cpp=.o)

all: $(SOURCES) $(BINARY)

$(BINARY): $(OBJECTS) $(MAINOBJECTS)
	$(CPLUSPLUS) $(OBJECTS) $(MAINOBJECTS) $(LDFLAGS) -o $@

app: $(BINARY)

testrunner: $(OBJECTS) $(TESTOBJECTS)
	$(CPLUSPLUS) $(OBJECTS) $(TESTOBJECTS) $(LDFLAGS) $(TESTLDFLAGS) -o $@

.cpp.o:
	$(CPLUSPLUS) $(CFLAGS) $< -o $@

test: $(BINARY)
	./$(BINARY)

distclean: clean
	rm -f $(BINARY)

clean:
	rm -f $(OBJECTS)
