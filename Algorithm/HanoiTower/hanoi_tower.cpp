// 참고: 윤성우 열혈 자료구조 챕터 2
#include <iostream>

// Suppose that the lowest number of disc is located at top.
void hanoi(int num, char from, char by, char to)
{
    if (num == 1)
    {
        std::cout << "Move disc1 from "<< from << " to " << to << "." << std::endl;
        return;
    }

    hanoi(num - 1, from, to, by);
    std::cout << "Move disc" << num << " from " << from << " to " << to << "." << std::endl;
    hanoi(num - 1, by, from, to);
}

int main(void)
{
    hanoi(3, 'A', 'B', 'C');
    return 0;
}
