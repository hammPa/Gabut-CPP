#include <ostream>
#include <iostream>

template <typename Type, size_t size_arr>
class array {
public:
    array() {}
    
    template <typename... Args>
    array(Args... args) {
        push(args...);
    }
    
    ~array() {}

    const size_t size() const {
        return index;
    }

    size_t size(){
        return index;
    }

    size_t max_size(){
        return length;
    }

    void reallocate_with_sum_of_element(){
        length = index;
    }

    void push(Type value){
        if(index >= length){
            std::cerr << "Array is full\n";
            return;
        }
        data[index] = value;
        index++;
    }

    template <typename... Args>
    void push(Type value, Args... args){
        push(value);
        push(args...);
    }

    void pop(){
        if(index == 0){
            data[index] = 0;
        }
        else {
            index--;
            data[index] = 0;
        }
    }

    void swap(Type val1, Type val2){
        Type temp;
        temp = val1;
        val1 = val2;
        val2 = temp;
    }

    Type operator[](size_t index) const {
        if(index >= length){
            std::cerr << "ErrorIndexOutOfBound\n";
            return Type();
        }
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const array& arr){
        os << "[ ";
        for(int i = 0; i < arr.size(); i++){
            os << arr[i] << " ";
        }
        os << "]";
        return os;
    }

    Type front(){
        return data[0];
    }

    Type back(){
        return data[length - 1];
    }

    const Type front() const {
        return data[0];
    }

    const Type back() const {
        return data[length - 1];
    }


    const Type* begin() const {
        return &data[0];
    }

    const Type* end() const {
        return &data[length];
    }

    Type* begin() {
        return &data[0];
    }

    Type* end() {
        return &data[length];
    }

    void change(size_t index_to_change, Type value){
        if(index_to_change >= 0 && index_to_change < length){
            data[index_to_change] = value;
        }
        else {
            std::cerr << "Index Not Found\n";
        }
    }

    bool isEmpty(){
        if(index == 0 && data[0] == 0) return true;
        return false;
    }

    bool isFull(){
        if(index == length) return true;
        return false;
    }

    Type find_at_index(size_t index) const {
        return data[index];
    }

    int find(Type value){ // linear search
        for(size_t i = 0; i < index; i++){
            if(data[i] == value) return i;
        }
        return -1;
    }

    // binary search
    size_t binary_search(){

    }

    void delete_at(size_t index_to_delete){
        data[index_to_delete] = 0;
        for(int i = index_to_delete; i < index; i++){
            data[i] = data[i + 1];
            data[i + 1] = 0;
        }
        index--;
    }

    Type max(){
        Type maximum = data[0];
        for(int i = 1; i < index; i++){
            if(data[i] > maximum){
                maximum = data[i];
            }
        }
        return maximum;
    }

    Type min(){
        Type minimum = data[0];
        for(int i = 1; i < index; i++){
            if(data[i] < minimum){
                minimum = data[i];
            }
        }
        return minimum;
    }

    Type average(){
        Type ave = data[0];
        for(int i = 1; i < length; i++){
            ave += data[i];
        }
        ave = ave / length;
        return ave;
    }

    Type median(){
        array<Type, size_arr> temp = *this;
        temp.sort();
        int mid = (0 + size()) / 2;
        return data[mid];
    }

    // Type quartile1(){
    //     array<Type, size_arr> temp = *this;
    //     temp.sort();
    //     int first_quarter = (0 + index) / 4;
    //     return data[first_quarter];
    // }

    // Type quartile2(){
    //     return median();
    // }

    // Type quartile3(){
    //     array<Type, size_arr> temp = *this;
    //     temp.sort();
    //     int third_quarter = size() - ((0 + size()) / 4);
    //     return data[third_quarter];
    // }

    // Type quartile4(){
    //     array<Type, size_arr> temp = *this;
    //     temp.sort();
    //     int fourth_quarter = size();
    //     std::cout << temp;
    //     return data[fourth_quarter];
    // }

    template<size_t ukuran_temp = 100>
    Type mode(){
        array<Type, ukuran_temp> tempValue;
        array<Type, ukuran_temp> tempJumlah;
        
        for(size_t i = 0; i < index; i++){
            int jumlah = 1;
            for(size_t j = i; j < index; j++){
                if(data[j] == data[i]) jumlah++;
            }
            tempJumlah.push(jumlah);
            tempValue.push(data[i]);
        }
        
        int max_jumlah = tempJumlah.max(); // jumlah terbanyak
        int index = tempJumlah.find(max_jumlah); // index jumlah terbanyak
        int data_terbanyak = tempValue[index];

        return data_terbanyak;
    }

    bool contains(Type value){
        for(size_t i = 0; i < index; i++){
            if(data[i] == value) return true;
        }
        return false;
    }


    void delete_duplicate(){
        array<Type, 100> temp;
        for(int i = 0; i < length; i++){
            bool isDUplicate = false;

            for(int j = i + 1; j < length; j++){ // ambil satu angka di index, misal index 0, lalu setiap index di depannya di cek apakah sama dengan nilai pada index yang di plih
                if(data[i] == data[j]){ 
                    isDUplicate = true;
                    break;
                }
            }
            
            if(!isDUplicate){
                temp.push(data[i]);
            }
        }
        temp.reallocate_with_sum_of_element();
        for (int i = 0; i < temp.size(); i++) {
            data[i] = temp[i];
        }

        // Perbarui panjang array asli
        length = temp.size();
        index = length;
    }
    
    void sort() {
        if (index > 0) {
            quick_sort(0, index - 1);
        }
    }

    void clear(){
        for(int i = size(); i <= 0; i++){
            data[i] = 0;
        }
        index = 0;
    }

    template<size_t another_size>
    array<Type, size_arr + another_size> operator+(const array<Type, another_size>& anotherArr) const {
        array<Type, size_arr + another_size> new_arr;

        for (size_t i = 0; i < index; i++) {
            new_arr.push(data[i]);
        }

        for (size_t i = 0; i < anotherArr.size(); i++) {
            new_arr.push(anotherArr[i]);
        }

        return new_arr;
    }

    // array<Type, size_arr * scalar> operator*(const Type& scalar) const {
    //     array<Type, size_arr * scalar> result;

    //     for (size_t i = 0; i < scalar; i++) {
    //         for (size_t j = 0; j < index; j++) {
    //             result.push(data[j]);
    //         }
    //     }
    //     return result;
    // }


private:
    Type data[size_arr];
    size_t length = size_arr;
    size_t index = 0;

    void quick_sort(size_t low, size_t high) {
        if (low < high) {
            Type pivot = data[high];
            size_t i = low;

            for (size_t j = low; j < high; j++) {
                if (data[j] < pivot) {
                    std::swap(data[i], data[j]);
                    i++;
                }
            }
            swap(data[i], data[high]);

            quick_sort(low, i - 1);
            quick_sort(i + 1, high);
        }
    }
};
