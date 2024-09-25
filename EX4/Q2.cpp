void imprimePai(no *T, int x)
{
    no *pai = encontraPai(T, x, NULL);
    if (pai != NULL)
    {
        cout << "\n O pai do no " << x << " e: " << pai->info;
    }
    else
    {
        cout << "\n O no " << x << " nao possui pai (e a raiz ou nao foi encontrado)";
    }
}

no *encontraPai(no *T, int x, no *pai)
{
    if (T == NULL)
    {
        return NULL;
    }
    if (T->info == x)
    {
        return pai;
    }
    if (x < T->info)
    {
        return encontraPai(T->Llink, x, T);
    }
    else
    {
        return encontraPai(T->Rlink, x, T);
    }
}
