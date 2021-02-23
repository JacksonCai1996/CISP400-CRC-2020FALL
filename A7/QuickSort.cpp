#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

int quickSortHelper(vector<int>&, int, int);
void quickSort(vector<int>&, int, int);
void swap(int*, int*);
void const display(vector<int>, int);

int main()
{

    vector<int> elements;
    const vector<string> suffiexs = { "", "st", "nd", "rd"};
    
    srand(time(0));

    for (int i = 1; i <= 10; i++)
    {
        int size = rand() % 21;
           
        cout << "The " << i << (i <= 3 ? suffiexs[i] : "th")
            << " set of data(" << size << "):\n";

        for (int i = 0; i < size; i++)
            elements.push_back(rand() % 101);

        cout << (size > 0 ? "  Initial vector values are:\n" : "  The vector is empty.\n");
        display(elements, size);       
        cout << endl;

        quickSort(elements, 0, size - 1);

        cout << (size > 0 ? "  The sorted vector values are:\n" : "  The sorted vector is empty.\n");
        display(elements, size);
        cout << endl << endl;

        elements.clear();
    }

    system("pause");
}


void quickSort(vector<int> &data, int low, int high)
{
    if (low < high)
    {
        int i = quickSortHelper(data, low, high);

        quickSort(data, low, i - 1);
        quickSort(data, i + 1, high);
    }
}


int quickSortHelper(vector<int> &vectorData, int low, int high)
{
    int i = low - 1;
    
    for (int j = low; j < high; j++)
    {
        if (vectorData[j] < vectorData[high])
        {
            i++;
            swap(&vectorData[i], &vectorData[j]);
        }
    }
    
    swap(&vectorData[i + 1], &vectorData[high]);

    return (i + 1);
}


void const display(vector<int> data, int size)
{  
    for (auto element : data)
        cout << setw(4) << element;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}