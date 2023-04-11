// HW1_CPP_Cource.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <string.h>
using namespace std;

// some constant coefficients
#define DIST_KF 7.13;
#define PRICE_KF 42.75;
#define PRICE_BASE 100.5;

//global var
int order_Id_Counter(1);

enum taxi_type
{
    econom = 1,
    bisines,
    baby
};

enum order_status
{
    ordered,
    inprogress,
    complite
};

struct taxi_order
{
    int id;
    taxi_type type;
    string point_from;
    string point_to;
    //char* point_to;
    float distance;
    double price;
    order_status status;
};


void make_order(taxi_order *order) 
{
    int type;
    order->id = order_Id_Counter++;

    std::cout << "Hello! Lets make a new order!\n";

    std::cout << "Choose a type of trip: 1 - econom, 2 - bisines, 3 - with children.\n";
    //cin >> order->type;
    std::cin >> type;
    order->type = (taxi_type)type;

    std::cout << "Enter start point:\n";
    std::cin >> order->point_from;

    std::cout << "Enter destination point:\n";
    std::cin >> order->point_to;

    order->distance = ((float)((*order).point_from).length() - (float)((*order).point_to).length()) * DIST_KF; 
    order->distance = order->distance < 0 ? (order->distance * -1) : order->distance;

    order->price = order->distance * PRICE_KF + PRICE_BASE;

    order->status = ordered;

    std::cout << "Thank you for order!\n";

};

void print_order(taxi_order* order)
{
    std::cout << "\n";
    std::cout << "id: " << "\t" << order->id << "\n";
    std::cout << "type: " << "\t" << order->type << "\n";
    std::cout << "to : " << "\t" << order->point_to << "\n";
    std::cout << "from : " << "\t" << order->point_from << "\n";
    std::cout << "dist.: " << "\t" << order->distance << "\n";
    std::cout << "price : " << "" << order->price << "\n";
    std::cout << "status : " << "" << order->status << "\n";
    std::cout << "\n";

}

int main()
{
    taxi_order order1;
    taxi_order order2;


    { // handle initialisation
        order1.id = order_Id_Counter++;
        order1.type = bisines;
        order1.point_to = (char*)"Domodedovo international airport";
        order1.point_from = (char*)"Kolomenskaya embankment 18";
        order1.distance = 50.50;
        order1.price = 100.5E02;
        order1.status = inprogress;
    }

    std::cout << "Test hardcode init order:\n";
    print_order(&order1);

    make_order(&order2);
    print_order(&order2);
    

    //{ //print
    //    std::cout << "id: " << "\t" << order1.id << "\n";
    //    std::cout << "type: "<< "\t" << order1.type << "\n";
    //    std::cout << "to : " << "\t" << order1.point_to << "\n";
    //}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
