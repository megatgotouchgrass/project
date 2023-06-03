#ifndef RESTAURANT_H
#define RESTAURANT_H
class Restaurant
{
private:
    int beverage;
    int food;

public:
    Restaurant(int B = 0, int F = 0)
    {
        beverage = B;
        food = F;
    }

    void setBeverage(int B)
    {
        beverage = B;
    }

    void setFood(int F)
    {
        food = F;
    }

    int getBeverage()
    {
        return beverage;
    }

    int getFood()
    {
        return food;
    }
};

class Bronco : public Restaurant
{
private:
    int priceFood;
    int price;

public:
    Bronco() {}

    void setPrice(int P)
    {
        priceFood = P;
    }

    void setPrice(int P)
    {
        priceFood = P;
    }

    int getPrice()
    {
        return price;
    }
};

#endif