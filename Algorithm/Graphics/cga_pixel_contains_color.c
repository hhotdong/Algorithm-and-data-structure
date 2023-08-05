// https://www.computerenhance.com/p/the-four-programming-questions-from?triedSigningIn=true
// https://stackoverflow.com/questions/15114140/writing-binary-number-system-in-c-code
// https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
#include <stdio.h>

#define B(x) S_to_binary_(#x)
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0')

static inline unsigned char S_to_binary_(const char *s)
{
        unsigned char i = 0;
        while (*s)
        {
            i <<= 1;
            i += *s++ - '0';
        }
        return i;
}

int ContainsColor(unsigned char pixel, unsigned char color)
{
   unsigned char tmp = ~(pixel ^ color);
   unsigned char mask = 0xAA;  // 10101010
   return (tmp & ((tmp & mask) >> 1));
}

void TestColor(unsigned char pixel, unsigned char color)
{
    unsigned char testingColor = 0;
    for (int i = 0; i < 4; ++i)
    {
        testingColor <<= 2;
        testingColor |= color;
    }

    int result = ContainsColor(pixel, testingColor);

    printf("Test color: pixel(" BYTE_TO_BINARY_PATTERN "), color(" BYTE_TO_BINARY_PATTERN "), result(%s)\n",
        BYTE_TO_BINARY(pixel), BYTE_TO_BINARY(color), result ? "true" : "false");
}

int main(void)
{
    TestColor(B(00000000), B(00000000));
    TestColor(B(00000000), B(00000001));
    TestColor(B(00000000), B(00000010));
    TestColor(B(00000000), B(00000011));
    printf("\n");
    
    TestColor(B(01000000), B(00000000));
    TestColor(B(01000000), B(00000001));
    TestColor(B(01000000), B(00000010));
    TestColor(B(01000000), B(00000011));
    printf("\n");
    
    TestColor(B(10000000), B(00000000));
    TestColor(B(10000000), B(00000001));
    TestColor(B(10000000), B(00000010));
    TestColor(B(10000000), B(00000011));
    printf("\n");

    TestColor(B(11000000), B(00000000));
    TestColor(B(11000000), B(00000001));
    TestColor(B(11000000), B(00000010));
    TestColor(B(11000000), B(00000011));
    printf("\n");

    return 0;
}
