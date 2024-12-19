#include<iostream>
#include<stdio.h>
#include<cstdlib> // For exit(0)

using namespace std;

class publication // declaring class Publication
{
private:
    string title;
    float price;
public:
    void add()
    {
        cout << "\nEnter the Publication information : " << endl;
        cout << "Enter Title of the Publication : ";
        cin.ignore();  // To clear the input buffer if necessary
        getline(cin, title);
        cout << "Enter Price of Publication : ";
        cin >> price;
    }
    
    void display()
    {
        cout << "\n--------------------------------------------------";
        cout << "\nTitle of Publication : " << title;
        cout << "\nPublication Price : " << price;
    }
};

class book : public publication // declaring class book which inherits class publication in public mode.
{
private:
    int page_count;
public:
    void add_book()
    {
        try
        {
            add();  // Inherit add() from Publication class
            cout << "Enter Page Count of Book : ";
            cin >> page_count;
            if (page_count <= 0)
            {
                throw page_count;
            }
        }
        catch(...)
        {
            cout << "\nInvalid Page Count!!!";
            page_count = 0;
        }
    }

    void display_book()
    {
        display();  // Inherited display() from Publication
        cout << "\nPage Count : " << page_count;
        cout << "\n--------------------------------------------------\n";
    }
};

class tape : public publication // declaring class tape which inherits class publication in public mode
{
private:
    float play_time;
public:
    void add_tape()
    {
        try
        {
            add();  // Inherit add() from Publication class
            cout << "Enter Play Duration of the Tape : ";
            cin >> play_time;
            if (play_time <= 0)
                throw play_time;
        }
        catch(...)
        {
            cout << "\nInvalid Play Time!!!";
            play_time = 0;
        }
    }

    void display_tape()
    {
        display();  // Inherited display() from Publication
        cout << "\nPlay Time : " << play_time << " min";
        cout << "\n--------------------------------------------------\n";
    }
};

int main()
{
    book b1[10]; // object of class book
    tape t1[10]; // object of class tape
    int ch, b_count = 0, t_count = 0;

    do
    {
        cout << "\n* * * * * PUBLICATION DATABASE SYSTEM * * * * *";
        cout << "\n--------------------MENU-----------------------";
        cout << "\n1. Add Information to Books";
        cout << "\n2. Add Information to Tapes";
        cout << "\n3. Display Books Information";
        cout << "\n4. Display Tapes Information";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice : ";
        cin >> ch;

        switch(ch)
        {
        case 1:
            b1[b_count].add_book();
            b_count++;  // Increment count after adding a book
            break;
        case 2:
            t1[t_count].add_tape();
            t_count++;  // Increment count after adding a tape
            break;
        case 3:
            cout << "\n* * * * BOOK PUBLICATION DATABASE SYSTEM * * * *";
            for (int j = 0; j < b_count; j++)
            {
                b1[j].display_book();
            }
            break;
        case 4:
            cout << "\n* * * * TAPE PUBLICATION DATABASE SYSTEM * * * *";
            for (int j = 0; j < t_count; j++)
            {
                t1[j].display_tape();
            }
            break;
        case 5:
            exit(0);
        default:
            cout << "\nInvalid choice! Please try again.";
        }

    } while (ch != 5);

    return 0;
}
