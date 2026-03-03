#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}--- Compiling the project ---${NC}"
make

echo -e "\n${YELLOW}--- Running Tests ---${NC}"

# Test 1: Level DEBUG
echo -e "${GREEN}[Test 1] Level DEBUG: should print all four levels${NC}"
./harlFilter "DEBUG"
echo

# Test 2: Level INFO
echo -e "${GREEN}[Test 2] Level INFO: should print three levels${NC}"
./harlFilter "INFO"
echo

# Test 3: Level WARNING
echo -e "${GREEN}[Test 3] Level WARNING: should print two levels${NC}"
./harlFilter "WARNING"
echo

# Test 4: Level ERROR
echo -e "${GREEN}[Test 4] Level ERROR: should print one level${NC}"
./harlFilter "ERROR"
echo

# Test 5: No level
echo -e "${GREEN}[Test 5] No level: should print [ Probably complaining about insignificant problems ]${NC}"
./harlFilter "I am tired"
echo

# Test 6: Wrong number of arguments
echo -e "${GREEN}[Test 6] Wrong number of arguments: should print error message${NC}"
./harlFilter
echo -e "${GREEN}Done!${NC}"