//变量重定义
int a;
int a;

//使用未定义的函数名
int main()
{
    a = 8;
}

//使用未定义的函数
int main()
{
    int a;
    a = test(1);
    return;
}

//变量赋值时类型错误
int main()
{
    int a;
    a = 1;
    void b;
    b = a;
    return 1;
}

//函数形参和实参不匹配
int demo()
{
    return 1;
}
int main()
{
    int c;
    c = demo(1);
    return 1;
}

//寄存器是否正常选用
int main(void)
{
    int a;int b;int c;int d;int e;int f;int g;int h;int i;int j;int k;int l;int m;int n;int o;int p;int q;int r;int s;int t;int u;
    
    a = 0;b = 1;c = 2;d = 3;e = 4;f = 5;g = 6;h = 7;i = 8;j = 9;k = 10;l = 11;m = 12;n = 13;o = 14;p = 15;q = 16;r = 17;s = 18;t = 19;u = 20;

    a = 0;b = 1;c = 2;d = 3;e = 4;f = 5;g = 6;h = 7;i = 8;j = 9;k = 10;l = 11;m = 12;n = 13;o = 14;p = 15;q = 16;r = 17;s = 18;t = 19;

    return 1;
}
