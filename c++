/*
Name: Ibrahim Amgd Algezoly.
Grade: 2nd.
Department: Computer Eng.
*/
#include <iostream>  //استدعاء لمكتبة الادخال و الاخراج
#include<bits/stdc++.h>
using namespace std; // std هنا قمنا بتضيمن النطاق

class Score{

    public:
    int stuDegree;
    Score *next;
};

void push(Score** head_ref, int new_stuDegree)  //إدراج عقدة جديدة في مقدّمة القائمة
{ 
	Score* new_score = new Score();  /* 1. حجز موقع العقدة في الذاكرة */

	new_score->stuDegree = new_stuDegree;  /* 2. إضافة البيانات */

	new_score->next = (*head_ref);  /* 3. جعل رأس القائمة هو العقدة التالية للعقدة الجديدة */
	
	(*head_ref) = new_score;  /* 4. تحريك رأس القائمة ليشير إلى العقدة الجديدة */
};

void insertAfter(Score* prev_score, int new_stuDegree)  /* إدراج عقدة بعد العقدة السابقة المعطاة */
{ 
	if (prev_score == NULL)  /* Null التحقق من أنّ العقدة السابقة المعطاة تحمل القيمة */
	{ 
		cout<<"the given previous Score cannot be NULL"; 
		return; 
	} 
	Score* new_score = new Score();  /*  حجز موقع العقدة الجديدة في الذاكرة */

	new_score->stuDegree = new_stuDegree;  /*  إضافة البيانات */

	new_score->next = prev_score->next;  /*  جعل العقدة اللاحقة للعقدة الجديدة هي العقدة اللاحقة للعقدة السابقة */

	prev_score->next = new_score;  /*  تحريك العقدة التالية للعقدة السابقة لتصبح العقدة الجديدة */
};

void append(Score** head_ref, int new_stuDegree)  //إلحاق عقدة جديدة في نهاية القائمة
{ 
	Score* new_score = new Score();  /*  حجز موقع العقدة الجديدة في الذاكرة */

	Score *last = *head_ref;  /* يستخدم في الخطوة */

	new_score->stuDegree = new_stuDegree;  /*  إدراج البيانات */

	new_score->next = NULL;  /*  ستكون العقدة الجديدة هي العقدة الأخير في القائمة
	لذا سنجعل العقدة اللاحقة لها هي
	NULL*/
	if (*head_ref == NULL)  /*  إن كانت القائمة فارغةً
	ستكون العقدة الجديدة في رأس القائمة*/
	{ 
		*head_ref = new_score; 
		return; 
	} 
	while (last->next != NULL)  /*  وإن لم تكن القائمة فارغة ننقل العقدة الجديدة إلى نهاية القائمة */
		last = last->next; 
	last->next = new_score; /* نغير العقدة اللاحقة للعقدة الأخيرة. */
	return; 
}; 

void deleteScore(Score *head, Score *n)  // تحذف الدالة أول ظهور للمفتاح المعطى في القائمة المترابطة
{ 
	if (head == n)     
	{ 
		if (head->next == NULL)
        {
            cout<<"There is only one node."<<"The list can't be made empty";
            return ;
        }
        head->stuDegree = head->next->stuDegree;  
        n = head->next;  
        head->next = head->next->next;  
        return;  
    }  
    Score *prev = head;  
    while(prev->next != NULL && prev->next != n)  
        prev = prev->next;  
    if(prev->next == NULL)  
    {  
        cout << "\nGiven node is not present in Linked List";  
        return;  
    }  
    prev->next = prev->next->next;  
    
    return;  
};  

bool search(Score* head, int x) 
{ 
	Score* current = head; // تهيئة العقدة الحالية
	while (current != NULL) 
	{ 
		if (current->stuDegree == x) 
			return true; 
		current = current->next; 
	} 
	return false; 
;} 


void printList(Score *d) 
{ 
	while (d != NULL) 
	{ 
		cout << d->stuDegree << " "; 
		d = d->next; 
	} 
}; 



class Stack 
{ 
    int top; 
public: 
    int a[1000];    //تعيين الحد الأعلى للكدس 
  
    Stack()  { top = -1; } 
    bool push(int x); 
    int pop(); 
    bool isEmpty(); 
}; 
  
