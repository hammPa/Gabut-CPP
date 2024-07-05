#include <iostream>
#include <variant>
#include <type_traits>
#include <ostream>
#include <istream>
#include <iomanip>
#include <string>
#include <typeinfo>
#include <initializer_list>
#include <vector>
#include <exception>

class let {
private:
    std::variant<int, bool, float, double, char, std::string> data;
    std::vector<std::variant<int, bool, float, double, char, std::string>> arr;
public:
    class fitur {
    public:
        static void tampil(){
            std::cout << "____________________________________________________________________\n";
            std::cout << "|                                                                  |\n";
            std::cout << "|    Selamat datang di program class let dengan C++                |\n";
            std::cout << "|    Created by : hammPa                                           |\n";
            std::cout << "|    Dengan sedikit bantuan gpt                                    |\n";
            std::cout << "|                                                                  |\n";
            std::cout << "|    Berikut hal yang bisa di lakukan dengan let :                 |\n";
            std::cout << "|    1. Deklarasi variabel tipe data dasar                         |\n";
            std::cout << "|       Contoh : let angkaI = 10;                                  |\n";
            std::cout << "|              : let angkaF = 10.5f;                               |\n";
            std::cout << "|              : let angkaD = 10.4223322;                          |\n";
            std::cout << "|              : let huruf = 'c';                                  |\n";
            std::cout << "|              : let teks = \"hello world\";                         |\n";
            std::cout << "|                                                                  |\n";
            std::cout << "|    2. Operasi aritmatika                                         |\n";
            std::cout << "|       Contoh : let angkaI = 10;                                  |\n";
            std::cout << "|              : let angkaF = 10.5f;                               |\n";
            std::cout << "|              : let hasilJumlah = angkaI + angkaF;                |\n";
            std::cout << "|                                                                  |\n";
            std::cout << "|    3. Deklarasi array tipe data dasar ukuran dinamis :           |\n";
            std::cout << "|       Contoh : let array = {10, \"hello\", 'c', 5.5};              |\n";
            std::cout << "|                                                                  |\n";
            std::cout << "|    4. Memanggil variabel baik biasa maupun array                 |\n";
            std::cout << "|       Contoh : std::cout << angkaI <<  std::endl;                |\n";
            std::cout << "|              : std::cout << array << std::endl;                  |\n";
            std::cout << "|                                                                  |\n";
            std::cout << "|    5. Memanggil variabel array dengan index                      |\n";
            std::cout << "|       Contoh : std::cout << array[0] <<  std::endl;              |\n";
            std::cout << "|              : std::cout << array[1] <<  std::endl;              |\n";
            std::cout << "|                                                                  |\n";
            std::cout << "|    6. Membandingkan variabel array ataupun biasa                 |\n";
            std::cout << "|       Contoh : std::cout << (array1 == array2) <<  std::endl;    |\n";
            std::cout << "|              : std::cout << (array1 != array2) <<  std::endl;    |\n";
            std::cout << "|              : std::cout << (angka1 == angka2) <<  std::endl;    |\n";
            std::cout << "|              : std::cout << (angka1 != angka2) <<  std::endl;    |\n";
            std::cout << "|                                                                  |\n";
            std::cout << "|    7. Melakukan input ke data biasa                              |\n";
            std::cout << "|       Contoh : std::cin >> angka1                                |\n";
            std::cout << "|              : std::cin >> angka2                                |\n";
            std::cout << "|__________________________________________________________________|\n";
            std::cout << "\n";            
        }
    };

    // default constructor
    let() : data(0){}

    // number
    template<typename Type>
    let(Type mydata){
        if constexpr (std::is_same<Type, int>::value) data = mydata;
        else if constexpr (std::is_same<Type, bool>::value) data = mydata;
        else if constexpr (std::is_same<Type, float>::value) data = mydata;
        else if constexpr (std::is_same<Type, double>::value) data = mydata;
        else if constexpr (std::is_same<Type, char>::value)  data = mydata;
        else if constexpr (std::is_same<Type, const char*>::value)  data = std::string(mydata);
        else {
            // throw std::runtime_error(typeid(mydata).name());
            throw std::runtime_error("Unsupported type in let variant");
        }
        // throw std::runtime_error("Cannot assign value with constructor, using assignment instead");        
    }
    
