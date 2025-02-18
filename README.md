Win32GUIExamples
This repository contains examples of Windows GUI applications using the Win32 API. Each example demonstrates specific aspects of Win32 development, such as window creation, event handling, and custom rendering.

🚀 Features
Basic Win32 window creation
Message loop and event handling
User interaction via buttons and menus
Custom drawing with GDI
Dialog boxes and additional UI elements
🛠 Installation
Clone the repository:
git clone https://github.com/avelic5/Win32GUIExamples-.git
Open the project in any C development environment that supports Win32 API (e.g., Visual Studio, Code::Blocks, MinGW, CMake with Ninja, etc.).
Compile and run the examples using the provided source files.
📂 Examples
Below are descriptions of each example.

🏠 Example 1 - Olympic Rings
This example demonstrates how to draw the Olympic Rings using the GDI in a Win32 application. It covers:

Handling WM_PAINT messages
Drawing circles in different colors to create the Olympic rings
Using BeginPaint and EndPaint for efficient rendering

![Screenshot 2025-02-18 164318](https://github.com/user-attachments/assets/c9570793-9d0d-400b-8286-47b49642e2cc)


🔘 Example 2 - Merge Messages
This example allows the user to input two separate messages and then combines them by pressing a button. Key features include:

Capturing user input through text fields
Dynamically updating the window with the merged message after button click
Handling WM_COMMAND for button interaction

![Screenshot 2025-02-18 164230](https://github.com/user-attachments/assets/b3e59930-40b5-4b20-8b3e-908ea4129dcc)


🎨 Example 3 - Display Message in New Window
In this example, the user enters a message, and after pressing a button, a new window pops up displaying that message. Key concepts:

Capturing and handling user input
Creating and managing multiple windows
Displaying a message in a new window

![Screenshot 2025-02-18 164358](https://github.com/user-attachments/assets/666ec4d1-2ba8-4d53-890b-15575bef7b91)


📋 Example 4 - Timer Button
This example shows how to create a button that starts a timer to track the time elapsed after it is pressed. Features include:

Starting a timer when the button is clicked
Displaying the time elapsed since the button press
Handling WM_TIMER for time updates

![Screenshot 2025-02-18 164428](https://github.com/user-attachments/assets/c03685a5-8261-45ea-b0aa-d9a1efe7e12e)

🔵 Example 5 - Dynamic Circle Sizing
This example allows the user to input a number, which then determines the size of two circles: one on the left and one on the right. It covers:

Capturing user input
Dynamically adjusting UI elements
Redrawing circles based on the selected value
Handling WM_PAINT for real-time updates

![Screenshot 2025-02-18 164450](https://github.com/user-attachments/assets/774cf4bb-ae4c-4965-a782-286cd35e0ce1)


🎶 Example 6 - Musical Note Display
This example simulates a simple musical note selection interface. The user can press a button to display one of the musical notes: Do, Re, Mi, Fa, So, La. Key features include:

Creating buttons for each musical note
Handling button click events
Updating the window to display the selected note

![Screenshot 2025-02-18 164506](https://github.com/user-attachments/assets/19723259-6cf8-4dc9-ad5a-89fd34793364)


🤝 Contributing
Feel free to submit pull requests with improvements or additional examples.
