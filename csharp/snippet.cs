static void Main(string[] args)
{
    Console.WriteLine("Hello World!");
    int i = 0;
    while(i < args.Length)
    {
        Console.WriteLine("{0}", args[i].ToString());
        i++;
    }
}