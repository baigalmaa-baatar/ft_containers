#include <iostream>

class Item
{
private:
    int _itemID;
    int _quantity;
    double _price;

public:
    Item() : _itemID(5), _quantity(10), _price(2.0)
    {
    }
    ~Item()
    {
    }
    void setValue(void);
    void display(void)
    {
        std::cout << "Item is " << _itemID << ", quantity is " << _quantity << ", price is " << _price << '\n';
    }
};
void Item::setValue(void)
{
    std::cout << "Enter the itemID : ";
    std::cin >> _itemID;
    std::cout << "Enter the quantity : ";
    std::cin >> _quantity;
    std::cout << "Enter the price : ";
    std::cin >> _price;
}

int main()
{
    Item _item;
    _item.setValue();
    _item.display();
    return 0;
}