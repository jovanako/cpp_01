#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}--- Compiling the project ---${NC}"
make

echo -e "\n${YELLOW}--- Setting up test files ---${NC}"
echo "Hello world. This is a test file." > test1.txt
echo "apple apple apple banana apple" > test2.txt
touch empty.txt
echo "You cannot read me!" > no_perm.txt
chmod 000 no_perm.txt

echo -e "\n${YELLOW}--- Running Tests ---${NC}"

# Test 1: Normal replacement
echo -e "${GREEN}[Test 1] Normal replacement: 'world' -> '42'${NC}"
./replace test1.txt "world" "42"
cat test1.txt.replace
echo

# Test 2: Multiple occurrences on one line
echo -e "${GREEN}[Test 2] Multiple replacements: 'apple' -> 'orange'${NC}"
./replace test2.txt "apple" "orange"
cat test2.txt.replace
echo

# Test 3: Empty s1 (The infinite loop trap)
echo -e "${GREEN}[Test 3] Empty s1 (Should not hang, should copy original)${NC}"
./replace test1.txt "" "42"
cat test1.txt.replace
echo

# Test 4: Empty s2 (Deletion)
echo -e "${GREEN}[Test 4] Empty s2 (Should delete 'apple')${NC}"
./replace test2.txt "apple" ""
cat test2.txt.replace
echo

# Test 5: Empty File
echo -e "${GREEN}[Test 5] Empty input file${NC}"
./replace empty.txt "a" "b"
cat empty.txt.replace
echo

# Test 6: File does not exist
echo -e "${GREEN}[Test 6] Non-existent file (Should print error, not crash)${NC}"
./replace does_not_exist.txt "a" "b"
echo

# Test 7: Permission denied
echo -e "${GREEN}[Test 7] File without read permissions (Should print error)${NC}"
./replace no_perm.txt "a" "b"
echo

# Test 8: Wrong number of arguments
echo -e "${GREEN}[Test 8] Wrong number of arguments (Should print usage error)${NC}"
./replace test1.txt "a"
echo

echo -e "${YELLOW}--- Cleaning up ---${NC}"
chmod 644 no_perm.txt # Restore permissions so rm can delete it
rm -f test1.txt test1.txt.replace test2.txt test2.txt.replace empty.txt empty.txt.replace no_perm.txt no_perm.txt.replace
echo "Done!"