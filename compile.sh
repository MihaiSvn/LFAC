#!/bin/bash

echo "compiling..."
rm -f lex.yy.c
rm -f limbaj.tab.c
rm -f limbaj.tab.h

flex limbaj.l
bison -d limbaj.y
g++ lex.yy.c limbaj.tab.c SymTable.cpp