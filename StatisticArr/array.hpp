#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <algorithm>
#include <ostream>
#include <iostream>
#include <functional>

enum SortType { QUICK_SORT, BUBBLE_SORT };
template <typename Type, size_t size_arr>
class array {
public:
    array() {}
    
    template <typename... Args>
    array(Args... args) { // push banyak data
        push(args...);
    }
    
    ~array() {}

    // ukuran
    size_t size() { return index; };
    const size_t size() const { return index; }

    // ukuran max
    size_t max_size() { return length; }
    const size_t max_size() const { return length; }

    void reallocate_with_sum_of_element(){ // mengubah ukuran dengan jumlah element
        length = index;
    }

    void push(Type value){ // push 1 data
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

    void pop(){ // hapus 1 data
        if(index == 0) data[index] = 0;
        else {
            index--;
            data[index] = 0;
        }
    }

    void swap(Type val1, Type val2){ // indahkan nilainya
        Type temp;
        temp = val1;
        val1 = val2;
        val2 = temp;
    }

    const Type operator[](size_t index) const { // operator index
        if(index >= length)
            throw std::out_of_range("ErrorIndexOutOfBound\n");
        return data[index];
    }
    
    Type operator[](size_t index){ // operator index
        if(index >= length)
            throw std::out_of_range("ErrorIndexOutOfBound\n");
        return data[index];
    }

    Type at(size_t index){ // operator index
        if(index >= length)
            throw std::out_of_range("ErrorIndexOutOfBound\n");
        return data[index];
    }
    
    const Type at(size_t index) const { // operator index
        if(index >= length)
            throw std::out_of_range("ErrorIndexOutOfBound\n");
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

    // element pertama
    Type front() { return data[0]; }
    const Type front() const { return data[0]; }

    // element terakhir
    Type back() { return data[length - 1]; }
    const Type back() const { return data[length - 1]; }

    void change(size_t index_to_change, Type value){ // mengubah nilai index ke n
        if(index_to_change >= 0 && index_to_change < length){
            data[index_to_change] = value;
        }
        else {
            std::cerr << "Index Not Found\n";
        }
    }

    bool isEmpty() const { // cek kosong
        if(index == 0 && data[0] == 0) return true;
        return false;
    }

    bool isFull() const { // cek full
        if(index == length) return true;
        return false;
    }

    // temukan data di index ke n
    Type find_at_index(size_t index) { return data[index]; }
    const Type find_at_index(size_t index) const { return data[index]; }

    int find(Type value){ // linear search
        for(size_t i = 0; i < index; i++){
            if(data[i] == value) return i;
        }
        return -1;
    }

    void delete_at(size_t index_to_delete){ // hapus di indexx tertentu
        data[index_to_delete] = 0;
        for(int i = index_to_delete; i < index; i++){
            data[i] = data[i + 1];
            data[i + 1] = 0;
        }
        index--;
    }

    Type max() const { // nilai maksimum
        Type maximum = data[0];
        for(int i = 1; i < index; i++){
            if(data[i] > maximum){
                maximum = data[i];
            }
        }
        return maximum;
    }

    Type min() const { // nilai minimum
        Type minimum = data[0];
        for(int i = 1; i < index; i++){
            if(data[i] < minimum){
                minimum = data[i];
            }
        }
        return minimum;
    }

    Type average() const { // rata rata
        Type ave = data[0];
        for(int i = 1; i < length; i++){
            ave += data[i];
        }
        ave = ave / length;
        return ave;
    }

    Type median() const { // nilai tengah
        array<Type, size_arr> temp = *this;
        temp.sort(SortType::BUBBLE_SORT);
        int mid = (0 + size()) / 2;
        return data[mid];
    }

    Type quartile1() {
        array<Type, size_arr> temp = *this;
        temp.sort(SortType::BUBBLE_SORT);  // Urutkan dulu
        size_t first_quarter = size_arr / 4;
        return temp[first_quarter];  // Ambil dari temp, bukan data
    }

    Type quartile2() {
        return median();  // Kuartil kedua sama dengan median
    }

    Type quartile3() {
        array<Type, size_arr> temp = *this;
        temp.sort(SortType::BUBBLE_SORT);
        size_t third_quarter = (size_arr * 3) / 4;
        return temp[third_quarter];
    }

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

    // isi semua dengan nilai
    void fill(const Type& value){
        for(size_t i = 0; i < size_arr; i++){
            data[i] = value;
        }
    }

    template <typename Func>
    Type reduce(Func op, Type init) {
        Type result = init;
        for (size_t i = 0; i < size_arr; i++) {
            result = op(result, data[i]);
        }
        return result;
    }

    bool contains(Type value){ // apakah ada nilai n di array
        for(size_t i = 0; i < index; i++){
            if(data[i] == value) return true;
        }
        return false;
    }


    void delete_duplicate(){ // hapus nilai yang sama
        array<Type, 100> temp;
        for(int i = 0; i < length; i++){
            bool isDuplicate = false;

            for(int j = i + 1; j < length; j++){ // ambil satu angka di index, misal index 0, lalu setiap index di depannya di cek apakah sama dengan nilai pada index yang di plih
                if(data[i] == data[j]){ 
                    isDuplicate = true;
                    break;
                }
            }
            
            if(!isDuplicate){
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

    void clear(){ // kosongkan semua element
        for(int i = size(); i <= 0; i++){
            data[i] = 0;
        }
        index = 0;
    }

    bool operator==(const array<Type, size_arr>& other) const { // menyamakan nilai semua elemen
        if(index != other.index) return false;
        for(size_t i = 0; i < index; i++){
            if(data[i] != other.data[i]) return false;
        }
        return true;
    }

    template<size_t another_size>
    array<Type, size_arr + another_size> operator+(const array<Type, another_size>& anotherArr) const { // gabungkan 2 array
        array<Type, size_arr + another_size> new_arr;

        for (size_t i = 0; i < index; i++) {
            new_arr.push(data[i]);
        }

        for (size_t i = 0; i < anotherArr.size(); i++) {
            new_arr.push(anotherArr[i]);
        }

        return new_arr;
    }

    array<Type, size_arr> filter(std::function<bool(Type)> predicate) const {
        array<Type, size_arr> result;
        for(size_t i = 0; i < index; i++){
            if(predicate(data[i])) result.push(data[i]);
        }
        return result;
    }

    void forEach(std::function<void(Type&)> callback){
        for(size_t i = 0; i < index; i++){
            callback(data[i]);
        }
    }

    bool some(std::function<void(Type&)> predicate){
        for(size_t i = 0; i < index; i++){
            if(predicate(data[i])) return true;
        }
        return false;
    }

    bool every(std::function<void(const Type&)> predicate){
        for(size_t i = 0; i < index; i++){
            if(!predicate(data[i])) return false;
        }
        return true;
    }

    array<Type, size_arr> operator-(Type value) const { // menghapus elemen dari array
        array<Type, size_arr> newArr;
        for (size_t i = 0; i < index; i++) {
            if (data[i] != value) {
                newArr.push(data[i]);
            }
        }
        return newArr;
    }

    array<Type, size_arr> operator*(Type value) const { // mengalikan elemen dari array
        array<Type, size_arr> newArr;
        for (size_t i = 0; i < index; i++) {
            newArr.push(data[i] * value);
        }
        return newArr;
    }

    void sort(SortType type) {
        switch (type) {
            case SortType::QUICK_SORT:
                quick_sort(0, index - 1);
                break;
            case SortType::BUBBLE_SORT:
                bubble_sort();
                break;
        }
    }

    // Binary Search (hanya untuk array yang sudah terurut)
    int binary_search(Type target) {
        size_t low = 0, high = size_arr - 1;
        while (low <= high) {
            size_t mid = low + (high - low) / 2;
            if (data[mid] == target) return mid; // Ditemukan
            else if (data[mid] < target) low = mid + 1; // Cari di kanan
            else high = mid - 1; // Cari di kiri
        }
        return -1; // Tidak ditemukan
    }

    void reverse() {
        size_t left = 0, right = index - 1;
        while (left < right) {
            std::swap(data[left], data[right]);
            left++;
            right--;
        }
    }

    int linear_search(Type target) {
        for (size_t i = 0; i < size_arr; i++) {
            if (data[i] == target) return i;
        }
        return -1;
    }


    class Iterator {
    private:
        Type* ptr;
    public:
        Iterator(Type* p) : ptr(p) {}

        Type& operator*() { return *ptr; }
        Iterator& operator++() { ptr++; return *this; }
        Iterator& operator++(int) { Iterator temp = *this; ++(*this); return temp; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    // alamat pertama
    Iterator begin() { return Iterator(data); }
    const Iterator begin() const { return Iterator(data); }
    // alamat terakhir
    Iterator end() { return Iterator(data + index); }
    const Iterator end() const { return Iterator(data + index); }


private:
    Type data[size_arr];
    size_t length = size_arr;
    size_t index = 0;

    void quick_sort(size_t low, size_t high) {
        if (low < high) return;

        Type pivot = data[high];
        size_t i = low;
        for (size_t j = low; j < high; j++) {
            if (data[j] < pivot) {
                std::swap(data[i], data[j]);
                i++;
            }
        }
        swap(data[i], data[high]);

        if(i > 0) quick_sort(low, i - 1);
        quick_sort(i + 1, high);
    }

    void bubble_sort() {
        bool swapped;
        for (size_t i = 0; i < index - 1; i++) {
            swapped = false;
            for (size_t j = 0; j < index - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                    swapped = true;
                }
            }
            // Jika tidak ada elemen yang ditukar, array sudah terurut
            if (!swapped) {
                break;
            }
        }
    }
};

#endif
