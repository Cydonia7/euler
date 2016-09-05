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
    ASSERT_EQUALS(BigInteger("99912345789999") * BigInteger("12803790127641293087"), BigInteger("1279256706655472308200952912436913"));

    // Power
    ASSERT_EQUALS(BigInteger(2).power(100), BigInteger("1267650600228229401496703205376"));

    END_TEST();

    return 0;
}

