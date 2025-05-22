#include "Bank.h"
#include "CustomerVIP.h"
#include <iostream>
#include <limits>
#include <filesystem>
#include <memory>

namespace fs = std::filesystem;

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showMenu() {
    std::cout << "\n1. Dodaj klienta\n"
              << "2. Zasil konto\n"
              << "3. Wypłać z konta\n"
              << "4. Przelej między kontami\n"
              << "5. Nalicz oprocentowanie\n"
              << "6. Wyświetl wszystkich klientów\n"
              << "7. Wyszukaj klienta po ID\n"
              << "8. Zakończ\n"
              << "Wybierz opcję: ";
}

std::unique_ptr<Customer> createCustomerFromInput() {
    int id;
    std::string firstName, lastName;
    double balance, rate;

    std::cout << "ID: "; std::cin >> id;
    std::cout << "Imię: "; std::cin >> firstName;
    std::cout << "Nazwisko: "; std::cin >> lastName;
    std::cout << "Saldo: "; std::cin >> balance;
    std::cout << "Oprocentowanie: "; std::cin >> rate;

    std::cout << "Czy klient jest VIP? (1 - tak, 0 - nie): ";
    int isVip;
    std::cin >> isVip;

    if (isVip == 1) {
        double additionalRate;
        std::cout << "Dodatkowe oprocentowanie VIP: ";
        std::cin >> additionalRate;
        return std::make_unique<CustomerVIP>(id, firstName, lastName, balance, rate, additionalRate);
    }

    return std::make_unique<Customer>(id, firstName, lastName, balance, rate);
}

int main() {
    Bank bank("customers.dat");

    if (fs::exists("customers.dat")) {
        bank.loadCustomers();
    } else {
        std::cout << "Brak pliku danych. Dodaj pierwszego klienta.\n";
        bank.addCustomer(createCustomerFromInput());
    }

    while (true) {
        showMenu();
        int option;
        std::cin >> option;

        if (std::cin.fail()) {
            std::cout << "Nieprawidłowy wybór. Spróbuj ponownie.\n";
            clearInput();
            continue;
        }

        switch (option) {
            case 1: {
                bank.addCustomer(createCustomerFromInput());
                break;
            }
            case 2: {
                int id;
                double amount;
                std::cout << "ID klienta: "; std::cin >> id;
                std::cout << "Kwota: "; std::cin >> amount;
                Customer* customer = bank.findCustomer(id);
                if (customer) customer->deposit(amount);
                else std::cout << "Nie znaleziono klienta.\n";
                break;
            }
            case 3: {
                int id;
                double amount;
                std::cout << "ID klienta: "; std::cin >> id;
                std::cout << "Kwota: "; std::cin >> amount;
                Customer* customer = bank.findCustomer(id);
                if (customer) {
                    if (!customer->withdraw(amount)) {
                        std::cout << "Niewystarczające środki.\n";
                    }
                } else {
                    std::cout << "Nie znaleziono klienta.\n";
                }
                break;
            }
            case 4: {
                int from, to;
                double amount;
                std::cout << "Z ID: "; std::cin >> from;
                std::cout << "Do ID: "; std::cin >> to;
                std::cout << "Kwota: "; std::cin >> amount;
                if (!bank.transfer(from, to, amount)) {
                    std::cout << "Błąd przelewu.\n";
                }
                break;
            }
            case 5:
                bank.calculateAllInterest();
                std::cout << "Oprocentowanie naliczone.\n";
                break;
            case 6:
                bank.listCustomers();
                break;
            case 7: {
                int id;
                std::cout << "ID klienta: "; std::cin >> id;
                Customer* customer = bank.findCustomer(id);
                if (customer) customer->display();
                else std::cout << "Nie znaleziono klienta.\n";
                break;
            }
            case 8:
                bank.saveCustomers();
                std::cout << "Zapisano dane. Do widzenia.\n";
                return 0;
            default:
                std::cout << "Nieprawidłowa opcja.\n";
        }
    }

    return 0;
}
