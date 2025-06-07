# Pointer to Pointer

## Uses

#### Data structures like strings, linked-lists, or arrays

Whenever you are passing these as arguments to functions, it's better to pass them as **pointer to pointer**. This helps majorly especially when:

- We need to modify the size of the data structure being returned from the original
- We have to modify the head of the list

```c
// Example in linked list for inserting at the beginning
void insert_at_head(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}
```

#### Dynamic allocation of 2D arrays

```c
int main() {
    int rows = 3, cols = 4;  // Example dimensions
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    // Don't forget to free memory when done
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}
```

#### modify pointers in function

```c
void allocate_memory(int** ptr, int size) {  
*ptr = (int*)malloc(size * sizeof(int));  
}  
  
int main() {  
int* my_array = NULL;  
allocate_memory(&my_array, 5);  
  
if (my_array != NULL) {  
printf("Memory allocated successfully!\n");  
free(my_array);  
}  
return 0;  
}
```

#### command line args
```c
int main(int argc, char *argv[])           
{                                             
  return EXIT_SUCCESS;                     
}                                          

```