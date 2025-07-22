# 🔗 pipex – 42 Barcelona

[![Language: C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))  
[![Project: 42](https://img.shields.io/badge/42%20Network-pipex-1f425f.svg)](https://42.fr/)  
[![Status: Completed](https://img.shields.io/badge/status-completed-brightgreen)](https://github.com/)  
[![License: Custom](https://img.shields.io/badge/license-42%20School%20Policy-lightgrey)](https://42.fr/)

---

## 🌐 English Description

**pipex** is a Unix-based project where I recreated the behavior of shell piping (`|`) by chaining commands through inter-process communication. The goal was to deepen my understanding of process creation, file descriptor manipulation, and command execution using system calls like `pipe()`, `fork()`, and `execve()` in C.

The program simulates the following shell behavior:

```bash
< infile cmd1 | cmd2 > outfile
```
Key concepts explored:

Process creation and synchronization

Redirection of standard input/output

Executing commands via the PATH

File descriptor and pipe management

> ✅ **Status:** This repository is complete and will not receive further updates. 
---

## 🇪🇸 Descripción en Español

**pipex** es un proyecto basado en Unix en el que repliqué el comportamiento del pipe (|) de la shell, encadenando comandos mediante comunicación entre procesos. El objetivo fue profundizar en el manejo de procesos, descriptores de archivo y ejecución de comandos usando llamadas al sistema como `pipe()`, `fork()` y `execve() en C.
El programa simula el siguiente comportamiento de la shell:

```bash
< infile cmd1 | cmd2 > outfile
```
Conceptos clave abordados:

Creación y sincronización de procesos

Redirección de entradas y salidas estándar

Ejecución de comandos usando la variable PATH

Gestión de descriptores de archivo y pipes

> ✅ **Status:** Este repositorio está finalizado y no se actualizará.

---
## 🧪 How to Use

```bash
git clone https://github.com/ineiras/pipex.git
cd pipex
make
