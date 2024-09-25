no *rotacaoDireita(no *p){
    no *temp, *q;
    q = p->Llink;
    temp = q->Rlink;
    q->Rlink = p;
    p->Llink = temp;
    return q;
}
