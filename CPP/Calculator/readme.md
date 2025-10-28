C++ Console Calculator

This is a simple, robust, and easy-to-use calculator application written in C++. It runs in the console and performs basic arithmetic operations while handling common errors.

✨ Features

Basic Arithmetic: Performs addition (+), subtraction (-), multiplication (*), and division (/).

Continuous Input: The calculator runs in a loop, allowing you to perform multiple calculations without restarting.

Robust Error Handling:

Gracefully handles invalid input formats (e.g., 5 + three, 10 *).

Prevents crashes from division by zero.

Catches unknown operators.

User-Friendly: Simple prompt and clear output.

Clean Exit: Quit anytime by typing q or exit.

⚙️ Requirements

To compile and run this program, you will need:

A C++ compiler (e.g., g++ on Linux/macOS, MSVC on Windows).

🚀 How to Compile and Run

Save the Code:
Save the code as calculator.cpp.

Open Your Terminal:
Navigate to the directory where you saved the file.

Compile the Code:

On macOS or Linux (using g++):

g++ calculator.cpp -o calculator


This command compiles the source code (calculator.cpp) and creates an executable file named calculator.

On Windows (using MinGW/g++):

g++ calculator.cpp -o calculator.exe


On Windows (using Visual Studio Developer Command Prompt):

cl calculator.cpp


This will create calculator.exe.

Run the Program:

On macOS or Linux:

./calculator


On Windows:

.\calculator.exe


(or just calculator in CMD)

📝 How to Use

Once the program is running, you will see a > prompt.

Enter a calculation in the format: number operator number

> 10 + 5

Result: 15

You can use floating-point numbers:

> 2.5 * 4

Result: 10

If you make an error, the program will notify you:

> 10 / 0

Error: Cannot divide by zero.

To quit, type q or exit and press Enter:

> q

Goodbye!
