# C SERVER

**date :** 02/08/2021

**author :** Anatole de Chauveron

**version :** 1.0.0

**copyrights :** All rights reserved

An exerice of server in C. This code for now contains the server script and the client script.
tol
## Installation

Before you run the project you must ensure that you have a running version of gcc.

```bash
git clone https://github.com/Anatole-DC/c_server.git
make all # Compile all the *.c files
```

## Usage

### Server

First you need to run the server script.

```bash
./server.exe 9092 #9092 beeing the port on which the server will listen
```
Nothing should appear as the server is waiting for a connection.

### Client

Now you need to use the client script to connect to the server. You can either use the script on the same machine as the server, or use a different machine, in which case, you will need to get the IP address of the machine on which the server is running.

The client script is used as such :

```bash
# Admitting that your server is listening on port 9092
./client.exe 127.0.0.1 9092     # In case you are running both scripts on the same machine
./client.exe 192.168.1.78 9092  # In case you'll be using another computer
```

You should see a message request in your command prompt, as soon as you will enter the message, you should get a "Hello World !" message. On the server side, the message that you typed should appear.
