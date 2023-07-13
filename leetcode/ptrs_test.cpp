#include <cassert>
#include <iostream>

using namespace std;


struct Car
{
    int doors;
    int *a;
    Car *next_car;
};

int main()
{
    Car car;
    car.doors = 5;

    
    cout << car.doors << "\n";
    cout <<"car_addr: "<< &car <<"\t" << "car.doors_addr: " << &car.doors << "\t" << "car.a" << car.a <<"\n";

    int a = 1;
    int* b = &a;
    car.a = &a;

    cout <<"car.a"<< car.a << "\n";
    
    *b = 2;
    cout <<*b<< "\n";
    Car *car_ptr = &car;
    car.next_car = car_ptr;
    car.next_car = new Car();
    car.next_car->doors = 10;

    Car **car3 = &car.next_car;
    cout << "car3_prt_prt: " <<car3 << "\n";
    cout << "car3_prt_deref: " << *car3 << "\n";
    cout << "car3_doors: " << (*car3)->doors <<"\n";
    
    cout << *(car_ptr->a) << "\n";
    cout << car.next_car->doors <<"\n";


}