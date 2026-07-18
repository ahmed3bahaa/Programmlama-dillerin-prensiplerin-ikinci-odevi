#!/usr/bin/env bash
set -euo pipefail

mkdir -p build/cpp build/java

g++ -std=c++11 -Wall -Wextra -pedantic cpp/nfa_to_dfa.cpp -o build/cpp/nfa_to_dfa
g++ -std=c++11 -Wall -Wextra -pedantic cpp/dfa_minimization.cpp -o build/cpp/dfa_minimization
g++ -std=c++11 -Wall -Wextra -pedantic cpp/kleene_regex.cpp -o build/cpp/kleene_regex

javac -encoding UTF-8 -d build/java java/src/VM_odev/NfaToDfa.java

echo "Build completed successfully."