    // array
    // template<typename Type>
    let(std::initializer_list<std::variant<int, bool, float, double, char, const char*>> mydata){
        for(const auto& item: mydata){
            if(std::holds_alternative<const char*>(item)){
                const char* str = std::get<const char*>(item);
                arr.push_back(std::string(str));         
            }
            else if(std::holds_alternative<int>(item)){
                arr.push_back(std::get<int>(item));
            }
            else if(std::holds_alternative<bool>(item)){
                arr.push_back(std::get<bool>(item));
            }
            else if(std::holds_alternative<float>(item)){
                arr.push_back(std::get<float>(item));
            }
            else if(std::holds_alternative<double>(item)){
                arr.push_back(std::get<double>(item));
            }
            else if(std::holds_alternative<char>(item)){
                arr.push_back(std::get<char>(item));
            }
            data = 0;
        }
    }

    void setData(){
        data = 0;
    }

    // get data number
    template<typename Type>
    Type getData() const {
        return std::get<Type>(data);
    }

    template<typename Type>
    let& operator=(const let& myLet){
        if(this != &myLet) data = myLet.data;
        return *this;
    }

    friend let operator+(const let& myLet1, const let& myLet2){
        // int int
        if (std::holds_alternative<int>(myLet1.data) && std::holds_alternative<int>(myLet2.data)) {
            int result = std::get<int>(myLet1.data) + std::get<int>(myLet2.data);
            return let(result);
        }
        // float float
        else if (std::holds_alternative<float>(myLet1.data) && std::holds_alternative<float>(myLet2.data)) {
            float result = std::get<float>(myLet1.data) + std::get<float>(myLet2.data);
            return let(result);
        }
        // double double
        else if (std::holds_alternative<double>(myLet1.data) && std::holds_alternative<double>(myLet2.data)) {
            double result = std::get<double>(myLet1.data) + std::get<double>(myLet2.data);
            return let(result);
        }
        // int double
        else if (std::holds_alternative<int>(myLet1.data) && std::holds_alternative<double>(myLet2.data)) {
            double result = std::get<int>(myLet1.data) + std::get<double>(myLet2.data);
            return let(result);
        }
        // double int
        else if (std::holds_alternative<double>(myLet1.data) && std::holds_alternative<int>(myLet2.data)) {
            double result = std::get<double>(myLet1.data) + std::get<int>(myLet2.data);
            return let(result);
        }
        // int float
        else if (std::holds_alternative<int>(myLet1.data) && std::holds_alternative<float>(myLet2.data)) {
            float result = std::get<int>(myLet1.data) + std::get<float>(myLet2.data);
            return let(result);
        }
        // float int
        else if (std::holds_alternative<float>(myLet1.data) && std::holds_alternative<int>(myLet2.data)) {
            float result = std::get<float>(myLet1.data) + std::get<int>(myLet2.data);
            return let(result);
        }
        else {
            throw std::runtime_error("Unsupported operation: Addition between incompatible types");
        }
    }

    // pengurangan
    friend let operator-(const let& myLet1, const let& myLet2){
        // int int
        if (std::holds_alternative<int>(myLet1.data) && std::holds_alternative<int>(myLet2.data)) {
            int result = std::get<int>(myLet1.data) - std::get<int>(myLet2.data);
            return let(result);
        }
        // float float
        else if (std::holds_alternative<float>(myLet1.data) && std::holds_alternative<float>(myLet2.data)) {
            float result = std::get<float>(myLet1.data) - std::get<float>(myLet2.data);
            return let(result);
        }
        // double double
        else if (std::holds_alternative<double>(myLet1.data) && std::holds_alternative<double>(myLet2.data)) {
            double result = std::get<double>(myLet1.data) - std::get<double>(myLet2.data);
            return let(result);
        }
        // int double
        else if (std::holds_alternative<int>(myLet1.data) && std::holds_alternative<double>(myLet2.data)) {
            double result = std::get<int>(myLet1.data) - std::get<double>(myLet2.data);
            return let(result);
        }
        // double int
        else if (std::holds_alternative<double>(myLet1.data) && std::holds_alternative<int>(myLet2.data)) {
            double result = std::get<double>(myLet1.data) - std::get<int>(myLet2.data);
            return let(result);
        }
        // int float
        else if (std::holds_alternative<int>(myLet1.data) && std::holds_alternative<float>(myLet2.data)) {
            float result = std::get<int>(myLet1.data) - std::get<float>(myLet2.data);
            return let(result);
        }
        // float int
        else if (std::holds_alternative<float>(myLet1.data) && std::holds_alternative<int>(myLet2.data)) {
            float result = std::get<float>(myLet1.data) - std::get<int>(myLet2.data);
            return let(result);
        }
        else {
            throw std::runtime_error("Unsupported operation: Addition between incompatible types");
        }
    }

