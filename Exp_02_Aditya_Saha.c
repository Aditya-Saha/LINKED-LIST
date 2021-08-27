#include<stdio.h>
#include<stdlib.h>

//single link list node structure for all operations
typedef struct SLLnode
{
  int Data;
  struct SLLnode *Next;
}sllnode;

//single link list node structure made to store address in data part
typedef struct SLLNODE
{
  struct SLLnode *data;
  struct SLLNODE *next;
}sllnode2;



int main()
{
  
  int choice1 ,flag, choice2, key , max , min, counter;//variables declaration

  sllnode *LIST, *ploc , *loc, *LIST2;//sllnode structure pointers declaration

  sllnode2 *list, *q;//sllnode2 structure pointer declaration

  //assigning pointers to NULL
  list=NULL;

  LIST=NULL;
  LIST2=NULL;


  char ch, control;//declaration of char type variables 
 
  control='y';//storing y initilally

  //prototypes declaration
  int menu(int *);
  int submenu(int *);
  sllnode* CreateNode();
  int initialisation_of_list(sllnode **);
  int display(sllnode *);
  int order(int *, sllnode *);
  int insert_in_ordered_list(int ,sllnode **);
  int prepend(sllnode **);
  int append(sllnode **);
  int insert_after_a_value(int ,sllnode *,sllnode **);
  int insert_before_a_value(int  , sllnode *  ,sllnode ** );
  int maximum_value(int *,sllnode *, sllnode **);
  int minimum_value(int *, sllnode *, sllnode **, sllnode **);
  int search(int , sllnode *, sllnode **, sllnode **);
  int search_number_of_occurence(int ,int *,sllnode * ,sllnode2 **);
  int delete_a_value(sllnode **, sllnode *,sllnode *); 
  int delete_all_repeated_occurence(sllnode *);
  int concatenate(sllnode *,sllnode *);
  int merge(int , sllnode ** ,sllnode *);
  int randomize(sllnode **);
  int reverse(sllnode ** );



  //taking input of a linked list initially by calling the function
  initialisation_of_list(&LIST);

  while(1)
  {
    system("clear");

    menu(&choice1);//calling function to display original menu list

    switch(choice1)
    {
       case 1:display(LIST);//calling function to display the linked list 
       break;
  
       case 2: 
       if(LIST==NULL)
       {
         initialisation_of_list(&LIST);
       }
       order(&flag, LIST);//calling function to find the order of the list

       if(flag!=0)
       {
          printf("\nThe list is ordered.");

          insert_in_ordered_list(flag, &LIST);//calling function to insert value in orderly fashion

          printf("\nThe value is inserted in the ordered list accordingly.");
       }
       else
       {
          printf("\nThe list is un-ordered.");
          
          ch='y';
         
          while(1)
          {
            submenu(&choice2);//calling function to display sub_menu list
       
            switch(choice2)
            {
               case 1: prepend(&LIST);//function call
               printf("\nThe value is prepended");
               break;
                
               case 2: append(&LIST);//function call
               printf("\nThe value is appended");
               break;
               
               case 3: printf("\nEnter the node value after which you want to insert the new node:");
               scanf("%d",&key);//input of value
              
               search( key, LIST, &ploc, &loc) ;//function call to search the value
            
               if(loc==NULL)
               {
                 printf("\nThe value is not present in the list");
               }
               else
               {
                 insert_after_a_value( key ,loc, &LIST);//function call to insert after that value

                 printf("\nThe value is inserted");
               }
      
               break;

               case 4:printf("\nEnter the node value before which you want to insert the new node:");
               scanf("%d",&key);//input of value
              
               search( key, LIST, &ploc, &loc) ;//function call to search the value
            
               if(loc==NULL)
               {
                 printf("\nThe value is not present in the list");
               }
               else
               {

                 insert_after_a_value( key ,ploc, &LIST);//function call to insert before that value
                 printf("\nThe value is inserted");
               }
               break;

               case 5:maximum_value(&max, LIST, &loc);//function call to find maximum value
               
               insert_after_a_value( max ,loc, &LIST);//function call to insert after maximum value
               
               printf("\nThe value is inserted after maximum value");
               break;
            
               case 6:minimum_value(&min, LIST, &ploc,&loc);//function call to find minimum value
               
               insert_before_a_value(min, ploc ,&LIST);//function call to insert before minimum value
               
               printf("\nThe value is inserted before minimum value");
               break;
               default:printf("\nWrong choice .please read the menu  carefully.....\n");//displaying the error message

               break;  

            }  
            printf("\nDo you want to continue with the insert for unordered list?"); 

            getchar();

            printf("\n\n press y to continue:");//asking user whether he wants to continue thwn to press y 

            control=getchar();   
            if(control!='y')//checking whether user pressed any other character other than y
            {
              printf("\nOperations on unordered list is discontinued");
              break;//then break from the loop structure
            }
            
          }
        }
 
        break;

        case 3:printf("\nEnter the value to be searched:");
        scanf("%d",&key);//input of value

        search(key, LIST , &ploc, &loc);//function call to search the value

        printf("\nThe value is found at %p ",loc );//printing the address where value is found
        
        break;

        case 4:printf("\nEnter the value whose number of occurence to be searched:");
        scanf("%d",&key);//input of value
 
        counter=0;
        //function call to search number of occurence of a value
        search_number_of_occurence( key , &counter ,LIST ,&list);
        
         printf("\nThe number of occurence are %d and addresses are:\n",counter);
         
         q=list;
         while(q!=NULL)
         {
             printf("|%p| ,   ",q->data);

             q=q->next;
         }
        break;

        case 5:printf("\nEnter the value to be deleted:");
        scanf("%d",&key);//input of value
 
        search(key, LIST ,&ploc, &loc);//function call to search the value

        if(loc==NULL)
        {
          printf("\nThe value is not present in the list");
        }
        else
        {
          delete_a_value(&LIST , loc, ploc);//calling function to delete the value
          printf("\nThe value is deleted");
        }

        break;

        case 6:order(&flag, LIST);//calling function to find the order of the list
     
        if(flag!=0)
        {
          printf("\nDeletion of minimum value isn't allowed in this case");
        }
        else
        {
          minimum_value(&min, LIST, &ploc, &loc);//function call to find minimum value's location
 
          delete_a_value(&LIST , loc, ploc);//calling function to delete the value

          printf("\nThe minimum value is deleted from the unordered linked list");
        }
        break;
  
        case 7:delete_all_repeated_occurence( LIST);//function call to delete all repeated occurence
 
        printf("\nAll repeated occurence have been removed from the linked list");
        break;
 
        case 8:printf("\nGiving second linked list input...");

        LIST2=NULL;
        initialisation_of_list(&LIST2);//function call to take second linked list input

        concatenate( LIST, LIST2);//function call to concatenate two linked list
        printf("\nTwo linked list is concatenated in the original linked list...");
        break;
 
        case 9:order(&flag, LIST);//calling function to find the order of the list

        if(flag==0)
        {
           printf("\n The list is not ordered ....");
        }
        else
        { 
          counter=0;

          printf("\nGiving second linked list input...");

          printf("\nEnter the number of nodes you want in second linked list:");
          scanf("%d",&counter);
      

          LIST2=NULL;
          
          while(counter!=0)
          {
            insert_in_ordered_list( flag, &LIST2);
          
            counter= counter-1;
          }
          
          merge( flag ,&LIST, LIST2);//function call to merge two linked list
          
          printf("\nTwo linked list is merged in the original linked list...");
        }
        break;

        case 10: randomize(&LIST);//function call
        printf("\nThe linked list has been randomized");
        break;
 
        case 11: reverse(&LIST);//function call 

        printf("\nThe linked list has been reversed...");
        break;

        default:printf("\nWrong choice .please read the menu  carefully.....\n");//displaying the error message

        break;  

    }

    getchar();

    printf("\n\n press y to continue with original menu list:");//asking user whether he wants to continue thwn to press y 

    control=getchar();   
    if(control!='y')//checking whether user pressed any other character other than y
    {
       break;//then break from the loop structure
    }

  }
 
  return(1);
}
//------------------------------------------------------------------------------
int menu(int *choice1)//separate function to diplay the menu list to the user
{
  printf("\t\tThe menu of operations are listed below ");//showing menu
 
  printf("\n1.Display the content of the Linked-List along with node address.\n2. Insert a value.\n3.Search a value in the Linked-List as per the order/ un-order.\n4. Search the number of occurrences of a given value from the Linked-List.\n5.Delete a given value from the Linked-List as per the order/ un-order.\n6.Delete minimum value from the Linked-List(only for un-ordered list).\n7.Remove all repeated occurrence from the Linked-List.\n8.Concatenation of two un-ordered Linked List.\n9.Merge of two ordered Linked List.\n10.Randomize an ordered list.\n11.Reverse the Linked-List.");

  printf("\n\nEnter choice:");
  scanf("%d",&*choice1);//taking choice of user as input
  return(1);
}



