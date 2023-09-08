#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main() {
    // Veriyi oku ve vektörde depola
    std::ifstream dosya("loan.csv");
    std::vector<std::string> veri;
    std::string satir;

    while (std::getline(dosya, satir)) {
        veri.push_back(satir);
    }
    dosya.close();

    cout << "Veri boyutu: " << veri.size() << endl;

    // Veriyi 1/10'unu ayır ve ayrı bir dosyaya kaydet
    std::ofstream ayrilanDosya("ayrilan_veri.csv");
    int ayrilanBoyut = veri.size() / 10;

    for (int i = 0; i < ayrilanBoyut; i++) {
        ayrilanDosya << veri[i] << std::endl;
    }
    cout << "Ayrilan veri boyutu: " << ayrilanBoyut << endl;
    ayrilanDosya.close();

    // Geri kalan 9/10'unu ayır ve ayrı bir dosyaya kaydet
    std::ofstream geriKalanDosya("geri_kalan_veri.csv");

    for (int i = ayrilanBoyut; i < veri.size(); i++) {
        geriKalanDosya << veri[i] << std::endl;
    }
    cout << "Geri kalan veri boyutu: " << veri.size() - ayrilanBoyut << endl;
    geriKalanDosya.close();
}