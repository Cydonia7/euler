#include "../BigInteger.h"
#include "../test.h"

#include <string>

using namespace std;

int main()
{
    BEGIN_TEST();

    ASSERT_EQUALS(BigInteger("123456789987654321").toString(), "123456789987654321");
    ASSERT_EQUALS((BigInteger("123456") + BigInteger("987987987")).toString(), "988111443");

    END_TEST();

    return 0;
}

