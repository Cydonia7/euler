#include "../BigInteger.h"
#include "../test.h"

using namespace std;

int main()
{
    BEGIN_TEST();

    // Conversion to string
    ASSERT_EQUALS(BigInteger("123456789987654321").toString(), "123456789987654321");
    ASSERT_EQUALS(BigInteger("10000000009").toString(), "10000000009");

    // Construct from numbers
    ASSERT_EQUALS(BigInteger("12345678"), BigInteger(12345678));

    // Equality testing
    ASSERT_EQUALS(BigInteger("12345678"), BigInteger("12345678"));
    ASSERT_NOT_EQUALS(BigInteger("12345678"), BigInteger("5678"));

    // Sum
    ASSERT_EQUALS(BigInteger("123456") + BigInteger("987987987"), BigInteger("988111443"));
    ASSERT_EQUALS(BigInteger("9999") + BigInteger("99999999"), BigInteger("100009998"));

    // Product
    ASSERT_EQUALS(BigInteger(12345) * BigInteger(56789), BigInteger("701060205"));
    // 6789 * 2345 = 15920205
    // 6789 * 10000 = 67890000
    // 6789 * 12345 = 83810205
    // 50000 * 2345 = 117250000
    // 50000 * 10000 = 500000000
    // 50000 * 12345 = 617250000

    END_TEST();

    return 0;
}

