#include <iostream>
#include<string>
#include <stdlib.h>
using namespace std;
int counter_items = 0;
string counter_category_fruit = "0";
string counter_category_car = "0";
string counter_category_clothes = "0";
string counter_category_book = "0";
string counter_category_electorincs = "0";
int counter_point = 0;
string Best_seller;
struct member  //storing information of member
{
    int memberID;
    string email;
    string name;
    int password;
    string address;
    int phone;
};
member dataofmember(member s) // input data of member
{
    cout << "please sign up" << endl;
    cout << "Enter your ID" << endl;
    cin >> s.memberID;
    cout << "Enter your email" << endl;
    cin >> s.email;
    cout << "Enter your name" << endl;
    cin >> s.name;
    cout << "Enter your password" << endl;
    cin >> s.password;
    cout << "Enter your delivery address" << endl;
    cin >> s.address;
    cout << "Enter your phone number" << endl;
    cin >> s.phone;
    return s;
}
struct items   // storing information of item
{
    int number;
    string category;
    int price;
    string startDate;
    string endDate;
    bool status;
    int id;
    float rate;
};
void item(items v, items i[])   //input information of item
{
    cout << "Enter item number" << endl;
    cin >> v.number;
    cout << "Choose item category for car press 1 for fruit press 2 clothes press 3 book press 4 electronics 5  " << endl;
    int category_num;
    cin >> category_num;
    if (category_num == 1)
    {
        v.category = "car";
    }
    else if (category_num == 2)
    {
        v.category = "fruit";
    }
    else if (category_num == 3)
    {
        v.category = "clothes";
    }
    else if (category_num == 4)
    {
        v.category = "book";
    }
    else if (category_num == 5)
    {
        v.category = "electronics";
    }
    cout << "enter item price" << endl;
    cin >> v.price;
    cout << "enter start date" << endl;
    cin >> v.startDate;
    cout << "Enter item end date" << endl;
    cin >> v.endDate;
    v.status = true;
    cout << " statue : available for buying" << endl;
    i[counter_items] = v;
    counter_items++;
}
void best_seller(int z, items i[])   // make a report of the top category in respect of the monthly transactions
{
    if (i[z].status == false && i[z].category == "car")
    {
        counter_category_car = counter_category_car + "1";
    }
    if (i[z].status == false && i[z].category == "fruit")
    {
        counter_category_fruit = counter_category_fruit + "1";
    }
    if (i[z].status == false && i[z].category == "clothes")
    {
        counter_category_clothes = counter_category_clothes + "1";
    }
    if (i[z].status == false && i[z].category == "book")
    {
        counter_category_book = counter_category_book + "1";
    }
    if (i[z].status == false && i[z].category == "electronics")
    {
        counter_category_electorincs = counter_category_electorincs + "1";
    }
}
void rates(int z, items i[])
{
    if (i->rate >= 3)
    {
        counter_point = counter_point++;
        cout << "other member participating point :" << counter_point << endl;
    }
}
void confirmation(int confirm, int z, items i[])
{
    if (confirm == 1)
    {
        string comment;
        cout << "operation has been done" << endl;
        cout << "item sold out" << endl;
        cout << "please input other member participating id and rate him and write a comment about him" << endl;
        cin >> i[z].id;
        cin >> i[z].rate;
        cin >> comment;
        cout << "other member participating id :" << i[z].id << endl;
        cout << "other member participating rate:" << i[z].rate << endl;
        cout << "your comment about other member :" << comment << endl;
        rates(z, i);
        i[z].status = false;
        best_seller(z, i);
    }
}
int main()
{
    system("color F0");
    member s;
    dataofmember(s);
    items i[50];
    while (true)
    {
        // user choose mode
        cout << "hello member please choose your mode" << endl;
        cout << "press 1 for buyer mode " << endl;
        cout << "press 2 for seller mode" << endl;
        cout << "press 3 for a report of the top category in respect of the monthly transactions" << endl;
        cout << "press 8 for search by category and price" << endl;
        cout << "press 9 for search by category only" << endl;
        cout << "press 4 for exit" << endl;
        int mode;
        cin >> mode;
        if (mode == 1)
        {
            for (int z = 0; z < counter_items; z++)
            {
                // show the items for sale
                cout << "item number :" << i[z].number << endl;
                cout << "item category :" << i[z].category << endl;
                cout << "price :" << i[z].price << endl;
                cout << "start date :" << i[z].startDate << endl;
                cout << "end date :" << i[z].endDate << endl;
                if (i[z].status == true)
                {
                    cout << "available now " << endl;
                }
                else
                {
                    cout << "sold out you can not make any operation on it" << endl;
                }
            }
            for (int z = 0; z < counter_items; z++)
            {
                if (i[z].status == true)
                {
                    cout << "Enter item number to buy or press 0 to back to main menu" << endl;
                    int item_num;
                    cin >> item_num;
                    // check if item number is true or not
                    if (item_num == i[z].number)
                    {
                        cout << "do you want to send request to buy it ? 1/yes 2/suggest price 3/no" << endl;
                        int request;
                        cin >> request;
                        if (request == 1)
                        {
                            //user accept the price and he will buy directly
                            cout << "your request has been sent" << endl;
                            cout << " seller , do you confirm operation ? 1/yes 2/No " << endl;
                            int confirm;
                            cin >> confirm;
                            confirmation(confirm, z, i);
                        }
                        else if (request == 2)
                        {
                            // user suggest a suit price
                            cout << "enter your suit price" << endl;
                            int price;
                            cin >> price;
                            cout << " seller ,do you confirm operation ? 1/yes 2/No " << endl;
                            int confirm;
                            cin >> confirm;
                            confirmation(confirm, z, i);
                        }
                    }
                    else if (item_num != i[z].number)
                    {
                        cout << "invalid item number" << endl;
                    }
                    else if (item_num == 0)
                    {
                        break;
                    }
                }
            }
        }
        else if (mode == 2)
        {
            // Enter the data of item which user want to sell it
            while (true)
            {
                cout << "hello member please Enter your item data" << endl;
                items v;
                item(v, i);
                cout << "item added successful" << endl;
                cout << " do you want to add another item ? 1/yes 2/no" << endl;
                int addtion_item;
                cin >> addtion_item;
                if (addtion_item == 2)
                {
                    dataofmember(s);
                    break;
                }
            }
        }
        else if (mode == 3)
        {
            //a report of the top category in respect of the monthly transactions

            string Best_seller_array[5] = { counter_category_car,counter_category_fruit,counter_category_clothes,counter_category_book,counter_category_electorincs };
            Best_seller = counter_category_car;
            int x = 1;
            for (int i = 0; i < 5; i++)
            {
                if (Best_seller < Best_seller_array[x])
                {
                    Best_seller = Best_seller_array[x];
                    x++;
                }
            }
            if (Best_seller == counter_category_car)
            {
                cout << "the top category in respect of the monthly transactions is a car" << endl;
            }
            else if (Best_seller == counter_category_fruit)
            {
                cout << "the top category in respect of the monthly transactions is a fruit " << endl;
            }
            else if (Best_seller == counter_category_clothes)
            {
                cout << "the top category in respect of the monthly transactions is a clothes " << endl;
            }
            else if (Best_seller == counter_category_book)
            {
                cout << "the top category in respect of the monthly transactions is a book " << endl;
            }
            else if (Best_seller == counter_category_electorincs)
            {
                cout << "the top category in respect of the monthly transactions is a electorincs  " << endl;
            }
        }
        else if (mode == 8)
        {
            //search via price and category
            cout << "enter price " << endl;
            int price;
            cin >> price;
            cout << "enter category" << endl;
            string category;
            cin >> category;
            for (int z = 0; z < counter_items; z++)
            {
                if (price != i[z].price && category != i[z].category)
                {
                    cout << " this item does not exist" << endl;
                }
                //check the category and price is true or not
                else if (price == i[z].price && category == i[z].category)
                {
                    cout << "item number :" << i[z].number << endl;
                    cout << "item category :" << i[z].category << endl;
                    cout << "price :" << i[z].price << endl;
                    cout << "start date :" << i[z].startDate << endl;
                    cout << "end date :" << i[z].endDate << endl;
                    cout << "Enter item number to buy or press 0 to back to main menu" << endl;
                    int item_num;
                    cin >> item_num;
                    for (int z = 0; z < counter_items; z++)
                    {
                        // check the item number is true or not
                        if (item_num == i[z].number)
                        {
                            cout << "do you want to send request to buy it ? 1/yes 2/suggest price 3/no" << endl;
                            int request;
                            cin >> request;
                            if (request == 1)
                            {
                                //user accept the price and he will buy directly
                                cout << "your request has been sent" << endl;
                                cout << " seller , do you confirm operation ? 1/yes 2/No " << endl;
                                int confirm;
                                cin >> confirm;
                                confirmation(confirm, z, i);
                            }
                            else if (request == 2)
                            {
                                // user suggest a suit price
                                cout << "enter your suit price" << endl;
                                int price;
                                cin >> price;
                                cout << " seller ,do you confirm operation ? 1/yes 2/No " << endl;
                                int confirm;
                                cin >> confirm;
                                confirmation(confirm, z, i);
                            }
                        }
                        else if (item_num != i[z].number)
                        {
                            cout << "invalid item number" << endl;
                        }
                        else if (item_num == 0)
                        {
                            break;
                        }
                    }
                }
            }
        }
        else if (mode == 9)
        {
            cout << "enter category" << endl;
            string category;
            cin >> category;
            for (int z = 0; z < counter_items; z++)
            {
                if (category != i[z].category)
                {
                    cout << "this category does not exist" << endl;

                }
                // check if category is true or not
                else if (category == i[z].category)
                {

                    cout << "item number :" << i[z].number << endl;
                    cout << "item category :" << i[z].category << endl;
                    cout << "price :" << i[z].price << endl;
                    cout << "start date :" << i[z].startDate << endl;
                    cout << "end date :" << i[z].endDate << endl;

                    cout << "Enter item number to buy" << endl;
                    int item_num;
                    cin >> item_num;
                    for (int z = 0; z < counter_items; z++)
                    {
                        if (item_num == i[z].number)
                        {
                            // check if item number is true or not
                            cout << "do you want to send request to buy it ? 1/yes 2/suggest price 3/no" << endl;
                            int request;
                            cin >> request;
                            if (request == 1)
                            {
                                //user accept the price and he will buy directly
                                cout << "your request has been sent" << endl;
                                cout << " seller , do you confirm operation ? 1/yes 2/No " << endl;
                                int confirm;
                                cin >> confirm;
                                confirmation(confirm, z, i);
                            }
                            else if (request == 2)
                            {
                                // user suggest a suit price
                                cout << "enter your suit price" << endl;
                                int price;
                                cin >> price;
                                cout << " seller ,do you confirm operation ? 1/yes 2/No " << endl;
                                int confirm;
                                cin >> confirm;
                                confirmation(confirm, z, i);
                            }
                            else if (item_num != i[z].number)
                            {
                                cout << "invalid item number" << endl;
                            }
                        }
                    }
                }
            }
        }
        else if (mode == 4)
        {
            break;
        }
    }
    return 0;
}