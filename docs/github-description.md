# GitHub Repository Description

Use this text in the GitHub repository About section:

```text
Formal languages automata project with C++ and Java examples for NFA-to-DFA conversion, DFA minimization, and NFA-to-regex state elimination.
```

## Longer Project Summary

Programlama Dillerin Prensipleri - Ikinci Odevi is an educational automata-theory repository for formal languages coursework. It includes C++ and Java examples that demonstrate epsilon-closure calculation, NFA-to-DFA conversion, DFA minimization, and NFA-to-regular-expression conversion through state elimination.

The project is organized as a source-first GitHub repository with build scripts, CI validation, and documentation that explains both how to run the examples and how the underlying algorithms work.

## Suggested Topics

```text
formal-languages
automata-theory
nfa
dfa
regular-expression
state-elimination
cpp
java
compiler-design
coursework
```

## Deployment Notes

This project does not need a web host. Its GitHub deployment is complete when the repository contains:

- The C++ and Java source files.
- Repeatable local build scripts.
- A clean README with run instructions.
- A GitHub Actions workflow that builds and smoke-tests the examples.
- Ignored local build artifacts so generated binaries do not pollute commits.

## Visual Recommendation

Automata projects are easier to understand with diagrams. Good optional additions:

- `docs/assets/nfa-diagram.png`
- `docs/assets/dfa-output.png`
- `docs/assets/minimization-flow.png`

Avoid committing large video files directly to Git. Use GitHub Releases for videos or convert the useful portion into a small GIF or PNG sequence under `docs/assets/`.
