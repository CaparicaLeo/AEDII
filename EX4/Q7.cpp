no *rotacaoEsquerda(no *p){
    no *temp, *q;
    q = p->Rlink;
    temp = q->Llink;
    q->Llink = p;
    p->Rlink = temp;
    return q;
}