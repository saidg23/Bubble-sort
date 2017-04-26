#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

//length of the array
const int arrayLength = 45;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
//gets a unique random number for every index in the array
void getArray(int array[arrayLength])
{
    for(int count = 0; count <= arrayLength-1;)
    {
        int placeholder = getRandomNumber(1, arrayLength);
        bool passFail = true;
        int check = 0;

        //checks for duplicates
        for(; check <= arrayLength-1; ++check)
        {
            if(placeholder == array[check])
            {
                passFail = false;
                break;
            }
        }
        if(passFail)
        {
            array[count] = placeholder;
            ++count;
        }

    }
}

int main()
{
    srand(time(0));

    int array[arrayLength] {0};
    getArray(array);

    for(int iteration = 0; iteration < arrayLength-1; ++iteration)
    {
        //tracks whether a swap was performed
        bool swapCheck = false;
        for(int pos = 0; pos < (arrayLength-1)-iteration; ++pos)
        {
            if(array[pos] > array[pos+1])
            {
                swapCheck = true;
                swap(array[pos], array[pos+1]);
            }
            for(int pos = 0; pos <= arrayLength-1; ++pos)
            {
                if(array[pos] < 10)
                    cout << array[pos] << "  ";
                else
                    cout << array[pos] << " ";

                for(int count = array[pos]; count >= 1; --count)
                {
                    cout << "|";
                }

                cout << '\n';
            }

            //Sleep(150); //uncomment for slower execution
            system("cls");
        }

        //outputs the last iteration permanently
        if(swapCheck == false)
        {
            system("cls");

            for(int pos = 0; pos <= arrayLength-1; ++pos)
            {
                if(array[pos] < 10)
                    cout << array[pos] << "  ";
                else
                    cout << array[pos] << " ";

                for(int count = array[pos]; count >= 1; --count)
                {
                    cout << "|";
                }

                cout << '\n';
            }

            cout << "early termination on iteration " << iteration << '\n';
            iteration = arrayLength;
        }
    }
}


