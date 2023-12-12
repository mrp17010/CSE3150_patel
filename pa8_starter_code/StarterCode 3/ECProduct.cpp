#include "ECProduct.h"

using namespace std;

//Product functionality
Product::Product(int id, string name, double price): id_(id), name_(name), price_(price){}
int Product::getId() const {
    return id_;
}

string Product::getName() const{
    return name_;
}

double Product::getPrice() const{
    return price_;
}


//Book functionality (doing it first because that's what's in main)
//Electronics and clothing will be added later

Book::Book(int id, string name, double price, string author): Product(id, name, price), author_(author){}
Book::~Book(){}
string Book::getDescription() const
{
    return "Book: " + getName() + ", Author: "+ author_;
}


//Electronics functionality
Electronics::Electronics(int id, string name, double price, string specs): Product(id,name, price), specs_(specs){}
Electronics::~Electronics(){}
string Electronics::getDescription() const
{
    return "Electronic: " + getName() + ", Specs: "+ specs_;
}

//Clothing functionality
Clothing::Clothing(int id, string name, double price, string size): Product(id,name, price), size_(size){}
Clothing::~Clothing(){}
string Clothing::getDescription() const
{
    return "Clothing: " + getName() +", Size: "+ size_;
}