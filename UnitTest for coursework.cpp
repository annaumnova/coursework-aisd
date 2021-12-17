#include "pch.h"
#include "CppUnitTest.h"
#include "../course aisd/PPx Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestforcoursework
{
	TEST_CLASS(UnitTestforcoursework)
	{
	public:
		//arithmetics
		TEST_METHOD(in_degree_pow)
		{
			Assert::IsTrue(postfix_calculating("6^2")==36);
		}

		TEST_METHOD(multiplication)
		{
			Assert::IsTrue(postfix_calculating("6*6") == 36);
		}
		TEST_METHOD(division)
		{
			Assert::IsTrue(postfix_calculating("6/6") == 1);
		}
		TEST_METHOD(subtraction)
		{
			Assert::IsTrue(postfix_calculating("6-6") == 0);
		}
		TEST_METHOD(addition)
		{
			Assert::IsTrue(postfix_calculating("6+6") == 12);
		}
		//logarithmic
		TEST_METHOD(natural_logarithm)
		{
			Assert::IsTrue(postfix_calculating("ln(1)") == 0);
		}
		TEST_METHOD(decimal_logarithm)
		{
			Assert::IsTrue(postfix_calculating("log(1000)") == 3);
		}
		TEST_METHOD(square_root)
		{
			Assert::IsTrue(postfix_calculating("sqrt(9)") == 3);
		}
		//trigonometric
		TEST_METHOD(sine)
		{
			Assert::IsTrue(postfix_calculating("sin(0)") == 0);
		}
		TEST_METHOD(cosine)
		{
			Assert::IsTrue(postfix_calculating("cos(0)") == 1);
		}
		TEST_METHOD(tangent)
		{
			Assert::IsTrue(postfix_calculating("tg(0)") == 0);
		}
		TEST_METHOD(cotangent)
		{
			Assert::IsTrue(postfix_calculating("ctg(1)") == 0.642093);
		}
		TEST_METHOD(arch_cosh)
		{
			Assert::IsTrue(postfix_calculating("Arch(1)") == 1.545308);
		}
		//expression
		TEST_METHOD(express_1)
		{
			Assert::IsTrue(postfix_calculating("2*3+10*(9-11)") == -14);
		}
		TEST_METHOD(express_2)
		{
			Assert::IsTrue(postfix_calculating("exp") == 2.72);
			Assert::IsTrue(postfix_calculating("pi") == 3.14);
		}
		TEST_METHOD(express_3)
		{
			Assert::IsTrue(postfix_calculating("2*3+10*(9/3)") == 36);
		}
	};
}
