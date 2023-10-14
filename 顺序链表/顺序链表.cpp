#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // 定义顺序表的最大容量

typedef struct {
    int data[MAX_SIZE];  // 存储数据的数组
    int length;          // 当前顺序表中元素的个数
} SeqList;

// 初始化顺序表
void init(SeqList* list) {
    list->length = 0;
}

// 在顺序表的末尾插入一个元素
int insert(SeqList* list, int element) {
    if (list->length >= MAX_SIZE) {
        printf("顺序表已满，无法插入元素\n");
        return -1;  // 表示插入失败
    }
    list->data[list->length] = element;
    list->length++;
    return 0;  // 表示插入成功
}

// 根据索引删除元素
int det(SeqList* list, int index) {
    if (index < 0 || index >= list->length) {
        printf("无效的索引\n");
        return -1;  // 表示删除失败
    }
    for (int i = index; i < list->length - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->length--;
    return 0;  // 表示删除成功
}

// 根据索引获取元素
int get(SeqList* list, int index) {
    if (index < 0 || index >= list->length) {
        printf("无效的索引\n");
        return -1;  // 返回一个特定的错误值表示获取失败
    }
    return list->data[index];
}

int main() {
    SeqList myList;
    init(&myList);

    // 插入元素
    for (int i = 1; i <= 5; i++) {
        insert(&myList, i * 10);
    }

    // 打印顺序表中的元素
    for (int i = 0; i < myList.length; i++) {
        printf("%d ", get(&myList, i));
    }
    printf("\n");

    // 删除元素
    det(&myList, 2);

    // 打印删除后的顺序表
    for (int i = 0; i < myList.length; i++) {
        printf("%d ", get(&myList, i));
    }
    printf("\n");

    return 0;
}
