# Introduction to Arduino  

## Table of Contents
- [What is Arduino?](#what-is-arduino)
- [Where does it come from?](#where-does-it-come-from)
- [What can Arduino do?](#what-can-arduino-do)
- [Arduino as a language and toolset](#arduino-as-a-language-and-toolset)
- [The Arduino ecosystem](#the-arduino-ecosystem)
- [Our board](#our-board)
- [Coding with Arduino](#coding-with-arduino)
  - [Example 001 – Basic LED Blink](#example-001--basic-led-blink)
  - [Example 002 – Blink with Variable + Serial Feedback](#example-002--blink-with-variable--serial-feedback)
  - [Example 003 – Blink with a Function](#example-003--blink-with-a-function)
  - [Example 004 – Control with if Statement](#example-004--control-with-if-statement)
  - [Example 005 – Iteration with for Loop](#example-005--iteration-with-for-loop)
  - [Example 006 – For Loop with Array](#example-006--for-loop-with-array)
  - [Example 007 – Control LED via Serial Monitor](#example-007--control-led-via-serial-monitor)
  - [Example 008 – Messages in the Serial Interface](#example-008--messages-in-the-serial-interface)

---

## What is Arduino?  
Arduino is an **open-source electronics platform** designed to make it easy for anyone to work with microcontrollers.  
A microcontroller is a small computer on a chip that can read **inputs** (like a button press, light level, or temperature) and control **outputs** (like LEDs, motors, or speakers).  

Arduino combines:  
- **Simple hardware**: affordable circuit boards with a microcontroller  
- **Simple software**: the Arduino IDE (programming environment) where you write and upload code  

Together, this makes Arduino perfect for learning electronics, building prototypes, and experimenting with interactive projects.  

---

## Where does it come from?  
Arduino was first developed in **2003** at the *Interaction Design Institute Ivrea* (IDII) in Ivrea, Italy.  
One of the founders, **Massimo Banzi**, and his colleagues wanted a tool that design students could use without being experts in electronics.  

From the beginning, Arduino was **open-source**: anyone could look at the hardware design, copy it, or improve it.  
This openness is one of the reasons Arduino spread so quickly and became the go-to platform for prototyping.  

> 💡 *Fun fact: “Arduino” is named after a bar in Ivrea where the founders used to meet.*  

---

## What can Arduino do?  
Arduino is excellent for building **small, interactive devices**, for example:  
- Controlling LEDs, motors, or speakers  
- Reading sensors (light, motion, temperature)  
- Making simple robots  
- Creating smart IoT devices  

Compared to a Raspberry Pi (a small single-board computer), Arduino has:  
- **No operating system**  
- **Less processing power**  
- **No video output**  

…but it is:  
- **Cheaper**  
- **More energy-efficient**  
- **Easier to program for electronics tasks**  

This is why Arduino is often the first step in prototyping before moving to more complex systems.  

---

## Arduino as a language and toolset  
Arduino is not only the hardware — it’s also the **programming language and environment**.  

The language is based on **C/C++**, but simplified with built-in libraries.  
Every Arduino program (called a *sketch*) has two main parts:  

```c
void setup() {
  // runs once at the start
}

void loop() {
  // runs repeatedly forever
}
```  

The Arduino IDE translates this sketch into machine code that your specific board understands.  

> ⚠️ For each new board type, the IDE needs to be configured. Sometimes you must install additional board definitions.  

---

## The Arduino ecosystem  
Because Arduino is open-source, many companies produce compatible boards.  
Popular options include:  

- **Official Arduino boards**: Uno, Nano, Mega, MKR, Portenta  
- **Compatible boards**: Adafruit, SparkFun, Seeed Studio  

You can buy them from the [Arduino Store](https://www.arduino.cc), or resellers like Amazon or eBay.  

💡 Tip: Stick with well-known brands — the documentation and tutorials are usually better.  

---

### Choosing a Board  

There are many Arduino and Arduino-compatible boards available.  
When buying a board, students should consider:  
- **Size** – does it fit your project?  
- **Power** – do you need battery support or USB only?  
- **Connectivity** – WiFi / Bluetooth / LoRa / none?  
- **Pins** – how many sensors or actuators you want to connect  
- **Community support** – are there tutorials and documentation?
- **Features** – what are the extra fesatures on the board?  

For the purpose of this course, we will stick to the **Arduino Uno R4 WiFi**:  
- A reliable **entry point** into Arduino  
- Includes **WiFi/Bluetooth connectivity**  
- Supports a wide range of **“shields”** (plug-in extension boards that stack on top)  
- Well documented and widely supported  

👉 The Uno R4 is an **all-rounder**, but keep in mind it is **relatively large** compared to some alternatives.  

📄 [Uno R4 WiFi Documentation](https://docs.arduino.cc/hardware/uno-r4-wifi) 
---

#### Alternatives You Might Explore  

##### Adafruit Feather Boards  
- **Small, lightweight** boards designed for portability  
- Built-in **battery connector** for easy mobile projects  
- Many options available (WiFi, Bluetooth, LoRa, etc.)  
- Great if you want to build **wearables** or battery-powered devices  

📄 [Adafruit Feather Overview](https://learn.adafruit.com/adafruit-feather/feather-family)  

---

##### ESP8266 Boards (e.g., NodeMCU)  
- Very **cheap** and widely available  
- Built on the popular **ESP8266 chip**  
- Powerful enough for most beginner IoT projects  
- Many variations exist (some even with **battery connector** built onto the board)  
- Strong community and huge number of tutorials  

📄 [NodeMCU ESP8266](https://www.nodemcu.com/)  

---

##### Arduino Mega / Giga  
- Much **larger boards** with **many more pins**  
- Useful if you need to connect lots of sensors or devices at once  
- Same Arduino ecosystem, but not as compact as the Uno or Feather  

---




 

---

# Coding with Arduino  

A typical Arduino sketch follows this sequence:  
1. **Libraries** (optional)  
2. **Declare variables**  
3. `void setup()` (runs once at start)  
4. `void loop()` (runs repeatedly)  
5. **Functions** (optional, for organizing code)  

---

## Example 001 – Basic LED Blink  

<details>
<summary>Click to expand code</summary>

```c
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
```

</details>  

---

## Example 002 – Blink with Variable + Serial Feedback  

We introduce a **variable** and send output to the **Serial Monitor**.  

> ℹ️ The Arduino Uno R4 WiFi has different memory types:  
> - **EEPROM**: 8 KB (permanent memory)  
> - **RAM**: 32 KB (temporary runtime data like variables)  
> - **Flash**: 256 KB (where code is stored)  

Common datatypes include `boolean`, `char`, `int`, and `float`.  

<details>
<summary>Click to expand code</summary>

```c
int pause = 50;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(pause);
  digitalWrite(LED_BUILTIN, LOW);
  delay(pause);
  Serial.print("The delay is: "); 
  Serial.print(pause);
  Serial.println("ms");
}
```

</details>  

---

## Example 003 – Blink with a Function  

Functions help keep code **organized and reusable**.  

<details>
<summary>Click to expand code</summary>

```c
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  flash(50, LED_BUILTIN);
  flash(500, LED_BUILTIN);
}

void flash(int pause, int ledNumber) {
  digitalWrite(ledNumber, HIGH);
  delay(pause);
  digitalWrite(ledNumber, LOW);
  delay(pause);
  Serial.print("The delay is: "); 
  Serial.print(pause);
  Serial.println("ms");
}
```

</details>  

---

## Example 004 – Control with if Statement  

<details>
<summary>Click to expand code</summary>

```c
bool Fast = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Fast == true) {
    flash(50, LED_BUILTIN);
  } else {
    flash(400, LED_BUILTIN);
  }
}

void flash(int period, int led) {
  digitalWrite(led, HIGH);
  delay(period);
  digitalWrite(led, LOW);
  delay(period);
  Serial.print("The delay is: ");
  Serial.println(period);
}
```

</details>  

---

## Example 005 – Iteration with for Loop  

<details>
<summary>Click to expand code</summary>

```c
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i = i + 1) {
    Serial.print("Loop Nr.");
    Serial.print(i);
    Serial.print("	");
    flash(20, LED_BUILTIN);
  }
}

void flash(int period, int led) {
  digitalWrite(led, HIGH);
  delay(period);
  digitalWrite(led, LOW);
  delay(period);
  Serial.print("The delay is: ");
  Serial.println(period);
}
```

</details>  

---

## Example 006 – For Loop with Array  

<details>
<summary>Click to expand code</summary>

```c
int timedelay[] = {200, 40, 50, 500, 70};

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 5; i = i + 1) {
    Serial.print("Loop Nr.");
    Serial.print(i);
    Serial.print("	");
    Serial.print("Number from array: ");
    Serial.print(timedelay[i]);
    Serial.print("	");
    flash(timedelay[i], LED_BUILTIN);
  }
}

void flash(int period, int led) {
  digitalWrite(led, HIGH);
  delay(period);
  digitalWrite(led, LOW);
  delay(period);
  Serial.print("The delay is: ");
  Serial.println(period);
}
```

</details>  

---

## Example 007 – Control LED via Serial Monitor  

<details>
<summary>Click to expand code</summary>

```c
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char letter = Serial.read();
    if (letter == '1') {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED is ON!");
    }
    else if (letter == '0') {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED is OFF!");
    }
  }
}
```

</details>  

---

## Example 008 – Messages in the Serial Interface  

<details>
<summary>Click to expand code</summary>

```c
void setup() {
  Serial.begin(9600);
}

void loop() {
  String message = "";
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
      message = message + char(Serial.read());
      delay(250);
    }
    Serial.println(message);
  }
}
```

</details>  

---



































![alt text](images/Arduino_Logo.svg.png)


# Introduction to Arduino


## What is Arduino, where does it come from?
Arduino is an open-source electronics platform that allows users to program microcontrollers. It was developed in 2003 at the Interaction Design Institute Ivrea (IDII) in Ivrea, Italy by Massimo Banzi. From the outset, it has been developed as an open-source language that allows easy programming of low-cost microprocessors. This proved to be remarkably successful, and Arduino managed to establish itself as one of the main languages to program microprocessors and for easy prototyping.

![alt text](images/BarArduinoReal.jpg)

Above the bar “Arduino” in Ivrea where the founders used to hang out. 

![alt text](images/FirstArduino.jpg)

The image on the top shows the first Arduino. 

You can visit the webpage here:  **[Arduino Website](https://www.arduino.cc/)**

## What can it do and what not?
Arduino enables the creation of prototypes for microprocessors, allowing the development of various devices such as sensors, robots, and smart IoT devices. However, Arduino is different from computers like the Raspberry Pi. While it is short on processing power and has no operating system, it is more energy-efficient, compact, and easier to deal with (and also cheaper!).

Ardunio has open the world of microprocessoprs to the wider public:

1. Arduino programming is not geared toward professional production. It employs a simplified language designed for prototyping. Imagine this this language as an *extra layer* that sits between you and the microprocessor.  
2. Most, but not every microprocessor can be programmed using Arduino. The *extra layer* must exist and has to be intalled separatly.
3. The break though is that, the same -simplified- script can work on different microprocessors (with minor adaptations!).


## Language

The Arduino project consists of two parts: the language and the hardware. Both are linked together, as the language can only work on hardware that "knows" Arduino. The language is based on the **C Language**, a low-level language with a few simplifications.

The programming environment is called **Arduino IDE**. It translates the code into the specific language of the microprocessor, making Arduino accessible and successful.

> [!NOTE]
> For each new microprocessor, you need to configure the IDE accordingly. If it's not already available, you will need to download and install the correct configuration.


## The Ecosytem

Arduino is an open-source project. This transparency means anyone can use it without restrictions. Many companies now produce Arduino-compatible boards. Here are a few examples:

- [Adafruit](https://www.adafruit.com/)
- [SparkFun](https://www.sparkfun.com/)
- [Seeed Studio](https://www.seeedstudio.com/)

You can find various types on Amazon or eBay. It's advisable to choose well-known brands for better documentation.


---
# Our Board

There are many types of boards available, each suited to different projects. The Arduino **Uno R4 Wifi** is a felxible entry-level board suitable for a wide range of applications. 

![alt text](images/arduino-uno-r4-wifi-arduino.jpg)

- [Arduino Uno R4 Wifi Documentation](https://docs.arduino.cc/hardware/uno-r4-wifi/)

---

# Coding in Arduino (C Language)

**000 - Anatomy**
The typical arduino sketch follows this sequence. 

- Libraries
- Declare variables
- `Void setup()`
- `Void loop()`
- Functions

Refer to the [Arduino Reference Page](https://www.arduino.cc/reference/en/) for more information.

Arduino compiles the code in the IDE as follows:

![alt text](images/Compiling.png)

---

### 001 - Basic LED Blink Sketch

Anatomy of a sketch, basic intro, commands, setup, and loop:

```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
```

---

### 002 - Basic LED Blink Sketch with Variable and Feedback over the Serial Monitor

Introduction of a variable and output over the serial monitor. We’ll declare our first variable, and it’s worth looking at typical datatypes in C.

1 byte is 8 bits (00000001)

- 1 is `00000001`
- 2 is `00000010`
- ...
- 256 is `11111111` (the largest possible value in byte)

The Arduino Rev 4 Wifi has different types of memory:

- **EEPROM:** 8 KB (permanent memory)
- **RAM:** 32 KB (temporary data or runtime data such as variables)
- **FLASH:** 256 KB (where the code is saved)

Common datatypes include `boolean`, `char`, `int`, and `float`.

![alt text](images/Datatypes.png)

```cpp
int pause = 50;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(pause);
  digitalWrite(LED_BUILTIN, LOW);
  delay(pause);
  Serial.print("The delay is: "); 
  Serial.print(pause);
  Serial.println("ms");
}
```

---

### 003 - Blink Sketch with a Function

Introduction of a simple function to keep the code organized, shorter, and modular:

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  flash(50, LED_BUILTIN);
  flash(500, LED_BUILTIN);
}

void flash(int pause, int ledNumber) {
  digitalWrite(ledNumber, HIGH);
  delay(pause);
  digitalWrite(ledNumber, LOW);
  delay(pause);
  Serial.print("The delay is: "); 
  Serial.print(pause);
  Serial.println("ms");
}
```

---

### 004 - Control Structure with “if”

An `if` control structure with a simple conditional statement:

```cpp
bool Fast = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Fast == true) {
    flash(50, LED_BUILTIN);
  } else {
    flash(400, LED_BUILTIN);
  }
}

void flash(int period, int led) {
  digitalWrite(led, HIGH);
  delay(period);
  digitalWrite(led, LOW);
  delay(period);
  Serial.print("The delay is: ");
  Serial.println(period);
}
```

---

### 005 - Iterations with the "for" Loop

A simple **for** loop example:

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i = i + 1) {
    Serial.print("Loop Nr.");
    Serial.print(i);
    Serial.print("\t");
    flash(20, LED_BUILTIN);
  }
}

void flash(int period, int led) {
  digitalWrite(led, HIGH);
  delay(period);
  digitalWrite(led, LOW);
  delay(period);
  Serial.print("The delay is: ");
  Serial.println(period);
}
```

---

### 006 - For Loop with Array

Demonstrating array syntax and how to call a number from an array:

```cpp
int timedelay[] = {200, 40, 50, 500, 70};

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 5; i = i + 1) {
    Serial.print("Loop Nr.");
    Serial.print(i);
    Serial.print("\t");
    Serial.print("Number from array: ");
    Serial.print(timedelay[i]);
    Serial.print("\t");
    flash(timedelay[i], LED_BUILTIN);
  }
}

void flash(int period, int led) {
  digitalWrite(led, HIGH);
  delay(period);
  digitalWrite(led, LOW);
  delay(period);
  Serial.print("The delay is: ");
  Serial.println(period);
}
```

---

### 007 - Communication via the Serial Monitor

Example showing how to control an LED via the serial monitor:

```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char letter = Serial.read();
    if (letter == '1') {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED is on!");
    }
    else if (letter == '0') {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED is OFF!");
    }
  }
}
```



---

### 008 - Messages in the Serial Interface

Sending and receiving messages via the serial monitor:

```cpp
void setup() {
  Serial.begin(9600);
}

void loop() {
  String message = "";
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
      message = message + char(Serial.read());
      delay(250);
    }
    Serial.println(message);
  }
}
```

---




