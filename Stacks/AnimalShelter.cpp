#include <iostream>
#include <map>
#include <list>
#include <type_traits>
#include <string>
using namespace std;

template <typename Base, typename T>
inline bool isInstanceof(const T *)
{
    return is_base_of<Base, T>::value;
}

class Animal
{
public:
    int order;
    string name;
    bool isdog = false;
    Animal(string name)
    {
        this->name = name;
    }

    void setOrder(int order)
    {
        this->order = order;
    }
    int getOrder()
    {
        return order;
    }

    bool isOrderOlderthan(Animal a)
    {
        return this->order < a.getOrder();
    }
    bool isdog()
    {
        return isdog;
    }
};

class Dog : Animal
{
public:
    Dog(string name) : Animal(name) { isdog = true; }
};

class Cat : Animal
{
public:
    Cat(string name) : Animal(name) {}
};

class Animalshelter
{
public:
    list<Dog> dogs;
    list<Cat> cats;

    int order = 0;

    void addAnimal(Animal a)
    {
        a.setOrder(order);
        order++;

        if (a.isdog())
        {
            dogs.push_back(a);
        }
        else
        {
            cats.push_back(a);
        }
    }

    void removeAny()
    {
        Dog dog = dogs.front();
        Cat cat = cats.front();

        if (dog.isOrderOlderthan(cat))
        {
            //dequeue dog
        }
        else if (cat.isOrderOlderthan(dog))
        {
            //dequeue cat
        }
    }

    void removeDog()
    {
        cout << "removing dog: ";
        //cout << dogs.front() << endl;
        dogs.pop_front();
    }

    void removeCat()
    {
        cout << "removing cat: ";
        //cout << cats.front().name << endl;
        cats.pop_front();
    }
};

int main()
{
    Animalshelter as;

    as.addAnimal(new Dog("shadow"));

    return 0;
}