#include "SymTable.h"
#include "AST.h"
#include <algorithm>
bool SymTable::addVariable(const string& varName, const string& varType,const optional<string>& value,const optional<string>& className){
    if(variables.find(varName)!=variables.end()){ //exista deja variabila declarata
        return false;
    }
    if(vectors.find(varName)!=vectors.end()){ //exista deja vector declarat
        return false;
    }
    variables[varName] = make_tuple(varType,value,className);
    return true;
}

bool SymTable::addVector(const string& vecName, const string& vecType,int numberElements, const optional<vector<string>> values,const optional<string>& className){
    vector<string> initialValues(numberElements, "0");
     if(variables.find(vecName)!=variables.end()){ //exista deja variabila declarata
        return false;
    }
    if(vectors.find(vecName)!=vectors.end()){ //exista deja vector declarat
        return false;
    }
    vectors[vecName] = make_tuple(vecType,numberElements,optional<vector<string>>(initialValues),className);
    return true;
}


bool SymTable::addFunction(const string& funName, const string& funType,const optional<vector<string>> parameters, const optional<string>& className){
    if(functions.find(funName)!=functions.end()){ 
        return false;
    }
    //cout<<"Added fucntion "<<funName<<" of type "<<funType<<" to scope "<<this->name<<endl;

    functions[funName]=make_tuple(funType,parameters,className);
    return true;
}

bool SymTable::addClass(const string& className){
    if(find(classes.begin(),classes.end(),className)!=classes.end()){  //exista deja clasa
        return false;
    }
    classes.push_back(className);
    return true;
}

string SymTable::getType(const string& varName){
    auto var=searchVariable(varName);
    if(var.has_value()){
        return get<0>(var.value());
    }
    auto vec=searchVector(varName);
    if(vec.has_value()){
        return get<0>(vec.value());
    }
    return "";
}


optional<tuple<string,optional<string>,optional<string>>> SymTable::searchVariable(const string& varName){
    //printf("Searching for variable %s\n",varName.c_str());
    if(variables.find(varName) != variables.end()){
        return variables[varName];
    }
    if(parentScope){
        return parentScope->searchVariable(varName);
    }
    return nullopt;
}

optional<tuple<string,int,optional<vector<string>>,optional<string>>> SymTable::searchVector(const string& vecName){
    //printf("Searching for vector %s\n",vecName.c_str());
    if (vectors.count(vecName)) {
        return vectors[vecName];
    }
    if (parentScope != nullptr) {
        return parentScope->searchVector(vecName); 
    }
    return nullopt;
}


optional<tuple<string,optional<vector<string>>,optional<string>>> SymTable::searchFunction(const string& funName){
    auto it=functions.find(funName);
    //cout<<"searched function "<<funName<<" in scope "<<this->name<<endl;
    if(it!=functions.end()){
        return it->second;  //exista functia, returnam tipul, parametrii si clasa
    }
    if(parentScope){
        return parentScope->searchFunction(funName);  //daca nu exista, cautam in scope ul parinte
    }
    return nullopt;
}

optional<tuple<string,optional<vector<string>>,optional<string>>> SymTable::searchMethodInClass(const string& className,const string& methodName, SymTable* globalScope){
    
    SymTable* classScope = globalScope->getChildScope(className);
    //cout << "DEBUG: Looking for " << methodName << " in class " << className << endl;
if (classScope != nullptr) {
    for (auto const& [key, val] : classScope->functions) {
        //cout << "DEBUG: Found existing method in map: " << key << endl;
    }
}
    if (classScope != nullptr) {
        if (classScope->functions.count(methodName)) {
            return classScope->functions[methodName];
        }
    }
    return nullopt;
}