//-----------------------------------------------------------------------------
int submenu(int *choice2)
{
  printf("\n\t\tThe menu of operations for un-ordered lists are as follows ");//showing menu
 
  printf("\n1.Prepend.\n2.Append.\n3.After a specific given value.\n4.Before a specific given value.\n5.After the maximum value of the list.\n6.Before the minimum value of the list.");

  printf("\n\nEnter your choice:");
  scanf("%d",&*choice2);//taking choice of user as input
  return(1);
}

//------------------------------------------------------------------------------
sllnode* CreateNode()//function to create node and returning node pointer
{
  sllnode *p;
  p=(sllnode*)malloc(sizeof(sllnode));
  
  p->Next=NULL;

  printf("\nEnter the node data:");
  scanf("%d",&p->Data);//taking input of data in the node
 
  return(p);
}
//------------------------------------------------------------------------------
int initialisation_of_list(sllnode **list)
{
  int n, i;

  sllnode* CreateNode();//prototype of function
   
  sllnode *nn ,*p;//declaring sllnode type pointer variable

  printf("\nEnter the number of nodes you want initially in your linked list:");
  scanf("%d",&n);//taking no. of nodes input

  while(n!=0)
  {
    nn=CreateNode();//function cal to get a new node

    if(*list==NULL)
    {
      *list=nn;//pointing list to the new node if the list is null
    }
    else
    {
      p=*list;//p pointing to the first node

      while(p->Next !=NULL)//traversing till last node
      {
        p=p->Next;
      }
      
      p->Next=nn;
    }

    n=n-1;
  }


  return(1);
}

