#include <iostream>
#include <string>
using namespace std;

class Kitchen {
public:
    int PreparePizza() {
        cout << "🍕 Готуємо піцу...\n";
        return 200;
    }
    int PrepareSalad() {
        cout << "🥗 Готуємо салат...\n";
        return 100;
    }
};

class DeliveryService {
public:
    int DeliverToAddress(const string& address) {
        cout << "🚚 Доставляємо за адресою: " << address << endl;
        return 50;
    }
};

class PaymentSystem {
public:
    void PayOnline(int amount) {
        cout << "💳 Оплата онлайн: " << amount << " грн\n";
    }
};


class FoodOrderFacade {
private:
    Kitchen kitchen;
    DeliveryService delivery;
    PaymentSystem payment;

public:
    int OrderFullDinner(const string& address) {
        int pizzaPrice = kitchen.PreparePizza();
        int saladPrice = kitchen.PrepareSalad();
        int deliveryPrice = delivery.DeliverToAddress(address);
        int total = pizzaPrice + saladPrice + deliveryPrice;
        payment.PayOnline(total);
        return total;
    }

    int OrderOnlyPizza(const string& address) {
        int pizzaPrice = kitchen.PreparePizza();
        int deliveryPrice = delivery.DeliverToAddress(address);
        int total = pizzaPrice + deliveryPrice;
        payment.PayOnline(total);
        return total;
    }
};

int main() {
    FoodOrderFacade order;
    int totalPrice = order.OrderFullDinner("вул. Незалежності, 12");
    cout << "Загальна вартість замовлення: " << totalPrice << " грн\n";
    return 0;
}