optional<tuple<string,optional<string>,optional<string>>> SymTable::searchVariableInClass(const string& className,const string& varName,SymTable* globalScope){
     SymTable* classScope = globalScope->getChildScope(className);
    //cout << "DEBUG: Looking for " << varName << " in class " << className << endl;
if (classScope != nullptr) {
    for (auto const& [key, val] : classScope->functions) {
        //cout << "DEBUG: Found existing method in map: " << key << endl;
    }
}
    if (classScope != nullptr) {
        if (classScope->variables.count(varName)) {
            return classScope->variables[varName];
        }
    }
    return nullopt;
}
optional<tuple<string,int,optional<vector<string>>,optional<string>>> SymTable::searchVectorInClass(const string& className,const string& varName,SymTable* globalScope){
     SymTable* classScope = globalScope->getChildScope(className);
    //cout << "DEBUG: Looking for " << varName << " in class " << className << endl;
if (classScope != nullptr) {
    for (auto const& [key, val] : classScope->functions) {
        //cout << "DEBUG: Found existing method in map: " << key << endl;
    }
}
    if (classScope != nullptr) {
        if (classScope->vectors.count(varName)) {
            return classScope->vectors[varName];
        }
    }
    return nullopt;
}


bool SymTable::updateVarValue(const string& varName, const string& newValue){
    //cout<<"UPDATEZ VARIABILA "<<varName<<" CU VALOAREA "<<newValue<<endl;
    if (variables.find(varName) != variables.end()) {
        get<1>(variables[varName]) = newValue;
        return true;
    }

    if (parentScope != nullptr) {
        return parentScope->updateVarValue(varName, newValue);
    }

    return false;
}

bool SymTable::updateVarValueInClass(const string& className,const string& varName, const string&varType, const string& newValue,SymTable* globalScope){

    //cout<<"ACTUALIZEZ VARIABILA DIN CLASA EHHH"<<endl;
    SymTable* classScope = globalScope->getChildScope(className);
    
    if (classScope == nullptr) {
        return false;
    }

    auto it = classScope->variables.find(varName);
    
    if (it != classScope->variables.end()) {
        auto& [existingType, existingValue, existingClass] = it->second;
        
        if (existingType == varType) {
            existingValue = newValue;
            return true;
        }
    }
    
    return false;
}

bool SymTable::updateVectorElement(const string& vecName, int idx, const string& newValue) {
    //cout<<"ACTUALIZEZ VECTOR EHHH"<<endl;
    if (vectors.count(vecName)) {
        auto& [tip, marime, dateVector, clasa] = vectors[vecName];
        
        if (idx < 0 || idx >= marime) return false;

        if (!dateVector.has_value()) {
            dateVector = vector<string>(marime, ""); 
        }

        dateVector.value()[idx] = newValue;
        return true;
    }

    if (parentScope != nullptr) {
        return parentScope->updateVectorElement(vecName, idx, newValue);
    }

    return false;
}

bool SymTable::updateVectorElementInClass(const string& className, const string& vecName, int idx, const string& newValue, SymTable* globalScope) {
    SymTable* classScope = globalScope->getChildScope(className);
    if (classScope == nullptr) return false;

    auto it = classScope->vectors.find(vecName);
    if (it != classScope->vectors.end()) {
        auto& [tip, marime, dateVector, clasa] = it->second;

        if (idx < 0 || idx >= marime) return false;

        if (!dateVector.has_value()) {
            dateVector = vector<string>(marime, "");
        }

        dateVector.value()[idx] = newValue;
        return true;
    }

    return false;
}




bool SymTable::classExists(const string& className){
    return find(classes.begin(),classes.end(),className)!=classes.end();
}


bool SymTable::setFunctionParams(const string& funName, const string& varType){
    auto fun=searchFunction(funName);
    if(!fun.has_value()){  //nu exista
        return false;
    }
    //cout<<"placing variable of type "<<varType<<" in function "<<funName<<" in scope "<<this->name<<endl;
    auto [tip,params,clasa] = fun.value();
    if(params.has_value()){
        auto& prm = params.value();
        prm.emplace_back(varType);
    }
    else
    {
        params=vector<string>({varType});
    }
    functions[funName] = make_tuple(tip,params,clasa);
    return true;
}

