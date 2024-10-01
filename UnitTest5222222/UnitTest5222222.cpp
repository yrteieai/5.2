#include "pch.h"
#include "CppUnitTest.h"
#include <cmath> 
#include "../52222222222/52222222222.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:

		TEST_METHOD(TestAFunction)
		{
		
			double x = 1.0;  
			int n = 1;
			double a = 1.0;

		
			double expected = -x * x / 2;

			// Перевірка, що результат наближений до очікуваного
			Assert::IsTrue(fabs(A(x, n, a) - expected) < 1e-10, L"Test A failed");
		}

		TEST_METHOD(TestSFunction)
		{
			
			double x = 1.0;  
			double eps = 1e-10;
			int n = 0;
			double s = 0;

			double expected = cos(x);

			Assert::IsTrue(fabs(S(x, eps, n, s) - expected) < eps, L"Test S failed");
		}
	};
}
