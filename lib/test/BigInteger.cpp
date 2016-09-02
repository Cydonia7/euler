#include "../BigInteger.h"
#include "../test.h"

#include <string>

using namespace std;

int main()
{
    BEGIN_TEST();

    ASSERT_EQUALS(BigInteger("123456789987654321").toString(), "123456789987654321");

    END_TEST();

    return 0;
}

