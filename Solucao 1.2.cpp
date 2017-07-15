#include <iostream>
#include <string>
using namespace std;

class NO {

public:
	char operador;
	NO* ProximoNO;

	NO(char operador) {
		this->ProximoNO = NULL;
		this->operador = operador;
	}

	~NO() {
	}

	friend class Pilha;
};

class Pilha {

public:
	NO* Topo;

	Pilha() {
		this->Topo = NULL;
	}

	~Pilha() {
		NO* atual;
		while (Topo != NULL) {
			atual = Topo->ProximoNO;
			Topo->~NO();
			Topo = atual;
		}
	}

	void Empilhar(char operador) {
		if (Topo != NULL) {
			if (Topo->operador == '(' && operador == ')') {
				Desempilhar();
				return;
			}
			else if (Topo->operador == '[' && operador == ']') {
				Desempilhar();
				return;
			}
			else if (Topo->operador == '{' && operador == '}') {
				Desempilhar();
				return;
			}
			else {
				NO* novo = new NO(operador);
				novo->ProximoNO = Topo;
				Topo = novo;
			}
		}
		if (Topo == NULL) {
			NO* novo = new NO(operador);
			this->Topo = novo;
		}
	}

	void Desempilhar() {
		NO* VelhoTopo = Topo;
		Topo = Topo->ProximoNO;
		VelhoTopo->~NO();
	}

	void PilhaVazia() {
		if (Topo != NULL) cout << "\nSetenca de operadores de precedencia invalida.";
		if (Topo == NULL) cout << "\nSetenca de operadores de precedencia valida.";
	}
};

int main() {

	Pilha Solucao;

	string entrada;
	int escolha;

	do {
		cout << "\n\n1. Inserir string de operadores de precedencia. \n2. Finalizar.\n";
		cin >> escolha;
		switch (escolha) {
		case 1: {
			cout << "\nInforme a string de operadores de precedencia: ";
			cin >> entrada;
			char* expressao = new char[entrada.size() + 1];
			strcpy(expressao, entrada.c_str());
			for (int i = 0; i < entrada.size(); i++) {
				if (expressao[i] == '(' || expressao[i] == ')' || expressao[i] == '[' || expressao[i] == ']' || expressao[i] == '{' || expressao[i] == '}') {
					Solucao.Empilhar(expressao[i]);
				}
			}
			Solucao.PilhaVazia();
			break;
		}
		case 2: break;
		default: break;
		}	
	} while (escolha != 2);
	
	Solucao.~Pilha();
}

