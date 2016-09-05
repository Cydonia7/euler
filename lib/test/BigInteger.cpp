#include "../BigInteger.h"
#include "../test.h"

using namespace std;

int main()
{
    BEGIN_TEST();

    ASSERT_EQUALS(BigInteger("123456789987654321").toString(), "123456789987654321");
    ASSERT_EQUALS(BigInteger("10000000009").toString(), "10000000009");

    ASSERT_EQUALS((BigInteger("123456") + BigInteger("987987987")).toString(), "988111443");
    ASSERT_EQUALS((BigInteger("9999") + BigInteger("99999999")).toString(), "100009998");

    END_TEST();

    return 0;
}