    // perkalian
    friend let operator*(const let& myLet1, const let& myLet2){
        // int int
        if (std::holds_alternative<int>(myLet1.data) && std::holds_alternative<int>(myLet2.data)) {
            int result = std::get<int>(myLet1.data) * std::get<int>(myLet2.data);
            return let(result);
        }
        // float float
        else if (std::holds_alternative<float>(myLet1.data) && std::holds_alternative<float>(myLet2.data)) {
            float result = std::get<float>(myLet1.data) * std::get<float>(myLet2.data);
            return let(result);
        }
        // double double
        else if (std::holds_alternative<double>(myLet1.data) && std::holds_alternative<double>(myLet2.data)) {
            double result = std::get<double>(myLet1.data) * std::get<double>(myLet2.data);
            return let(result);
        }
        // int double
        else if (std::holds_alternative<int>(myLet1.data) && std::holds_alternative<double>(myLet2.data)) {
            double result = std::get<int>(myLet1.data) * std::get<double>(myLet2.data);
            return let(result);
        }
        // double int
        else if (std::holds_alternative<double>(myLet1.data) && std::holds_alternative<int>(myLet2.data)) {
            double result = std::get<double>(myLet1.data) * std::get<int>(myLet2.data);
            return let(result);
        }
        // int float
        else if (std::holds_alternative<int>(myLet1.data) && std::holds_alternative<float>(myLet2.data)) {
            float result = std::get<int>(myLet1.data) * std::get<float>(myLet2.data);
            return let(result);
        }
        // float int
        else if (std::holds_alternative<float>(myLet1.data) && std::holds_alternative<int>(myLet2.data)) {
            float result = std::get<float>(myLet1.data) * std::get<int>(myLet2.data);
            return let(result);
        }
        else {
            throw std::runtime_error("Unsupported operation: Addition between incompatible types");
        }
    }

    // pembagian
    friend let operator/(const let& myLet1, const let& myLet2){
        // int int
        if (std::holds_alternative<int>(myLet1.data) && std::holds_alternative<int>(myLet2.data)) {
            int result = std::get<int>(myLet1.data) / std::get<int>(myLet2.data);
            return let(result);
        }
        // float float
        else if (std::holds_alternative<float>(myLet1.data) && std::holds_alternative<float>(myLet2.data)) {
            float result = std::get<float>(myLet1.data) / std::get<float>(myLet2.data);
            return let(result);
        }
        // double double
        else if (std::holds_alternative<double>(myLet1.data) && std::holds_alternative<double>(myLet2.data)) {
            double result = std::get<double>(myLet1.data) / std::get<double>(myLet2.data);
            return let(result);
        }
        // int double
        else if (std::holds_alternative<int>(myLet1.data) && std::holds_alternative<double>(myLet2.data)) {
            double result = std::get<int>(myLet1.data) / std::get<double>(myLet2.data);
            return let(result);
        }
        // double int
        else if (std::holds_alternative<double>(myLet1.data) && std::holds_alternative<int>(myLet2.data)) {
            double result = std::get<double>(myLet1.data) / std::get<int>(myLet2.data);
            return let(result);
        }
        // int float
        else if (std::holds_alternative<int>(myLet1.data) && std::holds_alternative<float>(myLet2.data)) {
            float result = std::get<int>(myLet1.data) / std::get<float>(myLet2.data);
            return let(result);
        }
        // float int
        else if (std::holds_alternative<float>(myLet1.data) && std::holds_alternative<int>(myLet2.data)) {
            float result = std::get<float>(myLet1.data) / std::get<int>(myLet2.data);
            return let(result);
        }
        else {
            throw std::runtime_error("Unsupported operation: Addition between incompatible types");
        }
    }

