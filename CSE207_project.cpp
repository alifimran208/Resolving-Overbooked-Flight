#include<bits/stdc++.h>
#define STACK_MAX 20
using namespace std;
bool a=1;
struct Stack
{
    string data[STACK_MAX];
    int mileage1[STACK_MAX];
    int year1[STACK_MAX];
    int sequence1[STACK_MAX];
    int priority1[STACK_MAX];
    int top;
};
struct node
{
    string name;
    int mileage;
    int year;
    int sequence;
    int priority;
};

void heapify(struct node arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].priority < arr[smallest].priority)
        smallest = l;

    if (r < n && arr[r].priority < arr[smallest].priority)
        smallest = r;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
//Sort data in descending order
void heapsort(struct node arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify1(struct node arr1[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr1[l].priority > arr1[largest].priority)
        largest = l;

    if (r < n && arr1[r].priority > arr1[largest].priority)
        largest = r;

    if (largest != i)
    {
        swap(arr1[i], arr1[largest]);
        heapify1(arr1, n, largest);
    }
}

//Sort data in ascending order
void heapsort1(struct node arr1[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify1(arr1, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr1[0], arr1[i]);
        heapify1(arr1, i, 0);
    }
}
void push(Stack *s,struct node item)
{
    if(s->top <STACK_MAX)
    {
        s->data[s->top]= item.name;
        s->mileage1[s->top]= item.mileage;
        s->year1[s->top]= item.year;
        s->sequence1[s->top]= item.sequence;
        s->priority1[s->top]= item.priority;
        s->top= s->top+1;
    }
    else
    {
        cout<<"The Stack is full "<<endl;
    }
}
void pop(Stack *s)
{
    struct node item;
    if(s->top ==0)
    {
        cout<<"The stack is empty! "<<endl;
        a=0;
    }
    else
    {
        s->top= s->top-1;
        cout<<s->data[s->top]<<"\t"<<s->mileage1[s->top]<<"\t"<<s->year1[s->top]<<"\t"<<s->sequence1[s->top]<<"\t"<<s->priority1[s->top]<<endl;
    }
}
int main()
{
    struct Stack my_stack;
    my_stack.top=0;
    struct node temp;
    struct node *x,*y;
    int cancel;
    x= new node[15];
    y= new node[15];
    int n;
    cout<<"Input the number of passengers on the waiting list "<<endl;
    cin>>n;
    cout<<endl<<endl;
    cout<<"Name"<<"\t"<<"Mileage"<<"\t"<<"Year"<<"\t"<<"Sequence"<<"\t"<<"Priority"<<"\t"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>x[i].name>>x[i].mileage>>x[i].year>>x[i].sequence;
        x[i].priority= (x[i].mileage/1000)+x[i].year- x[i].sequence;  // priority= (mileage/1000)+ years- sequence
    }
    heapsort(x,n);
    cout<<endl<<endl;
    cout<<"Name"<<"\t"<<"Mileage"<<"\t"<<"Year"<<"\t"<<"Sequence"<<"\t"<<"Priority"<<"\t"<<endl;
    for(int i=0; i< n; i++)
    {
        cout<<x[i].name<<"\t"<<x[i].mileage<<"\t"<<x[i].year<<"\t"<<x[i].sequence<<"\t"<<x[i].priority<<endl;
    }
    for(int i=0; i<n; i++)
    {
        y[i]= x[i];
    }
    cout<<endl<<endl;
    heapsort1(y,n);
    cout<<"Input the number of passengers canceled the flight "<<endl<<endl;
    cin>>cancel;
    cout<<endl<<endl;
    cout<<"Name"<<"\t"<<"Mileage"<<"\t"<<"Year"<<"\t"<<"Sequence"<<"\t"<<"Priority"<<"\t"<<endl;
    for(int i=0; i<n; i++)
    {
        temp= y[i];
        push(&my_stack,temp);
    }
     my_stack.top=(my_stack.top)-cancel;
    for(int i=0; i<n; i++)
    {
         if(a) pop(&my_stack);
    }

}
