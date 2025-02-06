# Como Compilar e Executar o Projeto

## Passo 1: Configuração do Ambiente

Certifique-se de que você possui o seguinte:

- Um compilador **C++** instalado (como o `g++` do **GCC**).
- (Obs: este projeto foi desenvolvido no **Windows** com **MinGW**).
- Todos os arquivos do projeto na mesma pasta:
  - `main.cpp`
  - `Lexer.cpp`, `Lexer.h`
  - `Parser.cpp`, `Parser.h`
  - `Expression.cpp`, `Expression.h`
  - `Evaluator.cpp`, `Evaluator.h`

---

## Passo 2: Compilar o Projeto

Use o seguinte comando no terminal para compilar todos os arquivos:

```sh
g++ main.cpp Lexer.cpp Parser.cpp Expression.cpp Evaluator.cpp -o main
```

Este comando cria um executável chamado **main** (ou **main.exe** no Windows).

📌 **Certifique-se de que todos os arquivos `.cpp` e `.h` estão no mesmo diretório antes de executar o comando.**

---

## Passo 3: Executar o Programa

Após compilar, execute o programa digitando no terminal:

```sh
./main
```

Se você estiver no **Windows** (para rodar no **cmd**), use:

```sh
main.exe
```

🔹 **Para rodar no VS Code (mesmo no Windows), use o comando:**
```sh
./main
```

O programa solicitará que você insira o número de expressões a serem avaliadas e, em seguida, cada expressão em uma nova linha.

---

## Passo 4: Inserir as Expressões

O programa solicita que você insira o número de expressões a serem avaliadas e, em seguida, cada expressão em uma nova linha.

### **Exemplo de Entrada:**
```
3
2 + 3 * 4
(2 + 3) * 4
true && false || true
```

### **Saída Esperada:**
```
14
20
true
```

---

## 🚨 Erros Possíveis

O programa detecta e exibe **"error"** nos seguintes casos:

### **Divisão por zero:**
**Exemplo:**
```
2 / 0
```
**Saída:**
```
error
```

### **Sintaxe inválida:**
**Exemplos:**
```
2 + * 3
(2 + )
```
**Saída:**
```
error
```
