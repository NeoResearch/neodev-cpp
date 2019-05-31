#FILENAME :=  $(patsubst %.Test.cpp,%.core.test,$(wildcard core.tests/*.Test.cpp))

ROOT_PATH=..
SRC_PATH=../src
GTEST_PATH=gtestlib/googletest
GMOCK_PATH=gtestlib/googlemock

all:
	@echo "please type 'make test'"

test: clean all.test #$(FILENAME)
	@echo "Executed tests"
	./all.test

all.test : all.Test.cpp
	g++  --coverage -g -O0 --std=c++11 -DNEODEV_CPP_TEST -I$(ROOT_PATH) -I$(SRC_PATH) -I$(GTEST_PATH)/include -I$(GMOCK_PATH)/include  -pthread $< -o $@ $(GMOCK_PATH)/gtest/libgtest_main.a $(GMOCK_PATH)/gtest/libgtest.a $(GMOCK_PATH)/libgmock.a -lpthread -ldl

#examples.test : examples.Test.cpp
	#g++ --coverage -O0 -I../src/core --std=c++11 -I$(OPENSSL_PATH)/include $(OPENSSL_PATH)/../CryptoNeoOpenSSL.cpp $(CORE_PATH)/payloads/TransactionFactory.cpp -I$(GTEST_PATH)/include -L$(GMOCK_PATH)/gtest -L$(GMOCK_PATH) -lgtest -lgtest_main  -L$(OPENSSL_PATH) -llinux-openssl-crypto-x86_64 -lpthread -ldl $< -o $@
#	g++ --coverage -g -O0 --std=c++11 -I$(CORE_PATH) -I$(GTEST_PATH)/include -I$(GMOCK_PATH)/include -I$(OPENSSL_PATH)/include -pthread $< -o $@ $(GMOCK_PATH)/gtest/libgtest_main.a $(GMOCK_PATH)/gtest/libgtest.a $(GMOCK_PATH)/libgmock.a $(OPENSSL_PATH)/../CryptoNeoOpenSSL.cpp -L$(OPENSSL_PATH) -llinux-openssl-crypto-x86_64 -lpthread -ldl

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
