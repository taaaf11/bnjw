CXXFLAGS := -ggdb

P1_sources := $(wildcard P1/*.cpp)
P1_objs := $(P1_sources:%.cpp=%.o)
P1_deps := $(P1_objs:%.o=%.d)

P2_sources := $(wildcard P2/*.cpp)
P2_objs := $(P2_sources:%.cpp=%.o)
P2_deps := $(P2_objs:%.o=%.d)

P3_sources := $(wildcard P3/*.cpp)
P3_objs := $(P3_sources:%.cpp=%.o)
P3_deps := $(P3_objs:%.o=%.d)

main.exe: $(P1_objs) $(P2_objs) $(P3_objs) main.cpp
	g++ $^ -o main.exe $(CXXFLAGS)

$(P1_objs): %.o : %.cpp
	g++  -c $^ -o $@  $(CXXFLAGS) -MMD -MP -MF ${@:.o=.d}

$(P2_objs): %.o : %.cpp
	g++  -c $^ -o $@  $(CXXFLAGS) -MMD -MP -MF ${@:.o=.d}

$(P3_objs): %.o : %.cpp
	g++  -c $^ -o $@   $(CXXFLAGS) -MMD -MP -MF ${@:.o=.d}

-include $(P1_deps)
-include $(P2_deps)
-include $(P3_deps)

clean:
	rm P1/*.o
	rm P1/*.d
	rm P2/*.o
	rm P2/*.d
	rm P3/*.o
	rm P3/*.d