#include "List.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void populate(List&);
void display(const List&) ;
void instructions();

int main()
{
    int choice;
    int number;
    int index;
    List linkList;
    
    populate(linkList);
    display(linkList);

    do 
    {
        instructions();
        cin >> choice;

        switch (choice)
        {           
            case 1:
                cout << "\nEnter the index where you want the new value to appear:\n ";
                cin >> index;
                cout << "Enter the value you want added at this location: ";
                cin >> number;
                
                if (linkList.insertNode(number, index))
                    display(linkList);
                else
                    cout << "Invalid index, no data added to list.";
                break; 
            
            case 2:
                cout << "\nEnter an integer to delete: ";
                cin >> number;

                if (linkList.deleteNode(number))
                {
                    cout << number << " is deleted from the list.\n";
                    display(linkList);
                }
                else
                    cout << "The number is not found.";
                break;

            case 3:
                linkList.clear();
                populate(linkList);
                cout << endl;
                
                display(linkList);
                break;
            
            case -1:
                break;
            
            default:
                cout << "\n\nThe input information is not a selection.\n"
                    << " Please input the selection again.";
                break;
        }

    } while (choice != -1);

    cout << "\n\n\n******     Good Bye      ******\n\n";
    
    system("pause");
}

void populate(List &listData)
{
    srand(time(0));
    
    for (int i = 0; i < 20; i++)
        listData.append(rand() % 201);
}

void display(const List& listData)
{
    cout << "The list is:\n";
    listData.display();
}

void instructions()
{
    cout << "\n\n\nPlease select one from of the following selection orenter -1 to exit:\n"
        << "1. Insert an element to the List.\n"
        << "2. Delete an element from the List.\n"
        << "3. Repopulate the List.\n"
        << ":";
}