//-----------------------------------------------------------------------------
int display(sllnode *LIST)
{
  sllnode *p;//declaring sllnode type pointer variable
  
  if(LIST==NULL)
  {
    printf("\nThe linked list is empty.");
  }
  else
  {
    p=LIST;
    while(p!=NULL)
    {
      //printing the list along with node address
      printf("\nContent of node is %d at address %p ", p->Data ,p);

      p=p->Next;//p moving forward
    }
  }

  return(1);
}
//---------------------------------------------------------------------------
int order(int *flag, sllnode *LIST)
{
  sllnode *p, *np;//declaring sllnode type pointer variables

  p=LIST;//p pointing to the first node

  np=p->Next;//np pointing to the next node of p

  *flag=0; 
  while(np!= NULL)//traversing till last node
  {
    if(p->Data <= np->Data)
    {
      *flag=1;//if ascending
    }
    else
    {
      *flag=0;//found unordered and break from loop
      break;          

    }
     
    p=np;
    np=p->Next;
  }


  if(np==NULL)
  {
    return(1);
  }

  p=LIST;//p pointing to the first node
  np=p->Next;//np pointing to the next node of p
  
  while(np!= NULL)//traversing till last node
  {
     if(p->Data >= np->Data)
     {
       *flag=2;//if descending
     }
     else
     {
       *flag=0;  //found unordered and break from loop
       break;
       
     }
     
     p=np;
     np=p->Next;
  }
  

  return(1);
}
//------------------------------------------------------------------------