bool Stack::push(int x) 
{ 
    if (top >= (1000-1)) 
    { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else
    { 
        a[++top] = x; 
        cout<<x <<" pushed into stack\n"; 
        return true; 
    } 
} 
  
int Stack::pop() 
{ 
    if (top < 0) 
    { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else
    { 
        int x = a[top--]; 
        return x; 
    } 
} 
  
bool Stack::isEmpty() 
{ 
    return (top < 0); 
};



class Queue 
{ 
	public: 
	int front, rear, size; 
	unsigned capacity; 
	int* array; 
}; 

// تنشئ هذه الدالة رتلًا بسعة معينة
// وتهيئ الرتل ليكون بالحجم 0
Queue* createQueue(unsigned capacity) 
{ 
	Queue* queue = new Queue(); 
	queue->capacity = capacity; 
	queue->front = queue->size = 0; 
	queue->rear = capacity - 1; // enqueue هذه الخطوة مهمة راجع الدالة
	queue->array = new int[(queue->capacity * sizeof(int))]; 
	return queue; 
} 

// يصبح الرتل ممتلئًا عندما
// عندما يصبح حجم الرتل مساويًا لسعته

int isFull(Queue* queue) 
{ return (queue->size == queue->capacity); } 

// يصبح الرتل فارغًا عندما يصبح حجمه مساويًا للصفر

int isEmpty(Queue* queue) 
{ return (queue->size == 0); } 

// تضيف الدالة عنصرًا إلى الرتل
// وتعدل الفهرس الأخير وحجم الرتل
void enqueue(Queue* queue, int item) 
{ 
	if (isFull(queue)) 
		return; 
	queue->rear = (queue->rear + 1) % queue->capacity; 
	queue->array[queue->rear] = item; 
	queue->size = queue->size + 1; 
	cout << item << " enqueued to queue\n"; 
} 

// تحذف الدالة عنصرًا من الرتل
// وتعدل الفهرس الأول وحجم الرتل
int dequeue(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	int item = queue->array[queue->front]; 
	queue->front = (queue->front + 1) % queue->capacity; 
	queue->size = queue->size - 1; 
	return item; 
} 

// تجلب الدالة العنصر الأول في الرتل
int front(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->front]; 
} 

// تجلب الدالة العنصر الأخير في الرتل
int rear(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->rear]; 
}; 

int main(){
    
    Score* head=NULL; Score* second=NULL; Score* third=NULL; Score* fourth=NULL;
    int x= 33;
    class Stack s;
    Queue* queue = createQueue(1000); 
    string choose, sel;

    cout<<"Select the method you want to try: \n 1- list \n 2- stack \n 3- queue \n";
    cin>>choose;
    if (choose=="list"){
        head = new Score(); second = new Score(); third = new Score(); fourth = new Score();

        head->stuDegree = 10; head->next = second; 
        second->stuDegree = 20; second->next = third; 
        third->stuDegree = 30; third->next = fourth;
        fourth->stuDegree = 40; fourth->next = NULL;  
        printList(head);
        cout<<endl;
        cout<<"Choose what do you want to do:add/sub:- ";
        cin>>sel;
        if (sel=="add"){
            append(&head, 5);
            push(&head, 15);  
            insertAfter(head->next, 25); 
            printList(head);
            cout<<endl;
            cout<<"--<--<--<--<--<--\n";
        }else if (sel=="sub"){
            deleteScore(head, head->next); 
            printList(head);
            cout<<endl;
            cout<<"--<--<--<--<--<--\n";
        }     
        search(head, 15)? cout<<"15 is found\n" : cout<<"15 Not found\n";
        printList(head);
        cout<<endl;
    }else if (choose=="stack"){
        s.push(10); 
        s.push(20); 
        s.push(30); 
        cout<<s.pop() << " Popped from stack\n";
        cout<<endl;
    }else if (choose=="queue"){
        enqueue(queue, 10); 
	    enqueue(queue, 20); 
	    enqueue(queue, 30); 
	    enqueue(queue, 40); 

    	cout<<dequeue(queue)<<" dequeued from queue\n"; 

    	cout << "Front item is " << front(queue) << endl; 
    	cout << "Rear item is " << rear(queue) << endl; 
    };

    
    return 0;
}
