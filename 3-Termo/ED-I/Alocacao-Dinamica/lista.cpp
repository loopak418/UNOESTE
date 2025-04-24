#include <iostream>
#include <string>
#define nullptr NULL
using namespace std;

// ------------------ Estrutura do Nó ------------------
struct No {
    string valor;
    No* proximo;

    No(string val) {
        valor = val;
        proximo = nullptr;
    }
};

// ------------------ Classe da Lista ------------------
class Lista {
private:
    No* inicio;

public:
    Lista() {
        inicio = nullptr;
    }

    void exibirPrimeiro() {
        if (!inicio) cout << "Lista vazia\n";
        else cout << "Primeiro: " << inicio->valor << endl;
    }

    void exibirUltimo() {
        if (!inicio) {
            cout << "Lista vazia\n";
            return;
        }
        No* atual = inicio;
        while (atual->proximo)
            atual = atual->proximo;
        cout << "Último: " << atual->valor << endl;
    }

    void inserirFim(string val) {
        No* novo = new No(val);
        if (!inicio) {
            inicio = novo;
            return;
        }
        No* atual = inicio;
        while (atual->proximo)
            atual = atual->proximo;
        atual->proximo = novo;
    }

    void inserirEntre(string antes, string depois, string novoVal) {
        No* atual = inicio;
        while (atual && atual->proximo) {
            if (atual->valor == antes && atual->proximo->valor == depois) {
                No* novo = new No(novoVal);
                novo->proximo = atual->proximo;
                atual->proximo = novo;
                return;
            }
            atual = atual->proximo;
        }
        cout << "Posição não encontrada\n";
    }

    void consultar(string val) {
        No* atual = inicio;
        while (atual) {
            if (atual->valor == val) {
                cout << "Encontrado: " << atual->valor << endl;
                return;
            }
            atual = atual->proximo;
        }
        cout << "Não encontrado\n";
    }

    void exibirRecursivo(No* no) {
        if (!no) return;
        cout << no->valor << " -> ";
        exibirRecursivo(no->proximo);
    }

    void exibirTodos() {
        exibirRecursivo(inicio);
        cout << "NULL\n";
    }

    void excluir(string val) {
        No *atual = inicio, *anterior = nullptr;
        while (atual) {
            if (atual->valor == val) {
                if (!anterior)
                    inicio = atual->proximo;
                else
                    anterior->proximo = atual->proximo;
                delete atual;
                cout << "Removido: " << val << endl;
                return;
            }
            anterior = atual;
            atual = atual->proximo;
        }
        cout << "Elemento não encontrado\n";
    }

    void excluirTodos() {
        No* atual = inicio;
        while (atual) {
            No* temp = atual;
            atual = atual->proximo;
            delete temp;
        }
        inicio = nullptr;
    }

    void excluirTodosRec(No* no) {
        if (!no) return;
        excluirTodosRec(no->proximo);
        delete no;
    }

    void excluirRec() {
        excluirTodosRec(inicio);
        inicio = nullptr;
    }

    void inserirOrdenado(string val) {
        No* novo = new No(val);
        if (!inicio || val < inicio->valor) {
            novo->proximo = inicio;
            inicio = novo;
            return;
        }

        No* atual = inicio;
        while (atual->proximo && atual->proximo->valor < val)
            atual = atual->proximo;

        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
};

// ------------------ Função Principal ------------------
int main() {
    Lista lista;

    cout << "--- Inserindo ordenadamente ---\n";
    lista.inserirOrdenado("Carlos");
    lista.inserirOrdenado("Ana");
    lista.inserirOrdenado("João");
    lista.inserirOrdenado("Bruno");
    lista.exibirTodos(); // Ana -> Bruno -> Carlos -> João

    cout << "\n--- Exibir primeiro e último ---\n";
    lista.exibirPrimeiro();
    lista.exibirUltimo();

    cout << "\n--- Consultar elemento ---\n";
    lista.consultar("Carlos");
    lista.consultar("Zelda");

    cout << "\n--- Inserir no fim ---\n";
    lista.inserirFim("Zelda");
    lista.exibirTodos();

    cout << "\n--- Inserir entre dois conhecidos (Carlos e João) ---\n";
    lista.inserirEntre("Carlos", "João", "Daniel");
    lista.exibirTodos();

    cout << "\n--- Excluir elemento (Bruno) ---\n";
    lista.excluir("Bruno");
    lista.exibirTodos();

    cout << "\n--- Excluir todos (iterativo) ---\n";
    lista.excluirTodos();
    lista.exibirTodos();

    cout << "\n--- Recriando lista e excluindo recursivamente ---\n";
    lista.inserirOrdenado("Leo");
    lista.inserirOrdenado("Zoe");
    lista.inserirOrdenado("André");
    lista.exibirTodos();
    lista.excluirRec();
    lista.exibirTodos();

    return 0;
}
