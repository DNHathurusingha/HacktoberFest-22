int value(int *x, int *y){
    *x=20;
    *y=10;
    return 0;
}

int main()
{
    int x,y;
    x=10;
    y=20;
    value(&x,&y);
    printf("x = %d\ny = %d",x,y);
    return 0;
}
