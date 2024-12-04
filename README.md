# 🗣️ Minitalk: A Simple Client-Server Communication with Signals! 🚀

Welcome to **Minitalk**, where **signals** are the messengers and **client-server communication** becomes fun! 🌟  
This project is all about building a lightweight communication system using **signals** in Unix. The client and server communicate through signals to send and receive messages. 📡

---

## 📖 **Project Overview**  

The main goal of **Minitalk** is to create a client-server communication system where:
- The **server** listens for incoming signals, reconstructs the message, and displays it.
- The **client** sends a message to the server using signals.

### **How It Works:**
- The **server** starts first and displays its **Process ID (PID)**.
- The **client** sends the message by encoding each character as a binary signal using **SIGUSR1** and **SIGUSR2**.
- The **server** receives these signals, decodes them, and displays the message.

---

## 💻 **Key Features**

### **Server:**
- Starts by displaying its **PID** to let the client know where to send the signals.  
- Listens for incoming **SIGUSR1** and **SIGUSR2** signals.
- Reconstructs the received message from the binary signals and prints it.  
- Runs **indefinitely**, ready to receive messages from several clients one after another.

### **Client:**
- Takes the **server’s PID** and the message to send as input.  
- Sends the message, one character at a time, using **SIGUSR1** and **SIGUSR2** for binary encoding.  
- Terminates gracefully after sending the message.

---

## 🛠️ **Technical Implementation**

### **Signal Usage**
- We use **SIGUSR1** and **SIGUSR2** signals to encode the binary representation of each character in the message.
- The client sends these signals to the server, which decodes them back into the original string.

This system allows us to communicate **without traditional networking**, just pure signal magic! 🎩✨

---

## 🚀 **Getting Started**

1. **Clone the repository**:  
   ```bash
   git clone https://github.com/ananunan/Minitalk.git
   cd Minitalk
   
2. **Compile the project**:
   
   `make`

3. **Start the server**:
   
In the terminal, run the server first:
`./server`

- The server will print its PID.
  
4. **Run the client**:
In a separate terminal, run the client with the server PID and the message you want to send:
`./client <server_pid> "Your message here"`

5. The server will receive the message and print it in the terminal! 🎉

## 🌟 **Why Minitalk**?

- **Simple and Lightweight**: Minitalk is a minimalistic project that shows how powerful Unix signals can be for inter-process communication.
- **Learning Opportunity**: This project is perfect for understanding signals, binary encoding, and how to build client-server applications with just a few lines of code.
- **Fun**: It’s a fun way to use something as simple as signals to send messages between processes!
