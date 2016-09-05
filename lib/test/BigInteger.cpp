#include "../BigInteger.h"
#include "../test.h"

using namespace std;

int main()
{
    BEGIN_TEST();

    // Conversion to string
    ASSERT_EQUALS(BigInteger("123456789987654321").toString(), "123456789987654321");
    ASSERT_EQUALS(BigInteger("10000000009").toString(), "10000000009");

    // Equality testing
    ASSERT_EQUALS(BigInteger("12345678"), BigInteger("12345678"));
    ASSERT_NOT_EQUALS(BigInteger("12345678"), BigInteger("5678"));

    // Sum
    ASSERT_EQUALS(BigInteger("123456") + BigInteger("987987987"), BigInteger("988111443"));
    ASSERT_EQUALS(BigInteger("9999") + BigInteger("99999999"), BigInteger("100009998"));

    // Product
    //ASSERT_EQUALS((BigInteger("123") * BigInteger("789")).toString(), "97047");

    END_TEST();

    return 0;
}

