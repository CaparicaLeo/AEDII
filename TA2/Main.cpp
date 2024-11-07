#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_tamanho = 100; // Tamanho máximo do heap
int heap[MAX_tamanho];       // Array para armazenar o MaxHeap
int tamanho = 0;             // Variável para rastrear o tamanho atual do heap

// Função para reorganizar o heap de baixo para cima (heapify up)
void corrigirCima(int index) {
    if (index == 0) return; // Se estiver na raiz, nada a fazer

    int parent = (index - 1) / 2;
    if (heap[index] > heap[parent]) {
        swap(heap[index], heap[parent]);
        corrigirCima(parent);
    }
}

// Função para reorganizar o heap de cima para baixo (heapify down)
void corrigirBaixo(int index) {
    int maior = index;
    int Llink = 2 * index + 1;
    int Rlink = 2 * index + 2;

    if (Llink < tamanho && heap[Llink] > heap[Rlink]) {
        maior = Llink;
    }

    if (Rlink < tamanho && heap[Rlink] > heap[maior]) {
        maior = Rlink;
    }

    if (maior != index) {
        swap(heap[index], heap[maior]);
        corrigirBaixo(maior);
    }
}

// Função para inserir um elemento no MaxHeap
void insira(int value) {
    if (tamanho >= MAX_tamanho) {
        cout << "Heap está cheio!" << endl;
        return;
    }

    heap[tamanho] = value;
    corrigirCima(tamanho);
    tamanho++;
}

// Função para remover e retornar o elemento máximo (raiz) do MaxHeap
int maximoValor() {
    if (tamanho == 0) {
        cout << "Heap vazio!" << endl;
        return -1;
    }

    int max = heap[0];
    heap[0] = heap[tamanho - 1];
    tamanho--;
    corrigirBaixo(0);

    return max;
}

// Função para exibir o heap
void printarHeap() {
    for (int i = 0; i < tamanho; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    // Inserindo elementos no MaxHeap
    insira(10);
    insira(20);
    insira(5);
    insira(30);
    insira(25);

    cout << "MaxHeap atual: ";
    printarHeap();

    // Extraindo o máximo
    cout << "Máximo extraído: " << maximoValor() << endl;

    cout << "MaxHeap após extração: ";
    printarHeap();

    return 0;
}
