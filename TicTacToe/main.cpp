#include <iostream>
#include <array>
#include <ostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <tuple>
#include <thread>
#include <chrono>
#include <algorithm>

#define ROWS 13
#define COLS 24

enum Character { X, O };

enum Mode { EASY, MEDIUM, HARD };

class TicTacToe {
private:
    enum Character ch;
    std::string player, enemy;
    
    std::vector<std::tuple<int, int, int>> position;
    std::array<std::string, ROWS> background;
    std::array<std::array<std::string, 3>, 3> data;
    
    std::vector<int> userInput, aiInput;
    std::array<std::array<int, 3>, 8> winCondition = {{
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9},
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9},
        {1, 5, 9}, {3, 5, 7}
    }};
public:
    enum Mode mode;
    TicTacToe(){
        initTable();
        initPair();
    }

    void setMode(Mode mode){
        this->mode = mode;
        std::cout << "Mode has been set to " << (this->mode == EASY ? "Easy" : (this->mode ==  MEDIUM ? "Medium" : "Hard")) << "\n";
    }

    void initPair(){
        position.push_back(std::tuple<int, int, int>(1, 2, 4)); // cell ke, posisi baris, posisi kolom
        position.push_back(std::tuple<int, int, int>(2, 2, 12));
        position.push_back(std::tuple<int, int, int>(3, 2, 20));
        position.push_back(std::tuple<int, int, int>(4, 6, 4));
        position.push_back(std::tuple<int, int, int>(5, 6, 12));
        position.push_back(std::tuple<int, int, int>(6, 6, 20));
        position.push_back(std::tuple<int, int, int>(7, 10, 4));
        position.push_back(std::tuple<int, int, int>(8, 10, 12));
        position.push_back(std::tuple<int, int, int>(9, 10, 20));
    }

    void initTable(){
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(i == ROWS - 1 || i % 4 == 0) background[i].append("-");
                else if(j == COLS - 1 || j % 8 == 0) background[i].append("|"); 
                else  background[i].append(" ");
            }
            if(i != ROWS -1) background[i].append("\n");
        }
    }

    std::string getRows(int index){ return background[index]; }

    friend std::ostream& operator<<(std::ostream& os, TicTacToe& tictactoe){
        for(int i = 0; i < ROWS; i++) os << tictactoe.getRows(i);
        return os;
    }

    void init_char(){
        int random = std::rand() % 2;
        if(random == X){
            player = "X";
            enemy = "O";
        }
        else {
            player = "O";
            enemy = "X";
        }
    }

    std::string getPlayer(){ return player; }
    
    std::string getEnemy(){ return enemy; }

    bool searchPlayerNum(int num_to_search){
        for(int& num: userInput){
            if(num == num_to_search) return true;
        }
        return false;
    }

    bool searchAiNum(int num_to_search){
        for(int& num: aiInput){
            if(num == num_to_search) return true;
        }
        return false;
    }

    void getInput(){
        int number, percobaan = 0;
        do {
            if(percobaan != 0) std::cerr << "Posisi sudah terisi\n";
            std::cout << "Masukkan cell yang akan anda isi : ";
            std::cin >> number;
            percobaan++;
            std::cout << searchPlayerNum(number) << "\n";
        } while (searchPlayerNum(number) || searchAiNum(number));
        userInput.push_back(number);
        
    }

    void getAiInput(){
        int random; // random dari 1 sampai 9;
        do {
            random = std::rand() % 9 + 1; // random from 1 to 9
        } while (searchPlayerNum(random) || searchAiNum(random)); // Ensure the position is not taken
        aiInput.push_back(random);
    }

    void getAiHardInput(){
        int random; // random dari 1 sampai 9;
        // std::cout << "ai hard berjalan\n";
        
        // cari pola player
        std::vector<int> predictPlayerCondition;
        for(std::array<int, 3>& array: winCondition){
            int countPlayerPattern = counting(array, userInput);
            if(countPlayerPattern == 2){
                predictPlayerCondition = std::vector<int>(array.begin(), array.end());
                // Cek apakah langkah yang diprediksi sudah terisi
                for (int pos : predictPlayerCondition) {
                    if (!searchPlayerNum(pos) && !searchAiNum(pos)) {
                        aiInput.push_back(pos);
                        return;
                    }
                }
            }
        }

        do {
            random = std::rand() % 9 + 1; // random from 1 to 9
        } while (searchPlayerNum(random) || searchAiNum(random)); // Ensure the position is not taken
        aiInput.push_back(random);
    }


    char getCharacter(const char* character){
        return (character == "player" ? player[0] : enemy[0]);
    }

    int getLastValue(const char* character){
        return (character == "player" ? userInput.back() : aiInput.back() );
    }

    void update(int cell_number, char character){
        for(int i = 0; i < position.size(); i++){ // cari
            if(std::get<0>(position[i]) == cell_number){
                int row = std::get<1>(position[i]);
                int col = std::get<2>(position[i]);
                background[row].at(col) = character;
                break;
            }
        }
    }

    void loading(){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::system("clear");
        std::cout << "Loading";
        std::string loading = ".";
        for(int i = 0; i < 5; i++){
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            std::cout << loading << std::flush;
        }
        std::cout << "Enemy memilih : " << aiInput.back() << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout <<  "\n";
    }

    int counting(const std::array<int, 3>& array, const std::vector<int>& input) {
        int count = 0;
        for (const int& arrayValue : array) {
            for (const int& targetValue : input) {
                if (arrayValue == targetValue) count++;
            }
        }
        return count;
    }

    bool checkWin(const char *character){
        std::vector<int> *input;
        if(character == "player") input = &userInput;
        else input = &aiInput;
        
        for(std::array<int, 3> & array: winCondition){ // ini 3
            int count = counting(array, *input);
            if(count == 3) return true;
        }
        return false;
    }
};

