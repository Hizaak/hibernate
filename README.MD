# Hibernate

## Description

Hibernate is a small utility written in C that allows you to hibernate your Linux system in a simple and efficient manner. This program is designed to be used in the command line and can be useful for saving energy on embedded systems or automating tasks. It was originally developed because hibernating my laptop was not working properly with the default tools of my Linux distribution (Arch Linux/Manjaro).

## Installation

### Prerequisites

Make sure you have the following installed on your system:

- `gcc` (GNU Compiler Collection) for compiling C code.
- `git` for cloning the repository.

### Quick Installation

Run the following command in your terminal to install Hibernate in a single line:

```bash
curl -sSL https://raw.githubusercontent.com/hizaak/hibernate/master/install.sh | sudo bash
```

This command downloads the installation script from this GitHub repository and automatically executes it to install Hibernate on your system. Make sure you understand the implications of running scripts from the internet before executing this command.

## Usage

Once installed, you can use Hibernate by running the following command in your terminal:

```bash
sudo hibernate <state>
```

Here are the available states for Hibernate:
- freeze / s2idle: Puts the system into hibernation.
- mem: Puts the system into hibernation by saving the memory state.
- standby / shallow: Puts the system into extended sleep.
- disk: Puts the system into hibernation by saving the memory state to disk.
- deep: Puts the system into hibernation by saving the memory state to disk and cutting off power.

Not all states are available on all systems. You can check the available states on your system by running the command `cat /sys/power/state` in your terminal.

Documentation on Linux kernel sleep states:
- [https://www.kernel.org/doc/html/latest/admin-guide/pm/sleep-states.html](https://www.kernel.org/doc/html/latest/admin-guide/pm/sleep-states.html)
- [https://www.kernel.org/doc/Documentation/power/states.txt](https://www.kernel.org/doc/Documentation/power/states.txt)

## Contributions

Contributions in the form of bug reports, pull requests, and enhancements are welcome! Feel free to open an issue or send a pull request.