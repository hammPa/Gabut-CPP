#include <iostream>
#include <string>

namespace std {
    namespace hamm {
        struct Array {
            void* value;
            string type;
        };

        class DynamicArray {
        private:
            int index = 0;
            struct Array arr[100];

        public:
            DynamicArray(){}

            template <typename T, typename... Args>
            void push(T param, Args... args){
                T* temp = new T; // alokasi
                *temp = param;
                arr[index].value = temp; // memori tipe data ditunjuk void
                if (typeid(T) == typeid(int))
                    arr[index].type = "int";
                else if (typeid(T) == typeid(float))
                    arr[index].type = "float";
                else if (typeid(T) == typeid(double))
                    arr[index].type = "double";
                else if (typeid(T) == typeid(char))
                    arr[index].type = "char";
                else if (typeid(T) == typeid(bool))
                    arr[index].type = "bool";
                index++;
                if constexpr(sizeof...(args) > 0) {
                    push(args...);
                }
            }

            template <typename... Args>
            DynamicArray(Args... args) {
                index = 0; // Reset index before pushing elements
                push(args...);
            }

            void display() {
                cout << "[ ";
                for (int i = 0; i < index; i++) {
                    if (arr[i].type == "int")
                        cout << *(int*)(arr[i].value) << ", ";
                    else if (arr[i].type == "float")
                        cout << *(float*)(arr[i].value) << ", ";
                    else if (arr[i].type == "char")
                        cout << *(char*)(arr[i].value) << ", ";
                    else if (arr[i].type == "double")
                        cout << *(double*)(arr[i].value) << ", ";
                    else if (arr[i].type == "bool")
                        cout << *(bool*)(arr[i].value) << ", ";
                }
                cout << " ]\n";
            }
        };
    };
};