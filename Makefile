CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -g -c
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi
ASANFLAGS = -fsanitize=address -fno-omit-frame-pointer

DEP_OBJS = inherit_test.o

all: comp

comp: main main-asan

main: main.cpp temp_test.cpp temp_test.h linked_list.cpp linked_list.hpp $(DEP_OBJS)
	$(LD) $(DEP_OBJS) $< $(LDFLAGS) -o $@

main-asan: main.cpp temp_test.cpp temp_test.h linked_list.cpp linked_list.hpp $(DEP_OBJS)
	$(LD) $(DEP_OBJS) $< $(LDFLAGS) $(ASANFLAGS) -o $@

$(DEP_OBJS): inherit_test.cpp inherit_test.h
	$(CXX) $(CXXFLAGS) $<