int main(){

    TicTacToe tictactoe;
    std::srand(std::time(0));
    int giliran = 0;
    tictactoe.init_char();
    bool isPlayerWin;
    bool isEnemyWin;
    int pilihanMode;

    std::cout << "Pilih mode : \n";
    std::cout << "1. Easy\n2. Medium\n3. Hard\n";
    std::cout << "Pilihan : ";
    std::cin >> pilihanMode;
    tictactoe.setMode(pilihanMode == 1 ? EASY : (pilihanMode == 2 ? MEDIUM : HARD));

    while(giliran < 9){
        std::cout << "Kamu adalah : " << tictactoe.getCharacter("player") << "\n";
        std::cout << tictactoe << "\n";
        if(giliran % 2 == 0){
            tictactoe.getInput();
            tictactoe.update(tictactoe.getLastValue("player"), tictactoe.getCharacter("player"));
        }
        else {
            if(tictactoe.mode == HARD) tictactoe.getAiHardInput();
            else if(tictactoe.mode == MEDIUM)  tictactoe.getAiInput();            
            else tictactoe.getAiInput();
            
            tictactoe.loading();
            tictactoe.update(tictactoe.getLastValue("enemy"), tictactoe.getCharacter("enemy"));
        }
        isPlayerWin = tictactoe.checkWin("player");
        isEnemyWin = tictactoe.checkWin("enemy");

        giliran++;
        if(isPlayerWin || isEnemyWin) break;
        std::system("clear");
    }

    std::cout << tictactoe << "\n";
    bool winner = (isPlayerWin ? true : false);
    if(!winner){
        std::cout << "Kamu kalah, Enemy Menang\n";
        return 0;
    }
    std::cout << "Kamu menang, Enemy Kalah" << "\n";

    // kalau nilai celll nya sudah ada tapi di input lagi masih bisa, harusnya tidak bisa : done
    // kalau sebaris atau sekolom atau diagonal langsung menang : done
    // deteksi input player, halangi agar player menang : done cuman ngebug dikit
    // tambahkan delay untuk enemy : done

    return 0;
}
