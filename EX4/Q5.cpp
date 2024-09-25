int contaNos(no *T){
    if (T == NULL){
        return 0;
    } else {
        return 1 + contaNos(T->Llink) + contaNos(T->Rlink);
    }
}
