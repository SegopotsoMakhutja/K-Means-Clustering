# canonical makefile for C++
# author: MKHSEG001
# August 2019

CXX 	:= g++
INCDIRS := -I.
CXXFLAGS:= -std=c++11 -Wall -w
SRCFILES:= $(wildcard *.cpp) 
OBJFILES:= $(patsubst %.cpp,%.o,$(SRCFILES))
DEPFILES:= $(patsubst %.cpp,%.d,$(SRCFILES))

PRODUCT := KMeans # change name accordingly for each assignment

$(PRODUCT): $(OBJFILES)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCDIRS) -c $< -o $@

%.d: %.cpp
	$(CXX) $(INCDIRS) -MM $< > $@

-include $(DEPFILES)

clean:
	@rm -f *.o *.d $(PRODUCT)

run:
	./$(PRODUCT)
