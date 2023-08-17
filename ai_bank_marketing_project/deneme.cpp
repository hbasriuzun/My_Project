#include <bits/stdc++.h>
#include <fstream>

class Customer {
public:
    int age;
    std::string job;
    std::string marital;
    std::string education;
    std::string default_status;
    std::string housing;
    std::string loan;
    std::string contact;
    std::string month;
    std::string day_of_week;
    int duration;
    int campaign;
    int pdays;
    int previous;
    std::string poutcome;
    float emp_var_rate;
    float cons_price_idx;
    float cons_conf_idx;
    float euribor3m;
    int nr_employed;
    std::string y;
};

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream file("bank-additional-full.csv");
    if (!file.is_open()) {
        std::cerr << "Dosya açılamadı." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Başlık satırını oku ve atla

    std::vector<Customer> customers;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ';')) {
            tokens.push_back(token);
        }

        Customer customer;
        customer.age = std::stoi(tokens[0]);
        customer.job = tokens[1];
        customer.marital = tokens[2];
        customer.education = tokens[3];
        customer.default_status = tokens[4];
        customer.housing = tokens[5];
        customer.loan = tokens[6];
        customer.contact = tokens[7];
        customer.month = tokens[8];
        customer.day_of_week = tokens[9];
        customer.duration = std::stoi(tokens[10]);
        customer.campaign = std::stoi(tokens[11]);
        customer.pdays = std::stoi(tokens[12]);
        customer.previous = std::stoi(tokens[13]);
        customer.poutcome = tokens[14];
        customer.emp_var_rate = std::stof(tokens[15]);
        customer.cons_price_idx = std::stof(tokens[16]);
        customer.cons_conf_idx = std::stof(tokens[17]);
        customer.euribor3m = std::stof(tokens[18]);
        customer.nr_employed = std::stoi(tokens[19]);
        customer.y = tokens[20];

        customers.push_back(customer);
    }

    file.close();
    int count = 0,i=0;

    // Okunan verileri işleme ve çıktı üretme
    for ( Customer& customer : customers) {
        
        // if(customer.y == "yes")
        //     customer.y = (std::string)"1";
        // else
        //     customer.y = (std::string)"0";
        
        // if(customer.y == "yes" && customer.previous > 0){
        //     count++;
        //     std::cout << i << count << ". Müşteri" << std::endl;
        // }
        std::cout<< "i number:" << i << "customer: " << customer.y << ",slm" << customer.previous << std::endl;
        i++;
        // Diğer verileri de benzer şekilde yazdırabilirsiniz
    }
    std::cout << "Önceki kampanya ile iletişime geçilen müşteri sayısı: " << count << std::endl; 
    auto end = std::chrono::high_resolution_clock::now();

    // Zaman farkını hesaplayın
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << "Geçen süre: " << duration << " mikrosaniye" << std::endl;

    return 0;
}