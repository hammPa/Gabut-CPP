#include <iostream>
namespace hamm {
    template <typename T, int size>
    class array {
    private:
        T *data;
        int index = 0;
    public:
        array(){
            data = new T[size];
            for(int i = 0; i < index; i++){
                if(typeid(T) == typeid(int)) this->data[i] = 0;
                // else if(typeid(T) == typeid(std::string)) this->data[i] = " ";
                // else if(typeid(T) == typeid(char)) this->data[i] = ' ';
            }
        }

        void push(T data){
            this->data[index] = data;
            index++;
        }

        void pop(){
            this->data[index] = 0;
            index--;
        }

        // int at(int target){
        //     for(int i = 0; i < this->index; i++){
        //         if(i == target){
        //             return this->data[i];
        //         }
        //     }
        // }

        void display(){
            std::cout << "[ ";
            for(int i = 0; i < this->index; i++){
                std::cout << this->data[i] << " ";
            }
            std::cout << "]";
            std::cout << "\n";
        }

        void forEach(void (*func)(int element)){
            for(int i = 0; i < this->index; i++){
                func(this->data[i]);
            }
        }

        array map(T (*func)(int element)){
            array<T, 10> newArr;
            for(int i = 0; i < this->index; i++){
                newArr.push(func(this->data[i]));
            }
            return newArr;
        }

        void sort(){
            for(int i = 0; i < this->index; i++){
                for(int j = i + 1; j < this->index; j++){
                    if(this->data[j] < this->data[i]){ // ascending
                        int temp = this->data[j];
                        this->data[j] = this->data[i];
                        this->data[i] = temp;
                    }
                }
            }
        }

        void sort(int(*func)(int first, int second)){
            for(int i = 0; i < this->index; i++){
                for(int j = i + 1; j < this->index; j++){
                    if(func(this->data[i], this->data[i + 1]) > 0){ // ascending
                        int temp = this->data[i];
                        this->data[i] = this->data[j];
                        this->data[j] = temp;
                    }
                }
            }
        }
    };
};
