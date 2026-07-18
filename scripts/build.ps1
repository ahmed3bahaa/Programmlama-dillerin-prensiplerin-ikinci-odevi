$ErrorActionPreference = "Stop"

New-Item -ItemType Directory -Force -Path "build/cpp" | Out-Null
New-Item -ItemType Directory -Force -Path "build/java" | Out-Null

$cppTargets = @{
    "nfa_to_dfa"       = "cpp/nfa_to_dfa.cpp"
    "dfa_minimization" = "cpp/dfa_minimization.cpp"
    "kleene_regex"    = "cpp/kleene_regex.cpp"
}

foreach ($target in $cppTargets.GetEnumerator()) {
    g++ -std=c++11 -Wall -Wextra -pedantic $target.Value -o "build/cpp/$($target.Key).exe"
}

javac -encoding UTF-8 -d "build/java" "java/src/VM_odev/NfaToDfa.java"

Write-Host "Build completed successfully."
