void apagaArvore(no *T){
    if (T != NULL){
        apagaArvore(T->Llink);
        apagaArvore(T->Rlink);
        delete T;
    }
}