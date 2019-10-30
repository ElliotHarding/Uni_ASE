#include "CppUnitTest.h"
#include "../Lab2/BST.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:
	
		TEST_METHOD(InsertTest)
		{
			BST testTree = BST();

			testTree.insert(1, "item");

			const BST::Item* i = testTree.lookup(1);
			Assert::AreEqual(std::string("item"), std::string(*i));
		}

		TEST_METHOD(DisplayTreeTest)
		{
			BST testTree = BST();
			testTree.insert(22, "Jane");
			testTree.insert(22, "Mary");
			testTree.insert(0, "Harold");
			testTree.insert(9, "Edward");
			testTree.insert(37, "Victoria");
			testTree.insert(4, "Matilda");
			testTree.insert(26, "Oliver");
			testTree.insert(42, "Elizabeth");
			testTree.insert(19, "Henry");
			testTree.insert(4, "Stephen");
			testTree.insert(24, "James");
			testTree.insert(-1, "Edward");
			testTree.insert(31, "Anne");
			testTree.insert(23, "Elizabeth");
			testTree.insert(1, "William");
			testTree.insert(26, "Charles");
			testTree.displayTree();
			
			/*
			- 1 Edward
			0 Harold
			1 William
			4 Stephen
			9 Edward
			19 Henry
			22 Mary
			23 Elizabeth
			24 James
			26 Charles
			31 Anne
			37 Victoria
			42 Elizabeth
			*/
		}

		TEST_METHOD(RemoveTest)
		{
			BST testTree = BST();
			testTree.insert(22, "Jane");
			testTree.insert(22, "Mary");
			testTree.insert(0, "Harold");
			testTree.insert(9, "Edward");
			testTree.insert(37, "Victoria");
			testTree.remove();

			const BST::Item* i = testTree.lookup(37);
			Assert::IsTrue(i == nullptr);
		}

		TEST_METHOD(CopyTest)
		{
			BST t1;
			t1.insert(2, "Will");

			BST t2 = t1;
			t1.insert(22, "Mary");

			std::string* name = t2.lookup(22);

			Assert::IsTrue(name == nullptr);
		}
	};
}
