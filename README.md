# Solucao-1.2
Proposta de algoritmo para solução do problema 1.2: Validar o input (entrada) de sequência de operadores de precedência.

Foi utilizado o paradigma de orientação à objetos com uma estrutura similar a uma pilha dinâmica. O algoritmo verifica a string informada pelo usuário e empilha qualquer operador de precedência que encontrar, desempilhando ao mesmo tempo operadores de precedência "equivalentes" ("( com )", "[ com ]", "{ com }") que estejam em sequência.

Neste processo, se ao terminar a análise a pilha estiver vazia, a string apresenta uma sequência de operadores de precedência válida. 

O algoritmo foi desenvolvido na linguagem C++, para o console win32, na IDE Visual Studio 2017.
