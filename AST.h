#include <string>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class SymTable;
enum ast_type
{
    astINT,
    astCH,
    astSTR,
    astFL,
    astBOOL,
    astID,
    OP_UNAR,
    OP_BINAR,
    astERROR
};
class ASTNode
{
public:
    struct ValueWrapper
    {
        string type;
        int iVal;
        float fVal;
        char cVal;
        string sVal;
        bool bVal;
        string errorVal;
    } value;
    string label;
    ast_type type;
    string exprType;

    string getStringValue();
    string get_type();

    void Print();
    void printAST(int level);
    int compareNodes(ASTNode* L, ASTNode* R);

    ASTNode* left;
    ASTNode* right;

    ASTNode(string type, string value, string exprType); //pentru frunze
    ASTNode(ASTNode* left,string op,ASTNode* right); //pentur operatori
    ASTNode* evaluate(SymTable* currentScope);
};