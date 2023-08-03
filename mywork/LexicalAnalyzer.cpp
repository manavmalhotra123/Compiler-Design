#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

// Token contains the information of the token and it's type
class Token
{
public:
    // members are type of token and value of the token
    string type;
    string value;

    // constructor so that we can access this thing directly everywhere in the code
    Token(const string &type, const string &value)
    {
        this->type = type;
        this->value = value;
    }
};

class Lexer
{
private:
    // source code string
    string source_code;
    // token vector that is taking the Token object as type
    vector<Token> tokens;

public:
    // constructor of the lexer
    Lexer(const string &source_code) : source_code(source_code) {}

    // main kaam yha pr shuru hoga ab
    void tokenize()
    {
        // string bnaalo ek
        tokens.clear();
        string current_token;

        // loop over whole the code we read from the file
        for (size_t i = 0; i < source_code.length(); ++i)
        {
            char current_char = source_code[i];

            // if the current character is identifier
            if (isalpha(current_char))
            {
                // Identify identifiers
                current_token += current_char;
                while (i + 1 < source_code.length() && (isalnum(source_code[i + 1]) || source_code[i + 1] == '_'))
                {
                    current_token += source_code[i + 1];
                    ++i;
                }
                tokens.push_back(Token("IDENTIFIER", current_token));
                current_token = "";
            }
            else if (isdigit(current_char))
            {
                // Identify integers
                current_token += current_char;
                while (i + 1 < source_code.length() && isdigit(source_code[i + 1]))
                {
                    current_token += source_code[i + 1];
                    ++i;
                }
                tokens.push_back(Token("INTEGER", current_token));
                current_token = "";
            }
            else if (isspace(current_char))
            {
                // Ignore whitespaces
                continue;
            }
            else
            {
                // Treat other characters as individual tokens
                tokens.push_back(Token(string(1, current_char), string(1, current_char)));
            }
        }
    }

    const vector<Token> &getTokens() const
    {
        return tokens;
    }
};

int main()
{
    ifstream infile("input_code.txt");
    if (!infile)
    {
        cerr << "Failed to open input_code.txt\n";
        return 1;
    }

    string source_code((istreambuf_iterator<char>(infile)), (istreambuf_iterator<char>()));

    Lexer lexer(source_code);
    lexer.tokenize();
    const vector<Token> &tokens = lexer.getTokens();

    for (const Token &token : tokens)
    {
        cout << "(" << token.type << ", " << token.value << ") ";
    }
    cout << endl;
    return 0;
}
