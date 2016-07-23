PROJECT= resume
SOURCES= src/cheapgmp.cpp src/accessories.cpp
MAINSRC= src/main.cpp
CMDSRC= src/cmd.cpp
TESTSOURCES= tests/test_cheapgmp.cpp
LDFLAGS=
TESTLDFLAGS= -laeryn_tests -laeryn_core

# Enable __USE_MISC if you're using clang
CFLAGS= -c -Wall -std=c++11 # -D__USE_MISC
CPLUSPLUS= g++
BINARY=cheapgmp
CMD=gmpcmd
TESTBINARY=testrunner

OBJECTS=$(SOURCES:.cpp=.o)
TESTOBJECTS=$(TESTSOURCES:.cpp=.o)
MAINOBJECTS=$(MAINSRC:.cpp=.o)
CMDOBJECTS=$(CMDSRC:.cpp=.o)

all: $(SOURCES) $(BINARY)

$(BINARY): $(OBJECTS) $(MAINOBJECTS)
	$(CPLUSPLUS) $(OBJECTS) $(MAINOBJECTS) $(LDFLAGS) -o $@

app: $(BINARY)

gmpcmd: $(CMDOBJECTS) $(OBJECTS)
	$(CPLUSPLUS) $(OBJECTS) $(CMDOBJECTS) $(LDFLAGS) -o $@

testrunner: $(OBJECTS) $(TESTOBJECTS)
	$(CPLUSPLUS) $(OBJECTS) $(TESTOBJECTS) $(LDFLAGS) $(TESTLDFLAGS) -o $@

.cpp.o:
	$(CPLUSPLUS) $(CFLAGS) $< -o $@

test: $(BINARY)
	./$(BINARY)

distclean: clean
	rm -f $(BINARY) $(TESTBINARY) $(CMD)

clean:
	rm -f $(OBJECTS) $(TESTOBJECTS) $(MAINOBJECTS) $(CMDOBJECTS)