int insert_in_ordered_list(int flag,sllnode **LIST)
{
  sllnode *nn, *q, *p;//declaring sllnode type pointer variables

  sllnode* CreateNode();//prototype of function

  nn=CreateNode();//calling function to get new node 
  
  if(*LIST==NULL)
  {
  	*LIST= nn;
  	return(1);
  }

  p=*LIST;
  q=p->Next;
  
  if(flag==1)//condition for ascending order
  {
     if(nn->Data < p->Data )
     {
       //appending new node
        
       nn->Next=*LIST;
       *LIST=nn;
       return(1);
     }
    
     while(p->Next!=NULL)
     {
       if((nn->Data >= p->Data) && ( nn->Data < q->Data))//condition check for suitable place of insertion
       {
         //inserting the new node in that position 
         nn->Next=p->Next;
         p->Next=nn;
         break;
       }
      
       p=p->Next;//moving p forward
       q=p->Next;//moving q forward
     
     }
   
     if(p->Next==NULL)//CHECKING IF POINTER REACHED THE END OF LINKED LIST
     {
       p->Next=nn;//then inserting in the end of list
     }

  }
  else if(flag==2)//condition for descending order
  {
      if(nn->Data > p->Data )
     {
       //appending new node
       nn->Next=*LIST;
       *LIST=nn;
       return(1);
     }
  
     while(p->Next!=NULL)
     {
       if((nn->Data <= p->Data) && ( nn->Data > q->Data))//condition check for suitable place of insertion
       {
         //inserting the new node in that position 
         nn->Next=p->Next;
         p->Next=nn;
         break;
       }
      //moving p and q forward
       p=p->Next;
       q=p->Next;
     
     }
     
     if(p->Next==NULL)//CHECKING IF POINTER REACHED THE END OF LINKED LIST
     {
       p->Next=nn;//then inserting in the end of list
     }
  }

  return(1);
}  
//-----------------------------------------------------------------------------
int prepend(sllnode **LIST)
{
  sllnode *nn;//declaring sllnode type pointer variable

  sllnode* CreateNode();//prototype of function

  nn=CreateNode();//calling function to get new node 
  
  if(*LIST==NULL)//CHECKING IF LIST IF NULL
  {
     *LIST=nn;//inserting the node at first
  }
  else
  {
     //prepending the node
     nn->Next=*LIST;
     *LIST=nn;
  }
  
  return(1);
}
//-----------------------------------------------------------------------------
int append(sllnode **LIST)
{
  sllnode *nn, *q;//declaring sllnode type pointer variables

  sllnode* CreateNode();//prototype of function

  nn=CreateNode();//calling function to get new node 
 
  if(*LIST==NULL)//CHECKING IF LIST IF NULL
  {
     *LIST=nn;//inserting the node at first
  }
  else
  {
    q=*LIST;//q pointing to first node

    while(q->Next!=NULL)//loop to run till q next part is null
    {
      q=q->Next;//moving forward
    }
    q->Next=nn;//appending the node

  }
 
  return(1);
}

//-----------------------------------------------------------------------------

