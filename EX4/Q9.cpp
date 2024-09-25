no *menor_AB(no *T){
    if (T == NULL) {
        return NULL;
    }
    while (T->Llink != NULL) {
        T = T->Llink;
    }
    return T;
}