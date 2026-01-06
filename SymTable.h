#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <optional>
#include <fstream>
#include <tuple>
#include <unordered_set>
using namespace std;

class SymTable{
    public:
    string name;
    SymTable* parentScope;
    unordered_map<string,tuple<string,optional<string>,optional<string>>> variables; // nume, <tip, valoare, clasa>
    unordered_map<string,tuple<string,int,optional<vector<string>>,optional<string>>> vectors; // nume, <tip, numar_elemente, valoari, clasa>
    unordered_map<string,tuple<string,optional<vector<string>>,optional<string>>> functions; // <nume,clasa>, <tip,parametrii,clasa(daca e metoda)>
    vector<string> classes; //lista clase
    vector<SymTable*> childScopes;

    SymTable(const string& scopeName, SymTable* parent=nullptr) : name(scopeName), parentScope(parent) {}

    bool addVariable(const string& varName, const string& varType,const optional<string>& value=nullopt,const optional<string>& className=nullopt);
    bool addVector(const string& vecName, const string& vecType,int numberElements, const optional<vector<string>> values=nullopt,const optional<string>& className=nullopt);
    bool addFunction(const string& funName, const string& funType,const optional<vector<string>> parameters=nullopt, const optional<string>& className=nullopt);
    bool addClass(const string& className);

    string getType(const string& varName);
    optional<tuple<string,optional<string>,optional<string>>> searchVariable(const string& varName);
    optional<tuple<string,int,optional<vector<string>>,optional<string>>> searchVector(const string& vecName);
    optional<tuple<string,optional<vector<string>>,optional<string>>> searchFunction(const string& funName);
    optional<tuple<string,optional<vector<string>>,optional<string>>> searchMethodInClass(const string& className,const string& methodName,SymTable* globalScope);
    optional<tuple<string,optional<string>,optional<string>>> searchVariableInClass(const string& className,const string& varName,SymTable* globalScope);
    optional<tuple<string,int,optional<vector<string>>,optional<string>>> searchVectorInClass(const string& className,const string& vecName,SymTable* globalScope);

    bool updateVarValue(const string& varName, const string& newValue);
    bool updateVarValueInClass(const string& className,const string& varName, const string&varType, const string& newValue,SymTable* globalScope);
    bool updateVectorElement(const string& vecName, int idx, const string& newValue);
    bool updateVectorElementInClass(const string& className, const string& vecName, int idx, const string& newValue, SymTable* globalScope);
    bool classExists(const string& className);

    bool verifParamType(const string& funName, int nr_param, const string& paramType);
    bool verifParamNumber(const string& funName,int nr_param);
    bool setFunctionParams(const string& funName, const string& varType);
    bool setFunctionClass(const string& funName);

    SymTable* getChildScope(const string& scopeName);
    SymTable* enterScope(const string& newScopeName);
    SymTable* exitScope();
};