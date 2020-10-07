#include <iostream>
#include <stdlib.h>
#include <vector>
#include "LinkedList.h"
//#include "debug.h"
using namespace std;

enum TestResult { TR_PASS, TR_FAIL };

#define ASSERT(condition)                                                         \
    if ((condition) == false) {                                                   \
        cout << "FAILURE: " << __FILE__ << ":" << __LINE__ << "\n"                \
             << "\tExpression '" << #condition << "' evaluated to false" << endl; \
        return TR_FAIL;                                                           \
    }

/*
 * Test case for checking for correct size after prepend
 */
TestResult testPrepend1() {
    LinkedList *l = new LinkedList();
	l->prepend(-2);
	l->prepend(10);
	l->prepend(5);
    ASSERT(l->size()==3);
	//If TR_FAIL not returned already -- test passes
	return TR_PASS;
}

/*
 * Test case for checking for correct value in a specific position
 */
TestResult testPrepend2() {
    LinkedList *l = new LinkedList();
	l->prepend(-2);
	l->prepend(10);
	l->prepend(5);
    ASSERT(l->fetch(1)==5);
	ASSERT(l->fetch(2)==10);
	ASSERT(l->fetch(3)==-2);
	//If TR_FAIL not returned already -- test passes
    return TR_PASS;
}

/*
 * Test case for checking for correct position removal after prepend
 */
TestResult testPrependRemove1() {
    LinkedList *l = new LinkedList();
	l->prepend(-2);
	l->prepend(10);
	l->prepend(5);
	l->remove(2);
    ASSERT(l->fetch(1)==5);
	//ASSERT(l->fetch(2)==10);
	ASSERT(l->fetch(2)==-2);
	//If TR_FAIL not returned already -- test passes
    return TR_PASS;
}

/*
 * Test case for checking for exception condition when fetching from an 
 * empty list after removal
 */
TestResult testPrependRemoveFetch() {
    LinkedList *l = new LinkedList();
	l->prepend(-2);
	l->prepend(10);
	l->prepend(5);
	l->remove(1);
	l->remove(1);
	l->remove(1);
    ASSERT(l->size()==0);
	try{
		ASSERT(l->fetch(1)==0);
	}
	catch(int e){
		ASSERT(true);
	}
	//ASSERT(l->fetch(2)==10);
	//ASSERT(l->fetch(2)==-2);
	//If TR_FAIL not returned already -- test passes
    return TR_PASS;
}

/*
 * Test case for checking sequence of prepend followed by insert is
 * done correctly
 */
TestResult testPrependInsert() {
    LinkedList *l = new LinkedList();
	l->prepend(-2);
	l->prepend(10);
	l->prepend(5);
	l->insert(1,100);
	l->insert(3,300);
    ASSERT(l->size()==5);
	try{
		ASSERT(l->fetch(1)==100);
		ASSERT(l->fetch(2)==5);
		ASSERT(l->fetch(3)==300);
		ASSERT(l->fetch(4)==10);
		ASSERT(l->fetch(5)==-2);
	}
	catch(int e){
		ASSERT(false);
	}
	//ASSERT(l->fetch(2)==10);
	//ASSERT(l->fetch(2)==-2);
	//If TR_FAIL not returned already -- test passes
    return TR_PASS;
}

/*
 * Test case for checking complex interleaving of 
 * prepend, insert, followed by remove works correctly 
 * Also checks for fetching incorrect positions -- exception handling
 */
TestResult testPrependInsertRemove() {
    LinkedList *l = new LinkedList();
	l->prepend(-2);
	l->prepend(10);
	l->insert(1,100);
	l->insert(3,300);
	l->prepend(5);
	l->remove(5);
    ASSERT(l->size()==4);
	try{
		ASSERT(l->fetch(1)==5);
		ASSERT(l->fetch(2)==100);
		ASSERT(l->fetch(3)==10);
		ASSERT(l->fetch(4)==300);
		//exception should be thrown by fetch and hence ASSERT is not evaluated
		ASSERT(l->fetch(5)==-2);
	}
	catch(int e){
		//If an exception is correctly thrown then test should pass
		ASSERT(true);
	}
	//ASSERT(l->fetch(2)==10);
	//ASSERT(l->fetch(2)==-2);
	//If TR_FAIL not returned already -- test passes
    return TR_PASS;
}

vector<TestResult (*)()> generateTests() {
    vector<TestResult (*)()> tests;
    tests.push_back(&testPrepend1);
    tests.push_back(&testPrepend2);
    tests.push_back(&testPrependRemove1);
	tests.push_back(&testPrependRemoveFetch);
    //tests.push_back(&testPrependInsert);
    //tests.push_back(&testPrependInsertRemove);
	//tests.push_back(&testInterleaved1);
    return tests;
}

int main(int argc, const char * argv[]){

	#ifdef _DEBUG
	vector<TestResult(*)()> tests_to_run = generateTests();
    unsigned int pass_count = 0;
    unsigned int fail_count = 0;
    unsigned int run_count = 0;

	for (unsigned int t = 0; t < tests_to_run.size(); ++t) {
		++run_count;
		TestResult result = tests_to_run[t]();
		if (result == TR_FAIL) {
			cout << "FAIL: Test " << t << " failed." << endl;
			++fail_count;
		} else {
			cout << "PASS: Test " << t << " passed." << endl;
			++pass_count;
		}
	}

    cout << "\n-------------------------------------------------\n"
         << "Total Run: " << run_count << "\n"
         << "Total PASSED: " << pass_count << "\n"
         << "Total FAILED: " << fail_count << "\n"
         << "-------------------------------------------------\n" << endl;

    return 1;
	#else
	LinkedList *l = new LinkedList();
	l->prepend(-2);
	l->prepend(10);
	l->prepend(5);
	if(l->size()==3){
		cout<<"Three nodes inserted" <<endl;
		l->print();
	}
	else cout<<"Something went wrong" <<endl;
	cout <<"Appended node with 100"<<endl;
	l->append(100);
	//l->print();

	//try removing
		try{
			l->remove(4);}
			catch(int i){
				std::cout << "Program exited due to invalid position!\n";
				return 1;
		}

		/*try{
			l->remove(20);
		}
	    catch(int i){
	        	std::cout << "Program exited due to invalid position!\n";
	        	return 1;
	    }*/
	    //Try inserting
	    try{
	           l->insert(1, 20);
	           l->insert(3, 50);
	    }
	    catch(int i){
	        std::cout << "Program exited due to invalid position!\n";
	        return 1;
	    }

	    l->print();
	#endif
}