bool SymTable::verifParamType(const string& funName, int nr_param, const string& paramType){
    //cout<<"searching the param type of function "<<funName<<" at index "<<nr_param<<" and comparing with with the type "<<paramType<<endl;
    auto fun = searchFunction(funName);
    if(!fun.has_value()){
        return false;
    }

    auto [tip,params,clasa] = fun.value();
    if(params.has_value()){
        auto& prm = params.value();
        if(nr_param>=0 && nr_param< prm.size()){
            return prm[nr_param] == paramType;
        }
    }
    return false;
}

bool SymTable::verifParamNumber(const string& funName,int nr_param){
    auto fun=searchFunction(funName);
    if(!fun.has_value()){
        return false;
    }

    auto [tip,params,clasa] = fun.value();

    if(params.has_value()){
        auto& prm=params.value();
        return prm.size()==nr_param;
    } else {
        return nr_param==0;
    }
    return false;
}

void SymTable::setFunctionBody(std::string name, ASTNode* body){
    this->functionBodies[name] = body;
}

ASTNode* SymTable::getFunctionBody(std::string name) {
    if (functionBodies.find(name) != functionBodies.end()) {
        return functionBodies[name];
    }
    
    if (parentScope != nullptr) {
        return parentScope->getFunctionBody(name);
    }
    
    return nullptr;
}

SymTable* SymTable::getChildScope(const string& scopeName){
    for (SymTable* s : childScopes) {
        if (s != nullptr && s->name == scopeName) {
            return s;
        }
    }
    return nullptr;
}


SymTable* SymTable::enterScope(const string& newScopeName){
    //printf("Entering scope: %s\n",newScopeName.c_str());
    SymTable* newScope = new SymTable(newScopeName,this);
    childScopes.push_back(newScope);
    return newScope;
}

SymTable* SymTable::exitScope(){
    if (this->parentScope == nullptr) {
        //printf("CRITICAL ERROR: Trying to exit Global Scope!\n");
        return this; 
    }
    //printf("Exiting scope [%s], returning to [%s]\n", 
    //        this->name.c_str(), this->parentScope->name.c_str());
    return this->parentScope;
}

#include <iomanip>

void SymTable::printTableToFile(std::ofstream& fout) {
    string space=" ";
    
    fout << space << "========================================\n";
    fout << space << "SCOPE: " << this->name << "\n";
    fout << space << "========================================\n";

    // variabile
    fout << space << "[Variables]\n";
    if (variables.empty()) fout << space << "  (none)\n";
    for (auto const& [name, info] : variables) {
        auto [type, value, className] = info;
        fout << space << "  - " << name 
             << " | Type: " << std::setw(10) << type 
             << " | Value: " << (value.has_value() ? value.value() : "null") << "\n";
    }

    // vectori
    fout << space << "\n" << space << "[Vectors]\n";
    if (vectors.empty()) fout << space << "  (none)\n";
    for (auto const& [name, info] : vectors) {
        auto [type, size, values, className] = info;
        fout << space << "  - " << std::left << std::setw(15) << name 
             << " | Type: " << std::setw(10) << type 
             << " | Size: " << size << " | Elements: [";
        if (values.has_value()) {
            for (size_t i = 0; i < values.value().size(); ++i) {
                fout << values.value()[i] << (i == values.value().size() - 1 ? "" : ", ");
            }
        }
        fout << "]\n";
    }

    // functii
    fout << space << "\n" << space << "[Functions/Methods]\n";
    if (functions.empty()) fout << space << "  (none)\n";
    for (auto const& [name, info] : functions) {
        auto [type, params, className] = info;
        fout << space << "  - " << std::left << std::setw(15) << name 
             << " | Returns: " << std::setw(10) << type;
        if (className.has_value()) fout << " | Member of: " << className.value();
        fout << "\n";
    }

    fout << "\n";

    // mers in copii
    for (SymTable* child : childScopes) {
        if (child != nullptr) {
            child->printTableToFile(fout);
        }
    }
}

void SymTable::generateTableFile(SymTable* globalScope, const std::string& filename) {
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::cerr << "Nu s-a putut deschide fisierul pentru tabelele de simboluri!\n";
        return;
    }
    globalScope->printTableToFile(fout);
    fout.close();
    std::cout << "Tabelele de simboluri au fost salvate in " << filename << std::endl;
}
