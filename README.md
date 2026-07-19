<a id="readme-top"></a>

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]

<br />
<div align="center">
  <a href="https://github.com/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi">
    <img src="docs/images/logo-placeholder.svg" alt="Programlama Dillerin Prensipleri - Ikinci Odevi logo placeholder" width="90" height="90">
  </a>

  <h3 align="center">Programlama Dillerin Prensipleri - Ikinci Odevi</h3>

  <p align="center">
    Formal languages and automata theory project with C++ and Java examples for NFA-to-DFA conversion, DFA minimization, and NFA-to-regex state elimination.
    <br />
    <a href="docs/GITHUB_DESCRIPTION.md"><strong>Explore the docs Â»</strong></a>
    <br />
    <br />
    <a href="#usage">View Usage</a>
    &middot;
    <a href="https://github.com/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi/issues/new">Report Bug</a>
    &middot;
    <a href="https://github.com/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi/issues/new">Request Feature</a>
  </p>
</div>

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a><ul><li><a href="#built-with">Built With</a></li></ul></li>
    <li><a href="#getting-started">Getting Started</a><ul><li><a href="#prerequisites">Prerequisites</a></li><li><a href="#installation">Installation</a></li></ul></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#how-it-works">How It Works</a></li>
    <li><a href="#project-structure">Project Structure</a></li>
    <li><a href="#validation">Validation</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

## About The Project

[![Project overview placeholder][project-screenshot]](#usage)

Formal languages and automata theory project with C++ and Java examples for NFA-to-DFA conversion, DFA minimization, and NFA-to-regex state elimination.

The repository currently offers:

- C++ epsilon-NFA to DFA conversion
- Java epsilon-NFA to DFA conversion
- C++ DFA minimization
- C++ NFA to regular expression conversion
- Windows and Linux/macOS build scripts
- Optional CMake build
- GitHub Actions build and smoke-test workflow

This README follows the shared template requested for the repository set and keeps the claims limited to files and documentation present in this project.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

- C++
- Java
- CMake
- Bash
- PowerShell
- GitHub Actions

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Getting Started

Follow these steps to clone the repository and run the project locally.

### Prerequisites

- g++ with C++11 support
- Java JDK 17 or newer
- Optional CMake 3.12+

### Installation

~~~bash
git clone https://github.com/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi.git
cd Programmlama-dillerin-prensiplerin-ikinci-odevi
bash scripts/build.sh
~~~

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Usage

Useful commands and entry points:

~~~bash
powershell -ExecutionPolicy Bypass -File .\scripts\build.ps1
~~~

~~~bash
bash scripts/build.sh
~~~

~~~bash
./build/cpp/nfa_to_dfa
~~~

~~~bash
java -cp build/java VM_odev.NfaToDfa
~~~

### Visual Placeholders

Placeholder images are included under `docs/images/` so you can replace them manually later without changing the README layout.

<p align="center">
  <img src="docs/images/project-overview-placeholder.svg" alt="Programlama Dillerin Prensipleri - Ikinci Odevi overview placeholder" width="48%">
  <img src="docs/images/workflow-placeholder.svg" alt="Programlama Dillerin Prensipleri - Ikinci Odevi workflow placeholder" width="48%">
</p>

Suggested final visuals:

- Project overview screenshot or main terminal output.
- Workflow, architecture, or data-flow diagram.
- Example result, dashboard, report, or generated artifact screenshot.
- Short GIF only when it is small and useful.

Avoid committing large raw videos, private datasets, credentials, runtime logs, or generated secrets. Use sanitized screenshots and diagrams.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## How It Works

`	ext
Sample automaton -> epsilon closures and transition sets -> DFA states, minimized DFA, or regular expression output
`

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Project Structure

- cpp/ - C++ automata examples
- java/src/VM_odev/ - Java NFA-to-DFA example
- scripts/ - build helpers
- CMakeLists.txt - optional C++ build
- docs/ - GitHub description notes

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Validation

Run the most relevant checks for this repository:

~~~bash
bash scripts/build.sh
~~~

~~~bash
powershell -ExecutionPolicy Bypass -File .\scripts\build.ps1
~~~

Some validations depend on local tools, services, datasets, API credentials, or a configured lab environment.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Roadmap

- [ ] Replace placeholder images with final screenshots or diagrams.
- [ ] Keep setup commands synchronized with the current project files.
- [ ] Add more examples or test fixtures when the project grows.
- [ ] Add a repository-level license if the project will be reused outside its original context.

See the [open issues](https://github.com/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi/issues) for proposed features and known issues.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Contributing

Contributions are welcome for documentation, examples, tests, and implementation improvements.

1. Fork the project.
2. Create your feature branch:

   ~~~bash
   git checkout -b feature/AmazingFeature
   ~~~

3. Commit your changes:

   ~~~bash
   git commit -m "Add some AmazingFeature"
   ~~~

4. Push to the branch:

   ~~~bash
   git push origin feature/AmazingFeature
   ~~~

5. Open a pull request.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Top Contributors

<a href="https://github.com/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi" alt="Top contributors for Programlama Dillerin Prensipleri - Ikinci Odevi" />
</a>

## License

No repository-level license file was verified in this project. Add a license before reuse or distribution outside the intended coursework, lab, or prototype context.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Contact

Project owner: [@ahmed3bahaa](https://github.com/ahmed3bahaa)

Project Link: [https://github.com/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi](https://github.com/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Acknowledgments

- README structure adapted from [ahmed3bahaa/readme-template](https://github.com/ahmed3bahaa/readme-template).
- Project files, reports, fixtures, and documentation included in this repository.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

[contributors-shield]: https://img.shields.io/github/contributors/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi.svg?style=for-the-badge
[contributors-url]: https://github.com/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi.svg?style=for-the-badge
[forks-url]: https://github.com/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi/network/members
[stars-shield]: https://img.shields.io/github/stars/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi.svg?style=for-the-badge
[stars-url]: https://github.com/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi/stargazers
[issues-shield]: https://img.shields.io/github/issues/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi.svg?style=for-the-badge
[issues-url]: https://github.com/ahmed3bahaa/Programmlama-dillerin-prensiplerin-ikinci-odevi/issues
[project-screenshot]: docs/images/project-overview-placeholder.svg
