#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义链表结构
typedef struct LinkedList {
    Node* head;  // 指向链表的头节点
} LinkedList;

// 初始化链表
void init(LinkedList* list) {
    list->head = NULL;
}

// 在链表尾部插入节点
void append(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 删除指定值的节点
void det(LinkedList* list, int data) {
    Node* current = list->head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                list->head = current->next;
            }
            else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// 打印链表
void print(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}

int main() {
    LinkedList myList;
    init(&myList);

    // 插入元素
    append(&myList, 10);
    append(&myList, 20);
    append(&myList, 30);
    append(&myList, 40);

    // 打印链表
    printf("Linked List: ");
    print(&myList);

    // 删除元素
    det(&myList, 20);

    // 打印删除后的链表
    printf("Linked List after deleting 20: ");
    print(&myList);

    // 释放链表内存
    freeList(&myList);

    return 0;
}
