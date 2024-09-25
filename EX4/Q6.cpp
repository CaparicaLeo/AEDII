int somaNos(no *T){
    if (T == NULL){
        return 0;
    } else {
        return T->info + somaNos(T->Llink) + somaNos(T->Rlink);
    }
}