#include <iostream>
#include "matricula.h"

class TaxCalculator {
    double tax_rate = 0;
public:
    explicit TaxCalculator(const double tax_rate): tax_rate(tax_rate) {}
    double calculate(double amount) {
        return tax_rate * amount;
    }
};

// Register o Plain Object
struct Product {
    std::string name;
    double price = 0;
    double tax = 0;
    Product(const std::string& name, double price): name(name), price(price) {}
};

class Invoice {
    std::vector<Product> productos;
public:
    void add_product(const Product& product) {
        productos.push_back(product);
    }
    void calculate_tax(TaxCalculator tcalc) {
        for (auto& product : productos) {
            product.tax = tcalc.calculate(product.price);
        }
    }
    void list_product() {
        for (auto& product : productos) {
            std::cout << product.name << " " << product.price << " " << product.tax << std::endl;
        }
    }
};

void ejemplo_seccion() {
    Course p2 ("CS1112", "Programacion II");
    Professor pf("123123", "Ruben Rivas");
    Laboratory lab("M804");
    Section s203("2.03", p2, lab, pf);
    Student s1("Maria", "Diaz");
    Student s2("Jose", "Perez");
    Student s3("Jesus", "Perez Diaz");
    s203.enroll(s1);
    s203.enroll(s2);
    s203.enroll(s3);
    s203.show_list();
}

void ejemplo_factura() {
    Invoice inv;
    TaxCalculator t_calc(0.18);
    inv.add_product({Product("Azucar", 10.5)});
    inv.add_product({Product("Arroz", 15.5)});
    inv.calculate_tax(t_calc);
    inv.list_product();
}
int main() {
    ejemplo_factura();
    return 0;
}
