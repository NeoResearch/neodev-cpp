#FILENAME :=  $(patsubst %.Test.cpp,%.core.test,$(wildcard core.tests/*.Test.cpp))

ROOT_PATH=..
SRC_PATH=../src
GTEST_PATH=gtestlib/googletest
GMOCK_PATH=gtestlib/googlemock

all:
	@echo "please type 'make test'"

test: clean ex_HelloWorld.test ex_HelloWorldTests.test  #all.test #$(FILENAME)
	@echo "Executed tests"
	#./all.test

#all.test : all.Test.cpp
#	g++  --coverage -g -O0 --std=c++11 -DNEODEV_CPP_TEST -I$(ROOT_PATH) -I$(SRC_PATH) -I$(GTEST_PATH)/include -I$(GMOCK_PATH)/include  -pthread $< -o $@ $(GMOCK_PATH)/gtest/libgtest_main.a $(GMOCK_PATH)/gtest/libgtest.a $(GMOCK_PATH)/libgmock.a -lpthread -ldl

ex_%.test : examples_Tests/%.Test.cpp
	g++  --coverage -g -O0 --std=c++11 -DNEODEV_CPP_TEST -I$(ROOT_PATH) -I$(SRC_PATH) -I$(GTEST_PATH)/include -I$(GMOCK_PATH)/include  -pthread $< -o $@ $(GMOCK_PATH)/gtest/libgtest_main.a $(GMOCK_PATH)/gtest/libgtest.a $(GMOCK_PATH)/libgmock.a -lpthread -ldl
	./$@

test-coverage:
	mkdir -p reports
	lcov --directory . --capture --output-file reports/app.info
	(cd reports && genhtml app.info)

# cleaning tests
clean:
	rm -f *.test
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.info
