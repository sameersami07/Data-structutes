 #include<stdio.h>
 #include<stdlib.h>
 #define MAX 5
 int stack[MAX];
 int top = -1;
  void push(int);
  void pop();
  void display();
  int main()
    {
       int choice,item;
       char ch;
       while(1)
       {
          printf("\nMean\n");
          printf("1.push\n");
          printf("2.pop\n");
          printf("3.display\n");
          printf("4.exit\n");
          printf("Enter your choice:");
          scanf("%d",&choice);
          switch(choice)
          {
            case 1:printf("entre the element:");
                   scanf("%d",&item);
                   push(item);
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:exit(0); 
            default:printf("invalid choice\n");
         }
        }
       } 
       
      void push(int item)
      {
         if(top==MAX-1)printf("stack overflow\n");
         else 
         {
         stack[++top]=item;
         printf("elemets inserted\n");
         }
      }
      void pop()
      {
         if(top==-1)printf("stack underflow");
         else
         {
            printf("elemet deleted:%d\n",stack[top--]);
         }
       }
      void display()
      {
      int i;
        if(top==-1)printf("stack is empty\n");
        else
        {
        printf("stack content:\n");
        for(i=top;i>=0;i--)
             printf("%d",stack[i]);
       }
   } 