int insert_after_a_value(int key,sllnode *loc,sllnode **LIST)
{
  sllnode *nn, *q;//declaring sllnode type pointer variables

  sllnode* CreateNode();//prototype of function
  
  nn=CreateNode();//calling function to get new node 

  if(*LIST==NULL)//CHECKING IF LIST IF NULL
  {
    printf("\nNo node present in the linked list so new node will be inserted at start");
    *LIST=nn;//inserting the node at first
  }
  else
  {
    if(loc==NULL)
    {
      printf("\nNo such node value present in the linked list");
      free(nn);
    } 
    else
    {
      nn->Next=loc->Next;//storing loc next part to nn next part
      loc->Next=nn;//storing nn to loc next part
    }

  }

  return(1);
}
//--------------------------------------------------------------------------------
int insert_before_a_value(int key, sllnode *ploc ,sllnode **LIST)
{
  sllnode *nn, *q, *prev;//declaring sllnode type pointer variables

  sllnode* CreateNode();//prototype of function
  
  nn=CreateNode();//calling function to get new node 

  if(*LIST==NULL)//CHECKING IF LIST IF NULL
  {
    printf("\nNo node present in the linked list so new node will be inserted at start");
    *LIST=nn;//inserting the node at first
  }
  else
  {
    if(ploc==NULL)
    {
      printf("\nNo such node value present in the linked list");
      free(nn);
    } 
    else
    {
      nn->Next=ploc->Next;//storing ploc next part to nn next part
      ploc->Next=nn;//storing nn to ploc next part
    }

  }

  return(1);
}
//------------------------------------------------------------------------------
int maximum_value(int *max,sllnode *LIST, sllnode **loc)
{
  sllnode *p;//declaring sllnode type pointer variable
  
  
  p=LIST;//p pointing to first node

  *max=p->Data;//storing first node value to max
  p=p->Next; //moving p forward

  while(p!=NULL)
  {
    if(p->Data >= *max)//comparing each node value to max
    {
      *loc=p;
      *max=p->Data;//storing that value to max
    }
    
    p=p->Next;//moving p forward
  }

  return(1);
}

//-------------------------------------------------------------------------------

int minimum_value(int *min, sllnode *LIST, sllnode **ploc, sllnode **loc)
{
  sllnode *p, *temp;  //declaring sllnode type pointer variable
  
  *ploc=NULL;

  p=LIST;//p pointing to first node
  
  *min=p->Data;//storing first node value to min
  *loc=p;
  p=p->Next;//moving p forward

  while(p!=NULL)
  {
    if(p->Data < *min)//comparing each node value to min
    {
      *ploc=temp;
      *min=p->Data;//storing that value to min
      *loc=p;
    }
    temp=p;
    p=p->Next;//moving p forward
  }

  return(1);
}

//-------------------------------------------------------------------------------

int search(int key, sllnode *LIST, sllnode **ploc, sllnode **loc)
{
  *ploc=NULL;
  *loc=LIST;//pointing to first node

  while(*loc!=NULL)//traversing till last node of the list
  {
    if(((*loc)->Data)== key)//if the data is found
    {
      return(1);
    }
    else
    {
      *ploc=*loc;//moving forward
      *loc=(*loc)->Next;//moving loc forward
    }
  }

  return(1);
}
//----------------------------------------------------------------------------  

int search_number_of_occurence(int key , int *counter ,sllnode *LIST ,sllnode2 **list)
{
  sllnode *loc;//declaring sllnode type pointer variable

  sllnode2 *p ,*q;//declaring sllnode2 type pointer variable

  *counter=0;
  
  loc=LIST;// loc pointing to first node of original list
  
  while(loc!=NULL)//traversing till last node of the original list 
  {
    if(loc->Data== key)//if the data is found
    {
      *counter=*counter+1;//incremening the counter
      
      p=(sllnode2*)malloc(sizeof(sllnode2));

      p->data=loc;//storing the address of ocuurence in the second list node 

      p->next=NULL;

      if(*list==NULL)
      {
        *list=p;
      }
      else
      {
        q=*list;// loc pointing to first node of second list

        while(q->next!=NULL)//traversing till last node of the second list 
        {
          q=q->next;//moving q forward
        }
        q->next=p;

      }
       
    } 
    loc=loc->Next;//moving loc forward of the original list
  } 
  
  return(1);
}
//--------------------------------------------------------------------------  
int delete_a_value(sllnode **LIST , sllnode *loc,sllnode *ploc)
{
  if(loc==*LIST)//if loc point to first node
  {
    *LIST=loc->Next;//LIST gets updated
  }
  else
  {
    ploc->Next=loc->Next;//deleting the node
  }

  return(1);
}

