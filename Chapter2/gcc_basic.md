**2. Fondamenti di C**

D&R (Domande e risposte) pag 32

<br>

**2.1 utilizzo GCC opzioni:**

-Wall        --> mostra tutti i warning (Warning All) -O per avere effetto max

-W            --> Emette dei messaggi di warning addizzionali oltre a quelli prodotti da -Wall

-pedantic -->  Causa il rifiuto di tutti i programmi che utilizzano funzioni non standard

-ansi         --> Disabilità le funzionalità del GCC che non appartengono allo standard C e                         abilità le poche funzionalità standard che sono normalmente disabilitate

-std=c89  --> specifica la versione del C che deve usare il compilatore

-std=c99 

-S  [file.c] --> da c ad ASM (file.s)

<br>

**2.2 uso dettagliato di gcc:**

```shell
man gcc
```

<br>

**2.3 uso riassuntivo di gcc:**

```shell
sudo apt install tldr
tldr -u
tldr gcc
```
