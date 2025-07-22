# 🔗 pipex – 42 Barcelona

[![Language: C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))  
[![Project: 42](https://img.shields.io/badge/42%20Network-pipex-1f425f.svg)](https://42.fr/)  
[![Status: Completed](https://img.shields.io/badge/status-completed-brightgreen)](https://github.com/)  
[![License: Custom](https://img.shields.io/badge/license-42%20School%20Policy-lightgrey)](https://42.fr/)

---

## 🌐 English Description

**pipex** is one of my first experiences building low-level tools in C, simulating how shell piping (`|`) works under the hood. It was a great opportunity to understand how commands can be chained together through processes and file descriptors.

The program mimics this shell behavior:

```bash
< infile cmd1 | cmd2 > outfile
```


**Key concepts explored:**

-  Creating and synchronizing processes with `fork()`

-  Connecting commands using pipes and file descriptors

-  Redirecting standard input/output manually

-  Executing binaries with `execve()` and resolving paths

> ✅ **Status:** This repository is complete and will not receive further updates. 


---

## 🇪🇸 Descripción en Español

**pipex** es un proyecto basado en Unix en el que repliqué el comportamiento del pipe (|) de la shell, encadenando comandos mediante comunicación entre procesos. El objetivo fue profundizar en el manejo de procesos, descriptores de archivo y ejecución de comandos usando llamadas al sistema como `pipe()`, `fork()` y `execve() en C.
El programa simula el siguiente comportamiento de la shell:

```bash
< infile cmd1 | cmd2 > outfile
```


**Conceptos clave abordados:**

-  Crear y sincronizar procesos usando `fork()`

-  Comunicar procesos a través de pipes

-  Redirigir la entrada y salida estándar a mano

-  Ejecutar comandos con `execve()` y buscar rutas en `PATH`

> ✅ **Status:** Este repositorio está finalizado y no se actualizará.


---
## 🧪 How to Use

```bash
git clone https://github.com/ineiras/pipex.git
cd pipex
make
