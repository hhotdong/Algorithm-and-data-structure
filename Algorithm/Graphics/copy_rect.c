// https://www.computerenhance.com/p/the-four-programming-questions-from?triedSigningIn=true
// https://jsandler18.github.io/extra/framebuffer.html
// A Framebuffer is a piece of memory that is shared between the CPU and the GPU. The CPU writes RGB pixels to the buffer, 
// and the GPU renders it to whatever output device you have connected.
// The Depth of a framebuffer is the number of bits in every pixel. 
// The Pitch of a framebuffer is simply the number of bytes that are in each row on screen.
// We can calculate the Pixels Per Row by pitch / (depth / 8), or equivalently (pitch * 8) / depth.
// We can calculate the offset within the framebuffer of a pixel located at Coordinates (x,y) by pitch * y + (depth / 8) * x
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CopyRect(char * bufferA, int pitchA, char * bufferB, int pitchB,
              int fromMinX, int fromMinY, int fromMaxX, int fromMaxY,
              int toMinX, int toMinY)
{
    int bPos = pitchB * toMinY + toMinX;
    for (int ay = fromMinY; ay <= fromMaxY; ++ay)
    {
        for (int ax = fromMinX; ax <= fromMaxX; ++ax)
        {
            int aPos = pitchA * ay + ax;
            bufferB[bPos] = bufferA[aPos];
            ++bPos;
        }
        
        int width = fromMaxX - fromMinX + 1;
        if (pitchB > width)
            bPos = bPos + pitchB - width;
        else
            bPos = bPos + pitchB;
    }
}

void TestCopyRect(int row, int col)
{
    char bufA[][10] = {
        { '0','0','0','0','0','0','0','0','0','0' },
        { '0','0','0','0','0','0','0','0','0','0' },
        { '0','0','0','0','0','0','0','0','0','0' },
        { '0','0','0','1','1','1','1','0','0','0' },
        { '0','0','0','1','1','1','1','0','0','0' },
        { '0','0','0','1','1','1','1','0','0','0' },
        { '0','0','0','1','1','1','1','0','0','0' },
        { '0','0','0','0','0','0','0','0','0','0' },
        { '0','0','0','0','0','0','0','0','0','0' },
        { '0','0','0','0','0','0','0','0','0','0' }
    };

    char bufB[row][col];
    memset(bufB, '0', row * col);

    printf("Buffer A\n");
    for (int j = 0; j < 10; ++j)
    {
        for (int i = 0; i < 10; ++i)
            printf("%c ", bufA[j][i]);
        printf("\n");
    }
    printf("\n");
    
    printf("Buffer B\n");
    for (int j = 0; j < row; ++j)
    {
        for (int i = 0; i < col; ++i)
            printf("%c ", bufB[j][i]);
        printf("\n");
    }
    printf("\n");

    printf("Copy rectangle located at (3,3) in Buffer A.\nPaste it to the point located at (2,5) in Buffer B.\n\n");
    CopyRect(bufA[0], 10, bufB[0], col, 3, 3, 6, 6, 2, 5);
    
    printf("Buffer B\n");
    for (int j = 0; j < row; ++j)
    {
        for (int i = 0; i < col; ++i)
            printf("%c ", bufB[j][i]);
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        printf("Usage: <ProgramName> row column\n");
        return 0;
    }

    TestCopyRect(atoi(argv[1]), atoi(argv[2]));
    return 0;
}
