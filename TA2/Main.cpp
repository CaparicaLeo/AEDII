#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_tamanho = 100; 
int heap[MAX_tamanho];      
int tamanho = 0;             

void corrigirCima(int index) {
    if (index == 0) return; 

    int parent = (index - 1) / 2;
    if (heap[index] > heap[parent]) {
        swap(heap[index], heap[parent]);
        corrigirCima(parent);
    }
}

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

void insira(int value) {
    if (tamanho >= MAX_tamanho) {
        cout << "Heap está cheio!" << endl;
        return;
    }

    heap[tamanho] = value;
    corrigirCima(tamanho);
    tamanho++;
}

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

void printarHeap() {
    for (int i = 0; i < tamanho; i++) {
        cout << heap[i] << " ";
    }
}
void mensagem(){
    cout << endl <<"-------MaxHeap atual------"<< endl;
    printarHeap();
    cout << endl <<"--------------------------"<< endl;
}

int main() {
    cout << "-------CASO DE TESTE INICIAL------"<< endl;
    cout << "8 : 51: 19 : 20 : 73 : 35" << endl;
    cout << "----------------------------------" << endl;

    insira(8);
    mensagem();
    insira(51);
    mensagem();
    insira(19);
    mensagem();
    insira(20);
    mensagem();
    insira(73);
    mensagem();
    insira(35);
    mensagem();

    cout << "Maximo extraido: " << maximoValor() << endl;

    cout << "MaxHeap apos extracao: ";
    printarHeap();

    return 0;
}
