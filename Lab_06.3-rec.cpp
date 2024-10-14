#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX, int i)
{
    if (i < SIZE)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
        create(arr, SIZE, MIN, MAX, ++i);
    }
}

void Print(int* arr, const int SIZE, int i)
{
    cout << setw(4) << arr[i];
    if (i < SIZE - 1)
        Print(arr, SIZE, i + 1);
    else
        cout << endl;
}

int count(int* arr, int SIZE, int nCount, int i)
{
    if (i < SIZE)
    {
        if (arr[i] % 2 == 0 && arr[i] != 0)
        {
            nCount++;
        }
        count(arr, SIZE, nCount, ++i);
    }
    else return nCount;
}

template <typename T>
void SecondCreate(T* arr, int SIZE, T MIN, T MAX, int i)
{
    if (i < SIZE)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
        SecondCreate(arr, SIZE, MIN, MAX, ++i);
    }
}

template <typename T>
void SecondPrint(T* arr, const int SIZE, int i)
{
    cout << setw(4) << arr[i];
    if (i < SIZE - 1)
        Print(arr, SIZE, i + 1);
    else
        cout << endl;
}

template <typename T>
int SecondCount(T* arr, const int SIZE, int nCount, int i)
{
    if (i < SIZE)
    {
        if (arr[i] % 2 == 0 && arr[i] != 0)
        {
            nCount++;
        }
        SecondCount(arr, SIZE, nCount, ++i);
    }
    else return nCount;
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 10;
    int MIN = -10;
    int MAX = 10;

    int* arr = new int[SIZE];

    create(arr, SIZE, MIN, MAX, 0);

    Print(arr, SIZE, 0);

    cout << endl;
    cout << "count = " << count(arr, SIZE, 0, 0) << endl;

    SecondCreate(arr, SIZE, MIN, MAX, 0);

    SecondPrint(arr, SIZE, 0);

    cout << endl;
    cout << "secondCount = " << SecondCount(arr, SIZE, 0, 0) << endl;

    delete[] arr;

    return 0;
}
