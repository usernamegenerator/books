#include <iostream>

using namespace std;
/*
move 1 from A to C
move 2 from A to B
move 1 from C to B
move 3 from A to C
move 1 from B to A
move 2 from B to C
move 1 from A to C
*/
void hanoi(int n, char from, char helper, char to)
{
    if (n == 1)
    {
        cout << "move " << 1 << " from " << from << " to " << to << endl;
    }
    else
    {
        //open fridge's door
        //move n-1 from from to helper using to
        hanoi(n - 1, from, to, helper);
        //put the elephant in the fridge
        //move n from from to to using helper
        cout << "move " << n << " from " << from << " to " << to << endl;
        //close fridge's door
        //move n-1 from helper to to using from
        hanoi(n - 1, helper, from, to);
    }
}

int main()
{
    hanoi(3, 'A', 'B', 'C');
}