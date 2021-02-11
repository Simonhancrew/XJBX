//not implement by me
//redo is needed
class PriorityQueue
{
    static void Swap(ref int a,ref int b)//交换方法
    {
        int c = a;
        a = b;
        b = c;
    }

    int[] arr = null;
    int size = 1<<7;
    int length = 0;
    public PriorityQueue()
    {
        arr = new int[size];
    }
    static void Down(int[] arr,int n,int len)//下沉
    {
        int child1 = 2 * n + 1;
        if (child1 >= len) return;
        int child2 = child1 + 1;
        if (child2 >= len || arr[child1] < arr[child2])
        {
            if (arr[child1] < arr[n])
            {
                Swap(ref arr[n], ref arr[child1]);
                Down(arr, child1, len);
            }
        }
        else
        {
            if (arr[child2] < arr[n])
            {
                Swap(ref arr[n], ref arr[child2]);
                Down(arr, child2, len);
            }
        }
    }
    static void Up(int[]arr,int i)//上浮
    {
        if (i == 0) return;
        int father = (i - 1) >> 1;
        if (arr[father] > arr[i])
        {
            Swap(ref arr[father], ref arr[i]);
            Up(arr, father);
        }
    }
    void Enlarge()//扩容
    {
        size <<= 1;
        int[] temp = new int[size];
        Array.Copy(arr, 0, temp, 0, length);
        arr = temp;
    }
    public void Push(int val)//入队
    {
        arr[length++] = val;
        Up(arr,length - 1);
        if (length == size)
            Enlarge();
    }
    public int Pop()//出队
    {
        int temp = arr[0];
        arr[0] = arr[length - 1];
        length--;
        Down(arr, 0, length);
        return temp;
    }
    public int Top { get { return arr[0]; } }//堆顶元素
    public int Size { get { return length; } }//获取规模
}
class KthLargest
{
    PriorityQueue aQueue = new PriorityQueue();
    int key;

    public KthLargest(int k, int[] nums)
    {
        key = k;
        for (int i = 0;i<nums.Length;i++)
        {
            aQueue.Push(nums[i]);
        }
    }
    public int Add(int val)
    {
        aQueue.Push(val);
        while (aQueue.Size > key)
            aQueue.Pop();
        return aQueue.Top;
    }
}