//------------------------------------------------------------------------
int delete_all_repeated_occurence(sllnode *LIST)
{
  sllnode *p, *loc, *ploc;//declaring sllnode type pointer variables


  //ploc and p pointing to first node
  ploc=LIST;  
  p=LIST;

  loc=p->Next;//loc points to the next node pointed by p
  
  while(p!=NULL)//traversing till last node of the list
  {
    while(loc!=NULL)//traversing till last node of the list
    {
      if(p->Data==loc->Data)//checking if repeated ocuurence found
      {
        ploc->Next=loc->Next;//removing that node
        loc=loc->Next;//loc moving forward
      }
      else
      {
        ploc=loc;
        loc=loc->Next;//loc moving forward
      }
    }//end of inner while
    
    p=p->Next;//p moving forward
    ploc=p;
    if(p!=NULL)
    {
      loc=p->Next;
    }
  }//end of outer while
  return(1);
}
//-------------------------------------------------------------------
int concatenate(sllnode *LIST,sllnode *LIST2)
{
  sllnode *p;//declaring sllnode type pointer

  p=LIST;//p pointing to first node of first list
  
  while(p->Next!=NULL)//traversing original list till last node
  {
    p=p->Next;//p moving forward
  }

  p->Next=LIST2;//concatenating second list with the original list
  
  return(1);
}
//-------------------------------------------------------------------
int merge(int flag ,sllnode **LIST,sllnode *LIST2)
{
  sllnode *p, *temp;//declaring sllnode type pointers

  p=*LIST;//p pointing to first node of first list
  
  
  while((p!=NULL) && (LIST2!= NULL))//traversing original list till last node
  {
    temp=LIST2->Next;
    
    if(p->Next==NULL)
    {
      temp=LIST2;
      while(temp->Next!=NULL)
      {
        temp=temp->Next;
      }
      temp->Next=p->Next;
      p->Next=LIST2;
	  
      return(1); 	
   }

   if(flag==1)//this part gets executed when the list is in ascending order
   {
   
     if(LIST2->Data <= p->Data)
     {  
       // merging the node    
       LIST2->Next=p;

       *LIST=LIST2;

       LIST2=temp;
       p=*LIST;
     }
     else if((LIST2->Data > p->Data &&  LIST2->Data <= (p->Next)->Data))
     {
       //merging the nodes
       LIST2->Next=p->Next;
       p->Next=LIST2;
   
       LIST2=temp;
      
     }
     else
     {
       p=p->Next;
     }

   } 
   else //this part gets executed when the list is in descending order
   {
      if(LIST2->Data >= p->Data)
      {  
         // merging the node    
         LIST2->Next=p;

         *LIST=LIST2;

         LIST2=temp;
         p=*LIST;
      }
      else if((LIST2->Data < p->Data &&  LIST2->Data >= (p->Next)->Data) )
      {
         //merging the nodes
         LIST2->Next=p->Next;
         p->Next=LIST2;
   
         LIST2=temp;
      
      }
      else
      {
         p=p->Next;
      }
    }
  }

  return(1);
}
//----------------------------------------------------------------
int randomize(sllnode **LIST)
{
  sllnode *temp, *p , *ploc;//declaring sllnode type pointers

  //p and ploc pointing to first node 
  ploc=*LIST;
  p=*LIST;

  temp=p->Next;//temp pointing to next node to node pointed by p
  
  while(temp!=NULL)//traversing original list till last node
  {
    //altering node position
    p->Next=temp->Next;
    temp->Next=p;
    

    if(p==*LIST)
    {
      *LIST=temp;
    }
    else
    {
      //linking the previous node with the nodes altered
      ploc->Next=temp;
      ploc=p;
    }
    p=p->Next;

    if(p==NULL)
    {
      return(1);
    }
    else
    {
      temp=p->Next;
    }

  }
  return(1);
}
//----------------------------------------------------------------
int reverse(sllnode **LIST)
{
  sllnode *p , *np , *temp;//declaring sllnode type pointers

  p=*LIST;//p pointing to first node
  np= p->Next;//np pointing to next node to node pointed by p

  while(np!=NULL)//traversing original list till last node
  {

     temp=np->Next;//temp pointing  to next node of np

     np->Next=p;

     p=np;
     np=temp;
  }
  temp=*LIST;
   
  temp->Next=NULL;//storing null  to the next part of first node

  *LIST=p;

  return(1);
}
