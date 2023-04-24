## Жизненный цикл процесса.
#### Напишите программу, которая:
1. создает и инициализирует переменную (можно две: локальную и
глобальную);
2. выводит ее (их) адрес(а) и содержимое;
3. выводит pid;
4. порождает новый процесс (используйте fork(2)).
5. в дочернем процессе выводит pid и parent pid.
6. в дочернем процессе выводит адреса и содержимое переменных,
созданных в пункте а;
7. в дочернем процессе изменяет содержимое переменных и
выводит их значение;
8. в родительском процессе выводит содержимое переменных;
9. в родительском процессе делает sleep(30);
10. в дочернем процессе завершается с кодом “5” (exit(2)).
11. в родительском процессе дожидается завершения дочернего,
вычитывает код завершения и выводит причину завершения и код
завершения если он есть. В каком случае кода завершения не будет?
#### Объясните результаты работы программы.
#### Понаблюдайте за адресными пространствами в procfs.
#### Понаблюдайте за состояниями процесса в procfs или с помощью утилиты ps.

## Usage
### Linux
```shell
# linux
mkdir "build"
gcc main.c -o build/main
clear
build/main
```

## Output example
```text
[2] address of global variable: 0x5580a99e2010, content of global variable 10
[2] address of local variable: 0x7ffeb3981ab8,  content of local variable: 20
[3] pid: 23761
[8] address of global variable: 0x5580a99e2010, content of global variable 10
[8] address of local variable: 0x7ffeb3981ab8,  content of local variable: 20
[4] child pid from child: 23766
[5] parent pid from child: 23761
[6] address of global variable: 0x5580a99e2010, content of global variable 10
[6] address of local variable: 0x7ffeb3981ab8,  content of local variable: 20
[7] new content of global variable: 30
[7] new content of local variable: 40
[11] child process exited with code 5
```