#include <iostream>
#include <string>
using namespace std;

class Trip {
public:
    string Flight;
    string Hotel;
    string Insurance;
    string Excursion;

    string ToString() {
        return "🌍 Ваша подорож:\n" +
               Flight + "\n" +
               Hotel + "\n" +
               Insurance + "\n" +
               Excursion + "\n";
    }
};

class TripBuilder {
protected:
    Trip* trip;

public:
    virtual ~TripBuilder() {
        delete trip;
    }

    void CreateNewTrip() {
        trip = new Trip();
    }

    Trip* GetTrip() {
        return trip;
    }

    virtual void BookFlight() = 0;
    virtual void BookHotel() = 0;
    virtual void IncludeInsurance() = 0;
    virtual void AddExcursion() = 0;
};

class RelaxTripBuilder : public TripBuilder {
public:
    void BookFlight() override {
        trip->Flight = "✈ Авіаквиток до Мальдів";
    }

    void BookHotel() override {
        trip->Hotel = "🏨 5-зірковий готель з видом на океан";
    }

    void IncludeInsurance() override {
        trip->Insurance = "🛡 Повна медична страховка";
    }

    void AddExcursion() override {
        trip->Excursion = "⛵ Прогулянка на яхті";
    }
};

class AdventureTripBuilder : public TripBuilder {
public:
    void BookFlight() override {
        trip->Flight = "✈ Авіаквиток до Перу";
    }

    void BookHotel() override {
        trip->Hotel = "🏕 Кемпінг біля Мачу-Пікчу";
    }

    void IncludeInsurance() override {
        trip->Insurance = "🛡 Страховка для екстремальних пригод";
    }

    void AddExcursion() override {
        trip->Excursion = "🧗‍♂️ Похід у гори";
    }
};


class TravelAgency {
private:
    TripBuilder* builder;

public:
    void SetTripBuilder(TripBuilder* b) {
        builder = b;
    }

    Trip* OrganizeTrip() {
        builder->CreateNewTrip();
        builder->BookFlight();
        builder->BookHotel();
        builder->IncludeInsurance();
        builder->AddExcursion();
        return builder->GetTrip();
    }
};


int main() {
    RelaxTripBuilder* builder = new RelaxTripBuilder();
    TravelAgency agency;
    agency.SetTripBuilder(builder);

    Trip* myTrip = agency.OrganizeTrip();
    cout << myTrip->ToString();

    delete builder;
    return 0;
}
