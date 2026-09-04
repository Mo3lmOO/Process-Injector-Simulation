# Windows Process Injection Simulation

An educational and research-focused tool written in C++ that demonstrates Windows memory management and process interaction using native Windows APIs. This project simulates how the operating system manages memory allocation and remote thread execution across different processes.

⚠️ **Disclaimer:** This project is created strictly for educational, learning, and security research purposes only. 

## 🚀 Features
- **Dynamic Process Enumeration:** Creates a system snapshot to display active running processes and their PIDs.
- **Memory Allocation:** Demonstrates the use of `VirtualAllocEx` to allocate space in a target process's memory space.
- **Remote Thread Execution:** Uses `CreateRemoteThread` to interact with system APIs for demonstration purposes.

## 🛠️ Windows APIs Demonstrated
- `CreateToolhelp32Snapshot`
- `OpenProcess`
- `VirtualAllocEx`
- `WriteProcessMemory`
- `CreateRemoteThread`

## 📚 Educational Purpose
The main goal of this repository is to help cybersecurity students and software developers understand the lower-level mechanics of the Windows operating system, how memory permissions work, and how security tools monitor cross-process behaviors.

## 📄 License
This project is open-source and available under the [MIT License](LICENSE).