    // method untuk array
    template<typename Type>
    void push_back(Type newData){
        arr.push_back(newData);
    }

    int size(){
        return arr.size();
    }

    void pop_back(){
        arr.pop_back();
    }

    // fungsi membandingkan 
    template<typename Type>
    bool checkIsSame(const let& other) const {
        if(arr.empty() && other.arr.empty()){ /// jika data tunggal
            if(std::holds_alternative<Type>(data) && std::holds_alternative<Type>(other.data)) { //cek  apa tipe datanya sama
                if(std::get<Type>(data) == std::get<Type>(other.data)) return true;
                return false;
            }
        }
        // jika data array
        int jumlah_sama = 0;
        for(int index = 0; index < arr.size(); index++){
            if(std::get<Type>(arr.at(index)) ==  std::get<Type>(other.arr.at(index))){ // jika data per_index sama
                jumlah_sama++;
            }
        }
        if(jumlah_sama == arr.size()) return true;
        return false;
    }

    // untuk pembanding nilai baik data maupun array
    friend let operator==(const let& myLet1, const let& myLet2){
        // cek data tunggal
        bool result;
        if (std::holds_alternative<int>(myLet2.data)){ // jika tipenya int
            result = myLet1.checkIsSame<int>(myLet2); // cek dan kembalikan boolean
        }
        else if (std::holds_alternative<float>(myLet2.data)){
            result = myLet1.checkIsSame<float>(myLet2);
        }
        else if (std::holds_alternative<double>(myLet2.data)){
            result = myLet1.checkIsSame<double>(myLet2);
        }
        else if (std::holds_alternative<char>(myLet2.data)){
            result = myLet1.checkIsSame<char>(myLet2);
        }
        else if (std::holds_alternative<std::string>(myLet2.data)){
            result = myLet1.checkIsSame<std::string>(myLet2);
        }

        return (result ? let(true) : let(false));
        // cek array
    }
    
    // untuk pembanding nilai TIDAK SAMA baik data maupun array : HANYA BEDA DI RETURN 
    friend let operator!=(const let& myLet1, const let& myLet2){
        // cek data tunggal
        bool result;
        if (std::holds_alternative<int>(myLet2.data)){ // jika tipenya int
            result = myLet1.checkIsSame<int>(myLet2); // cek dan kembalikan boolean
        }
        else if (std::holds_alternative<float>(myLet2.data)){
            result = myLet1.checkIsSame<float>(myLet2);
        }
        else if (std::holds_alternative<double>(myLet2.data)){
            result = myLet1.checkIsSame<double>(myLet2);
        }
        else if (std::holds_alternative<char>(myLet2.data)){
            result = myLet1.checkIsSame<char>(myLet2);
        }
        else if (std::holds_alternative<std::string>(myLet2.data)){
            result = myLet1.checkIsSame<std::string>(myLet2);
        }

        return (result ? let(false) : let(true));
        // cek array
    }

    // output number dan array
    friend std::ostream& operator<<(std::ostream& os, const let& myLet) {
        if(myLet.arr.empty()){ // jika array kosong
            if(std::holds_alternative<bool>(myLet.data)){ // jika cek bool
                if(std::get<bool>(myLet.data) == true) os << "true";
                else os << "false";
            }
            else { // jika tampilkan yang biasa
                if (!std::holds_alternative<int>(myLet.data) || std::get<int>(myLet.data) != 0) {
                    if (std::holds_alternative<int>(myLet.data)) {
                        os << std::get<int>(myLet.data) << " (" << typeid(std::get<int>(myLet.data)).name() << ")";
                    } else if (std::holds_alternative<float>(myLet.data)) {
                        os << std::get<float>(myLet.data) << " (" << typeid(std::get<float>(myLet.data)).name() << ")";
                    } else if (std::holds_alternative<double>(myLet.data)) {
                        os << std::fixed << std::setprecision(10) << std::get<double>(myLet.data) << " (" << typeid(std::get<double>(myLet.data)).name() << ")";
                    } else if (std::holds_alternative<char>(myLet.data)) {
                        os << std::get<char>(myLet.data) << " (" << typeid(std::get<char>(myLet.data)).name() << ")";
                    } else if (std::holds_alternative<std::string>(myLet.data)) {
                        os << std::get<std::string>(myLet.data) << " (std::string)";
                    } else {
                        throw std::runtime_error("Unsupported type in let variant");
                    }
                }
            }
        }
        else { // jika array tidak kosong
            if(std::holds_alternative<int>(myLet.data) && std::get<int>(myLet.data) == 0){ // jika int dan nilainya 0
                os << "{ ";
                for (const auto& item : myLet.arr) {
                    if (std::holds_alternative<int>(item)) {
                        os << std::get<int>(item) << " ";
                    }
                    else if (std::holds_alternative<float>(item)) {
                        os << std::get<float>(item) << " ";
                    }
                    else if (std::holds_alternative<double>(item)) {
                        os << std::fixed << std::setprecision(10) << std::get<double>(item) << " ";
                    }
                    else if (std::holds_alternative<char>(item)) {
                        os << std::get<char>(item) << " ";
                    }
                    else if (std::holds_alternative<std::string>(item)) {
                        os << std::get<std::string>(item) << " ";
                    }
                }
                os << "}";
            }
        }
        return os;
    }

