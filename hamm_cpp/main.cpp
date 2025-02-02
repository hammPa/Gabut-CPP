#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

struct Token {
    std::string type;
    std::string value;
};

std::vector<Token> tokenize(const std::string& code) {
    std::vector<Token> tokens;
    std::istringstream stream(code);
    std::string word;

    while (stream >> word) {
        if (word == "let") {
            tokens.push_back({"KEYWORD", word});
        }
        else if (word == "=") {
            tokens.push_back({"ASSIGN", word});
        }
        else if (word == "if") {
            tokens.push_back({"IF", word});
        }
        else if (word == "else") {
            tokens.push_back({"ELSE", word});
        }
        else if (word == "for") {
            tokens.push_back({"FOR", word});
        }
        else if (word == "print") {
            tokens.push_back({"PRINT", word});
        }
        else if (std::isdigit(word[0]) || word[0] == '"') {
            tokens.push_back({"VALUE", word});
        }
        else if (word == "{" || word == "}") {
            tokens.push_back({"BRACE", word});
        }
        else {
            tokens.push_back({"IDENTIFIER", word});
        }
    }
    return tokens;
}

std::string parseAndGenerate(std::vector<Token> tokens) {
    if (tokens.empty()) return "";

    if (tokens[0].type == "KEYWORD" && tokens[0].value == "let") {
        if (tokens.size() < 4 || tokens[2].type != "ASSIGN") {
            throw std::runtime_error("Syntax Error on variable declaration!\n");
        }
        std::string varName = tokens[1].value;
        std::string expression;

        for (size_t i = 3; i < tokens.size(); i++) {
            expression += tokens[i].value + " ";
        }
        return "int " + varName + " = " + expression + ";";
    }

    if (tokens[0].type == "PRINT") {
        if (tokens.size() < 2) throw std::runtime_error("Syntax Error on print statement!\n");

        std::string output;
        for (size_t i = 1; i < tokens.size(); i++) {
            output += tokens[i].value + " ";
        }
        return "std::cout << " + output;
    }

    if (tokens[0].type == "IF") {
        if (tokens.size() < 2) throw std::runtime_error("Syntax Error on if statement!\n");

        std::string condition;
        for (size_t i = 1; i < tokens.size(); i++) {
            condition += tokens[i].value + " ";
        }
        // Menghapus spasi terakhir, jika ada
        if (!condition.empty() && condition.back() == ' ') {
            condition.pop_back();
        }
        // Menghapus '}' jika ada di akhir kondisi
        if (!condition.empty() && condition.back() == '{') {
            condition.pop_back();
        }
        return "if (" + condition + ") {";
    }

    if (tokens[0].type == "ELSE") {
        return "else {";
    }

    if (tokens[0].type == "FOR") {
        if (tokens.size() < 5) throw std::runtime_error("Syntax Error on for loop!\n");

        std::string loopHeader;
        for (size_t i = 1; i < tokens.size(); i++) {
            loopHeader += tokens[i].value + " ";
        }
        // Menghapus spasi terakhir, jika ada
        if (!loopHeader.empty() && loopHeader.back() == ' ') {
            loopHeader.pop_back();
        }
        // Menghapus '}' jika ada di akhir kondisi
        if (!loopHeader.empty() && loopHeader.back() == '{') {
            loopHeader.pop_back();
        }
        return "for (" + loopHeader + ") {";
    }

    if (tokens[0].type == "BRACE") {
        return tokens[0].value;
    }

    return "";
}

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No file provided" << std::endl;
        return 1;
    }

    // Ambil nama file dari argv
    const char* filename = argv[1];

    // Gabungkan filename dengan ".hamm" menggunakan std::string
    std::string file_path = std::string("./") + filename + ".hamm";

    // Buka file
    std::cout << file_path << "\n";
    std::cout << file_path.c_str() << "\n";
    std::ifstream file(file_path.c_str());
    
    if (!file) {
        std::cerr << "Gagal membuka file!\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    std::vector<std::string> parsedLines;
    std::string line;
    while (std::getline(buffer, line)) {
        if (line.empty()) continue;

        std::vector<Token> tokens = tokenize(line);
        std::string cpp_code = parseAndGenerate(tokens);
        if (!cpp_code.empty()) {
            parsedLines.push_back(cpp_code);
        }
    }

    std::ofstream output("output.cpp");
    output << "#include <iostream>\nint main() {\n";
    for (const auto& line : parsedLines) {
        output << "    " << line << "\n";
    }
    output << "    return 0;\n}";
    output.close();

    std::cout << "Berhasil dikompilasi ke output.cpp!\n";

    return 0;
}
