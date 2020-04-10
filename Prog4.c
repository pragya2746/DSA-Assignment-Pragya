
#include <stdio.h>




#include <stdlib.h>


#define initmemory() (struct node*)malloc(sizeof(struct node))







struct node {


  


   int data;


   struct node *left;


   struct node *right;


  


};







struct node* insert(struct node* root, int data) {


      


   if(root == NULL) {


  


       struct node* node = initmemory();







       node->data = data;







       node->left = NULL;


       node->right = NULL;


       return node;


  


   } else {


          


       if(data <= root->data) {


           root->left = insert(root->left, data);


       }







       else {


           root->right = insert(root->right, data);;


       }


       return root;


   }


}


struct node * minValueNode(struct node* node)


{


   struct node* current = node;






   while (current && current->left != NULL)


       current = current->left;






   return current;


}






struct node* deleteNode(struct node* root, int data)


{


   if (root == NULL) return root;







   if (data < root->data)


       root->left = deleteNode(root->left, data);






   else if (data > root->data)


       root->right = deleteNode(root->right, data);






   else


   {


       if (root->left == NULL)


       {


           struct node *temp = root->right;


           free(root);


           return temp;


       }


       else if (root->right == NULL)


       {


           struct node *temp = root->left;


           free(root);


           return temp;


       }






       struct node* temp = minValueNode(root->right);






       root->data = temp->data;






       root->right = deleteNode(root->right, temp->data);


   }


   return root;


}







int main(){


   int ans,data;


   struct node* root = NULL;


   while(1){


       printf("MENU\n1.insert an element\n2.delete an element\n3.exit\n");


       scanf("%d",&ans);


       switch(ans){


           case 1: {


               printf("enter the data to be inserted");


               scanf("%d",&data);


               insert(root,data);


               break;


           }


           case 2:{


               printf("enter the data to be deleted");


               scanf("%d",&data);


               deleteNode(root,data);


               break;


           }


           case 3:


           exit(0);break;


       }


   }


   return 0;


}