    // untuk input number
    friend std::istream& operator>>(std::istream& input, let& myLet){
        std::string token;
        input >> token;
     
        try {
            // coba token sebagai boolean
            if (token == "true" || token == "false") {
                myLet.data = (token == "true");
                return input;
            }
            // jika bukan bool coba int
            else {
                char char_to_find = '.';
                size_t position = token.find(char_to_find);
                // jika ditemukan titik
                if(position != std::string::npos){
                    char_to_find = 'f';
                    position = token.find('f');
                    // jika ditemukan f maka dia float
                    if(position != std::string::npos){
                        myLet.data = std::stof(token);
                        return input;
                    }
                    else { // jika  tidak maka dia double
                        myLet.data = std::stod(token);
                        return input;
                    }
                }

                // jika tidak  ditemukan titik berarti int
                myLet.data = stoi(token);
                return input;
            }
        } catch (const std::invalid_argument&) {
            // Token bukan boolean atau int, coba sebagai float
            if (token.size() == 1) {
                myLet.data = token[0];
                return input;
            } else {
                // Token bukan char, coba sebagai string
                myLet.data = token;
                return input;
            }
        }
    }

    let operator[](std::size_t index) {
        if(index >= arr.size()){
            throw std::runtime_error("Index not found");
        }

        std::variant<int, bool, float, double, char, std::string>& item = arr[index];

        // Gunakan konstruktor untuk menginisialisasi let dengan nilai dari variant yang sesuai
        if (std::holds_alternative<int>(item)) {
            return let(std::get<int>(item));
        } else if (std::holds_alternative<bool>(data)) {
            return let(std::get<bool>(item));
        } else if (std::holds_alternative<float>(item)) {
            return let(std::get<float>(item));
        } else if (std::holds_alternative<double>(item)) {
            return let(std::get<double>(item));
        } else if (std::holds_alternative<char>(item)) {
            return let(std::get<char>(item));
        } else if (std::holds_alternative<std::string>(item)) { // ubah dulu ke const char*
            const char *temp = std::get<std::string>(item).c_str();
            return let(temp);
        } else {
            throw std::runtime_error("Unsupported type in let variant");
        }
    }

    void forEach(void (*func)(let)){
        for(int index = 0; index < arr.size(); index++){
            std::variant<int, bool, float, double, char, std::string>& data = arr[index];
            if (std::holds_alternative<int>(data)) {
                func(let(std::get<int>(data)));
            } else if (std::holds_alternative<bool>(data)) {
                func(let(std::get<bool>(data)));
            } else if (std::holds_alternative<float>(data)) {
                func(let(std::get<float>(data)));
            } else if (std::holds_alternative<double>(data)) {
                func(let(std::get<double>(data)));
            } else if (std::holds_alternative<char>(data)) {
                func(let(std::get<char>(data)));
            } else if (std::holds_alternative<std::string>(data)) { // ubah dulu ke const char*
                const char *temp = std::get<std::string>(data).c_str();
                func(let(temp));
            } else {
                throw std::runtime_error("Ntahlah, ga kebaca dia");
            }
        }
    }
};

