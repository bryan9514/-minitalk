#!/bin/bash

PID=$1

GREEN="\033[0;32m"
BLUE="\033[0;34m"
NC="\033[0m" # No Color

echo -e "${BLUE}Probando: Hola mundo${NC}"
./client $PID "Hola mundo"
echo -e "${GREEN}✔ OK${NC}\n"

echo -e "${BLUE}Probando: String vacía${NC}"
./client $PID ""
echo -e "${GREEN}✔ OK${NC}\n"

echo -e "${BLUE}Probando: Cadena larga (1000 A's)${NC}"
./client $PID "$(head -c 1000 < /dev/zero | tr '\0' 'A')"
echo -e "${GREEN}✔ OK${NC}\n"

echo -e "${BLUE}Probando: Caracteres especiales${NC}"
./client $PID "!@#$%^&*()_+-=[]{}|;:',.<>/?\`~"
echo -e "${GREEN}✔ OK${NC}\n"

echo -e "${BLUE}Probando: Unicode (si implementado)${NC}"
./client $PID "¡Hola 👋, mundo 🌍!"
echo -e "${GREEN}✔ OK${NC}\n"

